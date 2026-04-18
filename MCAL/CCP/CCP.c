#include "CCP.h"
static CCP1_ONE_INIT=CCP1_NOT_INIT_YET;
static CCP2_ONE_INIT=CCP2_NOT_INIT_YET;
static pin_config_t CCP1_pin_config=
{
    .port=CCP1_PORT,
    .pin=CCP1_PIN,
    .logic=CCP_DEFULT_LOGIC_START
};
static pin_config_t CCP2_pin_config=
{
    .port=CCP1_PORT,
    .pin=CCP2_PIN,
    .logic=CCP_DEFULT_LOGIC_START
};
static timer2_t timer2_PWM=
{ 
    
};
static void (*CCP1_ISR_ptr)(void);
static void (*CCP2_ISR_ptr)(void);
void CCP1_INTERRUPT_HANDLER(void);
void CCP2_INTERRUPT_HANDLER(void);




STD_RETURN_TYPE CCP_capture_init(const CCP_t *ccp_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        CCP_CAPTURE_COMPARE_SELECT_TIMER_MODE(ccp_pin->ccp_capture_mode_config.timer_mode_select);
        
        if((CCP1_NOT_INIT_YET==CCP1_ONE_INIT)&&(CCP1_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin))
        {
            CCP1_ONE_INIT=CCP1_IS_INIT;
            CCP1_pin_config.direction=GPIO_INPUT;
            GPIO_PIN_initialize(&CCP1_pin_config);
            if((CCP_CAPTURE_MAX_MODE_VALUE>=ccp_pin->ccp_capture_mode_config.capture_varient_mode)&&(ccp_pin->ccp_capture_mode_config.capture_varient_mode>=CCP_CAPTURE_MIN_MODE_VALUE))
            {
                CCP1_SELECT_MODE(ccp_pin->ccp_capture_mode_config.capture_varient_mode);
            }
            else 
            {
                ret=E_NOK;
            }
#if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            CCP1_INTERRUPT_DISABLE();
            CCP1_ISR_ptr=ccp_pin->ccp_capture_mode_config.ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
          if(HIGH_PRIORITY==ccp_pin->ccp_capture_mode_config.capture_priority)
          {
              CCP1_HIGH_PRIORITY();
          }
          else
          {
              CCP1_LOW_PRIORITY();
          }
          
#endif 
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            INTERRUPT_GLOBAL_ENABLE();
            CCP1_INTERRUPT_ENABLE();
            
#elif 
            ret=E_NOK;
#endif 
        }
        else if((CCP2_NOT_INIT_YET==CCP2_ONE_INIT)&&(CCP2_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin))
        {
            CCP2_ONE_INIT=CCP2_IS_INIT;
            CCP2_pin_config.direction=GPIO_INPUT;
            GPIO_PIN_initialize(&CCP2_pin_config);
            if((CCP_CAPTURE_MAX_MODE_VALUE>=ccp_pin->ccp_capture_mode_config.capture_varient_mode)&&(ccp_pin->ccp_capture_mode_config.capture_varient_mode>=CCP_CAPTURE_MIN_MODE_VALUE))
            {
                CCP2_SELECT_MODE(ccp_pin->ccp_capture_mode_config.capture_varient_mode);
            }
            else 
            {
                ret=E_NOK;
            }
#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            CCP2_INTERRUPT_DISABLE();
            CCP2_ISR_ptr=ccp_pin->ccp_capture_mode_config.ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
          if(HIGH_PRIORITY==ccp_pin->ccp_capture_mode_config.capture_priority)
          {
              CCP2_HIGH_PRIORITY();
          }
          else
          {
              CCP2_LOW_PRIORITY();
          }
          
#endif 
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            INTERRUPT_GLOBAL_ENABLE();
            CCP2_INTERRUPT_ENABLE();
            
#elif 
            ret=E_NOK;
#endif  
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;
}

STD_RETURN_TYPE CCP_read_capture_value(const CCP_t *ccp_pin,uint16 *capture_value)
{
   STD_RETURN_TYPE ret=E_OK;
    if((NULL==ccp_pin)||(NULL==capture_value))
    {
        ret=E_NOK;
    }
    else
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            *capture_value=CCP1_READ_CAPTURE_VALUE();
        }
        else if(CCP2_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            *capture_value=CCP2_READ_CAPTURE_VALUE();
        }
        else 
        {
            ret=E_NOK;
        }
    }
    return ret;
}

