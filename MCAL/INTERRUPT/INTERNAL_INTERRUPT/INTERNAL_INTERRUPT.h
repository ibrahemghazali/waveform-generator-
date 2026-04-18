/* 
 * File:   INTERNAL_INTERRUPT.h
 * Author: ibrah
 *
 * Created on March 19, 2025, 8:42 AM
 */

#ifndef INTERNAL_INTERRUPT_H
#define	INTERNAL_INTERRUPT_H

/***********SECTION: library includes*******************/
#include "../../ADC/ADC_config.h"
#include "../INTERRUPT_manager/INTERRUPT_manager_config.h"
#include "INTERNAL_INTERRUPT_config.h"
#include <pic18f4620.h>
/***********SECTION: macro definition*******************/


/***********SECTION: function like macro*******************/

/**********************ADC interrupt flag**********/
#if ADC_CONVERTING_OPTION_METHOD==ADC_CONVERTING_BY_INTERRUPT
#define ADC_INTERRUPT_CLEAR_FLAG()      (PIR1bits.ADIF=0)
#define ADC_INTERRUPT_READ_FLAG()       (PIR1bits.ADIF)

/**********************ADC interrupt enable**********/
#define ADC_INTERRUPT_ENABLE()              (PIE1bits.ADIE=1)
#define ADC_INTERRUPT_DISABLE()             (PIE1bits.ADIE=0)
#define ADC_READ_ENABLE()                   (PIE1bits.ADIE)

/***********************ADC interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define ADC_HIGH_PRIORITY()         (IPR1bits.ADIP=1)
#define ADC_LOW_PRIORITY()          (IPR1bits.ADIP=0)
#define ADC_READ_PRIORITY()         (IPR1bits.ADIP)
#endif 

#endif
/***********SECTION: data type definition*******************/


#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define TIMER0_INTERRUPT_CLEAR_FLAG()      (INTCONbits.TMR0IF=0)
#define TIMER0_INTERRUPT_READ_FLAG()       (INTCONbits.TMR0IF)

/**********************ADC interrupt enable**********/
#define TIMER0_INTERRUPT_ENABLE()              (INTCONbits.TMR0IE=1)
#define TIMER0_INTERRUPT_DISABLE()             (INTCONbits.TMR0IE=0)
#define TIMER0_READ_ENABLE()                   (INTCONbits.TMR0IE)

/***********************ADC interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define TIMER0_HIGH_PRIORITY()         (INTCON2bits.TMR0IP=1)
#define TIMER0_LOW_PRIORITY()          (INTCON2bits.TMR0IP=0)
#define TIMER0_READ_PRIORITY()         (INTCON2bits.TMR0IP)
#endif 

#endif

/*****************timer 1*************/
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_CLEAR_FLAG()      (PIR1bits.TMR1IF=0)
#define TIMER1_INTERRUPT_READ_FLAG()       (PIR1bits.TMR1IF)

/**********************ADC interrupt enable**********/
#define TIMER1_INTERRUPT_ENABLE()              (PIE1bits.TMR1IE=1)
#define TIMER1_INTERRUPT_DISABLE()             (PIE1bits.TMR1IE=0)
#define TIMER1_READ_ENABLE()                   (PIE1bits.TMR1IE)

/***********************ADC interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define TIMER1_HIGH_PRIORITY()         (IPR1bits.TMR1IP=1)
#define TIMER1_LOW_PRIORITY()          (IPR1bits.TMR1IP=0)
#define TIMER1_READ_PRIORITY()         (IPR1bits.TMR1IP)
#endif 

#endif

/*****************timer 2*************/
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_CLEAR_FLAG()      (PIR1bits.TMR2IF=0)
#define TIMER2_INTERRUPT_READ_FLAG()       (PIR1bits.TMR2IF)

/**********************timer2 interrupt enable**********/
#define TIMER2_INTERRUPT_ENABLE()              (PIE1bits.TMR2IE=1)
#define TIMER2_INTERRUPT_DISABLE()             (PIE1bits.TMR2IE=0)
#define TIMER2_READ_ENABLE()                   (PIE1bits.TMR2IE)

/***********************timer2 interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define TIMER2_HIGH_PRIORITY()         (IPR1bits.TMR2IP=1)
#define TIMER2_LOW_PRIORITY()          (IPR1bits.TMR2IP=0)
#define TIMER2_READ_PRIORITY()         (IPR1bits.TMR2IP)
#endif 

#endif


/*****************timer 3*************/
#if TIMER_3_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_CLEAR_FLAG()      (PIR2bits.TMR3IF=0)
#define TIMER3_INTERRUPT_READ_FLAG()       (PIR2bits.TMR3IF)

/**********************timer2 interrupt enable**********/
#define TIMER3_INTERRUPT_ENABLE()              (PIE2bits.TMR3IE=1)
#define TIMER3_INTERRUPT_DISABLE()             (PIE2bits.TMR3IE=0)
#define TIMER3_READ_ENABLE()                   (PIE2bits.TMR3IE)

