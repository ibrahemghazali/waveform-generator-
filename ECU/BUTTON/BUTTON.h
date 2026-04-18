/* 
 * File:   BUTTON.h
 * Author: ibrah
 *
 * Created on January 27, 2025, 9:31 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H
/***********SECTION: library includes*******************/
#include "../../MCAL/GPIO/GPIO.h"

/***********SECTION: macro definition*******************/

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef enum
{
    BUTTON_PULL_UP=0,
            BUTTON_PULL_DOWN=1
}BUTTON_CONNECTION_T;

typedef enum
{
    BUTTON_ACTIVE=0,
            BUTTON_NOT_ACTIVE=1
}BUTTON_STATE_T;

typedef struct
{
    pin_config_t BUTTON_pin;
    uint8 BUTTON_connection;
}BUTTON_config_t;
/***********SECTION: function decleration*******************/
/**
 * @brief:this function to initialize the button with making the pin input
 * @param :button pointer from BUTTON_config_t 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_BUTTON_initialize(BUTTON_config_t *button);


/**
 * @brief:this function to read the state of button with if it is active or not
 * @param :button pointer from BUTTON_config_t 
 * @param:button_state pointer from BUTTON_STATE_T and used to return value of button 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_BUTTON_get_state(BUTTON_config_t *button,BUTTON_STATE_T *button_state);
#endif	/* BUTTON_H */

