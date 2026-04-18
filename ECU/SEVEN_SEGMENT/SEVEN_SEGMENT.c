#include "SEVEN_SEGMENT.h"
#define SEVEN_SEGMENT_NUMBERS 10
#define MAX_SEVEN_SEGMENT_NUMBER 9

#if SEVEN_SEGMENT_DIRECT_CONNECTION==ACTIVE_MODE
static uint8 seven_segment_numbers[10]={0b00111111,0x6,0b01011011,0b11001111,0b01100110,0b01101101,0b01111101,0x7,0x7F,0b01100111};
STD_RETURN_TYPE ECU_seven_segment_initialize(seven_segment_t *seven_segment)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if(NULL==seven_segment)
    {
        ret=E_NOK;
    }
    else
    {
        
        if(COMMON_ANODE==seven_segment->seven_segment_type)
        {
            for(counter=0;counter<SEVEN_SEGMENT_DIRECT_MODE_PINS;counter++)
            {
                GPIO_PIN_enable_direction(&(seven_segment->seven_segment_pins[counter]),GPIO_OUTPUT);
            }          
        }
        else if(COMMON_CATHODE==seven_segment->seven_segment_type)
        {
            for(counter=0;counter<SEVEN_SEGMENT_DIRECT_MODE_PINS;counter++)
            {
                GPIO_PIN_enable_direction(&(seven_segment->seven_segment_pins[counter]),GPIO_OUTPUT);
            }
                
        }
        else 
        {
            ret=E_NOK;
        }
            
    }
    return ret;
}

STD_RETURN_TYPE ECU_seven_segment_write_number(seven_segment_t *seven_segment,uint8 number)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if(NULL==seven_segment)
    {
        ret=E_NOK;
    }
    else
    {
        
        if(COMMON_ANODE==seven_segment->seven_segment_type)
        {
            for(counter=0;counter<SEVEN_SEGMENT_DIRECT_MODE_PINS;counter++)
            {
                GPIO_PIN_write_logic(&(seven_segment->seven_segment_pins[counter]),
                        GET_BIT(~(seven_segment_numbers[number]),counter));
            }          
        }
        else if(COMMON_CATHODE==seven_segment->seven_segment_type)
        {
            for(counter=0;counter<SEVEN_SEGMENT_DIRECT_MODE_PINS;counter++)
            {
                GPIO_PIN_write_logic(&(seven_segment->seven_segment_pins[counter]),
                        GET_BIT(seven_segment_numbers[number],counter));
            }
                
        }
        else 
        {
            ret=E_NOK;
        }
            
    }
    return ret;
}


#elif SEVEN_SEGMENT_BCD_CONNECTION==ACTIVE_MODE 
STD_RETURN_TYPE ECU_seven_segment_BCD_initialize(seven_segment_t *seven_segment)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if(NULL==seven_segment)
    {
        ret=E_NOK;
    }
    else
    {
        for(counter=0;counter<SEVEN_SEGMENT_BCD_MODE_PINS;counter++)
        {
            ret=GPIO_PIN_enable_direction(&(seven_segment->seven_segment_pins[counter]),GPIO_OUTPUT);
        }
       
    }
    return ret;
}

STD_RETURN_TYPE ECU_seven_segment_BCD_write_number(seven_segment_t *seven_segment,uint8 number)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 counter=0;
    if(NULL==seven_segment||number>MAX_SEVEN_SEGMENT_NUMBER)
    {
        ret=E_NOK;
    }
    else
    {
        for(counter=0;counter<SEVEN_SEGMENT_BCD_MODE_PINS;counter++)
        {
            ret=GPIO_PIN_write_logic(&(seven_segment->seven_segment_pins[counter]),GET_BIT(number,counter));
        } 
    }
    return ret;  
}

#endif
    