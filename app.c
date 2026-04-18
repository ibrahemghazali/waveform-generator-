#include "ECU/LCD/LCD.h"
#include "ECU/AD9833/AD9833.h"
#include "ECU/ECU_init.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"
#include "MCAL/Timers/TIMER1/Timer1.h"


#define WAVE_FORM_EEPROM_ADDRESS 0x01

#define SQUARE_MODE               0
#define TRIANGLE_MODE             1
#define SINE_MODE                 2

#define FIRST_TIME_USE 0xFF
#define DEFAULT_MODE              AD9833_SQUARE_WAVEFORM      
#define SCREEN1                         0
#define SCREEN2                         1
#define SQUARE_ROW                      2
#define TRIANGLE_ROW                    3
#define SINE_ROW                        4


#define ACTIVATED 1
#define UNACTIVATED 0

volatile uint8 ok_button_flag=UNACTIVATED;
volatile uint8 cursor_button_flag=UNACTIVATED;

ADC_result_t wave_frequency=0;
uint8 ret=E_OK;
uint8 current_mode=0;
uint8 current_screen=SCREEN1;
uint8 row_counter=0;
uint8 arrow_character[8]=
{
     0b00000, 0b00000, 0b00100, 0b00010, 0b11111,0b00010,0b00100,0b00000
};
void initialize_app(void);
void ADC_interrupt_change_frequency(void);
void ok_exit_button_interrupt(void);
void cursor_button_interrupt(void);

LCD_4bit_t Wave_form_lcd=
{
    /***EN pin initialization******/
 .EN_pin.port=GPIO_PORTD,
 .EN_pin.pin=GPIO_PIN1,
 .EN_pin.direction=GPIO_OUTPUT,
 .EN_pin.logic=GPIO_LOW,
 
 /****RS pin initialization*****/
 .RS_pin.port=GPIO_PORTD,
 .RS_pin.pin=GPIO_PIN0,
 .RS_pin.direction=GPIO_OUTPUT,
 .RS_pin.logic=GPIO_LOW,
 
 /********Data pins initialization*********/
 .data_pins[0].port=GPIO_PORTD,
 .data_pins[0].pin=GPIO_PIN2,
 .data_pins[0].direction=GPIO_OUTPUT,
 .data_pins[0].logic=GPIO_LOW,
 
 .data_pins[1].port=GPIO_PORTD,
 .data_pins[1].pin=GPIO_PIN3,
 .data_pins[1].direction=GPIO_OUTPUT,
 .data_pins[1].logic=GPIO_LOW,
 
 .data_pins[2].port=GPIO_PORTD,
 .data_pins[2].pin=GPIO_PIN4,
 .data_pins[2].direction=GPIO_OUTPUT,
 .data_pins[2].logic=GPIO_LOW,
 
 .data_pins[3].port=GPIO_PORTD,
 .data_pins[3].pin=GPIO_PIN5,
 .data_pins[3].direction=GPIO_OUTPUT,
 .data_pins[3].logic=GPIO_LOW,
 

};
/*interrupt just for test or use more peripheral but this is bad in real */
INTERRUPT_INTx_pin_t OK_button=
{
  .edge=RISING_EDGE,
  .pin_index=INT0_pin,
  .priority=HIGH_PRIORITY,
  .ISR_handler=ok_exit_button_interrupt
};
/*interrupt just for test or use more peripheral but this is bad in real */
INTERRUPT_INTx_pin_t CURSOR_button=
{
  .edge=RISING_EDGE,
  .pin_index=INT1_pin,
  .priority=HIGH_PRIORITY,
  .ISR_handler=cursor_button_interrupt
};
AD9833_t wave_generator=
{
    .AD9833_spi.SPI_MODE=SPI_MASTER_MODE_CLOCK_FOSC_4,
    .Fsync_pin.port=GPIO_PORTC,
    .Fsync_pin.pin=GPIO_PIN6,
    .start_waveform=DEFAULT_MODE
};


