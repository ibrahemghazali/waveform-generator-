#include "EUSART.h"
static void (*TX_isr_ptr)(void);
static void (*RX_isr_ptr)(void);
static void (*RX_frame_error_handler_ptr)(void);
static void (*RX_over_run_error_handler_ptr)(void);

void TX_INTERRUPT_HANDLER(void);
void RX_INTERRUPT_HANDLER(void);
void RX_over_run_handler(void);
void RX_frame_error_handler(void);

static uint8 interrupt_data_transmitting=0;
static uint8 *interrupt_data_receiving=0;
static pin_config_t TX_pin=
{
  .port=TX_PORT,
  .pin=TX_PIN,
  .logic=GPIO_LOW,
  .direction=GPIO_INPUT
};

static pin_config_t RX_pin=
{
  .port=RX_PORT,
  .pin=RX_PIN,
  .logic=GPIO_LOW,
  .direction=GPIO_INPUT
};
static STD_RETURN_TYPE EUSART_TX_asynchronous_init(const TX_t *eusart_obj);
static STD_RETURN_TYPE EUSART_RX_asynchronous_init(const RX_t *eusart_obj);
STD_RETURN_TYPE EUSART_asynchronous_init(const EUSART_t *eusart_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        DISABLE_EUSART_MODULE();
        GPIO_PIN_initialize(&TX_pin);
        GPIO_PIN_initialize(&RX_pin);
        SET_EUSART_MODE();
        SET_EUSART_BAUD_RATE(eusart_obj->baud_rate);
       ret=EUSART_TX_asynchronous_init(&(eusart_obj->tx_config));
       ret=EUSART_RX_asynchronous_init(&(eusart_obj->rx_config));
        ENABLE_EUSART_MODULE();
        
    }
    return ret;
}
STD_RETURN_TYPE EUSART_asynchronous_deinit(const EUSART_t *eusart_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        DISABLE_EUSART_MODULE();
    }
    return ret;    
}
STD_RETURN_TYPE EUSART_asynchronous_write_data_blocking(const EUSART_t *eusart_obj,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        while(IS_TRANSMITTING_NOT_PERMITTED());
        TXREG=data;
    }
    return ret;    
}

