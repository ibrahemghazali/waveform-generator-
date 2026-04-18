/* 
 * File:   LCD.h
 * Author: ibrah
 *
 * Created on February 6, 2025, 1:35 AM
 */

#ifndef LCD_H
#define	LCD_H

/***********SECTION: library includes*******************/
#include "LCD_config.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <string.h>
#include<stdio.h>
/***********SECTION: macro definition*******************/
#define DATA_PINS_8BIT_MODE 8
#define DATA_PINS_4BIT_MODE 4


#define LCD_COMMAND_LOGIC GPIO_LOW
#define LCD_DATA_LOGIC    GPIO_HIGH


#define DATA_PIN0 0
#define DATA_PIN1 1
#define DATA_PIN2 2
#define DATA_PIN3 3
#define DATA_PIN4 4
#define DATA_PIN5 5
#define DATA_PIN6 6
#define DATA_PIN7 7

#define DATA_BIT0 0
#define DATA_BIT1 1
#define DATA_BIT2 2
#define DATA_BIT3 3
#define DATA_BIT4 4
#define DATA_BIT5 5
#define DATA_BIT6 6
#define DATA_BIT7 7

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

/****LCD:commands*****/
#define LCD_CLEAR                                       0x01
#define LCD_RETURN_HOME                                 0x02

#define LCD_ENTRY_SET_MODE_INCREAMENT_ON_SHIFT_ON       0x07
#define LCD_ENTRY_SET_MODE_INCREAMENT_ON_SHIFT_OFF      0x06
#define LCD_ENTRY_SET_MODE_DECREAMENT_ON_SHIFT_ON       0x05
#define LCD_ENTRY_SET_MODE_DECREAMENT_ON_SHIFT_OFF      0x04


#define LCD_DISPLAY_OFF                                 0x08
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF              0x0E
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON               0x0F
#define LCD_DISPLAY_ON_CURSOR_OFF                       0x0C


#define LCD_CURSOR_MOVE_ON_DISPLAY_SHIFT_RIGHT          0x1C 
#define LCD_CURSOR_MOVE_ON_DISPLAY_SHIFT_LEFT           0x18
#define LCD_CURSOR_MOVE_OFF_DISPLAY_SHIFT_RIGHT         0x14
#define LCD_CURSOR_MOVE_OFF_DISPLAY_SHIFT_LEFT          0x10


#define LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR        0x38
#define LCD_DISPLAY_8BIT_2LINE_FONT_BIGGER         0x3C
#define LCD_DISPLAY_8BIT_1LINE_FONT_REGULAR        0x30
#define LCD_DISPLAY_8BIT_1LINE_FONT_BIGGER         0x34

#define LCD_DISPLAY_4BIT_2LINE_FONT_REGULAR        0x28
#define LCD_DISPLAY_4BIT_2LINE_FONT_BIGGER         0x2C
#define LCD_DISPLAY_4BIT_1LINE_FONT_REGULAR        0x20
#define LCD_DISPLAY_4BIT_1LINE_FONT_BIGGER         0x24



#define LCD_DDRAM_START_ADDRESS                    0x80
#define LCD_CGRAM_START_ADDRESS                    0x40
#define LCD_FIRST_ROW_START_ADDRESS                LCD_DDRAM_START_ADDRESS
#define LCD_SECOND_ROW_START_ADDRESS                0xC0
#define LCD_THIRD_ROW_START_ADDRESS                 0x94
#define LCD_FOURTH_ROW_START_ADDRESS                0xd4

/***********SECTION: function like macro*******************/


/***********SECTION: data type definition*******************/
#if LCD_8BIT_MODE==ACTIVE_MODE
typedef struct
{
    pin_config_t RS_pin;
    pin_config_t EN_pin;
    pin_config_t data_pins[DATA_PINS_8BIT_MODE];
}LCD_8bit_t;
#endif
#if LCD_4BIT_MODE==ACTIVE_MODE
typedef struct
{
    pin_config_t RS_pin;
    pin_config_t EN_pin;
    pin_config_t data_pins[DATA_PINS_4BIT_MODE];  
}LCD_4bit_t;
#endif
/***********SECTION: function decleration*******************/
/************LCD 8bits function*****************/
#if LCD_8BIT_MODE==ACTIVE_MODE
STD_RETURN_TYPE ECU_LCD_8bit_init(LCD_8bit_t *lcd);
STD_RETURN_TYPE ECU_LCD_8bit_set_cursor(LCD_8bit_t *lcd,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_8bit_send_data(LCD_8bit_t *lcd,uint8 data);
STD_RETURN_TYPE ECU_LCD_8bit_send_data_with_pos(LCD_8bit_t *lcd,uint8 data,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_8bit_send_command(LCD_8bit_t *lcd,uint8 command);
STD_RETURN_TYPE ECU_LCD_8bit_send_number(LCD_8bit_t *lcd,uint32 number);
STD_RETURN_TYPE ECU_LCD_8bit_send_number_with_pos(LCD_8bit_t *lcd,uint32 number,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_8bit_send_string(LCD_8bit_t *lcd,uint8 *string);
STD_RETURN_TYPE ECU_LCD_8bit_send_string_with_pos(LCD_8bit_t *lcd,uint8 *string,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_8bit_send_special_character(LCD_8bit_t *lcd,uint8 *character,uint8 row,uint8 col,uint8 mem_pos);
#endif
/************LCD 4bits function*****************/
#if LCD_4BIT_MODE==ACTIVE_MODE
STD_RETURN_TYPE ECU_LCD_4bit_init(LCD_4bit_t *lcd);
STD_RETURN_TYPE ECU_LCD_4bit_send_data(LCD_4bit_t *lcd,uint8 data);
STD_RETURN_TYPE ECU_LCD_4bit_send_data_with_pos(LCD_4bit_t *lcd,uint8 data,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_4bit_send_command(LCD_4bit_t *lcd,uint8 command);
STD_RETURN_TYPE ECU_LCD_4bit_send_number(LCD_4bit_t *lcd,uint32 number);
STD_RETURN_TYPE ECU_LCD_4bit_send_number_with_pos(LCD_4bit_t *lcd,uint32 number,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_4bit_send_string(LCD_4bit_t *lcd,uint8 *string);
STD_RETURN_TYPE ECU_LCD_4bit_send_string_with_pos(LCD_4bit_t *lcd,uint8 *string,uint8 row,uint8 col);
STD_RETURN_TYPE ECU_LCD_4bit_send_special_character(LCD_4bit_t *lcd,uint8 *character,uint8 row,uint8 col,uint8 mem_pos);
STD_RETURN_TYPE ECU_LCD_4bit_set_cursor(LCD_4bit_t *lcd,uint8 row,uint8 col);
#endif

#endif	/* LCD_H */

