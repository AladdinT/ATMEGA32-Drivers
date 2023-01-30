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
#include "../../MCAL/UART/UART_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


TWI_ErrorStatus EEPROM_voidSendByte( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte)
{
	if(Copy_u16LocationAddress > 1024)
	{
		/*return Error:: Invalid Address*/
	}

	u8 Local_u8AddressPacket;
	TWI_ErrorStatus LocalErorrStatus;
	/*Address : 1010 A2 B1B0 A7A6A5A4A3A2A1A0 */
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	LocalErorrStatus = TWI_SendStartCondition(); /*So far the code does not go past this function*/
	LocalErorrStatus = TWI_voidSendSlaveAddressWithWrite( Local_u8AddressPacket );


	/*Send EEPROM Address*/
	LocalErorrStatus = TWI_voidMasterWriteDataByte((u8) Copy_u16LocationAddress );

	/*Send Data*/
	LocalErorrStatus = TWI_voidMasterWriteDataByte( Copy_u8DataByte );

	TWI_voidSendStopCondition();
	_delay_ms(10);

	return LocalErorrStatus;

}


u8 EEPROM_u8ReadDataByte( u16 Copy_u16LocationAddress )
{
	u8 Local_u8AddressPacket;
	u8 Local_u8Data = 0;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	TWI_SendStartCondition();

	/*Send Slave Address with write*/
	TWI_voidSendSlaveAddressWithWrite( Local_u8AddressPacket );
	/*Send EEPROM Address*/
	TWI_voidMasterWriteDataByte( (u8) Copy_u16LocationAddress );

	/*Repeated Start to Read*/
	TWI_SendRepeatedStart();
	TWI_voidSendSlaveAddressWithRead( Local_u8AddressPacket );

	TWI_u8MasterReadDataByte( &Local_u8Data );
	TWI_voidSendStopCondition();

	return Local_u8Data;
}


void EEPROM_voidSendArrayOfBytes( u16 Copy_u16LocationAddress , u8* ArrayOfBytes, u8 Copy_u8ArraySize)
{
	if(Copy_u16LocationAddress > 1024)
	{
		/*return Error:: Invalid Address*/
	}

	u8 Local_u8AddressPacket;

	/*Address : 1010 A2 B1B0 A7A6A5A4A3A2A1A0 */
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	TWI_SendStartCondition();

	TWI_voidSendSlaveAddressWithWrite( Local_u8AddressPacket );

	for(u8 i=0 ; i < Copy_u8ArraySize ; i++ )
	{
		/*Send EEPROM Address*/
		TWI_voidMasterWriteDataByte((u8) Copy_u16LocationAddress + i );
		/*Send Data*/
		TWI_voidMasterWriteDataByte( ArrayOfBytes[i] );
		_delay_ms(10);
	}
	TWI_voidSendStopCondition();

}
