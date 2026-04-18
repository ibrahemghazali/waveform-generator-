/* 
 * File:   Timer3.h
 * Author: ibrah
 *
 * Created on April 20, 2025, 2:47 PM
 */

#ifndef TIMER3_H
#define	TIMER3_H
/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../../MCAL_STD_TYPES.h"
#include "../../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"
/***********SECTION: macro definition*******************/
#define TIMER3_TIMER_MODE 0
#define TIMER3_COUNTER_MODE 1

#define TIMER3_SYNCHRONIZATION_MODE 0
#define TIMER3_NON_SYNCHRONIZATION_MODE 1


#define TIMER3_PRESCALER_1TO1 0 
#define TIMER3_PRESCALER_1TO2 1
#define TIMER3_PRESCALER_1TO4 2
#define TIMER3_PRESCALER_1TO8 2
/***********SECTION: function like macro*******************/
#define TIMER3_ENABLE()                                 (T3CONbits.TMR3ON=1)
#define TIMER3_DISABLE()                                (T3CONbits.TMR3ON=0)


#define TIMER3_SELECT_TIMER_MODE()                      (T3CONbits.TMR3CS=0)
#define TIMER3_SELECT_COUNTER_MODE()                    (T3CONbits.TMR3CS=1)


#define TIMER3_SYNCHRONIZE_CLOCK_INPUT()                (T3CONbits.T3SYNC=0)
#define TIMER3_NOT_SYNCHRONIZE_CLOCK_INPUT()            (T3CONbits.T3SYNC=1)

#define TIMER3_SELECT_PRESCALER(prescaler_val)          (T3CONbits.T3CKPS=prescaler_val)
#define TIMER3_ENABLE_READ_OPERATIONS()                 (T3CONbits.RD16=0)

#define TIMER3_WRITE_PRELOADED_VALLUE_HIGH_REGISTER(VAL)            (TMR3H=VAL>>8)
#define TIMER3_WRITE_PRELOADED_VALUE_LOW_REGISTER(VAL)              (TMR3L=(uint8)VAL)


#define TIMER3_READ_LOW_REGISTER()                                   (TMR3L)
#define TIMER3_READ_HIGH_REGISTER()                                  (TMR3H)


/***********SECTION: data type definition*******************/

typedef struct
{
    void (*timer3_ISR)(void);
    uint8 Timer3_state :1;
    uint8 TIMER3_mode :1;
    uint8 TIMER3_synchoronization :1;
    uint8 TIMER3_prescaler :2;
    #if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
    uint8 TIMER3_priority :1;
    uint8 Timer3_reserved :2;
#elif 
    uint8 Timer3_reserved :3;
#endif 
    
    uint16 TIMER3_preloaded_val;
}TIMER3_t;

/***********SECTION: function decleration*******************/
STD_RETURN_TYPE TIMER3_init(TIMER3_t *timer);
STD_RETURN_TYPE TIMER3_deinit(TIMER3_t *timer);
STD_RETURN_TYPE TIMER3_write_preloaded_value(TIMER3_t *timer,uint16 val);
STD_RETURN_TYPE TIMER3_read(TIMER3_t *timer,uint16 *result);

#endif	/* TIMER3_H */

