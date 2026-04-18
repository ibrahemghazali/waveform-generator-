/* 
 * File:   RELAY.h
 * Author: ibrah
 *
 * Created on January 27, 2025, 10:13 PM
 */

#ifndef RELAY_H
#define	RELAY_H
/***********SECTION: library includes*******************/
#include "../../MCAL/GPIO/GPIO.h"

/***********SECTION: macro definition*******************/
#define MAX_RELAY_STATES 1

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef enum
{
    RELAY_UNACTIVE=0,
    RELAY_ACTIVE=1
}RELAY_STATE_T;


typedef struct
{
    pin_config_t relay_pin;
}RELAY_config_t;
/***********SECTION: function decleration*******************/
/**
 * @brief: this function used to initialize the relay with direction and a logic state 
 * @param relay pointer from RELAY_config_t 
 * @return  * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_RELAY_initialize(RELAY_config_t *relay);


/**
 * @brief: this function used to turn the relay on
 * @param relay pointer from RELAY_config_t 
 * @return  * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_RELAY_turn_on(RELAY_config_t *relay);

/**
 * @brief: this function used to turn the relay off
 * @param relay pointer from RELAY_config_t 
 * @return  * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_RELAY_turn_off(RELAY_config_t *relay);

/**
 * @brief: this function used to toggle the state of the relay
 * @param relay pointer from RELAY_config_t 
 * @return  * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_RELAY_toggle_state(RELAY_config_t *relay);

/**
 * @brief: this function used to turn relay with passed parameter
 * @param relay pointer from RELAY_config_t 
 * @return  * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_RELAY_turn(RELAY_config_t *relay,uint8 state);

#endif	/* RELAY_H */

