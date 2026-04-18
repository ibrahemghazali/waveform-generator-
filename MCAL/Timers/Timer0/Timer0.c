
#include "Timer0.h"
#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
static void (*TIMER0_ISR)(void);
static volatile uint16 timer0_ISR_preload_value=0;
void TIMER0_INTERRUPT_HANDLER(void);
#endif
STD_RETURN_TYPE TIMER_0_init(timer0_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER0_DISABLE();
        
         /****timer 0 select mode */
        if(TIMER0_TIMER_MODE==timer->timer0_mode)
        {
            TIMER0_SELECT_TIMER_MODE();
        }
        else if(TIMER0_COUNTER_MODE==timer->timer0_mode)
        {
            TIMER0_SELECT_COUNTER_MODE();
         /********timer 0 edge transition****/
        if(TIMER0_RISING_EDGE_TRANSITION==timer->timer_0_edge_transition)
        {
            TIMER0_SELECT_RISING_EDGE_TRANSITION();
        }
        else if(TIMER0_FALLING_EDGE_TRANSITION==timer->timer_0_edge_transition)
        {
            TIMER0_SELECT_FALLING_EDGE_TRANSITION();
        }
        else
        {
            ret=E_NOK;
        }
            /********timer 0 edge transition****/
        }
        else
        {
            ret=E_NOK;
        }
        /****timer 0 select mode */
        
       /**timer 0 prescalar configuration***/
        if(TIMER0_PRESCALER_ENABLED==timer->PRESCALER_STATE)
        {
            TIMER0_ENABLE_PRESCALER();
            TIMER0_SET_PRESCALER_VAL(timer->Timer0_prescaler);
        }
        else if(TIMER0_PRESCALER_DISABLED==timer->PRESCALER_STATE)
        {
            TIMER0_DISABLE_PRESCALER();
        }
        else
        {
            ret=E_NOK;
        }
        

        /****timer 0 select register size */
        if(TIMER0_8_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            TIMER0_SELECT_8_BIT_REGISTER_SIZE();
        }
        else if(TIMER0_16_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            TIMER0_SELECT_16_BIT_REGISTER_SIZE();
        }
        else 
        {
            ret=E_NOK;
        }
        timer0_ISR_preload_value=timer->timer0_preloaded_value;
        

        /***timer 0 interrupt configuration*/
#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_CLEAR_FLAG();
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_ISR=timer->timer0_isr;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        if(INTERRUPT_HIGH_PRIORITY==timer->timer0_priority)
        {
            TIMER0_HIGH_PRIORITY();
        }
        else if(INTERRUPT_LOW_PRIORITY==timer->timer0_priority)
        {
            TIMER0_LOW_PRIORITY();
        }
        else
        {
            ret=E_NOK;
        }
#endif
#endif
        /***timer 0 write preloaded value****/
        TIMER0_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(timer->timer0_preloaded_value);
        TIMER0_WRITE_PRELOADED_VALUE_LOW_REGISTER(timer->timer0_preloaded_value);
        TIMER0_ENABLE();
    }
    return ret;
}
STD_RETURN_TYPE TIMER_0_deinit(timer0_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER0_DISABLE();
        TIMER0_INTERRUPT_DISABLE();
    }
    return ret;    
}
STD_RETURN_TYPE TIMER_0_write_preload_value(timer0_t *timer,uint16 value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        if(TIMER0_8_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            TIMER0_WRITE_PRELOADED_VALUE_LOW_REGISTER(value);
        }
        else if(TIMER0_16_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            TIMER0_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(value);
            TIMER0_WRITE_PRELOADED_VALUE_LOW_REGISTER(value);
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;   
}
STD_RETURN_TYPE TIMER_0_read(timer0_t *timer ,uint16 *value)
{
    STD_RETURN_TYPE ret=E_OK;
    uint16 l_timer0_high_register=0;
    uint8 l_timer0_low_register=0;
    if((NULL==timer)||(NULL==value))
    {
        ret=E_NOK;
    }
    else
    {
        if(TIMER0_8_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            l_timer0_low_register=TIMER0_READ_LOW_REGISTER();
            *value=(uint16)l_timer0_low_register;
        }
        else if(TIMER0_16_BIT_REGISTER_SIZE==timer->timer0_register_size)
        {
            l_timer0_low_register=TIMER0_READ_LOW_REGISTER();
            l_timer0_high_register=TIMER0_READ_HIGH_REGISTER();
            *value=(uint16)((l_timer0_high_register<<8)+(l_timer0_low_register));
        }
        else 
        {
            ret=E_NOK;
        }
    }
    return ret;    
}

void TIMER0_INTERRUPT_HANDLER(void)
{
    TIMER0_INTERRUPT_CLEAR_FLAG();
    if(NULL==TIMER0_ISR)
    {
        
    }
    else
    {
        TIMER0_ISR();
    }      
    TIMER0_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(timer0_ISR_preload_value);
    TIMER0_WRITE_PRELOADED_VALUE_LOW_REGISTER(timer0_ISR_preload_value);
}