#include "BUTTON.h"


STD_RETURN_TYPE ECU_BUTTON_initialize(BUTTON_config_t *button)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==button)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(button->BUTTON_pin),GPIO_INPUT);
    }
    return ret;
}
STD_RETURN_TYPE ECU_BUTTON_get_state(BUTTON_config_t *button,BUTTON_STATE_T *button_state)
{
    STD_RETURN_TYPE ret=E_OK;
    PIN_LOGIC_T pin_state=0;
    if(NULL==button)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_read_logic(&(button->BUTTON_pin),&pin_state);
        if(BUTTON_PULL_DOWN==button->BUTTON_connection)
        {
            *button_state=(BUTTON_STATE_T)pin_state;
        }
        else if(BUTTON_PULL_UP==button->BUTTON_connection)
        {
            *button_state=!(BUTTON_STATE_T)pin_state;
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;
}

