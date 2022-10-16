/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_interface.h
 *       Module:  Digital Input Output (DIO)
 *
 *  Description:  This file has : -all macros that users may need
 *  							  -Module Functions description and declarations
 *  Created on: 	Aug 23, 2021
 *  Latest update : Oct 9, 2022
 *  Author : Ahmad Tohamy
 *********************************************************************************************************************/

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/StdTypes.h"



/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
/*Ports A,B,C,D*/
#define DIO_PORTA 	(0)
#define DIO_PORTB 	(1)
#define DIO_PORTC 	(2)
#define DIO_PORTD 	(3)

/*Pins 0->7*/
#define DIO_PIN0 	(0)
#define DIO_PIN1 	(1)
#define DIO_PIN2 	(2)
#define DIO_PIN3 	(3)
#define DIO_PIN4 	(4)
#define DIO_PIN5 	(5)
#define DIO_PIN6 	(6)
#define DIO_PIN7 	(7)

/*Function Parameters*/
#define DIO_HIGH  		 	(1)
#define DIO_LOW  		 	(0)
#define DIO_OUTPUT	 		1
#define DIO_INPUT			0
#define DIO_PULL_UP			1
#define DIO_FLOATING		0


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Name   		: DIO_SetPinValue
 * Description 	: Sets the Value of the specified pin
 * Arguments   	: Port:     takes only DIO_PORTA, DIO_PORTB, DIO_PORTC,  DIO_PORTD
 *                Pin     : takes only DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7
 * 			      Value   : takes only DIO_HIGH, DIO_LOW
 * return      	: void
 */
void DIO_SetPinValue(u8 Port ,u8 Pin , u8 value);


/*
 * Name 		: DIO_SetPinDirection
 * Description 	: Sets the direction of the specified pin
 * Arguments   	: Port:     takes only DIO_PORTA, DIO_PORTB, DIO_PORTC,  DIO_PORTD
 *                Pin     : takes only DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7
 * 			      Direct  : takes only DIO_INPUT, DIO_OUTPUT
 * return      	: void
 */
void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direct);



void DIO_SetPortValue(u8 Port, u8 value);
void DIO_TogglePinValue(u8 Port ,u8 Pin);
u8 DIO_GetPinValue(u8 Port,u8 Pin);
u8 DIO_GetPortValue(u8 Port);

void DIO_SetPortDirection(u8 Direct , u8 value);

#endif /* DIO_DIO_INTERFACE_H_ */

/**********************************************************************************************************************
*  END OF FILE: DIO_interface.h
*********************************************************************************************************************/
