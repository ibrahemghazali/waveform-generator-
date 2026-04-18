/* 
 * File:   EXTERNAL_INTERRUPT.h
 * Author: ibrah
 *
 * Created on February 20, 2025, 8:14 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H
/***********SECTION: library includes*******************/
#include "../INTERRUPT_manager/INTERRUPT_manager_config.h"
#include "../INTERRUPT_manager/INTERRUPT_manager.h"
#include "../../../MCAL/GPIO/GPIO.h"
#include "../../MCAL_STD_TYPES.h"
#include <pic18f4620.h>

/***********SECTION: macro definition*******************/
#if EXTERNAL_INTERRUPT_INTX_FEATURE ==INTERRUPT_FEATURE_ENABLE
/******************SECTION :INT0 pin********************/
#define INTERRUPT_INT0_PORT GPIO_PORTB
#define INTERRUPT_INT0_PIN GPIO_PIN0

/******************SECTION :INT1 pin********************/
#define INTERRUPT_INT1_PORT GPIO_PORTB
#define INTERRUPT_INT1_PIN GPIO_PIN1

/******************SECTION :INT2 pin********************/
#define INTERRUPT_INT2_PORT GPIO_PORTB
#define INTERRUPT_INT2_PIN GPIO_PIN2
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE== INTERRUPT_FEATURE_ENABLE
/**********************SECTION:RBx_pins*****/
/********************SECTION:RB4_pin*/
#define RB4_PORT        GPIO_PORTB
#define RB4_PIN         GPIO_PIN4
#define RB4_LOGIC       GPIO_LOW
#define RB4_DIRECTION   GPIO_INPUT

/********************SECTION:RB5_pin*/
#define RB5_PORT        GPIO_PORTB
#define RB5_PIN         GPIO_PIN5
#define RB5_LOGIC       GPIO_LOW
#define RB5_DIRECTION   GPIO_INPUT

/********************SECTION:RB6_pin*/
#define RB6_PORT        GPIO_PORTB
#define RB6_PIN         GPIO_PIN6
#define RB6_LOGIC       GPIO_LOW
#define RB6_DIRECTION   GPIO_INPUT

/********************SECTION:RB7_pin*/
#define RB7_PORT        GPIO_PORTB
#define RB7_PIN         GPIO_PIN7
#define RB7_LOGIC       GPIO_LOW
#define RB7_DIRECTION   GPIO_INPUT

#endif
/***********SECTION: function like macro*******************/
/*************************SECTION:INTx_pins********/
#if EXTERNAL_INTERRUPT_INTX_FEATURE ==INTERRUPT_FEATURE_ENABLE
/******************SECTION :INT0 pin********************/
/********************INT0 pin flag**********/
#define EXTERNAL_INTERRUPT_INT0_READ_FLAG()    (INTCONbits.INT0F)   
#define EXTERNAL_INTERRUPT_INT0_CLEAR_FLAG()   (INTCONbits.INT0F=0) 

/********************INT0 pin enable****************/
#define EXTERNAL_INTERRUPT_INT0_INTERRUPT_ENABLE()  (INTCONbits.INT0E=1)
#define EXTERNAL_INTERRUPT_INT0_INTERRUPT_DISABLE() (INTCONbits.INT0E=0)
#define EXTERNAL_INTERRUPT_INT0_INTERRUPT_CHECK()   (INTCONbits.INT0E)

/*********************INT0 interrupt edge***********/
#define EXTERNAL_INTERRUPT_INT0_FALLING_EDGE_ENABLE()   (INTCON2bits.INTEDG0=0)
#define EXTERNAL_INTERRUPT_INT0_RISING_EDGE_ENABLE()    (INTCON2bits.INTEDG0=1)

/*******************INT0 interrupt priority******/
//INT0 pin is high interrupt all time and can't be changed 


/******************SECTION :INT1 pin********************/
/********************INT1 pin flag**********/
#define EXTERNAL_INTERRUPT_INT1_READ_FLAG()    (INTCON3bits.INT1F)   
#define EXTERNAL_INTERRUPT_INT1_CLEAR_FLAG()   (INTCON3bits.INT1F=0) 

/********************INT1 pin enable****************/
#define EXTERNAL_INTERRUPT_INT1_INTERRUPT_ENABLE()  (INTCON3bits.INT1E=1)
#define EXTERNAL_INTERRUPT_INT1_INTERRUPT_DISABLE() (INTCON3bits.INT1E=0)
#define EXTERNAL_INTERRUPT_INT1_INTERRUPT_CHECK()   (INTCON3bits.INT1E)