int main()
{   
    initialize_app();
    while(1)
    {
        ADC_read_channel_blocking(ADC_CHANNEL_3,&wave_frequency);
    if(SCREEN1==current_screen)
    {
        ECU_LCD_4bit_send_number_with_pos(&Wave_form_lcd,wave_frequency,4,1);
    }
        __delay_ms(2000);
    if(ACTIVATED==ok_button_flag)
    {
            if(SCREEN1==current_screen)
    {
        current_screen=SCREEN2;
        ECU_LCD_4bit_send_command(&Wave_form_lcd,LCD_CLEAR);
        ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Choose option:",1,1);
        ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Square wave",2,2);
        ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Triangle wave",3,2);
        ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Sine wave",4,2);
        ECU_LCD_4bit_send_special_character(&Wave_form_lcd,arrow_character,2,1,1);
        ECU_LCD_4bit_set_cursor(&Wave_form_lcd,2,1);
        row_counter=2;
    }
    else if(SCREEN2==current_screen)
    {
        current_screen=SCREEN1;
        ECU_LCD_4bit_send_command(&Wave_form_lcd,LCD_CLEAR);
        ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Current mode:",1,1);
        if(SQUARE_ROW==row_counter)
        {
            ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Square waveform",2,1);
            ret=AD9833_set_square_waveform(&wave_generator);
            current_mode=SQUARE_MODE;
            EEPROM_write_data(WAVE_FORM_EEPROM_ADDRESS,current_mode);
        }
        else if(TRIANGLE_ROW==row_counter)
        {
            ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Triangle waveform",2,1);
            ret=AD9833_set_triangle_waveform(&wave_generator);
            current_mode=TRIANGLE_MODE;
            EEPROM_write_data(WAVE_FORM_EEPROM_ADDRESS,current_mode);
        }
        else if(SINE_ROW==row_counter)
        {
            ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Sine waveform",2,1);
            ret=AD9833_set_sine_waveform(&wave_generator);
            current_mode=SINE_MODE;
            EEPROM_write_data(WAVE_FORM_EEPROM_ADDRESS,current_mode);         
        }
        else
        {
            
        }
        ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"current frequency",3,1);
        ECU_LCD_4bit_send_number_with_pos(&Wave_form_lcd,wave_frequency,4,1);
        ok_button_flag=UNACTIVATED;
        
    }
    else
    {
        
    }
    }
    else{/*nothing */}

    if(ACTIVATED==cursor_button_flag)
    {
        if(SCREEN2==current_screen)
        {
            ECU_LCD_4bit_send_data_with_pos(&Wave_form_lcd,' ',row_counter,1);
            row_counter=(row_counter+1)%5;
            if(0==row_counter)
            {
                row_counter=2;
            }
            ECU_LCD_4bit_set_cursor(&Wave_form_lcd,row_counter,1);
            ECU_LCD_4bit_send_special_character(&Wave_form_lcd,arrow_character,row_counter,1,1);
        }
        cursor_button_flag=UNACTIVATED;
    }
    else{/*nothing*/}
    }
}


void initialize_app(void)
{
    ret=EEPROM_read_data(WAVE_FORM_EEPROM_ADDRESS,&current_mode);
    ret=ECU_LCD_4bit_init(&Wave_form_lcd);
    ret=ADC_init();
    ADC_read_channel_blocking(ADC_CHANNEL_3,&(wave_frequency));
    wave_generator.freq=wave_frequency;
    ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Current mode:",1,1);
    if(SQUARE_MODE==current_mode)
    {
        wave_generator.start_waveform=AD9833_SQUARE_WAVEFORM;
        ret=AD9833_init(&wave_generator);
        ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Square waveform",2,1);
    }
    else if(TRIANGLE_MODE==current_mode)
    {
       wave_generator.start_waveform=AD9833_TRIANGLE_WAVEFORM;
       ret=AD9833_init(&wave_generator);
       ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Triangle waveform",2,1);
    }
    else if(SINE_MODE==current_mode)
    {
       wave_generator.start_waveform=AD9833_SINE_WAVEFORM;
        ret=AD9833_init(&wave_generator);  
        ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Sine waveform",2,1);
    }
    else
    {
        wave_generator.start_waveform=AD9833_SQUARE_WAVEFORM;
        ret=AD9833_init(&wave_generator);
        ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"Square waveform",2,1);
    }
    ret=ECU_LCD_4bit_send_string_with_pos(&Wave_form_lcd,"CUREENT frequency:",3,1);
    ret=ECU_LCD_4bit_send_number_with_pos(&Wave_form_lcd,wave_frequency,4,1); 
    /*interrupt just for test or use more peripheral but this is bad in real */
    EXTERNAL_INTERRUPT_INTx_init(&OK_button);
    EXTERNAL_INTERRUPT_INTx_init(&CURSOR_button);
}



void ok_exit_button_interrupt(void)
{
    ok_button_flag=ACTIVATED;
}
void cursor_button_interrupt(void)
{
    cursor_button_flag=ACTIVATED;
}