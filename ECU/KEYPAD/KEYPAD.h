/* 
 * File:   KEYPAD.h
 * Author: ibrah
 *
 * Created on February 5, 2025, 6:52 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/***********SECTION: library includes*******************/
#include "KEYPAD_config.h"
#include "../../MCAL/GPIO/GPIO.h"
/***********SECTION: macro definition*******************/

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
typedef struct 
{
    pin_config_t row_pins[KEYPAD_ROWS];
    pin_config_t col_pins[KEYPAD_COLS];
}KEYPAD_t;
/***********SECTION: function decleration*******************/
STD_RETURN_TYPE ECU_KEYPAD_init(KEYPAD_t *keypad);
#if KEYPAD_ARRAYS_MODE==KEYPAD_STATIC_ARRAY
STD_RETURN_TYPE ECU_KEYPAD_get_pressed_key(KEYPAD_t *keypad ,uint8 *value);
#endif

#if KEYPAD_ARRAYS_MODE==KEYPAD_PASSED_ARRAY
STD_RETURN_TYPE ECU_KEYPAD_get_pressed_key(KEYPAD_t *keypad ,uint8 *value,uint8 *keypad_key);
#endif
        
#endif	/* KEYPAD_H */

