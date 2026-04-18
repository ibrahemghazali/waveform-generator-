/* 
 * File:   EUSART.h
 * Author: ibrah
 *
 * Created on June 9, 2025, 10:36 AM
 */

#ifndef EUSART_H
#define	EUSART_H
/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "EUSART_private.h"
#include "EUSART_config.h"
#include "../MCAL_STD_TYPES.h"
#include "../GPIO/GPIO.h"
#include "../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"

/***********SECTION: macro definition*******************/
/*******EUSART mode*******/
#define ASYNCHRONOUS_MODE 0
#define SYNCHRONOUS_MODE  1

#define LOW_SPEED   0
#define HIGH_SPEED  1

#define EIGHT_BIT_MODE      0
#define SIXTEEN_BIT_MODE     1

#define EUSART_DISABLED     0
#define EUSART_ENABLED       1

#define TX_PORT     GPIO_PORTC
#define RX_PORT     GPIO_PORTC


#define TX_PIN  GPIO_PIN6
#define RX_PIN  GPIO_PIN7
/***Macros for configure TX for user******/
#define EUSART_TX_ENABLED   1
#define EUSART_TX_DISABLED   0

#define EUSART_INTERRUPT_TX_ENABLED     1
#define EUSART_INTERRUPT_TX_DISABLED    0 

#define EUSART_TX_9BIT_MODE_ENABLED 1
#define EUSART_TX_9BIT_MODE_DISABLED 0

/***Macros for configure TX for user******/
#define EUSART_RX_ENABLED   1
#define EUSART_RX_DISABLED   0

#define EUSART_INTERRUPT_RX_ENABLED     1
#define EUSART_INTERRUPT_RX_DISABLED    0 

#define EUSART_RX_9BIT_MODE_ENABLED 1
#define EUSART_RX_9BIT_MODE_DISABLED 0
/***********SECTION: function like macro*******************/
#if EUSART_MODE==EUSART_8BIT_ASYNCHRONOUS_LOW_SPEED
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=ASYNCHRONOUS_MODE;\
                                      TXSTA1bits.BRGH=LOW_SPEED;\
                                      BAUDCONbits.BRG16=EIGHT_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     (SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*64))-1));
#elif EUSART_MODE==EUSART_8BIT_ASYNCHRONOUS_HIGH_SPEED
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=ASYNCHRONOUS_MODE;\
                                      TXSTA1bits.BRGH=HIGH_SPEED;\
                                      BAUDCONbits.BRG16=EIGHT_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     (SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*16))-1));

#elif EUSART_MODE==EUSART_16BIT_ASYNCHRONOUS_LOW_SPEED
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=ASYNCHRONOUS_MODE;\
                                      TXSTA1bits.BRGH=LOW_SPEED;\
                                      BAUDCONbits.BRG16=SIXTEEN_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     do \
                                            { \
                                            SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*16))-1);\
                                            SPBRGH=(uint8)((((_XTAL_FREQ)/(BAUD_RATE*16))-1)>>8);\
                                            }while(0);  

#elif EUSART_MODE==EUSART_16BIT_ASYNCHRONOUS_HIGH_SPEED
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=ASYNCHRONOUS_MODE;\
                                      TXSTA1bits.BRGH=HIGH_SPEED;\
                                      BAUDCONbits.BRG16=SIXTEEN_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     do \
                                            { \
                                            SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*4))-1);\
                                            SPBRGH=(uint8)((((_XTAL_FREQ)/(BAUD_RATE*4))-1)>>8);\
                                            }while(0); 

#elif EUSART_MODE==EUSART_8BIT_SYNCHRONOUS
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=SYNCHRONOUS_MODE;\
                                      BAUDCONbits.BRG16=EIGHT_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     do \
                                            { \
                                            SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*4))-1);\
                                            }while(0); 

#elif EUSART_MODE==EUSART_16BIT_SYNCHRONOUS
#define SET_EUSART_MODE()           do\
                                    {\
                                      TXSTA1bits.SYNC=ASYNCHRONOUS_MODE;\
                                      BAUDCONbits.BRG16=EIGHT_BIT_MODE; \
                                    }while(0);

