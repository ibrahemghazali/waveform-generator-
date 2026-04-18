
#include "EEPROM.h"

STD_RETURN_TYPE EEPROM_write_data(uint16 address,uint8 data)
{
    STD_RETURN_TYPE ret=E_OK;
    uint8 global_interrupt_state;
    /*read the global interrupt*/
    global_interrupt_state=INTERRUPT_GLOBAL_INTERRUPT_VALUE;
    //assigning the addresses to register
    EEADRH=(uint8)((address>>8)&(0x03));
    EEADR=(uint8)(address);
    /*updataing the data*/
    EEDATA=data;
    //accesssing EEPROM memory
    EEPROM_ACCESS_DATA_EEPROM_MEMORY();
    //accessing flash and EEPROM
    EEPROM_ACCESS_FLASH_AND_EEPROM_MEMORY();
    
    EEPROM_ALLOW_WRITE_CYCLY_TO_FLASH_OR_EEPROM();
    
    INTERRUPT_GLOBAL_DISABLE();
    
    EEPROM_UNLOCK_SEQUENCE_STEP1(); 
    EEPROM_UNLOCK_SEQUENCE_STEP2();
    EEPROM_INIATE_WRITE_ERASE_CYCLE();
    while(EEPROM_WAIT_WRITING_CYCLE_TO_COMPLETE());
    
    EEPROM_INHIBIT_WRITE_CYCLY_TO_FLASH_OR_EEPROM();
    INTERRUPT_GLOBAL_INTERRUPT_VALUE=global_interrupt_state;
    
    
    return ret;
    
}
STD_RETURN_TYPE EEPROM_read_data(uint8 address,uint8 *data)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==data)
    {
        ret=E_NOK;
    }
    else
    {
    EEADRH=(uint8)((address>>8)&(0x03));
    EEADR=(uint8)(address);
    
    EEPROM_ACCESS_DATA_EEPROM_MEMORY();
        
    EEPROM_ACCESS_FLASH_AND_EEPROM_MEMORY();
    
    EEPROM_INATIATE_READ_CYCLE();
    
    NOP();
    NOP();
    
    *data=EEDATA;
    }
    return ret;
}
