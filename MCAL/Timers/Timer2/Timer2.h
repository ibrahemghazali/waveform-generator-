/* 
 * File:   Timer2.h
 * Author: ibrah
 *
 * Created on April 2, 2025, 11:16 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H
/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../../MCAL_STD_TYPES.h"
#include "../../GPIO/GPIO.h"
#include "../../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"

/***********SECTION: macro definition*******************/

/***********SECTION: function like macro*******************/
#define TIMER2_ENABLE()             (T2CONbits.TMR2ON=1)
#define TIMER2_DISABLE()            (T2CONbits.TMR2ON=0)

#define TIMER2_SELECT_POSTSCALER(POSTSCALER)        (T2CONbits.TOUTPS=POSTSCALER)    
#define TIMER2_SELECT_PRESCALER(PRESCALER)          (T2CONbits.T2CKPS=PRESCALER)


#define TIMER2_WRITE_PRELOADED_VALUE(PRELOADED_VALUE)       (TMR2=PRELOADED_VALUE)
#define TIMER2_READ_PRELOADED_VALUE()       (TMR2)
/***********SECTION: data type definition*******************/
typedef enum
{
    TIMER2_POSTSCALER_MULTIPLIED_BY_1=0,
    TIMER2_POSTSCALER_MULTIPLIED_BY_2,
    TIMER2_POSTSCALER_MULTIPLIED_BY_3,
    TIMER2_POSTSCALER_MULTIPLIED_BY_4,
    TIMER2_POSTSCALER_MULTIPLIED_BY_5,
    TIMER2_POSTSCALER_MULTIPLIED_BY_6,
    TIMER2_POSTSCALER_MULTIPLIED_BY_7,
    TIMER2_POSTSCALER_MULTIPLIED_BY_8,
    TIMER2_POSTSCALER_MULTIPLIED_BY_9,
    TIMER2_POSTSCALER_MULTIPLIED_BY_10,
    TIMER2_POSTSCALER_MULTIPLIED_BY_11,
    TIMER2_POSTSCALER_MULTIPLIED_BY_12,
    TIMER2_POSTSCALER_MULTIPLIED_BY_13,
    TIMER2_POSTSCALER_MULTIPLIED_BY_14,
    TIMER2_POSTSCALER_MULTIPLIED_BY_15,
    TIMER2_POSTSCALER_MULTIPLIED_BY_16       
}TIMER2_POSTSCALER_t;

typedef enum
{
    TIMER2_PRESCALER_DIV_BY_1=0,
    TIMER2_PRESCALER_DIV_BY_4,
    TIMER2_PRESCALER_DIV_BY_16
}TIMER2_PRESCALER_t;


typedef struct 
{
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    void(* timer2_isr)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_priority_t timer2_priority;
#endif
#endif
    TIMER2_POSTSCALER_t timer2_postscaler;
    TIMER2_PRESCALER_t timer2_prescaler;
    uint8 timer2_preloaded_value;
}timer2_t;


/***********SECTION: function decleration*******************/
STD_RETURN_TYPE TIMER_2_init(timer2_t *timer);
STD_RETURN_TYPE TIMER_2_deinit(timer2_t *timer);
STD_RETURN_TYPE TIMER_2_write_preload_value(timer2_t *timer,uint8 value);
STD_RETURN_TYPE TIMER_2_read(timer2_t *timer ,uint8 *value);


#endif	/* TIMER2_H */

