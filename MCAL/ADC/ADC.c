#include "ADC.h"
void ADC_ISR(void);
void (*ADC_ISR_PTR)(void);
static STD_RETURN_TYPE ADC_input_pin(ADC_CHANNEL_t input_channel);
#if ADC_CODE_CONFIG==ADC_RUN_TIME_CONFIG

STD_RETURN_TYPE ADC_init(ADC_t *adc)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==adc)
    {
        ret=E_NOK;
    }
    else
    {
        ADC_CONVERTER_DISABLE();
        ADC_SET_ACQUISTION_TIME(adc->ADC_acquistion_time);
        ADC_SET_CONVERSION_CLOCK(adc->ADC_clock);
        /*ADC select result format*/
        if(ADC_RESULT_RIGHT_JUSTIFIED==adc->adc_result_justification)
        {
            ADC_SELECT_RESULT_RIGHT_JUSTIFIED();
        }
        else if(ADC_RESULT_LEFT_JUSTIFIED==adc->adc_result_justification)
        {
            ADC_SELECT_RESULT_LEFT_JUSTIFIED();
        }
        else
        {
            ret=E_NOK;
        }
        /*ADC select result format*/
        
        /**ADC_INTERRUPT config**/
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
         INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        ADC_INTERRUPT_DISABLE();
        ADC_INTERRUPT_CLEAR_FLAG();
        ADC_ISR_PTR=adc->ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_HIGH_PRIORITY==adc->ADC_priority)
        {
            ADC_HIGH_PRIORITY();
        }
        else if(INTERRUPT_LOW_PRIORITY==adc->ADC_priority)
        {
         ADC_LOW_PRIORITY();   
        }
        else
        {
            ret=E_NOK;
        }
        ADC_INTERRUPT_ENABLE();
#endif 
        
#endif 
        
        /**ADC_INTERRUPT config**/
        ADC_CONVERTER_ENABLE();
    }
    return ret;
}
STD_RETURN_TYPE ADC_deinit(ADC_t *adc)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==adc)
    {
        ret=E_NOK;
    }
    else
    {
        ADC_CONVERTER_DISABLE();
    }
    return ret;
}
STD_RETURN_TYPE ADC_read_channel(ADC_t *adc,ADC_CHANNEL_t channel,ADC_result_t *result)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==adc)||(NULL==result))
    {
        ret=E_NOK;
    }
    else
    {
        ret=ADC_input_pin(channel);
        ADC_SELECT_CHANNEL(channel);
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_BLOCKING
        ADC_START_CONVERSION();
        adc->channel_pin=channel;
        while(ADC_CONVERSION_STATE());
        ret=ADC_read_conversion(adc,result);
        
#elif ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
        ADC_START_CONVERSION(); 
        adc->channel_pin=channel;
#endif
   
    }
    return ret;
}



