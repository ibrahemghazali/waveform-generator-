/* 
 * File:   CCP.h
 * Author: ibrah
 *
 * Created on June 7, 2025, 1:47 PM
 */

#ifndef CCP_H
#define	CCP_H
/***********SECTION: library includes*******************/
#include "CCP_private.h"
#include "CCP_confg.h"
#include "../MCAL_STD_TYPES.h"
#include "../GPIO/GPIO.h"
#include "../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"
#include "../Timers/TIMER1/Timer1.h"
#include "../Timers/Timer2/Timer2.h"
#include "../Timers/Timer3/Timer3.h"

/***********SECTION: macro definition*******************/
#define CCP_DEFULT_LOGIC_START     GPIO_LOW
/******CCP varient mode********/
#define CCP_MODULE_DISABLED                     0
#define CCP_CAPTURE_MODE_EVERY_FALLING_EDGE     4
#define CCP_CAPTURE_MODE_EVERY_RISING_EDGE      5
#define CCP_CAPTURE_MODE_EVERY_4TH_RISING_EDGE  6
#define CCP_CAPTURE_MODE_EVERY_16TH_RISING_EDGE 7

#define CCP_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH 2
#define CCP_COMPARE_MODE_FORCE_PIN_HIGH         8
#define CCP_COMPARE_MODE_FORCE_PIN_LOW          9
#define CCP_COMPARE_MODE_GENERATE_INTERRUPT     10
#define CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT  11
#define CCP_PWM_MODE                            12

#define CCP_CAPTURE_MIN_MODE_VALUE    CCP_CAPTURE_MODE_EVERY_FALLING_EDGE  
#define CCP_CAPTURE_MAX_MODE_VALUE    CCP_CAPTURE_MODE_EVERY_16TH_RISING_EDGE

#define CCP_COMPARE_MAX_MODE_VALUE  CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT
#define CCP_COMPARE_MIN_MODE_VALUE  CCP_COMPARE_MODE_FORCE_PIN_HIGH 

/********CCP_PIN******/
#define CCP1_PIN_SELECTED                                0
#define CCP2_PIN_SELECTED                                1


/*********timer mode selecting*****/
#define CCP1_TIMER1_CCP2_TIMER1                  0
#define CCP1_TIMER1_CCP2_TIMER3                  1
#define CCP1_TIMER3_CCP2_TIMER3                  2

/********timer1&3 preloaded value*****/
#define CAPTURE_COMPARE_TIMER_PRESCALER_1TO1    0
#define CAPTURE_COMPARE_TIMER_PRESCALER_1TO2    1
#define CAPTURE_COMPARE_TIMER_PRESCALER_1TO4    2
#define CAPTURE_COMPARE_TIMER_PRESCALER_1TO8    3


#define CCP1_PORT       GPIO_PORTC 
#define CCP1_PIN        GPIO_PIN2

#define CCP2_PORT       GPIO_PORTC 
#define CCP2_PIN        GPIO_PIN1


#define CCP1_NOT_INIT_YET 0
#define CCP1_IS_INIT      1

#define CCP2_NOT_INIT_YET 0
#define CCP2_IS_INIT      1


/***********SECTION: function like macro*******************/
/*********selecting varient mode******/
#define CCP1_SELECT_MODE(VARIENT_MODE)          (CCP1CONbits.CCP1M=VARIENT_MODE)
#define CCP2_SELECT_MODE(VARIENT_MODE)          (CCP2CONbits.CCP2M=VARIENT_MODE)

/*******selecting timer mode******/
#define CCP_CAPTURE_COMPARE_SELECT_TIMER_MODE(TIMER_MODE)   do \
                                                            { \
                                                                T3CONbits.T3CCP1=GET_BIT(TIMER_MODE,0);\
                                                                T3CONbits.T3CCP2=GET_BIT(TIMER_MODE,1);\
                                                            }while(0);


#define CCP1_READ_CAPTURE_VALUE()       ((uint16)(CCPR1L+((uint16)CCPR1H<<8)))
#define CCP2_READ_CAPTURE_VALUE()       ((uint16)(CCPR2L+((uint16)CCPR2H<<8)))


