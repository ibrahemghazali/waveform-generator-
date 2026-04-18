#include "SPI.h"
static void(*SPI_isr_ptr)(void);
void SPI_INTERRUPT_HANDLER(void);
static pin_config_t SDO_pin=
{
    .port=SDO_PORT,
    .pin=SDO_PIN,
    .direction=GPIO_OUTPUT
};
static pin_config_t SCK_pin=
{
    .port=SCK_PORT,
    .pin=SCK_PIN,
};

static pin_config_t SS_pin=
{
    .port=SS_PORT,
    .pin=SS_PIN
};
STD_RETURN_TYPE SPI_init(SPI_t *SPI_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==SPI_obj)
    {
        ret=E_NOK;
    }
    else
    {
        SPI_DISABLE();
        SPI_SELECT_SAMPLING_MODE();
        SPI_SELECT_CLOCK_TRANSMITTING_MODE();
        SPI_SELECT_IDLE_STATE();
        if(SPI_CHECK_MASTER_MODE(SPI_obj->SPI_MODE))
        {
            SCK_pin.direction=GPIO_OUTPUT;
            SS_pin.direction=GPIO_OUTPUT;
            SPI_SELECT_MODE(SPI_obj->SPI_MODE);
            GPIO_PIN_initialize(&SCK_pin);
            GPIO_PIN_initialize(&SDO_pin);
            GPIO_PIN_initialize(&SS_pin);
        }
        else if(SPI_CHECK_SLAVE_MODE(SPI_obj->SPI_MODE))
        {
            SCK_pin.direction=GPIO_INPUT;
            SPI_SELECT_MODE(SPI_obj->SPI_MODE);
            ret=GPIO_PIN_initialize(&SCK_pin);
            if(SPI_SLAVE_MODE_SS_DISABLED==SPI_obj->SPI_MODE)
            {
                SS_pin.direction=GPIO_INPUT;
                GPIO_PIN_initialize(&SS_pin);
            }
            else
            {
                /*nothing*/
            }
        }
        else
        {
            ret=E_NOK;
        }
        
        /**INTERRUPT CONFIGURATION start******/
#if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
        if(SPI_INTERRUPT_ENABLED==SPI_obj->SPI_interrupt_enable)
        {
            SPI_INTERRUPT_DISABLE();
            SPI_isr_ptr=SPI_obj->SPI_ISR;
            INTERRUPT_GLOBAL_ENABLE();
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
       INTERRUPT_HIGH_PRIORITY_ENABLE();
       INTERRUPT_LOW_PRIORITY_ENABLE();
       if(HIGH_PRIORITY==SPI_obj->priority)
       {
           SPI_HIGH_PRIORITY();
       }
       else
       {
           SPI_LOW_PRIORITY();
       }
#endif    
       
        }

#endif 
        /**INTERRUPT CONFIGURATION end ******/
        
        SPI_ENABLE();

    }
    return ret;
}
STD_RETURN_TYPE SPI_Enable(SPI_t *SPI_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==SPI_obj)
    {
        ret=E_NOK;
    }
    else
    {
        SPI_ENABLE();
    }
    return ret; 
}
STD_RETURN_TYPE SPI_disable(SPI_t *SPI_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==SPI_obj)
    {
        ret=E_NOK;
    }
    else
    {
        SPI_DISABLE();
    }
    return ret;    
}

STD_RETURN_TYPE SPI_send_data_blocking(SPI_t *SPI_obj,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==SPI_obj)
    {
        ret=E_NOK;
    }
    else
    {

            if(SPI_WRITE_COLLOSION_READ())
            {
                SPI_WRITE_COLLOSION_CLEAR();
            }
            SPI_WRITE_TO_DATA_BUFFER(data);
            while(!IS_BUFFER_REGISTER_FULL());
    }
    return ret;   
}
STD_RETURN_TYPE SPI_read_data_blocking(SPI_t *SPI_obj,uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==SPI_obj)||(NULL==data))
    {
        ret=E_NOK;
    }
    else
    {
        if(SPI_CHECK_MASTER_MODE(SPI_obj->SPI_MODE))
        {
            while(!IS_BUFFER_REGISTER_FULL());
            *data=SPI_READ_DATA_BUFFER();
        }
        else if(SPI_CHECK_SLAVE_MODE(SPI_obj->SPI_MODE))
        {
            if(SPI_OVER_FLOW_READ())
            {
                SPI_OVER_FLOW_CLEAR();
            }
            while(!IS_BUFFER_REGISTER_FULL());
            *data=SPI_READ_DATA_BUFFER();
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;   
}
STD_RETURN_TYPE SPI_send_and_read_data_blocking(SPI_t *SPI_obj,uint8 data,uint8 *data_ptr)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==SPI_obj)||(NULL==data_ptr))
    {
        ret=E_NOK;
    }
    else
    {
        ret=SPI_send_data_blocking(SPI_obj,data);
        ret=SPI_read_data_blocking(SPI_obj,data_ptr);
    }
    return ret;
}

STD_RETURN_TYPE SPI_start_operation_nonblocking(SPI_t *SPI_obj,uint8 data)
{
    STD_RETURN_TYPE ret;
    if(NULL==SPI_obj)
    {
     ret=E_NOK;   
    }
    else
    {
        if(SPI_WRITE_COLLOSION_READ())
        {
            SPI_WRITE_COLLOSION_CLEAR();
        }
        if(SPI_OVER_FLOW_READ())
        {
            SPI_OVER_FLOW_CLEAR();
        }
        if(SPI_READ_ENABLE())//if interrupt enable or not
        {
            ret=E_NOK;
        }
        else
        {
            SPI_INTERRUPT_ENABLE();
            
            SPI_WRITE_TO_DATA_BUFFER(data);
            
        }
    }
    return ret;
}


STD_RETURN_TYPE SPI_send_16bit_data_blocking(SPI_t *SPI_obj,uint16 data)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==SPI_obj)
    {
        ret=E_NOK;
    }
    else
    {
        SPI_send_data_blocking(SPI_obj,(uint8)((data)>>8));
        SPI_send_data_blocking(SPI_obj,(uint8)data);
    }
    return ret;
    
}

void SPI_INTERRUPT_HANDLER(void)
{
    
    SPI_INTERRUPT_CLEAR_FLAG();
    SPI_INTERRUPT_DISABLE();
    if(SPI_isr_ptr)
    {
        SPI_isr_ptr();
    }
}