STD_RETURN_TYPE EUSART_asynchronous_write_String_blocking(const EUSART_t *eusart_obj,const uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if((NULL==eusart_obj)||(NULL==data))
    {
        ret=E_NOK;
    }
    else
    {
        while(data[counter]!='\0')
        {
         EUSART_asynchronous_write_data_blocking(eusart_obj,data[counter]);
         counter++;
        }
    }
    return ret;
}
STD_RETURN_TYPE EUSART_asynchronoues_read_data_blocking(const EUSART_t *eusart_obj,uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==eusart_obj)||(NULL==data))
    {
        ret=E_NOK;
    }
    else
    {
        if(READ_OVERRUN_ERROR())
        {
            EUSART_RX_DISABLE();
            RX_over_run_handler();
            EUSART_RX_ENABLE();
        }
        else
        {
            /*nothing*/
        }
        if(READ_FRAMING_ERROR())
        {
            RX_frame_error_handler();
        }
        else
        {
            /*nothing*/
        }
        while(!RX_INTERRUPT_READ_FLAG());
        *data=READ_RECEIVING_DATA();
    }
    return ret;   
}
STD_RETURN_TYPE EUSART_asynchronous_write_data_nonblocking(const EUSART_t *eusart_obj,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        if(TX_READ_ENABLE())
        {
            ret=E_NOK;
        }
        else
        {
            interrupt_data_transmitting=data;
            TX_INTERRUPT_ENABLE();
        }
    }
    return ret;
}
STD_RETURN_TYPE EUSART_asynchronous_write_String_nonblocking(const EUSART_t *eusart_obj,const uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if((NULL==eusart_obj)||(NULL==data))
    {
        ret=E_NOK;
    }
    else
    {
        while(data[counter]!='\0')
        {
        EUSART_asynchronous_write_data_nonblocking(eusart_obj,data[counter++]);
        }
    }
    return ret;
}
STD_RETURN_TYPE EUSART_asynchronoues_read_data_nonblocking(const EUSART_t *eusart_obj,uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==eusart_obj)||(NULL==data))
    {
        ret=E_NOK;
    }
    else
    {
        if(READ_OVERRUN_ERROR())
        {
            EUSART_RX_DISABLE();
            RX_over_run_handler();
            EUSART_RX_ENABLE();
        }
        else
        {
            /*nothing*/
        }
        if(READ_FRAMING_ERROR())
        {
            RX_frame_error_handler();
        }
        else
        {
            /*nothing*/
        }
        if(RX_READ_ENABLE())
        {
            ret=E_NOK;
        }
        else
        {
            RX_INTERRUPT_ENABLE();
            interrupt_data_receiving=data;
        }
    }
    return ret;
}
static STD_RETURN_TYPE EUSART_TX_asynchronous_init(const TX_t *eusart_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        if(EUSART_TX_ENABLED==eusart_obj->TX_enable)
        {
            EUSART_TX_ENABLE();
            if(EUSART_INTERRUPT_TX_ENABLED==eusart_obj->TX_interrupt_enable)
            {
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            TX_INTERRUPT_DISABLE();
            TX_INTERRUPT_CLEAR_FLAG();
            TX_isr_ptr=eusart_obj->TX_ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
            INTERRUPT_HIGH_PRIORITY_ENABLE();
            INTERRUPT_LOW_PRIORITY_ENABLE();
            if(HIGH_PRIORITY==eusart_obj->TX_priority)
            {
                TX_HIGH_PRIORITY();
            }
            else if(LOW_PRIORITY==eusart_obj->TX_priority)
            {
                TX_LOW_PRIORITY();
            }
            else
            {
                ret=E_NOK;
            }
            
#endif 
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            INTERRUPT_GLOBAL_ENABLE();
            TX_INTERRUPT_ENABLE();
#endif                 
            }
            else
            {
            TX_INTERRUPT_DISABLE();   
            }
            if(EUSART_TX_9BIT_MODE_ENABLED==eusart_obj->TX_9bit_mode_enable)
            {
                EUSART_TX_9BIT_ENABLE();
            }
            else
            {
                EUSART_TX_9BIT_DISABLE();
            }

        }

        else
        {
            EUSART_TX_DISABLE();
        }
    }
    return ret;
}
static STD_RETURN_TYPE EUSART_RX_asynchronous_init(const RX_t *eusart_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==eusart_obj)
    {
        ret=E_NOK;
    }
    else
    {
        if(EUSART_RX_ENABLED==eusart_obj->RX_enable)
        {
            RX_frame_error_handler_ptr=eusart_obj->framing_error_handler;
            RX_over_run_error_handler_ptr=eusart_obj->overrun_error_handler;
            EUSART_RX_ENABLE();
            if(EUSART_INTERRUPT_RX_ENABLED==eusart_obj->RX_interrupt_enable)
            {
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            RX_INTERRUPT_DISABLE();
            RX_isr_ptr=eusart_obj->RX_ISR;
            RX_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
            INTERRUPT_HIGH_PRIORITY_ENABLE();
            INTERRUPT_LOW_PRIORITY_ENABLE();
            if(HIGH_PRIORITY==eusart_obj->RX_priority)
            {
                RX_HIGH_PRIORITY();
            }
            else if(LOW_PRIORITY==eusart_obj->RX_priority)
            {
                RX_LOW_PRIORITY();
            }
            else
            {
                ret=E_NOK;
            }
            
#endif 
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            INTERRUPT_GLOBAL_ENABLE();
            RX_INTERRUPT_ENABLE();
#endif                 
            }
            else
            {
            RX_INTERRUPT_DISABLE();   
            }
            if(EUSART_RX_9BIT_MODE_ENABLED==eusart_obj->RX_9bit_mode_enable)
            {
                EUSART_RX_9BIT_ENABLE();
            }
            else
            {
                EUSART_RX_9BIT_DISABLE();
            }

        }

        else
        {
            EUSART_RX_DISABLE();
        }
    }
    return ret;    
}

void TX_INTERRUPT_HANDLER(void)
{
    TX_INTERRUPT_DISABLE();
    if(interrupt_data_transmitting)
    {    
        EUSART_WRITE_DATA(interrupt_data_transmitting);
        interrupt_data_transmitting=0;
    }

    if(TX_isr_ptr)
    {
        TX_isr_ptr();
    }
}
void RX_INTERRUPT_HANDLER(void)
{
    RX_INTERRUPT_DISABLE();
    if(interrupt_data_receiving)
    {
        *interrupt_data_receiving=READ_RECEIVING_DATA();
        interrupt_data_receiving=0;
    }
    if(RX_isr_ptr)
    {
        RX_isr_ptr();
    }
}

void RX_over_run_handler(void)
{
    if(RX_over_run_error_handler_ptr)
    {
        RX_over_run_error_handler_ptr();
    }
}
void RX_frame_error_handler(void)
{
    if(RX_frame_error_handler_ptr)
    {
        RX_frame_error_handler_ptr();
    }
}