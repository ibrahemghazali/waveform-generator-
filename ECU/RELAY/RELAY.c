#include "RELAY.h"
#define MAX_RELAY_STATES 1

STD_RETURN_TYPE ECU_RELAY_initialize(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==relay)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(relay->relay_pin),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(relay->relay_pin),relay->relay_pin.logic);
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_turn_on(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==relay)
    {
        ret=E_NOK;
    }
    else
    {
      ret=GPIO_PIN_write_logic(&(relay->relay_pin),GPIO_HIGH);
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_turn_off(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==relay)
    {
        ret=E_NOK;
    }
    else
    {
         ret=GPIO_PIN_write_logic(&(relay->relay_pin),GPIO_LOW);
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_toggle_state(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==relay)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_toggle_Logic(&(relay->relay_pin));
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_turn(RELAY_config_t *relay,uint8 state)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==relay)||state>MAX_RELAY_STATES)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(relay->relay_pin),state);
    }
    return ret; 
}
