#include "MOTOR_DRIVER.h"
STD_RETURN_TYPE ECU_MOTOR_DRIVER_initialize(MOTOR_t *motor)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==motor)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(motor->motor_pins[IN1]),GPIO_OUTPUT);
        ret=GPIO_PIN_enable_direction(&(motor->motor_pins[IN2]),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN1]),GPIO_LOW);
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN2]),GPIO_HIGH);
    }
    return ret;
}


STD_RETURN_TYPE ECU_MOTOR_DRIVER_turn_clockwise(MOTOR_t *motor)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==motor)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN1]),GPIO_HIGH);
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN2]),GPIO_LOW);
    }
    return ret;   
}

STD_RETURN_TYPE ECU_MOTOR_DRIVER_turn_counter_clockwise(MOTOR_t *motor)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==motor)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN2]),GPIO_HIGH);
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN1]),GPIO_LOW);
    }
    return ret;    
}

STD_RETURN_TYPE ECU_MOTOR_DRIVER_stop(MOTOR_t *motor)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==motor)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN1]),GPIO_LOW);
        ret=GPIO_PIN_write_logic(&(motor->motor_pins[IN2]),GPIO_LOW);
    }
    return ret;
} 