/* 
 * File:   MOTOR_DRIVER.h
 * Author: ibrah
 *
 * Created on January 27, 2025, 11:43 PM
 */

#ifndef MOTOR_DRIVER_H
#define	MOTOR_DRIVER_H

/***********SECTION: library includes*******************/
#include "../../MCAL/GPIO/GPIO.h"

/***********SECTION: macro definition*******************/
#define MOTOR_DRIVER_PINS 2
#define IN1 0
#define IN2 1
/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef enum
{
    MOTOR_OFF=0,
    MOTOR_ON=1        
}MOTOR_STATE_T;


typedef struct
{
    pin_config_t motor_pins[MOTOR_DRIVER_PINS];
}MOTOR_t;

/***********SECTION: function decleration*******************/
STD_RETURN_TYPE ECU_MOTOR_DRIVER_initialize(MOTOR_t *motor);


STD_RETURN_TYPE ECU_MOTOR_DRIVER_turn_clockwise(MOTOR_t *motor);

STD_RETURN_TYPE ECU_MOTOR_DRIVER_turn_counter_clockwise(MOTOR_t *motor);

STD_RETURN_TYPE ECU_MOTOR_DRIVER_stop(MOTOR_t *motor);

#endif	/* MOTOR_DRIVER_H */

