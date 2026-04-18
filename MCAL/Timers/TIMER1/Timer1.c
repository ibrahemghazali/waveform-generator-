#include "Timer1.h"
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
static void (*TIMER1_ISR)(void);
static volatile uint16 timer1_ISR_preload_value=0;
void TIMER1_INTERRUPT_HANDLER(void);
#endif
STD_RETURN_TYPE TIMER_1_init(timer1_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER1_DISABLE();
         /****timer1 select mode */
        if(TIMER1_TIMER_MODE==timer->timer1_mode)
        {
            TIMER1_ENABLE_TIMER_MODE();
        }
        else if(TIMER1_COUNTER_MODE==timer->timer1_mode)
        {
            TIMER1_ENABLE_COUNTER_MODE();  
            /**timer 1 synchronization select*/
            if(TIMER1_COUNTER_SYNCHRONIZED_WITH_CLOCK==timer->timer1_counter_synchoranization)
            {
                TIMER1_SYNCHRONIZE_INPUT_WITH_CLOCK();
            }
            else if(TIMER1_COUNTER_ASYNCHRONIZED_WITH_CLOCK==timer->timer1_counter_synchoranization)
            {
                TIMER1_ASYNCHRONIZE_INPUT_WITH_CLOCK();
            }
            else 
            {
                ret=E_NOK;
            }
        }
        else
        {
            ret=E_NOK;
        }
        TIMER1_SELECT_PRESCALER(timer->Timer1_prescaler);
         if(TIMER1_8BIT_READ_MODE==timer->timer1_read_method)
        {
            TIMER1_READ_8_BIT_TWO_TIMES();
        }
        else if(TIMER1_8BIT_READ_MODE==timer->timer1_read_method)
        {
            TIMER1_READ_16_BIT_ONE_TIME();
        }
        else 
        {
            ret=E_NOK;
        }
        timer1_ISR_preload_value=timer->timer1_preloaded_value;
        
       #if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        TIMER1_INTERRUPT_CLEAR_FLAG();
        TIMER1_INTERRUPT_ENABLE();
        TIMER1_ISR=timer->timer1_isr;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        if(INTERRUPT_HIGH_PRIORITY==timer->timer1_priority)
        {
            TIMER1_HIGH_PRIORITY();
        }
        else if(INTERRUPT_LOW_PRIORITY==timer->timer1_priority)
        {
            TIMER1_LOW_PRIORITY();
        }
        else
        {
            ret=E_NOK;
        }
#endif
#endif
        /***timer 0 write preloaded value****/
        TIMER1_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(timer->timer1_preloaded_value);
        TIMER1_WRITE_PRELOADED_VALUE_LOW_REGISTER(timer->timer1_preloaded_value);
        TIMER1_ENABLE();
    }
    return ret;
}
STD_RETURN_TYPE TIMER_1_deinit(timer1_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER1_INTERRUPT_DISABLE();
        TIMER1_DISABLE();
    }
    return ret;  
}
STD_RETURN_TYPE TIMER_1_write_preload_value(timer1_t *timer,uint16 value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER1_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(value);
        TIMER1_WRITE_PRELOADED_VALUE_LOW_REGISTER(value);
    }
    return ret;
}
STD_RETURN_TYPE TIMER_1_read(timer1_t *timer ,uint16 *value)
{
    STD_RETURN_TYPE ret=E_OK;
    uint16 l_timer1_high_register=0;
    uint8 l_timer1_low_register=0;
    if((NULL==value)||(NULL==timer))
    {
        ret=E_NOK;
    }
    else
    {
       l_timer1_low_register=TIMER1_READ_LOW_REGISTER();
       l_timer1_high_register=TIMER1_READ_HIGH_REGISTER();
      *value=(uint16)((l_timer1_high_register<<8)+(l_timer1_low_register));
    }
    return ret;   
}


#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER1_INTERRUPT_HANDLER(void)
{
    TIMER1_INTERRUPT_CLEAR_FLAG();
    if(TIMER1_ISR)
    {
        TIMER1_ISR();
        
    }
}
#endif