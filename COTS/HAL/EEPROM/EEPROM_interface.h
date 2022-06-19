/*
 * EEPROM_interface.h
 *
 *  Created on: Oct 30, 2021
 *      Author: ahmad
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidSendByte( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte( u16 Copy_u16LocationAddress );



#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
