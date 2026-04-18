#include "LM_35.h"

#if ADC_CODE_CONFIG==ADC_PRE_BUILD_CONFIG
STD_RETURN_TYPE LM_35_init()
{
    return ADC_init();
}
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_BLOCKING
STD_RETURN_TYPE LM_35_read_blocking(ADC_CHANNEL_t channel,ADC_result_t *result)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==result)
    {
        ret=E_NOK;
    }
    else
    {
        ADC_read_channel_blocking(channel,result);
    }
    return ret;
}

#elif ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE LM_35_read_interrupt(ADC_CHANNEL_t channel,void (*isr_ptr)(void))
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==isr_ptr)
    {
        ret=E_NOK;
    }
    else
    {
        ADC_read_channel_INTERRUPT(channel,isr_ptr);
    }
    return ret;
}
#endif
#endif 
