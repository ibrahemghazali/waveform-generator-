/* 
 * File:   Timer0.h
 * Author: ibrah
 *
 * Created on March 30, 2025, 2:21 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H
/***********SECTION: library includes*******************/
#include "../../GPIO/GPIO.h"
#include "../../MCAL_STD_TYPES.h"
#include "../../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"
#include <pic18f4620.h>

/***********SECTION: macro definition*******************/
#define TIMER0_PRESCALER_ENABLED       1
#define TIMER0_PRESCALER_DISABLED       0

#define TIMER0_8_BIT_REGISTER_SIZE 1
#define TIMER0_16_BIT_REGISTER_SIZE 0

#define TIMER0_TIMER_MODE           0
#define TIMER0_COUNTER_MODE         1

#define TIMER0_RISING_EDGE_TRANSITION       0
#define TIMER0_FALLING_EDGE_TRANSITION       1

/***********SECTION: function like macro*******************/
#define TIMER0_ENABLE()                                         (T0CONbits.TMR0ON=1)
#define TIMER0_DISABLE()                                         (T0CONbits.TMR0ON=0) 

#define TIMER0_SELECT_8_BIT_REGISTER_SIZE()                     (T0CONbits.T08BIT=1) 
#define TIMER0_SELECT_16_BIT_REGISTER_SIZE()                    (T0CONbits.T08BIT=0)

#define TIMER0_SELECT_TIMER_MODE()                              (T0CONbits.T0CS=0)
#define TIMER0_SELECT_COUNTER_MODE()                            (T0CONbits.T0CS=1)

#define TIMER0_SELECT_RISING_EDGE_TRANSITION()                    (T0CONbits.T0SE=0)
#define TIMER0_SELECT_FALLING_EDGE_TRANSITION()                   (T0CONbits.T0SE=1)

#define TIMER0_ENABLE_PRESCALER()                                (T0CONbits.PSA=0)
#define TIMER0_DISABLE_PRESCALER()                               (T0CONbits.PSA=1)

#define TIMER0_SET_PRESCALER_VAL(VAL)                              (T0CONbits.T0PS=VAL)

#define TIMER0_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(VAL)            (TMR0H=VAL>>8)
#define TIMER0_WRITE_PRELOADED_VALUE_LOW_REGISTER(VAL)              (TMR0L=(uint8)VAL)

#define TIMER0_READ_LOW_REGISTER()                                   (TMR0L)
#define TIMER0_READ_HIGH_REGISTER()                                  (TMR0H)

/***********SECTION: data type definition*******************/
typedef enum
{
    TIMER_0_PRESCALER_DIV_BY_2=0,
    TIMER_0_PRESCALER_DIV_BY_4,
    TIMER_0_PRESCALER_DIV_BY_8,
    TIMER_0_PRESCALER_DIV_BY_16,
    TIMER_0_PRESCALER_DIV_BY_32,
    TIMER_0_PRESCALER_DIV_BY_64,
    TIMER_0_PRESCALER_DIV_BY_128,
    TIMER_0_PRESCALER_DIV_BY_256,
    
}TIMER0_PRESCALER_t;

typedef struct
{
#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    void(* timer0_isr)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_priority_t timer0_priority;
#endif
#endif
    TIMER0_PRESCALER_t  Timer0_prescaler;
    uint16 timer0_preloaded_value;
    uint8 PRESCALER_STATE         :1;
    uint8 timer0_register_size    :1;
    uint8 timer0_mode             :1;
    uint8 timer_0_edge_transition :1;
    uint8 timer0_reserved         :4;
}timer0_t;

/***********SECTION: function decleration*******************/
STD_RETURN_TYPE TIMER_0_init(timer0_t *timer);
STD_RETURN_TYPE TIMER_0_deinit(timer0_t *timer);
STD_RETURN_TYPE TIMER_0_write_preload_value(timer0_t *timer,uint16 value);
STD_RETURN_TYPE TIMER_0_read(timer0_t *timer ,uint16 *value);

#endif	/* TIMER0_H */

