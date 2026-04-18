# 1 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.50\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c" 2
# 1 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.h" 1
# 12 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.h"
# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h" 1
# 12 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_REGISTER.h" 1
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_REGISTER.h"
# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 1
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/../COMPILER.h" 1
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/../MCAL_STD_TYPES.h" 2
# 93 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/../MCAL_STD_TYPES.h"
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
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_REGISTER.h" 2
# 12 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h" 2

# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_CONFIG.h" 1
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_CONFIG.h"
# 1 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h" 1
# 11 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO_CONFIG.h" 2
# 13 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h" 2
# 30 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
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
# 91 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin);
# 101 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction);
# 111 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction);
# 121 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic);
# 131 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic);







STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin);
# 150 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port);
# 160 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction);
# 170 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction);
# 180 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic);
# 190 "ECU/SEVEN_SEGMENT/../../MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic);







STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port);
# 12 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.h" 2

# 1 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT_config.h" 1
# 13 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.h" 2
# 29 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.h"
typedef enum
{
    COMMON_ANODE=0,
   COMMON_CATHODE=1
}SEVEN_SEGMENT_TYPE_T;
typedef struct
{
    pin_config_t seven_segment_pins[4];



}seven_segment_t;






STD_RETURN_TYPE ECU_seven_segment_BCD_initialize(seven_segment_t *seven_segment);

STD_RETURN_TYPE ECU_seven_segment_BCD_write_number(seven_segment_t *seven_segment,uint8 number);
# 1 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c" 2
# 81 "ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c"
STD_RETURN_TYPE ECU_seven_segment_BCD_initialize(seven_segment_t *seven_segment)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    uint8 counter=0;
    if(0==seven_segment)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        for(counter=0;counter<4;counter++)
        {
            ret=GPIO_PIN_enable_direction(&(seven_segment->seven_segment_pins[counter]),GPIO_OUTPUT);
        }

    }
    return ret;
}

STD_RETURN_TYPE ECU_seven_segment_BCD_write_number(seven_segment_t *seven_segment,uint8 number)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    uint8 counter=0;
    if(0==seven_segment||number>9)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        for(counter=0;counter<4;counter++)
        {
            ret=GPIO_PIN_write_logic(&(seven_segment->seven_segment_pins[counter]),((number>>counter)&(1)));
        }
    }
    return ret;
}
