/* 
 * File:   SEVEN_SEGMENT.h
 * Author: ibrah
 *
 * Created on January 28, 2025, 2:47 AM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/***********SECTION: library includes*******************/
#include "../../MCAL/GPIO/GPIO.h"
#include "SEVEN_SEGMENT_config.h"

/***********SECTION: macro definition*******************/
#if (SEVEN_SEGMENT_DIRECT_CONNECTION==ACTIVE_MODE)&&(SEVEN_SEGMENT_BCD_CONNECTION==ACTIVE_MODE)
#error "the driver support only one mode"
#elif SEVEN_SEGMENT_DIRECT_CONNECTION==ACTIVE_MODE
#define SEVEN_SEGMENT_DIRECT_MODE_PINS 8
#define SEVEN_SEGMENT_MODE_PINS SEVEN_SEGMENT_DIRECT_MODE_PINS
#elif SEVEN_SEGMENT_BCD_CONNECTION==ACTIVE_MODE 
#define SEVEN_SEGMENT_BCD_MODE_PINS 4
#define SEVEN_SEGMENT_MODE_PINS SEVEN_SEGMENT_BCD_MODE_PINS
#endif
/***********SECTION: function like macro*******************/

/***********SECTION: data type definition*******************/

typedef enum
{
    COMMON_ANODE=0,
   COMMON_CATHODE=1
}SEVEN_SEGMENT_TYPE_T;
typedef struct 
{
    pin_config_t seven_segment_pins[SEVEN_SEGMENT_MODE_PINS];
    #if SEVEN_SEGMENT_DIRECT_CONNECTION==ACTIVE_MODE
    uint8 seven_segment_type;
    #endif
}seven_segment_t;
/***********SECTION: function decleration*******************/
#if SEVEN_SEGMENT_DIRECT_CONNECTION==ACTIVE_MODE
STD_RETURN_TYPE ECU_seven_segment_initialize(seven_segment_t *seven_segment);

STD_RETURN_TYPE ECU_seven_segment_write_number(seven_segment_t *seven_segment,uint8 number);
#elif SEVEN_SEGMENT_BCD_CONNECTION==ACTIVE_MODE 
STD_RETURN_TYPE ECU_seven_segment_BCD_initialize(seven_segment_t *seven_segment);

STD_RETURN_TYPE ECU_seven_segment_BCD_write_number(seven_segment_t *seven_segment,uint8 number);
#endif


#endif	/* SEVEN_SEGMENT_H */

