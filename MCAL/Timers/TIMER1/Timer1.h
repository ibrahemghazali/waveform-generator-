/* 
 * File:   Timer2.h
 * Author: ibrah
 *
 * Created on April 1, 2025, 1:04 AM
 */

#ifndef TIMER1_H
#define	TIMER1_H

/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../../MCAL_STD_TYPES.h"
#include "../../GPIO/GPIO.h"
#include "../../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"

/***********SECTION: macro definition*******************/
/*******Timer 1 state********/
#define TIMER1_ENABLED  1
#define TIMER1_DISABLED 0

/*********Timer 1 mode******/
#define TIMER1_COUNTER_MODE 1
#define TIMER1_TIMER_MODE   0 

/*********Timer 1 synchornization with input******/
#define TIMER1_COUNTER_SYNCHRONIZED_WITH_CLOCK  0
#define TIMER1_COUNTER_ASYNCHRONIZED_WITH_CLOCK  1

/***********Timer 1 oscillator pin***/
#define TIMER1_EXTERNAL_OSCILLATOR_ENABLED 1
#define TIMER1_EXTERNAL_OSCILLATOR_DISABLED 0

/*****Timer 1 read operation method****/
#define TIMER1_16BIT_READ_MODE  1
#define TIMER1_8BIT_READ_MODE  0

/***********SECTION: function like macro*******************/
/*******Timer 1 state********/
#define TIMER1_ENABLE()     (T1CONbits.TMR1ON=1)
#define TIMER1_DISABLE()     (T1CONbits.TMR1ON=0)

/*********Timer 1 mode******/
#define TIMER1_ENABLE_TIMER_MODE()    (T1CONbits.TMR1CS=0)
#define TIMER1_ENABLE_COUNTER_MODE()    (T1CONbits.TMR1CS=1)

/*********Timer 1 synchornization with input******/
#define TIMER1_SYNCHRONIZE_INPUT_WITH_CLOCK()   (T1CONbits.T1SYNC=0)
#define TIMER1_ASYNCHRONIZE_INPUT_WITH_CLOCK()   (T1CONbits.T1SYNC=1)

/***********Timer 1 oscillator pin***/
#define TIMER1_EXTERNAL_OSCILLATOR_ENABLE()      (T1CONbits.T1OSCEN=1)
#define TIMER1_EXTERNAL_OSCILLATOR_DISABLE()      (T1CONbits.T1OSCEN=0)

/*****Timer 1 read system clock state*/
#define TIMER1_READ_SYSTEM_CLOCK_STATE()        (T1CONbits.T1RUN)

/*****Timer 1 prescaler select */
#define TIMER1_SELECT_PRESCALER(PRESCALER)          (T1CONbits.T1CKPS=PRESCALER)

/***********Timer 1 read method****/
#define TIMER1_READ_16_BIT_ONE_TIME()              (T1CONbits.RD16=1)
#define TIMER1_READ_8_BIT_TWO_TIMES()              (T1CONbits.RD16=1)


#define TIMER1_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(VAL)            (TMR1H=VAL>>8)
#define TIMER1_WRITE_PRELOADED_VALUE_LOW_REGISTER(VAL)              (TMR1L=(uint8)VAL)


#define TIMER1_READ_LOW_REGISTER()                                   (TMR1L)
#define TIMER1_READ_HIGH_REGISTER()                                  (TMR1H)

/***********SECTION: data type definition*******************/
typedef enum
{
    TIMER_1_PRESCALER_DIV_BY_1=0,
    TIMER_1_PRESCALER_DIV_BY_2,
    TIMER_1_PRESCALER_DIV_BY_4,
    TIMER_1_PRESCALER_DIV_BY_8
    
}TIMER1_PRESCALER_t;
typedef struct 
{
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    void(* timer1_isr)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_priority_t timer1_priority;
#endif
#endif
    TIMER1_PRESCALER_t  Timer1_prescaler;
    uint16 timer1_preloaded_value;
    uint8 timer1_mode                       :1;
    uint8 timer1_read_method                :1;
    uint8 timer1_counter_synchoranization  :1;
    uint8 timer1_osc_cfg                    :1;
    uint8 timer1_reserved                   :4;   
}timer1_t;
/***********SECTION: function decleration*******************/
STD_RETURN_TYPE TIMER_1_init(timer1_t *timer);
STD_RETURN_TYPE TIMER_1_deinit(timer1_t *timer);
STD_RETURN_TYPE TIMER_1_write_preload_value(timer1_t *timer,uint16 value);
STD_RETURN_TYPE TIMER_1_read(timer1_t *timer ,uint16 *value);

#endif	/* TIMER1_H */

