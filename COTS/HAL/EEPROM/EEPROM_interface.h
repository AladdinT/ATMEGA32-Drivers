/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EEPROM_interface.h
 *       Module:  External Electrically Erasable Programmable Read Only Memory (External EEPROM)
 *
 *  Description:  This file has : -all macros that users may need
 *  							  -Module Functions description and declarations
 *  			  Please Note that this driver at the moment is only compatible with 24c08 EEPROM
 *  Created on: 	Oct 30, 2021
 *  Latest update : Jan 27, 2023
 *  Author : Ahmad Tohamy
 *********************************************************************************************************************/
#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
TWI_ErrorStatus EEPROM_voidSendByte( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte( u16 Copy_u16LocationAddress );

void EEPROM_voidSendArrayOfBytes( u16 Copy_u16LocationAddress , u8* ArrayOfBytes, u8 Copy_u8ArraySize);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: EEPROM_interface.h
 *********************************************************************************************************************/
