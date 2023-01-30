/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TWI_interface.h
 *       Module:  Two-wire Serial Interface (TWI)
 *
 *  Description:  This file has : -all macros that users may need
 *  							  -Module Functions description and declarations
 *  Created on: 	Jan 25, 2023
 *  Latest update : Jan 26, 2023
 *  Author : Ahmad Tohamy
 *********************************************************************************************************************/

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lib/stdtypes.h"

/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
#define TWI_MASTER_NOT_ADDRESSIBLE 		0
#define ENABLE							1
#define DISABLE							0

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithReadError,
	SlaveAddressWithWriteError,
	MasterWriteByteError,
	MasterReadByteError
}TWI_ErrorStatus;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*Initializations*/
void TWI_voidMasterInit(u8 Copy_u8Address);
void TWI_voidSlaveInit(u8 Copy_u8Address);
/*Send Conditions*/
TWI_ErrorStatus TWI_SendStartCondition(void);
TWI_ErrorStatus TWI_SendRepeatedStart(void);
void TWI_voidSendStopCondition(void);
/*Push Slave Address to bus functions*/
TWI_ErrorStatus TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
/*Push/Pop Data from/to bus*/
TWI_ErrorStatus TWI_voidMasterWriteDataByte(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_u8MasterReadDataByte(u8* Copy_u8Data);


#endif /* MCAL_TWI_TWI_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: TWI_interface.h
 *********************************************************************************************************************/
