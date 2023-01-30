#include "../../LIB/stdtypes.h"
#include "../../LIB/bitmath.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "../UART/UART_interface.h"


/*Initializations*/
void TWI_voidMasterInit(u8 Copy_u8Address)
{
	/*Bit Rate (SCL clock frequency)*/
	/* F_SCL = F_CPU/ (16 + 2*TWBR*(4^TWPS) */
	/*Set F_SCL to 400kHz*/
	TWBR = 2;
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/*Assign salve address in case of receiving*/
	if(Copy_u8Address != TWI_MASTER_NOT_ADDRESSIBLE)
	{
		TWAR = Copy_u8Address<<1 ;
	}

#if		MASTER_ACK_EN == ENABLE
	SET_BIT(TWCR, TWCR_TWEA);
#elif MASTER_ACK_EN == DISABLE
	CLR_BIT(TWCR, TWCR_TWEA);
#endif

#if RECOGNIZE_GENERAL_CALL == ENABLE
	SET_BIT(TWAR, TWAR_TWGCE);
#endif

	/*Enable TWI*/
	SET_BIT(TWCR, TWCR_TWEN);

}
void TWI_voidSlaveInit(u8 Copy_u8Address)
{
	/*Assign slave address*/
	TWAR = Copy_u8Address<<1 ;
#if		SLAVE_ACK_EN == ENABLE
	SET_BIT(TWCR, TWCR_TWEA);
#elif SLAVE_ACK_EN == DISABLE
	CLR_BIT(TWCR, TWCR_TWEA);
#endif
	/*Enable TWI*/
	SET_BIT(TWCR, TWCR_TWEN);
}

/*Send Conditions*/
TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_status = NoError;
	/*Send Start Condition to bus*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*Clear interrupt flag*/
	/*Remember: Clearing this flag starts the operation of the TWI*/
	SET_BIT(TWCR, TWCR_TWINT);
	while( GET_BIT(TWCR, TWCR_TWINT) == 0 ); // <-------- LAST SEEN :: Didnt get out of it
	/*Check TWI status*/
	if( (TWSR & 0xF8) != START_ACK )
	{
		Local_status = StartConditionError;//0b 1111 1000
	}
	else
	{
		/*Do nothing*/
	}

	return Local_status;
}
TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_status = NoError;
	/*Send Start Condition to bus*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear interrupt flag*/
	/*Remember: Clearing this flag starts the operation of the TWI*/
	SET_BIT(TWCR, TWCR_TWINT);
	while(GET_BIT(TWCR, TWCR_TWINT)==0);

	/*Check TWI status*/
	if( (TWSR & 0xF8) != REP_START_ACK )
	{
		Local_status = RepeatedStartError;//0b 1111 1000
	}
	else
	{
		/*Do nothing*/
	}

	return Local_status;
}
void TWI_voidSendStopCondition(void)
{
	/*Push Stop condition to bus*/
	SET_BIT(TWCR, TWCR_TWSTO);
	/*Clear interrupt flag*/
	SET_BIT(TWCR, TWCR_TWINT);

}

/*Push Slave Address to bus functions*/
TWI_ErrorStatus TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_status = NoError;
	/*TWSTA has to be cleared once communication starts*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set slave address*/
	TWDR = Copy_u8SlaveAddress<<1;
	/*salve address is 7-bit , the 8th bit is for R/W*/
	SET_BIT(TWDR , TWDR_TWD0); //for read request

	/*Clear interrupt flag*/
	/*Remember: Clearing this flag starts the operation of the TWI*/
	SET_BIT(TWCR, TWCR_TWINT);
	while(GET_BIT(TWCR, TWCR_TWINT)==0);

	/*Check TWI status*/
	if( (TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_status = SlaveAddressWithReadError;//0b 1111 1000
	}
	else
	{
		/*Do nothing*/
	}

	return Local_status;
}
TWI_ErrorStatus TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_status = NoError;
	/*TWSTA has to be cleared once communication starts*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set slave address*/
	TWDR = Copy_u8SlaveAddress<<1;
	/*salve address is 7-bit , the 8th bit is for R/W*/
	CLR_BIT(TWDR , TWDR_TWD0); //for Write request

	/*Clear interrupt flag*/
	/*Remember: Clearing this flag starts the operation of the TWI*/
	SET_BIT(TWCR, TWCR_TWINT);
	while(GET_BIT(TWCR, TWCR_TWINT)==0);

	/*Check TWI status*/
	if( (TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_status = SlaveAddressWithWriteError;//0b 1111 1000
	}
	else
	{
		/*Do nothing*/
	}

	return Local_status;
}

/*Push/Pop Data from/to bus*/
TWI_ErrorStatus TWI_voidMasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_status = NoError;

	/*Push Data to Bus*/
	TWDR = Copy_u8DataByte;

	/*Clear interrupt flag*/
	/*Remember: Clearing this flag starts the operation of the TWI*/
	SET_BIT(TWCR, TWCR_TWINT);
	while(GET_BIT(TWCR, TWCR_TWINT)==0);

	/*Check TWI status*/
	if( (TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_status = MasterWriteByteError;//0b 1111 1000
	}
	else
	{
		/*Do nothing*/
	}

	return Local_status;
}
TWI_ErrorStatus TWI_u8MasterReadDataByte( u8* Copy_u8Data)
{
	TWI_ErrorStatus Local_status = NoError;

	/*Clear interrupt  flag*/
	/*Remember: Clearing this flag starts the operation of the TWI (Receiving slave's data)*/
	SET_BIT(TWCR, TWCR_TWINT);
	while(GET_BIT(TWCR, TWCR_TWINT)==0);

	/*Check TWI status*/
	if( (TWSR & 0xF8) != MSTR_RD_BYTE_ACK )
	{
		Local_status = MasterReadByteError;//0b 1111 1000
	}
	else
	{
		/*Store Data*/
		*Copy_u8Data = TWDR;
	}

	return Local_status;
}


