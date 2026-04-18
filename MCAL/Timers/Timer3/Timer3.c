#include "Timer3.h"
void TIMER3_INTERRUPT_HANDLER(void);
void (*TIMER3_ISR_PTR)(void);
STD_RETURN_TYPE TIMER3_init(TIMER3_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        //starting of initialization 
        TIMER3_DISABLE();
        TIMER3_INTERRUPT_DISABLE();
        
        //TIMER3 select mode  
        if(TIMER3_TIMER_MODE==timer->TIMER3_mode)
        {
            TIMER3_SELECT_TIMER_MODE();
        }
        else if(TIMER3_COUNTER_MODE==timer->TIMER3_mode)
        {
            TIMER3_SELECT_COUNTER_MODE();
        }
        else
        {
            //nothing that won't happen return to struct bitfields
        }
        
        //TIMER3 synchronization 
        if(TIMER3_SYNCHRONIZATION_MODE==timer->TIMER3_synchoronization)
        {
            TIMER3_SYNCHRONIZE_CLOCK_INPUT();
        }
        else if(TIMER3_NON_SYNCHRONIZATION_MODE==timer->TIMER3_synchoronization)
        {
            TIMER3_NOT_SYNCHRONIZE_CLOCK_INPUT();
        }
        else
        {
            //nothing that won't happen return to struct bitfields
        }
        
        //TIMER3 write preloaded value
        TIMER3_write_preloaded_value(timer,timer->TIMER3_preloaded_val);
        
        //TIMER3 select prescaler 
        TIMER3_SELECT_PRESCALER(timer->TIMER3_prescaler);
        //TIMER3 read enable
        TIMER3_READ_ENABLE();
        
        //TIMER3 interrupt 
        TIMER3_ISR_PTR=timer->timer3_ISR;
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_LOW_PRIORITY==timer->TIMER3_priority)
        {
            TIMER3_LOW_PRIORITY();
        }
        else if(INTERRUPT_HIGH_PRIORITY==timer->TIMER3_priority)
        {
            TIMER3_HIGH_PRIORITY();
        }
        else
        {
            //nothing that won't happen return to struct bitfields
        }
#elif 
        
#endif 
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        TIMER3_INTERRUPT_ENABLE();
        TIMER3_ENABLE();
    }
    return ret;
}
STD_RETURN_TYPE TIMER3_deinit(TIMER3_t *timer)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER3_DISABLE();
        TIMER3_INTERRUPT_DISABLE();
    }
    return ret;
}
STD_RETURN_TYPE TIMER3_write_preloaded_value(TIMER3_t *timer,uint16 val)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
        TIMER3_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(val); 
        TIMER3_WRITE_PRELOADED_VALUE_LOW_REGISTER(val);
    }
    return ret;
}
STD_RETURN_TYPE TIMER3_read(TIMER3_t *timer,uint16 *result)
{
    STD_RETURN_TYPE ret=E_OK;
    uint16 l_timer3_high_register=0;
    uint8 l_timer3_low_register=0;
    if(NULL==timer)
    {
        ret=E_NOK;
    }
    else
    {
       l_timer3_low_register=TIMER3_READ_LOW_REGISTER();
       l_timer3_high_register=TIMER3_READ_HIGH_REGISTER();
      *result=(uint16)((l_timer3_high_register<<8)+(l_timer3_low_register));
    }
    return ret; 
}
void TIMER3_INTERRUPT_HANDLER(void)
{
    if(TIMER3_ISR_PTR!=NULL)
    {
        TIMER3_ISR_PTR();
    }
}
