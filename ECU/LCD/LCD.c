#include"LCD.h"
#include <xc.h>

static uint8 number_array[12];
static STD_RETURN_TYPE convert_uint32_to_string(uint32 value);

#if LCD_8BIT_MODE==ACTIVE_MODE
STD_RETURN_TYPE ECU_LCD_8bit_init(LCD_8bit_t *lcd)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(lcd->RS_pin),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),GPIO_LOW);
        ret=GPIO_PIN_enable_direction(&(lcd->EN_pin),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
        for(L_counter=0;L_counter<DATA_PINS_8BIT_MODE;L_counter++)
        {
            ret=GPIO_PIN_enable_direction(&(lcd->data_pins[L_counter]),GPIO_OUTPUT);
            ret=GPIO_PIN_enable_direction(&(lcd->data_pins[L_counter]),GPIO_LOW);
        }
        __delay_ms(20);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
        __delay_ms(5);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
        __delay_us(150);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_CLEAR);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_RETURN_HOME);
        ret=ECU_LCD_8bit_send_command(lcd,LCD_DISPLAY_ON_CURSOR_OFF);
        
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_8bit_send_data(LCD_8bit_t *lcd,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),LCD_DATA_LOGIC);
        for(L_counter=0;L_counter<DATA_PINS_8BIT_MODE;L_counter++)
        {
            ret=GPIO_PIN_write_logic(&(lcd->data_pins[L_counter]),GET_BIT(data,L_counter));
        }
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
    }
    return ret;   
}
STD_RETURN_TYPE ECU_LCD_8bit_set_cursor(LCD_8bit_t *lcd,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        switch(row)
        {
            case ROW1: ret=ECU_LCD_8bit_send_command(lcd,LCD_FIRST_ROW_START_ADDRESS+(col-1)); break;
            case ROW2: ret=ECU_LCD_8bit_send_command(lcd,LCD_SECOND_ROW_START_ADDRESS+(col-1)); break;
            case ROW3: ret=ECU_LCD_8bit_send_command(lcd,LCD_THIRD_ROW_START_ADDRESS+(col-1)); break;
            case ROW4: ret=ECU_LCD_8bit_send_command(lcd,LCD_FOURTH_ROW_START_ADDRESS+(col-1)); break;
            default :ret=E_NOK;
        }
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_8bit_send_data_with_pos(LCD_8bit_t *lcd,uint8 data,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_8bit_set_cursor(lcd,row,col);
        ret=ECU_LCD_8bit_send_data(lcd,data);
    }
    return ret;     
}
STD_RETURN_TYPE ECU_LCD_8bit_send_command(LCD_8bit_t *lcd,uint8 command)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),LCD_COMMAND_LOGIC);
        for(L_counter=0;L_counter<DATA_PINS_8BIT_MODE;L_counter++)
        {
            ret=GPIO_PIN_write_logic(&(lcd->data_pins[L_counter]),GET_BIT(command,L_counter));
        }
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
    }
    return ret;    
}
STD_RETURN_TYPE ECU_LCD_8bit_send_number(LCD_8bit_t *lcd,uint32 number)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=convert_uint32_to_string(number);
        ret=ECU_LCD_8bit_send_string(lcd,number_array);
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_8bit_send_number_with_pos(LCD_8bit_t *lcd,uint32 number,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=convert_uint32_to_string(number);
        ret=ECU_LCD_8bit_send_string_with_pos(lcd,number_array,row,col);
    }
    return ret;   
}
STD_RETURN_TYPE ECU_LCD_8bit_send_string(LCD_8bit_t *lcd,uint8 *string)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd||NULL==string)
    {
        ret=E_NOK;
    }
    else
    {
        while(*string!=NULL)
        {
            ret=ECU_LCD_8bit_send_data(lcd,*string);
            string++;
        }
    }
    return ret;   
}
STD_RETURN_TYPE ECU_LCD_8bit_send_string_with_pos(LCD_8bit_t *lcd,uint8 *string,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd||NULL==string)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_8bit_set_cursor(lcd,row,col);
        ret=ECU_LCD_8bit_send_string(lcd,string);
    }
    return ret;   
}
STD_RETURN_TYPE ECU_LCD_8bit_send_special_character(LCD_8bit_t *lcd,uint8 *character,uint8 row,uint8 col,uint8 mem_pos)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd||NULL==character)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_8bit_send_command(lcd,LCD_CGRAM_START_ADDRESS+(8*mem_pos));
        for(L_counter=0;L_counter<8;L_counter++)
        {
            ret=ECU_LCD_8bit_send_data(lcd,character[L_counter]);
        }
        ret=ECU_LCD_8bit_send_data_with_pos(lcd,mem_pos,row,col);
    }
    return ret;  
}
#endif














