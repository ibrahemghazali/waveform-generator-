/* 
 * File:   INTERNAL_INTERRUPT_config.h
 * Author: ibrah
 *
 * Created on March 19, 2025, 8:43 AM
 */

#ifndef INTERNAL_INTERRUPT_CONFIG_H
#define	INTERNAL_INTERRUPT_CONFIG_H
/***********SECTION: library includes*******************/
#include "../INTERRUPT_manager/INTERRUPT_manager.h"

/***********SECTION: macro definition*******************/
#define TIMER_0_INTERRUPT INTERRUPT_FEATURE_ENABLE
#define TIMER_1_INTERRUPT INTERRUPT_FEATURE_ENABLE
#define TIMER_2_INTERRUPT INTERRUPT_FEATURE_ENABLE
#define TIMER_3_INTERRUPT INTERRUPT_FEATURE_ENABLE

#define CCP1_INTERRUPT    INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT    INTERRUPT_FEATURE_ENABLE


#define TX_INTERRUPT    INTERRUPT_FEATURE_ENABLE
#define RX_INTERRUPT    INTERRUPT_FEATURE_ENABLE


#define SPI_INTERRUPT   INTERRUPT_FEATURE_ENABLE 
/***********SECTION: function like macro*******************/

/***********SECTION: data type definition*******************/

/***********SECTION: function decleration*******************/
#endif	/* INTERNAL_INTERRUPT_CONFIG_H */

