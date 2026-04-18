/* 
 * File:   INTERRUPT_manager.h
 * Author: ibrah
 *
 * Created on February 20, 2025, 8:15 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../../ADC/ADC_config.h"
#include "../INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"

/***********SECTION: function like macro*******************/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_PRIORITY_FEATURE_ENABLE()                (RCONbits.IPEN=1)

#define INTERRUPT_GLOBAL_ENABLE()                           (INTCONbits.GIE=1)
#define INTERRUPT_GLOBAL_DISABLE()                          (INTCONbits.GIE=0)
#define INTERRUPT_GLOBAL_INTERRUPT_VALUE                    (INTCONbits.GIE)
#define INTERRUPT_HIGH_PRIORITY_ENABLE()                    (INTCONbits.GIEH=1)
#define INTERRUPT_HIGH_PRIORITY_DISABLE()                   (INTCONbits.GIEH=0)

#define INTERRUPT_LOW_PRIORITY_ENABLE()                     (INTCONbits.GIEL=1)
#define INTERRUPT_LOW_PRIORITY_DISABLE()                    (INTCONbits.GIEL=0)

#define INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()            (INTCONbits.PEIE=1)
#define INTERRUPT_PERIPHERAL_INTERRUPT_DISABLE()           (INTCONbits.PEIE=0)


#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
#define INTERRUPT_PRIORITY_FEATURE_DISABLE()        (RCONbits.IPEN=0)
#define INTERRUPT_GLOBAL_ENABLE()           (INTCONbits.GIE=1)
#define INTERRUPT_GLOBAL_DISABLE()          (INTCONbits.GIE=0)
#define PERIPHERAL_INTERRUPT_ENABLE()     (INTCONbits.PEIE=1)
#define  PERIPHERAL_INTERRUPT_DISABLE()    (INTCONbits.PEIE=0)


#else

#endif

/***********SECTION: data type definition*******************/
typedef enum
{
    INTERRUPT_LOW_PRIORITY=0,
    INTERRUPT_HIGH_PRIORITY=1
}INTERRUPT_priority_t;

/***********SECTION: function decleration*******************/
#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
void ISR_INT0(void); 
void ISR_INT1(void);
void ISR_INT2(void);
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE== INTERRUPT_FEATURE_ENABLE
void ISR_RB4(void); 
void ISR_RB5(void);
void ISR_RB6(void);
void ISR_RB7(void);
#endif

#if ADC_CONVERTING_OPTION_METHOD==ADC_CONVERTING_BY_INTERRUPT
void (ADC_ISR)(void);
#endif

#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER0_INTERRUPT_HANDLER(void);
#endif 

#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER1_INTERRUPT_HANDLER(void);
#endif 

#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER2_INTERRUPT_HANDLER(void);
#endif 

#if TIMER_3_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TIMER3_INTERRUPT_HANDLER(void);
#endif 

#if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void(CCP1_INTERRUPT_HANDLER)(void);
#endif 

#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void(CCP2_INTERRUPT_HANDLER)(void);
#endif 

#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void TX_INTERRUPT_HANDLER(void);
#endif 

#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void RX_INTERRUPT_HANDLER(void);
#endif 

#if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
void SPI_INTERRUPT_HANDLER(void);
#endif 

#endif	/* INTERRUPT_MANAGER_H */

