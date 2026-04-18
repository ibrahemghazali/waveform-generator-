#include "KEYPAD.h"
#include "KEYPAD_config.h"
#include <xc.h>
#define _XTAL_FREQ 8000000UL
STD_RETURN_TYPE ECU_KEYPAD_init(KEYPAD_t *keypad)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_counter=0;
    if(NULL==keypad)
    {
        ret=E_NOK;
    }
    else
    {
       for(L_counter=0;L_counter<KEYPAD_ROWS;L_counter++)
       {
           ret=GPIO_PIN_initialize(&(keypad->row_pins[L_counter]));
           //ret=GPIO_PIN_enable_direction(&(keypad->row_pins[L_counter]),GPIO_OUTPUT);
       }
       for(L_counter=0;L_counter<KEYPAD_COLS;L_counter++)
       {
           ret=GPIO_PIN_initialize(&(keypad->col_pins[L_counter]));
       }
    }
    return ret;
}


#if KEYPAD_ARRAYS_MODE==KEYPAD_STATIC_ARRAY
static uint8 keypad_keys[KEYPAD_ROWS][KEYPAD_COLS]=KEYPAD_KEYS;
STD_RETURN_TYPE ECU_KEYPAD_get_pressed_key(KEYPAD_t *keypad ,uint8 *value)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_row_counter=0,L_col_counter=0;
    PIN_LOGIC_T button_logic=GPIO_LOW;
    if(NULL==keypad||NULL==value)
    {
        ret=E_NOK;
    }
    else
    {
        for(L_row_counter=0;L_row_counter<KEYPAD_ROWS;L_row_counter++)
        {
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_LOW);    
        }
        for(L_row_counter=0;L_row_counter<KEYPAD_ROWS;L_row_counter++)
        {
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_HIGH);
            for(L_col_counter=0;L_col_counter<KEYPAD_COLS;L_col_counter++)
            {
                GPIO_PIN_read_logic(&(keypad->col_pins[L_col_counter]),&button_logic);
                if(GPIO_HIGH==button_logic)
                {
                    *value=keypad_keys[L_row_counter][L_col_counter]; 
                }
                else
                {
                    //nothing
                }
            }
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_LOW);       
        }
    }
    return ret;   
}
#endif


#if KEYPAD_ARRAYS_MODE==KEYPAD_PASSED_ARRAY
static uint8 keypad_keys[KEYPAD_ROWS][KEYPAD_COLS]=KEYPAD_KEYS;
STD_RETURN_TYPE ECU_KEYPAD_get_pressed_key(KEYPAD_t *keypad ,uint8 *value,uint8 *keypad_key)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 L_row_counter=0,L_col_counter=0;
    PIN_LOGIC_T button_logic=GPIO_LOW;
    if(NULL==keypad||NULL==value)
    {
        ret=E_NOK;
    }
    else
    {
        for(L_row_counter=0;L_row_counter<KEYPAD_ROWS;L_row_counter++)
        {
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_LOW);    
        }
        for(L_row_counter=0;L_row_counter<KEYPAD_ROWS;L_row_counter++)
        {
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_HIGH);
            for(L_col_counter=0;L_col_counter<KEYPAD_COLS;L_col_counter++)
            {
                GPIO_PIN_read_logic(&(keypad->col_pins[L_col_counter]),&button_logic);
                
                if(GPIO_HIGH==button_logic)
                {
                    *value=keypad_keys[L_row_counter][L_col_counter]; 
                }
                else
                {
                    /*Nothing*/
                }
            }
            ret=GPIO_PIN_write_logic(&(keypad->row_pins[L_row_counter]),GPIO_LOW);       
        }
    }
    return ret;   
}
#endif