/*********************INT0 interrupt edge***********/
#define EXTERNAL_INTERRUPT_INT1_FALLING_EDGE_ENABLE()   (INTCON2bits.INTEDG1=0)
#define EXTERNAL_INTERRUPT_INT1_RISING_EDGE_ENABLE()    (INTCON2bits.INTEDG1=1)

/*******************INT0 interrupt priority******/

#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_INT1_HIGH_PRIORITY_ENABLE()    (INTCON3bits.INT1P=1)
#define EXTERNAL_INTERRUPT_INT1_LOW_PRIORITY_ENABLE()   (INTCON3bits.INT1P=0)
#define EXTERNAL_INTERRUPT_INT1_PRIORITY_READ()   (INTCON3bits.INT1P)

#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE


#else 
#error "that isn't an available configurations "
#endif




/******************SECTION :INT2 pin********************/
/********************INT2 pin flag**********/
#define EXTERNAL_INTERRUPT_INT2_READ_FLAG()    (INTCON3bits.INT2F)   
#define EXTERNAL_INTERRUPT_INT2_CLEAR_FLAG()   (INTCON3bits.INT2F=0) 

/********************INT2 pin enable****************/
#define EXTERNAL_INTERRUPT_INT2_INTERRUPT_ENABLE()  (INTCON3bits.INT2E=1)
#define EXTERNAL_INTERRUPT_INT2_INTERRUPT_DISABLE() (INTCON3bits.INT2E=0)
#define EXTERNAL_INTERRUPT_INT2_INTERRUPT_CHECK()   (INTCON3bits.INT2E)

/*********************INT2 interrupt edge***********/
#define EXTERNAL_INTERRUPT_INT2_FALLING_EDGE_ENABLE()   (INTCON2bits.INTEDG2=0)
#define EXTERNAL_INTERRUPT_INT2_RISING_EDGE_ENABLE()    (INTCON2bits.INTEDG2=1)

/*******************INT2 interrupt priority******/

#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_INT2_HIGH_PRIORITY_ENABLE()    (INTCON3bits.INT2P=1)
#define EXTERNAL_INTERRUPT_INT2_LOW_PRIORITY_ENABLE()   (INTCON3bits.INT2P=0)
#define EXTERNAL_INTERRUPT_INT2_PRIORITY_READ()         (INTCON3bits.INT2P)

#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE


#else 
#error "that isn't an available configurations "
#endif
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
/*************************SECTION:RBx_pins********/
/********************RBx pin flag**********/
#define EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG()     (INTCONbits.RBIF=0)
#define EXTERNAL_INTERRUPT_RBX_READ_FLAG()      (INTCONbits.RBIF)
/********************RBx pin enable****************/
#define EXTERNAL_INTERRUPT_RBX_ENABLE()         (INTCONbits.RBIE=1)
#define EXTERNAL_INTERRUPT_RBX_DISABLE()        (INTCONbits.RBIE=0)
#define EXTERNAL_INTERRUPT_RBX_CHECK()          (INTCONbits.RBIE)


/*******************INT2 interrupt priority******/

#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_RBX_HIGH_PRIORITY_ENABLE()   (INTCON2bits.RBIP=1)
#define EXTERNAL_INTERRUPT_RBX_LOW_PRIORITY_ENABLE()   (INTCON2bits.RBIP=0)
#define EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK()         (INTCON2bits.RBIP=0)

#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE


#else 
#error "that isn't an available configurations "
#endif
#endif
/***********SECTION: data type definition*******************/
#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
typedef enum 
{
    INT0_pin=0,
    INT1_pin=1,
    INT2_pin=2
}INTx_pin_index_t;
typedef enum
{
    FALLING_EDGE=0,
    RISING_EDGE=1
}INTERRUPT_edge_t;

typedef struct
{
    void (*ISR_handler)(void);
    INTx_pin_index_t pin_index ;
    INTERRUPT_edge_t edge;
    INTERRUPT_priority_t priority;
}INTERRUPT_INTx_pin_t;
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
typedef enum
{
    RB4_pin=0,
    RB5_pin=1,
    RB6_pin=2,
    RB7_pin=3
}RBx_pin_index_t;

typedef struct
{
    void (*ISR_handler)(void);
    RBx_pin_index_t pin_index;
    INTERRUPT_priority_t priority;
}INTERRUPT_RBx_pin_t;
#endif

uint8 RB4_state=0,RB5_state=0,RB6_state=0,RB7_state=0;

/***********SECTION: function decleration*******************/
#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
STD_RETURN_TYPE EXTERNAL_INTERRUPT_INTx_init(INTERRUPT_INTx_pin_t *interrupt_pin);
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
STD_RETURN_TYPE EXTERNAL_INTERRUPT_RBx_init(INTERRUPT_RBx_pin_t *interrupt_pin);
#endif
#endif	/* EXTERNAL_INTERRUPT_H */