#define SET_EUSART_BAUD_RATE(BAUD_RATE)     do \
                                            { \
                                            SPBRG=(uint8)(((_XTAL_FREQ)/(BAUD_RATE*4))-1);\
                                            SPBRGH=(uint8)((((_XTAL_FREQ)/(BAUD_RATE*4))-1)>>8);\
                                            }while(0); 

#endif

#define DISABLE_EUSART_MODULE()     (RCSTA1bits.SPEN=EUSART_DISABLED)
#define ENABLE_EUSART_MODULE()      (RCSTA1bits.SPEN=EUSART_ENABLED)

#define EUSART_TX_ENABLE()          (TXSTAbits.TXEN=EUSART_TX_ENABLED)
#define EUSART_TX_DISABLE()         (TXSTAbits.TXEN=EUSART_TX_DISABLED)


#define EUSART_TX_9BIT_ENABLE()         (TXSTA1bits.TX9=EUSART_TX_9BIT_MODE_ENABLED)
#define EUSART_TX_9BIT_DISABLE()        (TXSTA1bits.TX9=EUSART_TX_9BIT_MODE_DISABLED)


#define EUSART_RX_ENABLE()          (RCSTA1bits.CREN=EUSART_RX_ENABLED)
#define EUSART_RX_DISABLE()         (RCSTA1bits.CREN=EUSART_RX_DISABLED)


#define EUSART_RX_9BIT_ENABLE()         (RCSTA1bits.RX9=EUSART_RX_9BIT_MODE_ENABLED)
#define EUSART_RX_9BIT_DISABLE()        (RCSTA1bits.RX9=EUSART_RX_9BIT_MODE_DISABLED)

#define IS_TRANSMITTING_NOT_PERMITTED()     (!TXSTA1bits.TRMT)


#define EUSART_WRITE_DATA(DATA)         (TXREG=DATA)
#define READ_RECEIVING_DATA()           (RCREG)

#define READ_OVERRUN_ERROR()            (RCSTA1bits.OERR)
#define READ_FRAMING_ERROR()            (RCSTA1bits.FERR)
/***********SECTION: data type definition*******************/
typedef struct 
{
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
 void (*TX_ISR)(void);
#endif 
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    uint8 TX_reserved           :4;
    uint8 TX_priority           :1;
#else
    uint8 TX_reserved           :5;
#endif    
    uint8 TX_enable             :1;
    uint8 TX_interrupt_enable   :1;
    uint8 TX_9bit_mode_enable   :1;
}TX_t;

typedef struct 
{
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
 void (*RX_ISR)(void);
#endif  
 void (*framing_error_handler)(void);
 void (*overrun_error_handler)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    uint8 RX_reserved           :4;
    uint8 RX_priority           :1;
#else
    uint8 RX_reserved           :5;
#endif 
    uint8 RX_enable             :1;
    uint8 RX_interrupt_enable   :1;
    uint8 RX_9bit_mode_enable   :1;
    
}RX_t;
typedef struct 
{
 uint32 baud_rate;   
 RX_t rx_config;
 TX_t tx_config;
 

 

}EUSART_t;

/***********SECTION: function decleration*******************/
STD_RETURN_TYPE EUSART_asynchronous_init(const EUSART_t *eusart_obj);
STD_RETURN_TYPE EUSART_asynchronous_deinit(const EUSART_t *eusart_obj);
STD_RETURN_TYPE EUSART_asynchronous_write_data_blocking(const EUSART_t *eusart_obj,uint8 data);
STD_RETURN_TYPE EUSART_asynchronous_write_String_blocking(const EUSART_t *eusart_obj,const uint8 *data);
STD_RETURN_TYPE EUSART_asynchronoues_read_data_blocking(const EUSART_t *eusart_obj,uint8 *data);

STD_RETURN_TYPE EUSART_asynchronous_write_data_nonblocking(const EUSART_t *eusart_obj,uint8 data);
STD_RETURN_TYPE EUSART_asynchronous_write_String_nonblocking(const EUSART_t *eusart_obj,const uint8 *data);
STD_RETURN_TYPE EUSART_asynchronoues_read_data_nonblocking(const EUSART_t *eusart_obj,uint8 *data);

#endif	/* EUSART_H */

