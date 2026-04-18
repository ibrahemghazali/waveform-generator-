/* 
 * File:   ADC_private.h
 * Author: ibrah
 *
 * Created on March 25, 2025, 5:10 PM
 */

#ifndef ADC_PRIVATE_H
#define	ADC_PRIVATE_H

/***********SECTION: library includes*******************/


/***********SECTION: macro definition*******************/
#define ADC_RUN_TIME_CONFIG 1
#define ADC_PRE_BUILD_CONFIG 2

#define ADC_CONVERSION_BY_BLOCKING 1
#define ADC_CONVERSION_BY_INTERRUPT 2


#define _ADC_CONVERSION_CLOCK_FOSC_2    0
#define _ADC_CONVERSION_CLOCK_FOSC_8    1
#define _ADC_CONVERSION_CLOCK_FOSC_32   2
#define _ADC_CONVERSION_CLOCK_FRC       3  
#define _ADC_CONVERSION_CLOCK_FOSC_4    4
#define _ADC_CONVERSION_CLOCK_FOSC_16   5
#define _ADC_CONVERSION_CLOCK_FOSC_64   6

#define _ADC_ACQUSITION_TIME_0TAD 0
#define _ADC_ACQUSITION_TIME_2TAD 1
#define _ADC_ACQUSITION_TIME_4TAD 2
#define _ADC_ACQUSITION_TIME_6TAD 3
#define _ADC_ACQUSITION_TIME_8TAD 4
#define _ADC_ACQUSITION_TIME_12TAD 5
#define _ADC_ACQUSITION_TIME_16TAD 6
#define _ADC_ACQUSITION_TIME_20TAD 7


#define _ADC_PINS_ALL_DIGITAL_FUNCTIONALLITY    0x0F
#define _ADC_AN0_ANALOG_FUNCTIONALLITY          0x0E
#define _ADC_AN1_ANALOG_FUNCTIONALLITY          0x0D
#define _ADC_AN2_ANALOG_FUNCTIONALLITY          0x0C
#define _ADC_AN3_ANALOG_FUNCTIONALLITY          0x0B
#define _ADC_AN4_ANALOG_FUNCTIONALLITY          0x0A
#define _ADC_AN5_ANALOG_FUNCTIONALLITY          0x09
#define _ADC_AN6_ANALOG_FUNCTIONALLITY          0x08
#define _ADC_AN7_ANALOG_FUNCTIONALLITY          0x07
#define  _ADC_AN8_ANALOG_FUNCTIONALLITY         0x06
#define _ADC_AN9_ANALOG_FUNCTIONALLITY          0x05
#define _ADC_AN10_ANALOG_FUNCTIONALLITY         0x04
#define _ADC_AN11_ANALOG_FUNCTIONALLITY         0x03
#define _ADC_AN12_ANALOG_FUNCTIONALLITY         0x02 

#define _ADC_RESULT_RIGHT_JUSTIFIED 1
#define _ADC_RESULT_LEFT_JUSTIFIED  2

#define _ADC_INTERNAL_VOLTAGE_REF 1 
#define _ADC_EXTERNAL_VOLTAGE_REF 2

#define _ADC_HIGH_PRIORITY 1
#define _ADC_LOW_PRIORITY 2

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/

/***********SECTION: function decleration*******************/
#endif	/* ADC_PRIVATE_H */

