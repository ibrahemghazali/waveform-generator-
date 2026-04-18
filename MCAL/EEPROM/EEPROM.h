/* 
 * File:   EEPROM.h
 * Author: ibrah
 *
 * Created on February 27, 2025, 7:32 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

/***********SECTION: library includes*******************/
#include <pic18f4620.h>
#include "../INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.h"
#include "../MCAL_STD_TYPES.h"
#include <xc.h>

/***********SECTION: macro definition*******************/

/***********SECTION: function like macro*******************/
#define EEPROM_ACCESS_DATA_EEPROM_MEMORY()      (EECON1bits.EEPGD=0)
#define EEPROM_ACCESS_DATA_FLASH_MEMORY()      (EECON1bits.EEPGD=1)


#define EEPROM_ACCESS_FLASH_AND_EEPROM_MEMORY()   (EECON1bits.CFGS=0)
#define EEPROM_ACCESS_CONFIGURATION_BITS()        (EECON1bits.CFGS=1)

#define EEPROM_ALLOW_WRITE_CYCLY_TO_FLASH_OR_EEPROM()   (EECON1bits.WREN=1)
#define EEPROM_INHIBIT_WRITE_CYCLY_TO_FLASH_OR_EEPROM()   (EECON1bits.WREN=0)

#define EEPROM_UNLOCK_SEQUENCE_STEP1()                              (EECON2=0x55)
#define EEPROM_UNLOCK_SEQUENCE_STEP2()                              (EECON2=0xAA)

#define EEPROM_INIATE_WRITE_ERASE_CYCLE()                             (EECON1bits.WR=1)
#define EEPROM_WAIT_WRITING_CYCLE_TO_COMPLETE()                        (EECON1bits.WR==1)

#define EEPROM_INATIATE_READ_CYCLE()                            (EECON1bits.RD=1)

/***********SECTION: data type definition*******************/

/***********SECTION: function decleration*******************/
STD_RETURN_TYPE EEPROM_write_data(uint16 address,uint8 data);
STD_RETURN_TYPE EEPROM_read_data(uint8 address,uint8 *data);

#endif	/* EEPROM_H */

