/* 
 * File:   app.h
 * Author: ibrah
 *
 * Created on January 25, 2025, 7:42 PM
 */

#ifndef APP_H
#define	APP_H
/***********SECTION: library includes*******************/
#include "ECU/ECU_init.h"
#include "MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"
#include "MCAL/EEPROM/EEPROM.h"
/***********SECTION: macro definition*******************/
#define _XTAL_FREQ 8000000UL

/***********SECTION: function like macro*******************/


/***********SECTION: function decleration*******************/
void app_init();
/***********SECTION: data type definition*******************/

#endif	/* APP_H */