STD_RETURN_TYPE ADC_read_conversion(ADC_t *adc,ADC_result_t *result)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==adc)||(NULL==result))
    {
        ret=E_NOK;
    }
    else
    {
        if(ADC_RESULT_RIGHT_JUSTIFIED==adc->adc_result_justification)
        {
            *result=(ADC_result_t)(ADRESL)+(ADC_result_t)(ADRESH<<8);
        }
        else if(ADC_RESULT_LEFT_JUSTIFIED==adc->adc_result_justification)
        {
           *result=(ADC_result_t)(((ADRESL)+(ADRESH<<8))>>6); 
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;
}


#elif ADC_CODE_CONFIG==ADC_PRE_BUILD_CONFIG
STD_RETURN_TYPE ADC_init()
{
        STD_RETURN_TYPE ret=E_OK;
        ADC_CONVERTER_DISABLE();
        ADC_SET_ACQUISTION_TIME(ADC_ACQUISTION_TIME);
        ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK);
        /*ADC select result format*/
        if(_ADC_RESULT_RIGHT_JUSTIFIED==ADC_RESULT_JUSTIFICATION)
        {
            ADC_SELECT_RESULT_RIGHT_JUSTIFIED();
        }
        else if(_ADC_RESULT_LEFT_JUSTIFIED==ADC_RESULT_JUSTIFICATION)
        {
            ADC_SELECT_RESULT_LEFT_JUSTIFIED();
        }
        else
        {
            ret=E_NOK;
        }
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
        ADC_INTERRUPT_DISABLE();
        ADC_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
        if(ADC_PRIORITY_INTERRUPT==_ADC_HIGH_PRIORITY)
        {
            ADC_HIGH_PRIORITY();
        }
        else if(ADC_PRIORITY_INTERRUPT==_ADC_HIGH_PRIORITY)
        {
            ADC_LOW_PRIORITY();
        }
        else
        {
            ret=E_NOK;
        }
        ADC_INTERRUPT_ENABLE();
#endif 
#endif
        /*ADC select volatage reference*/
        if(_ADC_INTERNAL_VOLTAGE_REF==ADC_VOLTAFE_REF)
        {
            ADC_SELECT_INTERNAL_VOLTAGE_REF();
        }
        else if(_ADC_EXTERNAL_VOLTAGE_REF==ADC_VOLTAFE_REF)
        {
           ADC_SELECT_EXTERNAL_VOLTAGE_REF(); 
        }
        else
        {
            ret=E_NOK;
        }
        ADC_ANALOG_DIGITAL_FUNCTIONALITY(ADC_ANALOG_DIGITAL_FUNCTIONLLITY);
        ADC_CONVERTER_ENABLE();
        return ret;
}
STD_RETURN_TYPE ADC_deinit()
{
    STD_RETURN_TYPE ret=E_OK;
    ADC_CONVERTER_DISABLE();
    return ret;
}
STD_RETURN_TYPE ADC_read_conversion(ADC_result_t *result)
{
    STD_RETURN_TYPE ret=E_OK;
        if(_ADC_RESULT_RIGHT_JUSTIFIED==ADC_RESULT_JUSTIFICATION)
        {
            *result=(ADC_result_t)(ADRESL)+(ADC_result_t)(ADRESH<<8);
        }
        else if(_ADC_RESULT_LEFT_JUSTIFIED==ADC_RESULT_JUSTIFICATION)
        {
           *result=(ADC_result_t)(((ADRESL)+(ADRESH<<8))>>6); 
        }
        else
        {
            ret=E_NOK;
        }
    
    
    return ret;
}
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE ADC_read_channel_blocking(ADC_CHANNEL_t channel,ADC_result_t *result)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==result)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ADC_input_pin(channel);
        ADC_SELECT_CHANNEL(channel);
        ADC_START_CONVERSION();
        while(ADC_CONVERSION_STATE());
        ret=ADC_read_conversion(result);
    }
}
#endif 
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE ADC_read_channel_INTERRUPT(ADC_CHANNEL_t channel,void(*ISR_ptr)(void))
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ISR_ptr)
    {
        ret=E_NOK;
    }
    else
    {
        ADC_ISR_PTR=ISR_ptr;
        ret=ADC_input_pin(channel);
        ADC_SELECT_CHANNEL(channel);
        ADC_START_CONVERSION();
    }
}
#endif
#endif
static STD_RETURN_TYPE ADC_input_pin(ADC_CHANNEL_t input_channel)
{
    STD_RETURN_TYPE ret=E_OK;
    switch(input_channel)
    {
            case ADC_CHANNEL_0: SET_BIT(TRISA,0); break;
            case ADC_CHANNEL_1: SET_BIT(TRISA,1); break;
            case ADC_CHANNEL_2: SET_BIT(TRISA,2); break;
            case ADC_CHANNEL_3: SET_BIT(TRISA,3); break;
            case ADC_CHANNEL_4: SET_BIT(TRISA,5); break;
            
            case ADC_CHANNEL_5: SET_BIT(TRISE,0); break;
            case ADC_CHANNEL_6: SET_BIT(TRISE,1); break;
            case ADC_CHANNEL_7: SET_BIT(TRISE,2); break;
            
            case ADC_CHANNEL_8:SET_BIT(TRISB,2); break;
            case ADC_CHANNEL_9:SET_BIT(TRISB,3); break;
            case ADC_CHANNEL_10:SET_BIT(TRISB,1); break;
            case ADC_CHANNEL_11:SET_BIT(TRISB,4); break;
            case ADC_CHANNEL_12:SET_BIT(TRISB,0); break;
            
            default :ret=E_NOK;  
    }
    return ret;
}

void ADC_ISR(void)
{
    ADC_INTERRUPT_CLEAR_FLAG();
    if(NULL==ADC_ISR_PTR)
    {
        
    }
    else
    {
        ADC_ISR_PTR();
    }
}