/*
 * EEPROM_program.c
 *
 *  Created on: Oct 30, 2021
 *      Author: ahmad
 */
#include "../../LIB/bitmath.h"
#include "../../LIB/stdtypes.h"
#include <util/delay.h>

#include "../../MCAL/TWI/TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


void EEPROM_voidSendByte( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	TWI_voidSendStartCondition();

	TWI_voidSendSlaveAddressWithWrite( Local_u8AddressPacket );
	/*Send Address*/
	TWI_voidMasterWriteDataByte((u8) Copy_u16LocationAddress );
	/*Send Data*/
	TWI_voidMasterWriteDataByte( Copy_u8DataByte );

	TWI_voidSendStopCondition();
	_delay_ms(10);

}


u8 EEPROM_u8ReadDataByte( u16 Copy_u16LocationAddress )
{
	u8 Local_u8AddressPacket;
	u8 Local_u8Data = 0;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	TWI_voidSendStartCondition();

	/*Send Slave Address with write*/
	TWI_voidSendSlaveAddressWithWrite( Local_u8AddressPacket );
	/**/
	TWI_voidMasterWriteDataByte( (u8) Copy_u16LocationAddress );

	/**/
	TWI_voidSendRepeatedStartCondition();
	TWI_voidSendSlaveAddressWithRead( Local_u8AddressPacket );

	Local_u8Data  = TWI_u8MasterReadDataByte();
	TWI_voidSendStopCondition();

	return Local_u8Data;


}
