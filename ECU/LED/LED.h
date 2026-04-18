/* 
 * File:   LED.h
 * Author: ibrah
 *
 * Created on January 27, 2025, 6:04 PM
 */

#ifndef LED_H
#define	LED_H
/***********SECTION: library includes*******************/
#include "../../MCAL/GPIO/GPIO.h"

/***********SECTION: macro definition*******************/
#define LED_HIGH 1
#define LED_LOW 0
#define MAX_STATE_PASSED 1
#define MAX_CONNECTION_TYPES 1
/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef enum
{
    SINK_CONNECTION=0,
    SOURCE_CONNECTION=1
}LED_CONNECTION_T;

typedef enum
{
    LED_OFF=GPIO_LOW,
    LED_ON=GPIO_HIGH
}LED_STATE_T;

typedef struct
{
    pin_config_t LED_config;
    uint8 LED_connection_type ;
}LED_config_t;
/***********SECTION: function decleration*******************/
/**
 * @brief:this function initialized the led with a state 
 * @param led pointer to type LED_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_LED_initialize(LED_config_t *led);

/**
 * @brief:this function turn the led on with any connection type 
 * @param led pointer to type LED_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_LED_turn_on(LED_config_t *led);

/**
 * @brief:this function turn the led off with any connection type 
 * @param led pointer to type LED_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_LED_turn_off(LED_config_t *led);

/**
 * @brief:this function toggle the led with any connection type 
 * @param led pointer to type LED_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_LED_toggle_state(LED_config_t *led);

/**
 * @brief:this function turn the led with 
 * @param led pointer to type LED_config_t
 * @param:state passed parmeter for led on pass LED_OFF or 0 and for 
 * led off pass LED_ON or 1 and the connection type doesn't matter because function will check it
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE ECU_LED_turn(LED_config_t *led,uint8 state);
#endif	/* LED_H */