STD_RETURN_TYPE CCP_change_capture_rising_to_falling(const CCP_t *ccp_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else 
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            if(CCP_CAPTURE_MODE_EVERY_RISING_EDGE==ccp_pin->ccp_capture_mode_config.capture_varient_mode)
            {
                CCP1_SELECT_MODE(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE);
            }
            else
            {
                ret=E_NOK;
            }
        }
        else if(CCP2_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            if(CCP_CAPTURE_MODE_EVERY_RISING_EDGE==ccp_pin->ccp_capture_mode_config.capture_varient_mode)
            {
                CCP2_SELECT_MODE(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE);
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
    }
}
STD_RETURN_TYPE CCP_change_capture_falling_to_rising(const CCP_t *ccp_pin)
{
 STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else 
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            if(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE==ccp_pin->ccp_capture_mode_config.capture_varient_mode)
            {
                CCP1_SELECT_MODE(CCP_CAPTURE_MODE_EVERY_RISING_EDGE);
            }
            else
            {
                ret=E_NOK;
            }
        }
        else if(CCP2_PIN_SELECTED==ccp_pin->ccp_capture_mode_config.capture_pin)
        {
            if(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE==ccp_pin->ccp_capture_mode_config.capture_varient_mode)
            {
                CCP2_SELECT_MODE(CCP_CAPTURE_MODE_EVERY_RISING_EDGE);
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
    }   
}
STD_RETURN_TYPE CCP_compare_init(const CCP_t *ccp_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        CCP_CAPTURE_COMPARE_SELECT_TIMER_MODE(ccp_pin->ccp_compare_mode_config.timer_mode_select);
        
        if((CCP1_NOT_INIT_YET==CCP1_ONE_INIT)&&(CCP1_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin))
        {
            CCP1_ONE_INIT=CCP1_IS_INIT;
            CCP1_pin_config.direction=GPIO_OUTPUT;
            GPIO_PIN_initialize(&CCP1_pin_config);
            CCP1_WRITE_COMPARE_VALUE(ccp_pin->ccp_compare_mode_config.compare_value);
            if(((ccp_pin->ccp_compare_mode_config.Compare_varient_mode<=CCP_COMPARE_MAX_MODE_VALUE)&&(ccp_pin->ccp_compare_mode_config.Compare_varient_mode>=CCP_COMPARE_MIN_MODE_VALUE))
              ||(CCP_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH==ccp_pin->ccp_compare_mode_config.Compare_varient_mode))
            {
                CCP1_SELECT_MODE(ccp_pin->ccp_compare_mode_config.Compare_varient_mode);
                
            }
            else
            {
             ret=E_NOK;   
            }
#if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            CCP1_INTERRUPT_DISABLE();
            CCP1_ISR_ptr=ccp_pin->ccp_compare_mode_config.ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
            if(HIGH_PRIORITY==ccp_pin->ccp_compare_mode_config.Compare_priority)
            {
                CCP1_HIGH_PRIORITY();
            }
            else if(LOW_PRIORITY==ccp_pin->ccp_compare_mode_config.Compare_priority)
            {
                CCP1_LOW_PRIORITY();
            }
            else
            {
                /*Nothing*/
            }
#endif 
            INTERRUPT_GLOBAL_ENABLE();
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            CCP1_INTERRUPT_ENABLE();
                   
#endif    
        }
        else if((CCP2_NOT_INIT_YET==CCP2_ONE_INIT)&&(CCP2_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin))
        {
            CCP2_ONE_INIT=CCP2_IS_INIT;
            CCP2_pin_config.direction=GPIO_OUTPUT;
            GPIO_PIN_initialize(&CCP2_pin_config);
            CCP2_WRITE_COMPARE_VALUE(ccp_pin->ccp_compare_mode_config.compare_value);
            if(((ccp_pin->ccp_compare_mode_config.Compare_varient_mode<=CCP_COMPARE_MAX_MODE_VALUE)&&(ccp_pin->ccp_compare_mode_config.Compare_varient_mode>=CCP_COMPARE_MIN_MODE_VALUE))
              ||(CCP_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH==ccp_pin->ccp_compare_mode_config.Compare_varient_mode))
            {
                CCP2_SELECT_MODE(ccp_pin->ccp_compare_mode_config.Compare_varient_mode);
                
            }
            else
            {
             ret=E_NOK;   
            }
#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
            CCP2_INTERRUPT_DISABLE();
            CCP2_ISR_ptr=ccp_pin->ccp_compare_mode_config.ISR;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
            if(HIGH_PRIORITY==ccp_pin->ccp_compare_mode_config.Compare_priority)
            {
                CCP2_HIGH_PRIORITY();
            }
            else if(LOW_PRIORITY==ccp_pin->ccp_compare_mode_config.Compare_priority)
            {
                CCP2_LOW_PRIORITY();
            }
            else
            {
                /*Nothing*/
            }
#endif 
            INTERRUPT_GLOBAL_ENABLE();
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
            CCP2_INTERRUPT_ENABLE();
                   
#endif 
        }
        else
        {
           ret=E_NOK; 
        }
    }
    return ret;   
}


