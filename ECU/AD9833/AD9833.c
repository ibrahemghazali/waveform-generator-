#include <builtins.h>

#include "AD9833.h"
static uint32 l_freq;
static uint16 LSB=0;
static uint8 current_waveform=0;
static STD_RETURN_TYPE AD9833_send_data_blocking(AD9833_t *AD9833_obj,uint16 command)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
        __delay_us(1);
        GPIO_PIN_write_logic(&(AD9833_obj->Fsync_pin),GPIO_LOW);
        SPI_send_16bit_data_blocking(&(AD9833_obj->AD9833_spi),command);
        GPIO_PIN_write_logic(&(AD9833_obj->Fsync_pin),GPIO_HIGH);
        __delay_us(1);
    }
    return ret;
}
STD_RETURN_TYPE AD9833_init(AD9833_t *AD9833_obj)
{
    STD_RETURN_TYPE ret=E_OK;

    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
        AD9833_obj->Fsync_pin.logic=GPIO_HIGH;
        AD9833_obj->Fsync_pin.direction=GPIO_OUTPUT;
        AD9833_obj->AD9833_spi.SPI_ISR=NULL;
        AD9833_obj->AD9833_spi.SPI_interrupt_enable=SPI_INTERRUPT_DISABLED;
        if(!SPI_CHECK_MASTER_MODE(AD9833_obj->AD9833_spi.SPI_MODE))
        {
            ret=E_NOK;
        }
        else
        {
            ret=ret&&SPI_init(&(AD9833_obj->AD9833_spi));
            ret=ret&&GPIO_PIN_initialize(&(AD9833_obj->Fsync_pin));
           l_freq=(uint32)(((POWER_2_28)*(AD9833_obj->freq*2ULL))/(MCLK_FREQ)); 
            if(AD9833_SQUARE_WAVEFORM==AD9833_obj->start_waveform)
            {
                current_waveform=AD9833_obj->start_waveform;
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE);
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE));
                
            }
            else if(AD9833_SQUARE_WAVEFORM_DIV_2==AD9833_obj->start_waveform)
            {
                current_waveform=AD9833_obj->start_waveform;
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_ENABLE);
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_ENABLE));
            }
            else if(AD9833_SINE_WAVEFORM==AD9833_obj->start_waveform)
            {
                current_waveform=AD9833_obj->start_waveform;
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE); 
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE));
            }
            else if(AD9833_SINE_WAVEFORM_DIV_2==AD9833_obj->start_waveform)
            {
                current_waveform=AD9833_obj->start_waveform;
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_ENABLE);  
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_ENABLE));
            }
            else if(AD9833_TRIANGLE_WAVEFORM==AD9833_obj->start_waveform)
            {
                current_waveform=AD9833_obj->start_waveform;
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE);    
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE));
            }
            else
            {
                ret=E_NOK;
            }
        }
    }
    return ret;
}
STD_RETURN_TYPE AD9833_set_square_waveform(AD9833_t *AD9833_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
        
        AD9833_send_data_blocking(AD9833_obj,
            AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE));
        
    }
    return ret;
}
STD_RETURN_TYPE AD9833_set_triangle_waveform(AD9833_t *AD9833_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE));   
    }
    return ret;
}
STD_RETURN_TYPE AD9833_set_sine_waveform(AD9833_t *AD9833_obj)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE));
    }
    return ret;
}
STD_RETURN_TYPE AD9833_set_frequency(AD9833_t *AD9833_obj,uint32 frequency)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==AD9833_obj)
    {
     ret=E_NOK;   
    }
    else
    {
        AD9833_obj->freq=frequency;
           l_freq=(uint32)(((POWER_2_28)*(AD9833_obj->freq*2ULL))/(MCLK_FREQ)); 
            if(AD9833_SQUARE_WAVEFORM==current_waveform)
            {
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE);
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_DISABLE));
                
            }
            else if(AD9833_SQUARE_WAVEFORM_DIV_2==current_waveform)
            {
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_ENABLE);
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SQUARE_WAVE_ENABLE_DIV2_ENABLE));
            }
            else if(AD9833_SINE_WAVEFORM==current_waveform)
            {
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE); 
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_DISABLE));
            }
            else if(AD9833_SINE_WAVEFORM_DIV_2==current_waveform)
            {
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_ENABLE);  
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_SINE_WAVE_ENABLE_DIV2_ENABLE));
            }
            else if(AD9833_TRIANGLE_WAVEFORM==current_waveform)
            {
                AD9833_send_data_blocking(AD9833_obj,
                        AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE);    
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_LSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,AD9833_FREQ0_MSB(l_freq));
                AD9833_send_data_blocking(AD9833_obj,
                AD9833_START_OUTPUT(AD9833_28BIT_FREQ_ENABLE_RESET_ENABLE_TRIANGLE_WAVE_ENABLE));
            }
            else
            {
                ret=E_NOK;
            }
    }
    return ret;    
}
