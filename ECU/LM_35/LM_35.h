/* 
 * File:   LM_35.h
 * Author: ibrah
 *
 * Created on March 26, 2025, 11:14 AM
 */

#ifndef LM_35_H
#define	LM_35_H

/***********SECTION: library includes*******************/
#include "../../MCAL/ADC/ADC.h"

/***********SECTION: macro definition*******************/
#define LM_35_CONSTANT 0.49f
/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/

/***********SECTION: function decleration*******************/
#if ADC_CODE_CONFIG==ADC_PRE_BUILD_CONFIG
STD_RETURN_TYPE LM_35_init();
#if ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_BLOCKING
STD_RETURN_TYPE LM_35_read_blocking(ADC_CHANNEL_t channel,ADC_result_t *result);
#elif ADC_CONVERSION_METHOD==ADC_CONVERSION_BY_INTERRUPT
STD_RETURN_TYPE LM_35_read_interrupt(ADC_CHANNEL_t channel,void (*isr_ptr)(void));
#endif
#endif 
#endif	/* LM_35_H */

