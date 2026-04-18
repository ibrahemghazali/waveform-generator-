/* 
 * File:   SPI_config.h
 * Author: ibrah
 *
 * Created on June 10, 2025, 6:02 PM
 */

#ifndef SPI_CONFIG_H
#define	SPI_CONFIG_H

/***********SECTION: library includes*******************/
#include "SPI_private.h"

/***********SECTION: macro definition*******************/
/*
SPI_SAMPLING_DATA_IN_MIDDLE 
SPI_SAMPLING_DATA_AT_END    
*/

#define SPI_SAMPLING_CONFIGURATIONS SPI_SAMPLING_DATA_IN_MIDDLE

/*
SPI_TRANSMIT_FROM_ACTIVE_TO_IDLE    
SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE    
*/

#define SPI_CLOCK_TRANSMITING_MODE SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE   

/*
IDLE_STATE_FOR_HIGH_LEVEL   
IDLE_STATE_FOR_LOW_LEVEL    
*/

#define SPI_IDLE_STATE IDLE_STATE_FOR_HIGH_LEVEL
/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/

/***********SECTION: function decleration*******************/




#endif	/* SPI_CONFIG_H */

