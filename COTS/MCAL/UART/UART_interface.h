/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART_interface.h
 *       Module:  Universal Asynchronous Transmitter Receiver (UART)
 *
 *  Description:  This file has : -all macros that users may need
 *  							  -Module Functions description and declarations
 *  Created on: 	Oct 5, 2021
 *  Latest update : Oct 9, 2022
 *  Author : Ahmad Tohamy
 *********************************************************************************************************************/

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Name 	   : UART_voidInit()
 * Description : initialize UART with pre-configured parameter
 * 				 (FOR THE MOMENT : uart is initialized to connect with HC-05 Bluetooth module)
 * 				 TODO : 1) Make this driver configurable 2) Create BT driver at HAL layer
 * Arguments   : TODO : configured with UART_config.h
 * return      : void
 */
void UART_voidInit(void);

/*
 * Name		   : UART_u8ReceiveAsynchronous()
 * Description : synchronous function that receives 1 byte over UART
 * Arguments   : void
 * return      : u8 received byte
 */
u8 UART_u8ReceiveAsynchronous(void);




void UART_voidTransmitAsynchronous( u8 Copy_u8Data );
void UART_voidReceiveString(u8 *str);
void UART_voidTransmitString(u8 *str);
void UART_voidTransmitNumber(s32 Copy_u32Number);


#endif /* MCAL_UART_UART_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: UART_interface.h
 *********************************************************************************************************************/
