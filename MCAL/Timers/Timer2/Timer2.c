#include "Timer2.h"
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER2_INTERRUPT_HANDLER(void);
void (*TIMER2_ISR)(void);
#endif 
static uint8 timer2_preloaded_value;
STD_RETURN_TYPE TIMER_2_init(timer2_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER2_DISABLE();
        TIMER2_SELECT_PRESCALER(timer->timer2_prescaler);
        TIMER2_SELECT_POSTSCALER(timer->timer2_postscaler);
        timer2_preloaded_value=timer->timer2_preloaded_value;
        TIMER2_WRITE_PRELOADED_VALUE(timer->timer2_preloaded_value);
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        TIMER2_INTERRUPT_CLEAR_FLAG();
        TIMER2_INTERRUPT_ENABLE();
        TIMER2_ISR=timer->timer2_isr;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        if(INTERRUPT_HIGH_PRIORITY==timer->timer2_priority)
        {
            TIMER1_HIGH_PRIORITY();
        }
        else if(INTERRUPT_LOW_PRIORITY==timer->timer2_priority)
        {
            TIMER1_LOW_PRIORITY();
        }
        else
        {
            ret=E_NOK;
        }
#endif
#endif
        TIMER2_ENABLE();
    }
    return ret;  
}
STD_RETURN_TYPE TIMER_2_deinit(timer2_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_DISABLE();
#endif
        TIMER2_DISABLE();
    }
    return ret;
}
STD_RETURN_TYPE TIMER_2_write_preload_value(timer2_t *timer,uint8 value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        timer2_preloaded_value=value;
        TIMER2_WRITE_PRELOADED_VALUE(value);
    }
    return ret;   
}
STD_RETURN_TYPE TIMER_2_read(timer2_t *timer ,uint8 *value)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==timer)||(NULL==value))
    {
        ret=E_NOK;
    }
    else
    {
        
        *value=TIMER2_READ_PRELOADED_VALUE(); 
    }
    return ret;   
}

#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER2_INTERRUPT_HANDLER(void)
{
    TIMER2_INTERRUPT_CLEAR_FLAG();
    if(TIMER2_ISR)
    {
        TIMER2_ISR();
    }
    TIMER2_WRITE_PRELOADED_VALUE(timer2_preloaded_value);
}
#endif 