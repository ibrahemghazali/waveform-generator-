
#include "LED.h"



STD_RETURN_TYPE ECU_LED_initialize(LED_config_t *led)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==led)||(MAX_CONNECTION_TYPES<led->LED_connection_type))
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(led->LED_config),GPIO_OUTPUT);
        if(SOURCE_CONNECTION==led->LED_connection_type)
        {
            ret=GPIO_PIN_write_logic(&(led->LED_config),led->LED_config.logic);
        }
        else//sink connection
        {
            ret=GPIO_PIN_write_logic(&(led->LED_config),!(led->LED_config.logic));
        }
                    
    }
    return ret;
}


STD_RETURN_TYPE ECU_LED_turn_on(LED_config_t *led)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==led)
    {
        ret=E_NOK;
    }
    else
    {
        if(SOURCE_CONNECTION==led->LED_connection_type)
        {
            ret=GPIO_PIN_write_logic(&(led->LED_config),GPIO_HIGH);
        }
        else//sink connnectioin
        {
             ret=GPIO_PIN_write_logic(&(led->LED_config),GPIO_LOW);
        }
    }
    return ret;
}


STD_RETURN_TYPE ECU_LED_turn_off(LED_config_t *led)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==led)
    {
        ret=E_NOK;
    }
    else
    {
       if(SOURCE_CONNECTION==led->LED_connection_type)
        {
            ret=GPIO_PIN_write_logic(&(led->LED_config),GPIO_LOW);
        }
        else//sink connnectioin
        {
             ret=GPIO_PIN_write_logic(&(led->LED_config),GPIO_HIGH);
        }
    }
    return ret;
}
STD_RETURN_TYPE ECU_LED_toggle_state(LED_config_t *led)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==led)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_toggle_Logic(&(led->LED_config));
    }
    return ret; 
}
STD_RETURN_TYPE ECU_LED_turn(LED_config_t *led,uint8 state)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==led)||(state>MAX_STATE_PASSED))
    {
        ret=E_NOK;
    }
    else
    {
       if(SOURCE_CONNECTION==led->LED_connection_type)
        {
           ret=GPIO_PIN_write_logic(&(led->LED_config),state);
        }
        else//sink connnectioin
        {
            ret= GPIO_PIN_write_logic(&(led->LED_config),!(state));
        }
          
    }
    return ret; 
}