/***********************timer2 interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define TIMER3_HIGH_PRIORITY()         (IPR2bits.TMR3IP=1)
#define TIMER3_LOW_PRIORITY()          (IPR2bits.TMR3IP=0)
#define TIMER3_READ_PRIORITY()         (IPR2bits.TMR3IP)
#endif 

#endif


/*****************CCP1*************/
#if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define CCP1_INTERRUPT_CLEAR_FLAG()      (PIR1bits.CCP1IF=0)
#define CCP1_INTERRUPT_READ_FLAG()       (PIR1bits.CCP1IF)

/**********************CCP1 interrupt enable**********/
#define CCP1_INTERRUPT_ENABLE()              (PIE1bits.CCP1IE=1)
#define CCP1_INTERRUPT_DISABLE()             (PIE1bits.CCP1IE=0)
#define CCP1_READ_ENABLE()                   (PIE1bits.CCP1IE)

/***********************timer2 interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define CCP1_HIGH_PRIORITY()         (IPR1bits.CCP1IP=1)
#define CCP1_LOW_PRIORITY()          (IPR1bits.CCP1IP=0)
#define CCP1_READ_PRIORITY()         (IPR1bits.CCP1IP)
#endif 

#endif


/*****************CCP2*************/
#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_CLEAR_FLAG()      (PIR2bits.CCP2IF=0)
#define CCP2_INTERRUPT_READ_FLAG()       (PIR2bits.CCP2IF)

/**********************CCP2 interrupt enable**********/
#define CCP2_INTERRUPT_ENABLE()              (PIE2bits.CCP2IE=1)
#define CCP2_INTERRUPT_DISABLE()             (PIE2bits.CCP2IE=0)
#define CCP2_READ_ENABLE()                   (PIE2bits.CCP2IE)

/***********************CCP2 interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define CCP2_HIGH_PRIORITY()         (IPR2bits.CCP2IP=1)
#define CCP2_LOW_PRIORITY()          (IPR2bits.CCP2IP=0)
#define CCP2_READ_PRIORITY()         (IPR2bits.CCP2IP)
#endif 

#endif


/*****************EUSART TX*************/
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define TX_INTERRUPT_CLEAR_FLAG()      (PIR1bits.TX1IF=0)
#define TX_INTERRUPT_READ_FLAG()       (PIR1bits.TX1IF)

/**********************EUSART TX interrupt enable**********/
#define TX_INTERRUPT_ENABLE()              (PIE1bits.TX1IE=1)
#define TX_INTERRUPT_DISABLE()             (PIE1bits.TX1IE=0)
#define TX_READ_ENABLE()                   (PIE1bits.TX1IE)

/***********************EUSART TX interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define TX_HIGH_PRIORITY()         (IPR1bits.TXIP=1)
#define TX_LOW_PRIORITY()          (IPR1bits.TX1IP=0)
#define TX_READ_PRIORITY()         (IPR1bits.TX1IP)
#endif 

#endif
 
/*****************EUSART RX*************/
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define RX_INTERRUPT_CLEAR_FLAG()      (PIR1bits.RC1IF=0)
#define RX_INTERRUPT_READ_FLAG()       (PIR1bits.RC1IF)

/**********************EUSART TX interrupt enable**********/
#define RX_INTERRUPT_ENABLE()              (PIE1bits.RC1IE=1)
#define RX_INTERRUPT_DISABLE()             (PIE1bits.RC1IE=0)
#define RX_READ_ENABLE()                   (PIE1bits.RC1IE)

/***********************EUSART TX interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define RX_HIGH_PRIORITY()         (IPR1bits.RC1IP=1)
#define RX_LOW_PRIORITY()          (IPR1bits.RC1IP=0)
#define RX_READ_PRIORITY()         (IPR1bits.RC1IP)
#endif 

#endif



/*****************SPI*************/
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#define SPI_INTERRUPT_CLEAR_FLAG()      (PIR1bits.SSPIF=0)
#define SPI_INTERRUPT_READ_FLAG()       (PIR1bits.SSPIF)

/**********************SPI interrupt enable**********/
#define SPI_INTERRUPT_ENABLE()              (PIE1bits.SSPIE=1)
#define SPI_INTERRUPT_DISABLE()             (PIE1bits.SSPIE=0)
#define SPI_READ_ENABLE()                   (PIE1bits.SSPIE)

/***********************SPI interrupt priority****/
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE

#define SPI_HIGH_PRIORITY()         (IPR1bits.SSPIP=1)
#define SPI_LOW_PRIORITY()          (IPR1bits.SSPIP=0)
#define SPI_READ_PRIORITY()         (IPR1bits.SSPIP)
#endif 

#endif
/***********SECTION: function decleration*******************/


#endif	/* INTERNAL_INTERRUPT_H */

