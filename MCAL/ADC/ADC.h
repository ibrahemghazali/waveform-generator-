/* 
 * File:   ADC.h
 * Author: ibrah
 *
 * Created on March 25, 2025, 5:10 PM
 */

#ifndef ADC_H
#define	ADC_H

/***********SECTION: library includes*******************/
#include "ADC_CONFIG.h"
#include "../INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.h"
#include "../MCAL_STD_TYPES.h"
#include <pic18f4620.h>

/***********SECTION: macro definition*******************/

/***********SECTION: function like macro*******************/
#define ADC_CONVERTER_ENABLE()                      (ADCON0bits.ADON=1)
#define ADC_CONVERTER_DISABLE()                     (ADCON0bits.ADON=0)


#define ADC_START_CONVERSION()                      (ADCON0bits.GO_nDONE=1)
#define ADC_CONVERSION_STATE()                      (ADCON0bits.GO_nDONE)

#define ADC_SELECT_CHANNEL(CHANNEL)                 (ADCON0bits.CHS=CHANNEL)
#define ADC_SET_ACQUISTION_TIME(ACQUISTION_TIME)    (ADCON2bits.ACQT=ACQUISTION_TIME)
#define ADC_SET_CONVERSION_CLOCK(CONVERSION_CLOCK)  (ADCON2bits.ADCS=CONVERSION_CLOCK)
#define ADC_ANALOG_DIGITAL_FUNCTIONALITY(ADC_CONFIG)    (ADCON1bits.PCFG=ADC_CONFIG)


#define ADC_SELECT_RESULT_RIGHT_JUSTIFIED()                (ADCON2bits.ADFM=1)
#define ADC_SELECT_RESULT_LEFT_JUSTIFIED()                (ADCON2bits.ADFM=0)




#define ADC_SELECT_INTERNAL_VOLTAGE_REF()                   do{ADCON1bits.VCFG1=0;\
                                                      ADCON1bits.VCFG0=0;\
                                                                        }while(0);
#define ADC_SELECT_EXTERNAL_VOLTAGE_REF()                  do{ADCON1bits.VCFG1=1;\
                                                        ADCON1bits.VCFG0=1;\
                                                                            }while(0);

/***********SECTION: data type definition*******************/
typedef uint16 ADC_result_t ;
typedef enum
{
    ADC_CHANNEL_0=0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12
}ADC_CHANNEL_t;
#if ADC_CODE_CONFIG==ADC_RUN_TIME_CONFIG
typedef enum
{
    ADC_RESULT_LEFT_JUSTIFIED=0,
    ADC_RESULT_RIGHT_JUSTIFIED=1
}ADC_RESULT_t;
typedef enum
{
    ADC_INTERNAL_VOLTAGE_REF=0,
    ADC_EXTERNAL_VOLTAGE_REF=1
}ADC_VOLTAGE_REF_t;
typedef enum
{
    ADC_CHANNEL_0=0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12
}ADC_CHANNEL_t;

typedef enum
{
 ADC_PINS_ALL_DIGITAL_FUNCTIONALLITY=0x0F,
 ADC_AN0_ANALOG_FUNCTIONALLITY=0x0E,
 ADC_AN1_ANALOG_FUNCTIONALLITY=0x0D,
 ADC_AN2_ANALOG_FUNCTIONALLITY=0x0C,
 ADC_AN3_ANALOG_FUNCTIONALLITY=0x0B,
 ADC_AN4_ANALOG_FUNCTIONALLITY=0x0A,
 ADC_AN5_ANALOG_FUNCTIONALLITY=0x09,
 ADC_AN6_ANALOG_FUNCTIONALLITY=0x08,
 ADC_AN7_ANALOG_FUNCTIONALLITY=0x07,
 ADC_AN8_ANALOG_FUNCTIONALLITY=0x06,
 ADC_AN9_ANALOG_FUNCTIONALLITY=        0x05,
 ADC_AN10_ANALOG_FUNCTIONALLITY=       0x04,
 ADC_AN11_ANALOG_FUNCTIONALLITY=      0x03,
ADC_AN12_ANALOG_FUNCTIONALLITY= 0x02 
}ADC_ANALOG_DIGITAL_FUNCTIONALLITY_t;

typedef enum
{
    ADC_ACQUSITION_TIME_0TAD,
    ADC_ACQUSITION_TIME_2TAD,
    ADC_ACQUSITION_TIME_4TAD,
    ADC_ACQUSITION_TIME_6TAD,
    ADC_ACQUSITION_TIME_8TAD,
    ADC_ACQUSITION_TIME_12TAD,
    ADC_ACQUSITION_TIME_16TAD,
    ADC_ACQUSITION_TIME_20TAD
}ADC_ACQUISTION_TIME_t;

typedef enum
{
    ADC_CONVERSION_CLOCK_FOSC_2=0,
    ADC_CONVERSION_CLOCK_FOSC_8,
    ADC_CONVERSION_CLOCK_FOSC_32,
    ADC_CONVERSION_CLOCK_FRC,
    ADC_CONVERSION_CLOCK_FOSC_4,
    ADC_CONVERSION_CLOCK_FOSC_16,
    ADC_CONVERSION_CLOCK_FOSC_64,
}ADC_CONVERSION_CLOCK_t;


typedef struct 
{
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
    void (*ISR)(void);
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_priority_t ADC_priority;
#endif
#endif 
    ADC_CONVERSION_CLOCK_t ADC_clock;
    ADC_ACQUISTION_TIME_t ADC_acquistion_time;
    ADC_ANALOG_DIGITAL_FUNCTIONALLITY_t ADC_Channels_config;/*note :that will determine analog digital functionallity*/
    ADC_RESULT_t adc_result_justification;
    ADC_VOLTAGE_REF_t ADC_voltage_ref;
    ADC_CHANNEL_t channel_pin;/*that's helper in driver you shouldn't define it*/
}ADC_t;
#endif 
/***********SECTION: function decleration*******************/
#if ADC_CODE_CONFIG==ADC_RUN_TIME_CONFIG
STD_RETURN_TYPE ADC_init(ADC_t *adc);
STD_RETURN_TYPE ADC_deinit(ADC_t *adc);
STD_RETURN_TYPE ADC_read_conversion(ADC_t *adc,ADC_result_t *result);
STD_RETURN_TYPE ADC_read_channel(ADC_t *adc,ADC_CHANNEL_t channel,ADC_result_t *result);
#endif

STD_RETURN_TYPE ADC_init();
STD_RETURN_TYPE ADC_deinit();
STD_RETURN_TYPE ADC_read_conversion(ADC_result_t *result);
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE ADC_read_channel_blocking(ADC_CHANNEL_t channel,ADC_result_t *result);
#endif 
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE ADC_read_channel_INTERRUPT(ADC_CHANNEL_t channel,void(*ISR_ptr)(void));
#endif
#endif	/* ADC_H */

