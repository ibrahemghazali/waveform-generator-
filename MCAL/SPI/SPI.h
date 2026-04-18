/* 
 * File:   SPI.h
 * Author: ibrah
 *
 * Created on June 10, 2025, 6:02 PM
 */

#ifndef SPI_H
#define	SPI_H
/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../GPIO/GPIO.h"
#include "../MCAL_STD_TYPES.h"
#include "SPI_config.h"
#include "../INTERRUPT/INTERNAL_INTERRUPT/INTERNAL_INTERRUPT.h"

/***********SECTION: macro definition*******************/

#define SDO_PORT    GPIO_PORTC
#define SDO_PIN     GPIO_PIN5

#define SCK_PORT    GPIO_PORTC
#define SCK_PIN     GPIO_PIN3

#define SS_PORT     GPIO_PORTA
#define SS_PIN      GPIO_PIN5
/***SPI_MODES_USER_SELECT*****/
#define SPI_SLAVE_MODE_SS_DISABLED  5
#define SPI_SLAVE_MODE_SS_ENABLED   4

#define SPI_MASTER_MODE_CLOCK_FOSC_64   2
#define SPI_MASTER_MODE_CLOCK_FOSC_16   1
#define SPI_MASTER_MODE_CLOCK_FOSC_4    0


#define SPI_INTERRUPT_DISABLED  0
#define SPI_INTERRUPT_ENABLED   1



/***********SECTION: function like macro*******************/
#define SPI_SELECT_MODE(MODE)                   (SSPCON1bits.SSPM=MODE)
#define SPI_SELECT_SAMPLING_MODE()              (SSPSTATbits.SMP=SPI_SAMPLING_CONFIGURATIONS)  
#define SPI_SELECT_CLOCK_TRANSMITTING_MODE()    (SSPSTATbits.CKE=SPI_CLOCK_TRANSMITING_MODE)
#define SPI_SELECT_IDLE_STATE()                 (SSPCON1bits.CKP=SPI_IDLE_STATE)

#define SPI_WRITE_COLLOSION_READ()              (SSPCON1bits.WCOL)
#define SPI_WRITE_COLLOSION_CLEAR()             (SSPCON1bits.WCOL=0)

#define SPI_OVER_FLOW_READ()                    (SSPCON1bits.SSPOV)
#define SPI_OVER_FLOW_CLEAR()                   (SSPCON1bits.SSPOV=0)

#define SPI_CHECK_MASTER_MODE(OBJ_CHECK)        ((SPI_MASTER_MODE_CLOCK_FOSC_64==OBJ_CHECK)||(SPI_MASTER_MODE_CLOCK_FOSC_16==OBJ_CHECK)||(SPI_MASTER_MODE_CLOCK_FOSC_4==OBJ_CHECK))
#define SPI_CHECK_SLAVE_MODE(OBJ_CHECK)         ((SPI_SLAVE_MODE_SS_DISABLED==OBJ_CHECK)||(SPI_SLAVE_MODE_SS_ENABLED==OBJ_CHECK))

#define SPI_ENABLE()                            (SSPCON1bits.SSPEN=1)
#define SPI_DISABLE()                           (SSPCON1bits.SSPEN=0)

#define IS_BUFFER_REGISTER_FULL()                  (SSPSTATbits.BF)

#define SPI_WRITE_TO_DATA_BUFFER(DATA)               (SSPBUF=DATA)
#define SPI_READ_DATA_BUFFER()                        (SSPBUF)


/***********SECTION: data type definition*******************/
typedef struct 
{
 #if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    void (*SPI_ISR)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    uint8 priority :1;
    uint8 SPI_reserved :2;
#else
    uint8 SPI_reserved :3;
#endif
#endif 
    uint8 SPI_MODE    :4;
    uint8 SPI_interrupt_enable  :1;

    
}SPI_t;
/***********SECTION: function decleration*******************/
STD_RETURN_TYPE SPI_init(SPI_t *SPI_obj);
STD_RETURN_TYPE SPI_Enable(SPI_t *SPI_obj);
STD_RETURN_TYPE SPI_disable(SPI_t *SPI_obj);

STD_RETURN_TYPE SPI_send_data_blocking(SPI_t *SPI_obj,uint8 data);
STD_RETURN_TYPE SPI_read_data_blocking(SPI_t *SPI_obj,uint8 *data);
STD_RETURN_TYPE SPI_send_and_read_data_blocking(SPI_t *SPI_obj,uint8 data,uint8 *data_ptr);

STD_RETURN_TYPE SPI_start_operation_nonblocking(SPI_t *SPI_obj,uint8 data);

STD_RETURN_TYPE SPI_send_16bit_data_blocking(SPI_t *SPI_obj,uint16 data);
STD_RETURN_TYPE SPI_send_16bit_data_nonblocking(SPI_t *SPI_obj,uint16 data);



#endif	/* SPI_H */