/************LCD 4bits function*****************/
#if LCD_4BIT_MODE==ACTIVE_MODE
static STD_RETURN_TYPE LCD_send_higher_nibble(LCD_4bit_t *lcd,uint8 command_or_data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        for(L_counter=0;L_counter<4;L_counter++)
        {
            ret=GPIO_PIN_write_logic(&(lcd->data_pins[L_counter]),GET_BIT(command_or_data,4+L_counter));
        }
    }
    return ret;  
}
static STD_RETURN_TYPE LCD_send_lower_nibble(LCD_4bit_t *lcd,uint8 command_or_data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        for(L_counter=0;L_counter<4;L_counter++)
        {
            ret=GPIO_PIN_write_logic(&(lcd->data_pins[L_counter]),GET_BIT(command_or_data,L_counter));
        }
    }
    return ret;     
}
STD_RETURN_TYPE ECU_LCD_4bit_init(LCD_4bit_t *lcd)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_enable_direction(&(lcd->RS_pin),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),GPIO_LOW);
        ret=GPIO_PIN_enable_direction(&(lcd->EN_pin),GPIO_OUTPUT);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
        for(L_counter=0;L_counter<DATA_PINS_4BIT_MODE;L_counter++)
        {
            ret=GPIO_PIN_enable_direction(&(lcd->data_pins[L_counter]),GPIO_OUTPUT);
            ret=GPIO_PIN_enable_direction(&(lcd->data_pins[L_counter]),GPIO_LOW);
        }
        __delay_ms(20);
        ret=ECU_LCD_4bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
        __delay_ms(5);
        ret=ECU_LCD_4bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
        __delay_us(150);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_DISPLAY_8BIT_2LINE_FONT_REGULAR);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_CLEAR);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_RETURN_HOME);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_ENTRY_SET_MODE_INCREAMENT_ON_SHIFT_OFF);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_DISPLAY_ON_CURSOR_OFF);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_DISPLAY_4BIT_2LINE_FONT_REGULAR);
       ret=ECU_LCD_4bit_send_command(lcd,LCD_DDRAM_START_ADDRESS);
        
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_4bit_send_data(LCD_4bit_t *lcd,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),LCD_DATA_LOGIC);
        ret=LCD_send_higher_nibble(lcd,data);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
        ret=LCD_send_lower_nibble(lcd,data);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
    }
    return ret;    
}
STD_RETURN_TYPE ECU_LCD_4bit_set_cursor(LCD_4bit_t *lcd,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        switch(row)
        {
            case ROW1: ret=ECU_LCD_4bit_send_command(lcd,LCD_FIRST_ROW_START_ADDRESS+(col-1)); break;
            case ROW2: ret=ECU_LCD_4bit_send_command(lcd,LCD_SECOND_ROW_START_ADDRESS+(col-1)); break;
            case ROW3: ret=ECU_LCD_4bit_send_command(lcd,LCD_THIRD_ROW_START_ADDRESS+(col-1)); break;
            case ROW4: ret=ECU_LCD_4bit_send_command(lcd,LCD_FOURTH_ROW_START_ADDRESS+(col-1)); break;
            default :ret=E_NOK;
        }
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_4bit_send_data_with_pos(LCD_4bit_t *lcd,uint8 data,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_4bit_set_cursor(lcd,row,col);
        ret=ECU_LCD_4bit_send_data(lcd,data);
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_4bit_send_command(LCD_4bit_t *lcd,uint8 command)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=GPIO_PIN_write_logic(&(lcd->RS_pin),LCD_COMMAND_LOGIC);
        ret=LCD_send_higher_nibble(lcd,command);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
        ret=LCD_send_lower_nibble(lcd,command);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_HIGH);
        __delay_us(5);
        ret=GPIO_PIN_write_logic(&(lcd->EN_pin),GPIO_LOW);
    }
    return ret; 
}
STD_RETURN_TYPE ECU_LCD_4bit_send_number(LCD_4bit_t *lcd,uint32 number)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=convert_uint32_to_string(number);
        ret=ECU_LCD_4bit_send_string(lcd,number_array);
    }
    return ret;
}
STD_RETURN_TYPE ECU_LCD_4bit_send_number_with_pos(LCD_4bit_t *lcd,uint32 number,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd)
    {
        ret=E_NOK;
    }
    else
    {
        ret=convert_uint32_to_string(number);
        ret=ECU_LCD_4bit_send_string_with_pos(lcd,number_array,row,col);
    }
    return ret;  
}
STD_RETURN_TYPE ECU_LCD_4bit_send_string(LCD_4bit_t *lcd,uint8 *string)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd||NULL==string)
    {
        ret=E_NOK;
    }
    else
    {
        while(*string!=NULL)
        {
            ret=ECU_LCD_4bit_send_data(lcd,*string);
            string++;
        }
    }
    return ret;    
}
STD_RETURN_TYPE ECU_LCD_4bit_send_string_with_pos(LCD_4bit_t *lcd,uint8 *string,uint8 row,uint8 col)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==lcd||NULL==string)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_4bit_set_cursor(lcd,row,col);
        ret=ECU_LCD_4bit_send_string(lcd,string);
    }
    return ret;    
}
STD_RETURN_TYPE ECU_LCD_4bit_send_special_character(LCD_4bit_t *lcd,uint8 *character,uint8 row,uint8 col,uint8 mem_pos)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==lcd||NULL==character)
    {
        ret=E_NOK;
    }
    else
    {
        ret=ECU_LCD_4bit_send_command(lcd,LCD_CGRAM_START_ADDRESS+(8*mem_pos));
        for(L_counter=0;L_counter<8;L_counter++)
        {
            ret=ECU_LCD_4bit_send_data(lcd,character[L_counter]);
        }
        ret=ECU_LCD_4bit_send_data_with_pos(lcd,mem_pos,row,col);
    }
    return ret;   
}
#endif
static STD_RETURN_TYPE convert_uint32_to_string(uint32 value)
{
    STD_RETURN_TYPE ret=E_OK;

        memset(number_array,'/0',11);
        sprintf(number_array,"%i",value);
        return ret;
}