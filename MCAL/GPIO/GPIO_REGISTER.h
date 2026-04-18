/* 
 * File:   GPIO_REGISTER.h
 * Author: ibrah
 *
 * Created on January 25, 2025, 7:51 PM
 */

#ifndef GPIO_REGISTER_H
#define	GPIO_REGISTER_H
/***********SECTION: library includes*******************/
#include "../MCAL_STD_TYPES.h"

/***********SECTION: macro definition*******************/

#define PORTA_ADDRESS HWREG(0xF80)
#define PORTB_ADDRESS HWREG(0xF81)
#define PORTC_ADDRESS HWREG(0xF82)
#define PORTD_ADDRESS HWREG(0xF83)
#define PORTE_ADDRESS HWREG(0xF84)

#define TRISA_ADDRESS HWREG(0xF92)
#define TRISB_ADDRESS HWREG(0xF93)
#define TRISC_ADDRESS HWREG(0xF94)
#define TRISD_ADDRESS HWREG(0xF95)
#define TRISE_ADDRESS HWREG(0xF96)

#define LATA_ADDRESS HWREG(0xF89)
#define LATB_ADDRESS HWREG(0xF8A)
#define LATC_ADDRESS HWREG(0xF8B)
#define LATD_ADDRESS HWREG(0xF8C)
#define LATE_ADDRESS HWREG(0xF8D)




/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/


/***********SECTION: function decleration*******************/

#endif	/* GPIO_REGISTER_H */