STD_RETURN_TYPE CCP_set_compare_value(const CCP_t *ccp_pin,uint16 compare_value)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin)
        {
            CCP1_WRITE_COMPARE_VALUE(ccp_pin->ccp_compare_mode_config.compare_value);
        }
        else if (CCP2_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin)
        {
             CCP2_WRITE_COMPARE_VALUE(ccp_pin->ccp_compare_mode_config.compare_value);
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret; 
}
STD_RETURN_TYPE CCP_change_compare_varient_mode(const CCP_t *ccp_pin,uint8 new_mode)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin)
        {
            if((CCP_CHECK_COMPARE_MODE(ccp_pin->ccp_compare_mode_config.Compare_varient_mode))
                    &&(CCP_CHECK_COMPARE_MODE(new_mode)))
            {
                CCP1_SELECT_MODE(new_mode);
                
            }
            else
            {
             ret=E_NOK;   
            }
        }
        else if (CCP2_PIN_SELECTED==ccp_pin->ccp_compare_mode_config.compare_pin)
        {
            if((CCP_CHECK_COMPARE_MODE(ccp_pin->ccp_compare_mode_config.Compare_varient_mode))
                    &&(CCP_CHECK_COMPARE_MODE(new_mode)))
            {
                CCP2_SELECT_MODE(new_mode);
                
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
    }
    return ret;  
}

STD_RETURN_TYPE CCP_PWM_init(const CCP_t *ccp_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 top_value=0;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        timer2_PWM.timer2_postscaler=ccp_pin->ccp_pwm_mode_config.TIMER_postscaler;
        timer2_PWM.timer2_prescaler=ccp_pin->ccp_pwm_mode_config.TIMER_prescaler;
        TIMER_2_init(&timer2_PWM);
        if(TIMER2_PRESCALER_DIV_BY_1==ccp_pin->ccp_pwm_mode_config.TIMER_prescaler)
        {
             top_value=(uint8)((_XTAL_FREQ)/(ccp_pin->ccp_pwm_mode_config.PWM_Freq*4*(ccp_pin->ccp_pwm_mode_config.TIMER_postscaler+1)*1));
             top_value-=1;
        }
        else if(TIMER2_PRESCALER_DIV_BY_4==ccp_pin->ccp_pwm_mode_config.TIMER_prescaler)
        {
             top_value=(uint8)((_XTAL_FREQ)/(ccp_pin->ccp_pwm_mode_config.PWM_Freq*4*(ccp_pin->ccp_pwm_mode_config.TIMER_postscaler+1)*4));
             top_value-=1;
        }
        else if(TIMER2_PRESCALER_DIV_BY_16==ccp_pin->ccp_pwm_mode_config.TIMER_prescaler)
        {
             top_value=(uint8)((_XTAL_FREQ)/(ccp_pin->ccp_pwm_mode_config.PWM_Freq*4*(ccp_pin->ccp_pwm_mode_config.TIMER_postscaler+1)*16));
             top_value-=1;
        }
        else
        {
            ret=E_NOK;
        }
       
        CCP_SET_TOP_VALUE(top_value);
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_pwm_mode_config.CCP_PIN)
        {
            CCP1_pin_config.direction=GPIO_OUTPUT;
            CCP1_pin_config.logic=GPIO_LOW;
            GPIO_PIN_initialize(&CCP1_pin_config);
            CCP1_SELECT_MODE(CCP_PWM_MODE);
            CCP1_PWM_SET_DUTY_CYCLE((uint16)(((PR2+1)*ccp_pin->ccp_pwm_mode_config.duty_cycle*4)/100));
        }
        else if(CCP2_PIN_SELECTED==ccp_pin->ccp_pwm_mode_config.CCP_PIN)
        {
            CCP2_pin_config.direction=GPIO_OUTPUT;
            CCP2_pin_config.logic=GPIO_LOW;
            GPIO_PIN_initialize(&CCP2_pin_config);
            CCP2_SELECT_MODE(CCP_PWM_MODE);
            CCP2_PWM_SET_DUTY_CYCLE((uint16)(((PR2+1)*ccp_pin->ccp_pwm_mode_config.duty_cycle*4)/100));
        }
        else 
        {
            /*nothing*/
        }
    }
    return ret;
}


STD_RETURN_TYPE CCP_PWM_set_duty_cycle(const CCP_t *ccp_pin,uint16 duty_cycle)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==ccp_pin)
    {
        ret=E_NOK;
    }
    else
    {
        if(CCP1_PIN_SELECTED==ccp_pin->ccp_pwm_mode_config.CCP_PIN)
        {
            CCP1_PWM_SET_DUTY_CYCLE((uint16)(((PR2+1)*duty_cycle*4)/100));
        }
        else if(CCP2_PIN_SELECTED==ccp_pin->ccp_pwm_mode_config.CCP_PIN)
        {
            CCP2_PWM_SET_DUTY_CYCLE((uint16)(((PR2+1)*duty_cycle*4)/100));
        }
        else 
        {
            /*nothing*/
        } 
    }
    return ret;   
}

void(CCP1_INTERRUPT_HANDLER)(void)
{
    CCP1_INTERRUPT_CLEAR_FLAG();
    if(CCP1_ISR_ptr)
    {
        CCP1_ISR_ptr();
    }
}

void(CCP2_INTERRUPT_HANDLER)(void)
{
    CCP2_INTERRUPT_CLEAR_FLAG();
    if(CCP2_ISR_ptr)
    {
        CCP2_ISR_ptr();
    }
}