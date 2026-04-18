# 1 "MCAL/GPIO/GPIO.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.50\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "MCAL/GPIO/GPIO.c" 2






# 1 "MCAL/GPIO/GPIO.h" 1
# 12 "MCAL/GPIO/GPIO.h"
# 1 "MCAL/GPIO/GPIO_REGISTER.h" 1
# 11 "MCAL/GPIO/GPIO_REGISTER.h"
# 1 "MCAL/GPIO/../MCAL_STD_TYPES.h" 1
# 11 "MCAL/GPIO/../MCAL_STD_TYPES.h"
# 1 "MCAL/GPIO/../COMPILER.h" 1
# 11 "MCAL/GPIO/../MCAL_STD_TYPES.h" 2
# 93 "MCAL/GPIO/../MCAL_STD_TYPES.h"
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
# 11 "MCAL/GPIO/GPIO_REGISTER.h" 2
# 12 "MCAL/GPIO/GPIO.h" 2

# 1 "MCAL/GPIO/GPIO_CONFIG.h" 1
# 11 "MCAL/GPIO/GPIO_CONFIG.h"
# 1 "MCAL/GPIO/GPIO.h" 1
# 11 "MCAL/GPIO/GPIO_CONFIG.h" 2
# 13 "MCAL/GPIO/GPIO.h" 2
# 30 "MCAL/GPIO/GPIO.h"
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
# 91 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin);
# 101 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction);
# 111 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction);
# 121 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic);
# 131 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic);







STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin);
# 150 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port);
# 160 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction);
# 170 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction);
# 180 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic);
# 190 "MCAL/GPIO/GPIO.h"
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic);







STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port);
# 7 "MCAL/GPIO/GPIO.c" 2

static uint8* PORT_registers[5]={((volatile uint8*)0xF80),((volatile uint8*)0xF81),((volatile uint8*)0xF82),((volatile uint8*)0xF83),((volatile uint8*)0xF84)};
static uint8* LAT_registers[5]={((volatile uint8*)0xF89),((volatile uint8*)0xF8A),((volatile uint8*)0xF8B),((volatile uint8*)0xF8C),((volatile uint8*)0xF8D)};
static uint8* TRIS_registers[5]={((volatile uint8*)0xF92),((volatile uint8*)0xF93),((volatile uint8*)0xF94),((volatile uint8*)0xF95),((volatile uint8*)0xF96)};
# 19 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==pin)||(pin->port>=5)||(pin->pin>=8))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(pin,pin->direction);
        ret=GPIO_PIN_write_logic(pin,pin->logic);
    }
    return ret;
}
# 41 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==pin)||(pin->port>=5)||(pin->pin>=8))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        if(GPIO_OUTPUT==direction)
        {
            (*(TRIS_registers[pin->port])&=~(1<<pin->pin));
            pin->direction=GPIO_OUTPUT;
        }
        else if(GPIO_INPUT==direction)
        {
            (*(TRIS_registers[pin->port])|=(1<<pin->pin));
            pin->direction=GPIO_INPUT;
        }
        else
        {
            ret=(STD_RETURN_TYPE)0x00;
        }
    }
    return ret;
}
# 75 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==pin)||(pin->port>=5)||(pin->pin>=8)||(0==direction))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *direction=((*(TRIS_registers[pin->port])>>pin->pin)&(1));
    }
    return ret;
}
# 96 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==pin)||(pin->port>=5)||(pin->pin>=8))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        if(GPIO_HIGH==logic)
        {
            (*LAT_registers[pin->port]|=(1<<pin->pin));
            pin->logic=GPIO_HIGH;
        }
        else if(GPIO_LOW==logic)
        {
            (*LAT_registers[pin->port]&=~(1<<pin->pin));
            pin->logic=GPIO_LOW;
        }
        else
        {
            ret=(STD_RETURN_TYPE)0x00;
        }
    }
    return ret;
}
# 131 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==pin)||(pin->port>=5)||(pin->pin>=8)||(0==logic))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *logic=((*(PORT_registers[pin->port])>>pin->pin)&(1));
    }
    return ret;
}
# 152 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if(0==pin)
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        (*(LAT_registers[pin->port])^=(1<<pin->pin));
    }
    return ret;
}
# 177 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        ret=GPIO_PORT_enable_direction(port,port->direction);
        ret=GPIO_PORT_write_logic(port,port->state);

    }
    return ret;
}
# 200 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *(TRIS_registers[port->port])=direction;
        port->direction=direction;
    }
    return ret;
}
# 223 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5)||(0==direction))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *direction=*(TRIS_registers[port->port]);
    }
    return ret;
}
# 245 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic)
{
     STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *(LAT_registers[port->port])=logic;
        port->state=logic;
    }
    return ret;
}
# 268 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic)
{
        STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5)||(0==logic))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
       *logic=*(PORT_registers[port->port]);
    }
    return ret;
}
# 291 "MCAL/GPIO/GPIO.c"
STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port)
{
    STD_RETURN_TYPE ret=(STD_RETURN_TYPE)0x01;
    if((0==port)||(port->port>=5))
    {
        ret=(STD_RETURN_TYPE)0x00;
    }
    else
    {
        *LAT_registers[port->port]^=0xFF;
    }
    return ret;
}
