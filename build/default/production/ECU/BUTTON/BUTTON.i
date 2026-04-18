# 1 "ECU/BUTTON/BUTTON.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.50\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ECU/BUTTON/BUTTON.c" 2
# 1 "ECU/BUTTON/BUTTON.h" 1
# 11 "ECU/BUTTON/BUTTON.h"
# 1 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h" 1
# 12 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
# 1 "ECU/BUTTON/../../MCAL/GPIO/GPIO_REGISTER.h" 1
# 11 "ECU/BUTTON/../../MCAL/GPIO/GPIO_REGISTER.h"
# 1 "ECU/BUTTON/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 1
# 11 "ECU/BUTTON/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
# 1 "ECU/BUTTON/../../MCAL/GPIO/../COMPILER.h" 1
# 11 "ECU/BUTTON/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 2
# 93 "ECU/BUTTON/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint24;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint24;
typedef signed long sint32;
typedef float float32;
typedef double float64;



typedef uint8 STD_RETURN_TYPE;
# 11 "ECU/BUTTON/../../MCAL/GPIO/GPIO_REGISTER.h" 2
# 12 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h" 2

# 1 "ECU/BUTTON/../../MCAL/GPIO/GPIO_CONFIG.h" 1
# 11 "ECU/BUTTON/../../MCAL/GPIO/GPIO_CONFIG.h"
# 1 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h" 1
# 11 "ECU/BUTTON/../../MCAL/GPIO/GPIO_CONFIG.h" 2
# 13 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h" 2
# 30 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
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


typedef struct
{
    uint8 port :3;
    uint8 pin :3;
    uint8 direction :1;
    uint8 logic :1;
}pin_config_t;



typedef struct
{
    uint8 port ;
    uint8 direction ;
    uint8 state;
}port_config_t;
# 91 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin);
# 101 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction);
# 111 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction);
# 121 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic);
# 131 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic);







STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin);
# 150 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port);
# 160 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction);
# 170 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction);
# 180 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic);
# 190 "ECU/BUTTON/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic);







STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port);
# 11 "ECU/BUTTON/BUTTON.h" 2








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







STD_RETURN_TYPE ECU_BUTTON_initialize(BUTTON_config_t *button);
# 53 "ECU/BUTTON/BUTTON.h"
STD_RETURN_TYPE ECU_BUTTON_get_state(BUTTON_config_t *button,BUTTON_STATE_T *button_state);
# 1 "ECU/BUTTON/BUTTON.c" 2



STD_RETURN_TYPE ECU_BUTTON_initialize(BUTTON_config_t *button)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==button)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(button->BUTTON_pin),GPIO_INPUT);
    }
    return ret;
}
STD_RETURN_TYPE ECU_BUTTON_get_state(BUTTON_config_t *button,BUTTON_STATE_T *button_state)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    PIN_LOGIC_T pin_state=0;
    if(0==button)
    {
        ret=(STD_RETURN_TYPE)0x00;
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
            ret=(STD_RETURN_TYPE)0x00;
        }
    }
    return ret;
}
