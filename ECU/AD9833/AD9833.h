/* 
 * File:   AD9833.h
 * Author: ibrah
 *
 * Created on June 12, 2025, 1:34 PM
 */

#ifndef AD9833_H
#define	AD9833_H
/***********SECTION: library includes*******************/
#include "../../MCAL/SPI/SPI.h"

/***********SECTION: macro definition*******************/
#define POWER_2_28  268435456ULL
#define MCLK_FREQ   25000000ULL


#define AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_ENABLE    0x2128
#define AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE   0x2120

#define AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_ENABLE      0x2108
#define AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE     0x2100

#define AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE              0x2102

#define AD9833_28BIT_FREQ_DISABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE   0x120
/****waveforms selected by user****/
#define AD9833_SQUARE_WAVEFORM              1
#define AD9833_SQUARE_WAVEFORM_DIV_2        2

#define AD9833_SINE_WAVEFORM                3
#define AD9833_SINE_WAVEFORM_DIV_2          4

#define AD9833_TRIANGLE_WAVEFORM            5



/***********SECTION: function like macro*******************/
#define AD9833_FREQ0_LSB(FREQ)          ((0x4000)|((FREQ)&(0x3FFF)))
#define AD9833_FREQ0_MSB(FREQ)          ((0x4000)|((FREQ>>14)&(0x3FFF)))
#define AD9833_START_OUTPUT(COMMAND)    (COMMAND&0x3EFF)


/***********SECTION: data type definition*******************/
typedef struct 
{
    uint32 freq;
    SPI_t AD9833_spi;
    uint8 start_waveform;
    pin_config_t Fsync_pin;
}AD9833_t;
/***********SECTION: function decleration*******************/
/*
* @brief: this function used to init the the module and mcal layers spi and gpio configuration too
* @param: pointer to structure of type AD9833_t which contains the configuration of the module @ref AD9833_t
* @return: E_OK if the function done successfully and E_NOK if there is an error in the configuration structure or in the initialization of the SPI or GPIO modules
*/
STD_RETURN_TYPE AD9833_init(AD9833_t *AD9833_obj);

/* 
* @brief: this function used to set the output waveform to square wave
* @param: pointer to structure of type AD9833_t which contains the configuration of the
* module @ref AD9833_t
* @return: E_OK if the function done successfully and E_NOK if there is an
*/
STD_RETURN_TYPE AD9833_set_square_waveform(AD9833_t *AD9833_obj);

/*
* @brief: this function used to set the output waveform to triangle wave
* @param: pointer to structure of type AD9833_t which contains the configuration of the
* module @ref AD9833_t
* @return: E_OK if the function done successfully and E_NOK if there is an error in the configuration structure or in the initialization of the SPI or GPIO modules
*/
STD_RETURN_TYPE AD9833_set_triangle_waveform(AD9833_t *AD9833_obj);

/*
* @brief: this function used to set the output waveform to sine wave
* @para: AD9833_t configuration 
* @ret: E_OK if the function done successfully and E_NOK if there is an error in the configuration structure or in the initialization of the SPI or GPIO modules
*/
STD_RETURN_TYPE AD9833_set_sine_waveform(AD9833_t *AD9833_obj);

/*
* @brief: this function used to set the output frequency of the module
* @para: AD9833_t configuration and the required frequency in Hz
* @ret: E_OK if the function done successfully and E_NOK if there is an error in the configuration structure or in the initialization of the SPI or GPIO modules
*/  

STD_RETURN_TYPE AD9833_set_frequency(AD9833_t *AD9833_obj,uint32 frequency);



#endif	/* AD9833_H */

