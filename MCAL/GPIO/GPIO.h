/* 
 * File:   GPIO.h
 * Author: ibrah
 *
 * Created on January 25, 2025, 7:26 PM
 */

#ifndef GPIO_H
#define	GPIO_H

/***********SECTION: library includes*******************/
#include "GPIO_REGISTER.h"
#include "GPIO_CONFIG.h"

/***********SECTION: macro definition*******************/
#define MICROCONTROLLER_PORTS 5
#define MICROCONTROLLER_PINS 8 
#define ALL_OUTPUT 0xff
#define ALL_INPUT 0x0

#define ACTIVE_FUNCTION 1
#define UNACTIVE_FUNCTION 0

#define PORT_TOGGLE_MASK 0xFF

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef enum
{
    GPIO_OUTPUT=0,
    GPIO_INPUT=1
}PIN_DIRECTION_T;

typedef enum
{
    GPIO_LOW=0,
    GPIO_HIGH=1
}PIN_LOGIC_T;

typedef enum 
{
    GPIO_PORTA=0,
    GPIO_PORTB=1,
    GPIO_PORTC=2,
    GPIO_PORTD=3,
     GPIO_PORTE=4
}PORT_INDEX_T;

typedef enum
{
    GPIO_PIN0=0,
    GPIO_PIN1=1,
    GPIO_PIN2=2,
    GPIO_PIN3=3,
    GPIO_PIN4=4,
    GPIO_PIN5=5,
    GPIO_PIN6=6,
   GPIO_PIN7=7
}PIN_INDEX_T;

#if (PIN_FUNCTION_ENABLE==ACTIVE_FUNCTION)
typedef struct 
{
    uint8 port      :3;
    uint8 pin       :3;
    uint8 direction :1;
    uint8 logic     :1;
}pin_config_t;
#endif

#if(PORT_FUNCITON_ENABLE==ACTIVE_FUNCTION)
typedef struct 
{
    uint8 port ;
    uint8 direction ;
    uint8 state;
}port_config_t;
#endif

/***********SECTION: function decleration*******************/
/**
 * @brief :initialize pin with direction and a state 
 * @param pin is poiter to pin data port,pin,direction,logic
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK  
 */
#if (PIN_FUNCTION_ENABLE==ACTIVE_FUNCTION)

STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin);


/**
 * @brif :this to enable pin to be input or output
 * @param pin is poiter to pin data port,pin,direction,logic
 * @param direction is to select pin to be input or output
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction);


/**
 * @brief:to read direction of the pin
 * @param pin is poiter to pin data port,pin,direction,logic
 * @param direction return be address to pointer from PIN_DIRECTION_T 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction);


/**
 *@brief:this function write logic on the pin with 0v or 5v 
 * @param pin is poiter to pin data port,pin,direction,log
 * @param logic to make the pin state high with 5v or with 0volt 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic);


/**
 *@brief:this function read logic on the pin with 0v or 5v 
 * @param pin is poiter to pin data port,pin,direction,log
 * @param logic pointer to return to it state of the pin
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic);

/**
 *@brief:this function toggle logic on the pin  
 * @param pin is poiter to pin data port,pin,direction,log
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin);

#endif

#if (PORT_FUNCITON_ENABLE==ACTIVE_FUNCTION)
/**
 * @breif this funnction iniitalize the port with direction and logic 
 * @param port pointer to port_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port);


/**
 * @brief ;this enable direction of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param direction 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction);


/**
 * @brief ;this read direction of port 8 or 16 pin with input ,output or some input and other output
 * @param port pointer to port_config_t
 * @param direction pointer of uint8 to return the direction
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction);


/**
 * @brief ;this write logic of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param logic will be written
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic);


/**
 * @brief ;this read logic of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param logic will be return in it 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic);

/**
 * @brief ;this toggle logic of port 8 or 16 pin 
 * @param port pointer to port_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port);

#endif
#endif	/* GPIO_H */

