/* 
 * File:   GPIO.h
 * Author: ibrahem EL-Ghazali
 *
 * Created on January 25, 2025, 7:26 PM
 */
#include "GPIO.h"
static uint8* PORT_registers[MICROCONTROLLER_PORTS]={PORTA_ADDRESS,PORTB_ADDRESS,PORTC_ADDRESS,PORTD_ADDRESS,PORTE_ADDRESS};
static uint8* LAT_registers[MICROCONTROLLER_PORTS]={LATA_ADDRESS,LATB_ADDRESS,LATC_ADDRESS,LATD_ADDRESS,LATE_ADDRESS};
static uint8* TRIS_registers[MICROCONTROLLER_PORTS]={TRISA_ADDRESS,TRISB_ADDRESS,TRISC_ADDRESS,TRISD_ADDRESS,TRISE_ADDRESS};

/**
 * @brief :initialize pin with direction and a state 
 * @param pin is poiter to pin data port,pin,direction,logic
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK  
 */
#if (PIN_FUNCTION_ENABLE==ACTIVE_FUNCTION)
STD_RETURN_TYPE GPIO_PIN_initialize(pin_config_t *pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==pin)||(pin->port>=MICROCONTROLLER_PORTS)||(pin->pin>=MICROCONTROLLER_PINS))
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(pin,pin->direction);
        ret=GPIO_PIN_write_logic(pin,pin->logic);
    }
    return ret;
}

/**
 * @brif :this to enable pin to be input or output
 * @param pin is poiter to pin data port,pin,direction,logic
 * @param direction is to select pin to be input or output
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_enable_direction(pin_config_t *pin,PIN_DIRECTION_T direction)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==pin)||(pin->port>=MICROCONTROLLER_PORTS)||(pin->pin>=MICROCONTROLLER_PINS))
    {
        ret=E_NOK;
    }
    else
    {
        if(GPIO_OUTPUT==direction)
        {
            CLEAR_BIT(*(TRIS_registers[pin->port]),pin->pin);
            pin->direction=GPIO_OUTPUT;
        }
        else if(GPIO_INPUT==direction)
        {
            SET_BIT(*(TRIS_registers[pin->port]),pin->pin);
            pin->direction=GPIO_INPUT;
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;
}

/**
 * @brief:to read direction of the pin
 * @param pin is poiter to pin data port,pin,direction,logic
 * @param direction return be address to pointer from PIN_DIRECTION_T 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_read_direction(pin_config_t *pin,PIN_DIRECTION_T *direction)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==pin)||(pin->port>=MICROCONTROLLER_PORTS)||(pin->pin>=MICROCONTROLLER_PINS)||(NULL==direction))
    {
        ret=E_NOK;
    }
    else
    {
        *direction=GET_BIT(*(TRIS_registers[pin->port]),pin->pin);
    }
    return ret;
}

/**
 *@brief:this function write logic on the pin with 0v or 5v 
 * @param pin is poiter to pin data port,pin,direction,log
 * @param logic to make the pin state high with 5v or with 0volt 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_write_logic(pin_config_t *pin,PIN_LOGIC_T logic)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==pin)||(pin->port>=MICROCONTROLLER_PORTS)||(pin->pin>=MICROCONTROLLER_PINS))
    {
        ret=E_NOK;
    }
    else
    {
        if(GPIO_HIGH==logic)
        {
            SET_BIT(*LAT_registers[pin->port],pin->pin);
            pin->logic=GPIO_HIGH;
        }
        else if(GPIO_LOW==logic)
        {
            CLEAR_BIT(*LAT_registers[pin->port],pin->pin);
            pin->logic=GPIO_LOW;
        }
        else
        {
            ret=E_NOK;
        }
    }
    return ret;
}


/**
 *@brief:this function read logic on the pin with 0v or 5v 
 * @param pin is poiter to pin data port,pin,direction,log
 * @param logic pointer to return to it state of the pin
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_read_logic(pin_config_t *pin,PIN_LOGIC_T *logic)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==pin)||(pin->port>=MICROCONTROLLER_PORTS)||(pin->pin>=MICROCONTROLLER_PINS)||(NULL==logic))
    {
        ret=E_NOK;
    }
    else
    {
        *logic=GET_BIT(*(PORT_registers[pin->port]),pin->pin);
    }
    return ret;
}


/**
 *@brief:this function toggle logic on the pin  
 * @param pin is poiter to pin data port,pin,direction,log
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PIN_toggle_Logic(pin_config_t *pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==pin)
    {
        ret=E_NOK;
    }
    else
    {
        TOGGLE_BIT(*(LAT_registers[pin->port]),pin->pin);
    }
    return ret;
}
#endif



#if (PIN_FUNCTION_ENABLE==ACTIVE_FUNCTION)

/**
 * @breif this funnction iniitalize the port with direction and logic 
 * @param port pointer to port_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_initialize(port_config_t *port)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS))
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PORT_enable_direction(port,port->direction);
        ret=GPIO_PORT_write_logic(port,port->state);
        
    }
    return ret;
}

/**
 * @brief ;this enable direction of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param direction 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_enable_direction(port_config_t *port,uint8 direction)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS))
    {
        ret=E_NOK;
    }
    else
    {
        *(TRIS_registers[port->port])=direction;
        port->direction=direction;//to make it stored in object
    }
    return ret;
}


/**
 * @brief ;this read direction of port 8 or 16 pin with input ,output or some input and other output
 * @param port pointer to port_config_t
 * @param direction pointer of uint8 to return the direction
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_read_direction(port_config_t *port,uint8 *direction)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS)||(NULL==direction))
    {
        ret=E_NOK;
    }
    else
    {
        *direction=*(TRIS_registers[port->port]);
    }
    return ret;
}


/**
 * @brief ;this write logic of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param logic will be written 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_write_logic(port_config_t *port,uint8 logic)
{
     STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS))
    {
        ret=E_NOK;
    }
    else
    {
        *(LAT_registers[port->port])=logic;
        port->state=logic;
    }
    return ret;
}


/**
 * @brief ;this write logic of port 8 or 16 pin with input or output
 * @param port pointer to port_config_t
 * @param logic will be written 
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_read_logic(port_config_t *port,uint8 *logic)
{
        STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS)||(NULL==logic))
    {
        ret=E_NOK;
    }
    else
    {
       *logic=*(PORT_registers[port->port]); 
    }
    return ret;
}




/**
 * @brief ;this toggle logic of port 8 or 16 pin 
 * @param port pointer to port_config_t
 * @return :STD_RETURN_TYPE refrenced to AUTOSAR and check if function worked succesfully then retururn E_OK
 * and if not will be E_NOK
 */
STD_RETURN_TYPE GPIO_PORT_toggle_logic(port_config_t *port)
{
    STD_RETURN_TYPE ret=E_OK;
    if((NULL==port)||(port->port>=MICROCONTROLLER_PORTS))
    {
        ret=E_NOK;
    }
    else
    {
        *LAT_registers[port->port]^=PORT_TOGGLE_MASK;
    }
    return ret;
}
#endif