#define CCP1_WRITE_COMPARE_VALUE(COMPARE_VALUE)          do \
                                                        { \
                                                        CCPR1L=(uint8)COMPARE_VALUE;\
                                                        CCPR1H=(uint8)((COMPARE_VALUE)>>8);\
                                                        }while(0);

#define CCP2_WRITE_COMPARE_VALUE(COMPARE_VALUE)          do \
                                                        { \
                                                        CCPR2L=(uint8)COMPARE_VALUE;\
                                                        CCPR2H=(uint8)((COMPARE_VALUE)>>8);\
                                                        }while(0);


#define CCP_CHECK_COMPARE_MODE(CHECKING)        (((CCP_COMPARE_MAX_MODE_VALUE>=CHECKING)&&(CCP_COMPARE_MIN_MODE_VALUE<=CHECKING))||(CCP_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH==CHECKING))

#define CCP_SET_TOP_VALUE(TOP_VAL)            (PR2=TOP_VAL)

#define CCP1_PWM_SET_DUTY_CYCLE(DUTY)              do \
                                                   { \
                                                    CCP1CONbits.DC1B0=GET_BIT(DUTY,0); \
                                                    CCP1CONbits.DC1B1=GET_BIT(DUTY,1); \
                                                    CCPR1L=(uint8)((DUTY)>>2); \
                                                    }while(0);

#define CCP2_PWM_SET_DUTY_CYCLE(DUTY)              do \
                                                   { \
                                                    CCP2CONbits.DC2B0=GET_BIT(DUTY,0); \
                                                    CCP2CONbits.DC2B1=GET_BIT(DUTY,1); \
                                                    CCPR2L=(uint8)((DUTY)>>2); \
                                                    }while(0);




/***********SECTION: data type definition*******************/
typedef struct 
{
    uint32 reserved_1;
    void (*ISR)(void);
    uint8 reserved_2;
    uint8 capture_varient_mode :4;
    uint8 timer_mode_select  :2;
    uint8 capture_pin          :1;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    uint8 capture_priority       :1;
#elif
uint8 reserved               :1;
#endif

}capture_t;

typedef struct 
{
    uint16 reserved_1;
    uint16 compare_value;
    void (*ISR)(void);
    uint8 reserved_2;
    uint8 Compare_varient_mode :4;
    uint8 timer_mode_select  :2;
    uint8 compare_pin         :1;
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    uint8 Compare_priority       :1;
#elif
uint8 reserved               :1;
#endif

}compare_t;

typedef struct 
{
    uint32 PWM_Freq;
    uint16 duty_cycle;
    uint8 TIMER_prescaler :4;
    uint8 TIMER_postscaler :2;
    uint8 CCP_PIN          :1;
    uint8 reserved         :1;
}PWM_t;

typedef union 
{
    capture_t ccp_capture_mode_config;
    compare_t ccp_compare_mode_config;
    PWM_t ccp_pwm_mode_config;
}CCP_t;
/***********SECTION: function decleration*******************/
STD_RETURN_TYPE CCP_capture_init(const CCP_t *ccp_pin);
STD_RETURN_TYPE CCP_change_capture_rising_to_falling(const CCP_t *ccp_pin);
STD_RETURN_TYPE CCP_change_capture_falling_to_rising(const CCP_t *ccp_pin);
STD_RETURN_TYPE CCP_read_capture_value(const CCP_t *ccp_pin,uint16 *capture_value);

STD_RETURN_TYPE CCP_compare_init(const CCP_t *ccp_pin);
STD_RETURN_TYPE CCP_set_compare_value(const CCP_t *ccp_pin,uint16 compare_value);
STD_RETURN_TYPE CCP_change_compare_varient_mode(const CCP_t *ccp_pin,uint8 new_mode);

STD_RETURN_TYPE CCP_PWM_init(const CCP_t *ccp_pin);
STD_RETURN_TYPE CCP_PWM_set_duty_cycle(const CCP_t *ccp_pin,uint16 duty_cycle);



#endif	/* CCP_H */

