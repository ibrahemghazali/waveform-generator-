# 1 "ECU/RELAY/RELAY.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.50\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ECU/RELAY/RELAY.c" 2
# 1 "ECU/RELAY/RELAY.h" 1
# 11 "ECU/RELAY/RELAY.h"
# 1 "ECU/RELAY/../../MCAL/GPIO/GPIO.h" 1
# 12 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
# 1 "ECU/RELAY/../../MCAL/GPIO/GPIO_REGISTER.h" 1
# 11 "ECU/RELAY/../../MCAL/GPIO/GPIO_REGISTER.h"
# 1 "ECU/RELAY/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 1
# 11 "ECU/RELAY/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
# 1 "ECU/RELAY/../../MCAL/GPIO/../COMPILER.h" 1
# 11 "ECU/RELAY/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 2
# 93 "ECU/RELAY/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
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
# 11 "ECU/RELAY/../../MCAL/GPIO/GPIO_REGISTER.h" 2
# 12 "ECU/RELAY/../../MCAL/GPIO/GPIO.h" 2

# 1 "ECU/RELAY/../../MCAL/GPIO/GPIO_CONFIG.h" 1
# 11 "ECU/RELAY/../../MCAL/GPIO/GPIO_CONFIG.h"
# 1 "ECU/RELAY/../../MCAL/GPIO/GPIO.h" 1
# 11 "ECU/RELAY/../../MCAL/GPIO/GPIO_CONFIG.h" 2
# 13 "ECU/RELAY/../../MCAL/GPIO/GPIO.h" 2
# 30 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
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
# 91 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin);
# 101 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction);
# 111 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction);
# 121 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic);
# 131 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic);







STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin);
# 150 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port);
# 160 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction);
# 170 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction);
# 180 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic);
# 190 "ECU/RELAY/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic);







STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port);
# 11 "ECU/RELAY/RELAY.h" 2
# 20 "ECU/RELAY/RELAY.h"
typedef enum
{
    RELAY_UNACTIVE=0,
    RELAY_ACTIVE=1
}RELAY_STATE_T;


typedef struct
{
    pin_config_t relay_pin;
}RELAY_config_t;







STD_RETURN_TYPE ECU_RELAY_initialize(RELAY_config_t *relay);
# 47 "ECU/RELAY/RELAY.h"
STD_RETURN_TYPE ECU_RELAY_turn_on(RELAY_config_t *relay);







STD_RETURN_TYPE ECU_RELAY_turn_off(RELAY_config_t *relay);







STD_RETURN_TYPE ECU_RELAY_toggle_state(RELAY_config_t *relay);







STD_RETURN_TYPE ECU_RELAY_turn(RELAY_config_t *relay,uint8 state);
# 1 "ECU/RELAY/RELAY.c" 2



STD_RETURN_TYPE ECU_RELAY_initialize(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==relay)
    {
        ret=(STD_RETURN_TYPE)0x00;
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
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==relay)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
      ret=GPIO_PIN_write_logic(&(relay->relay_pin),GPIO_HIGH);
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_turn_off(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==relay)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
         ret=GPIO_PIN_write_logic(&(relay->relay_pin),GPIO_LOW);
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_toggle_state(RELAY_config_t *relay)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==relay)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        ret=GPIO_PIN_toggle_Logic(&(relay->relay_pin));
    }
    return ret;
}
STD_RETURN_TYPE ECU_RELAY_turn(RELAY_config_t *relay,uint8 state)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==relay)||state>1)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(relay->relay_pin),state);
    }
    return ret;
}
