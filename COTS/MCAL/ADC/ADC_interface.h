/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ADC_interface.h
 *       Module:  Analog to Digital Converter (ADC)
 *
 *  Description:  This file has : -all macros that users may need
 *  							  -Module Functions description and declarations
 *  Created on: 	Sep 22, 2021
 *  Latest update : Oct 22, 2022
 *  Author : Ahmad Tohamy
 *********************************************************************************************************************/

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lib/stdtypes.h"

/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
/*Voltage Reference Configurations*/
/*IMT kit has AVCC already connected to VCC  
 *and AREF connected to the external capacitor*/
#define AVCC					1
#define AREF					2
#define INTERNAL_2_56V			3

/*Prescalar Options (Pre/Post build configuration)*/
#define PRESCALAR_DIV_2			1
#define PRESCALAR_DIV_4			2
#define PRESCALAR_DIV_8			3
#define PRESCALAR_DIV_16		4
#define PRESCALAR_DIV_32		5
#define PRESCALAR_DIV_64		6
#define PRESCALAR_DIV_128		7

/*Supported ADC channels ATM*/
#define CHANNEL_0		0
#define CHANNEL_1		1
#define CHANNEL_2		2
#define CHANNEL_3		3
#define CHANNEL_4		4
#define CHANNEL_5		5
#define CHANNEL_6		6
#define CHANNEL_7		7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Name   		: ADC_voidInit
 * Description 	: Initializes ADC peripheral with desired configurations regarding
 *				  (Left Adjustment, Voltage Reference, Prescalar value, ADC Enable, ADC Interrupt Enable)	
 * Arguments   	: Macros defined at ADC_config.h 
 * return      	: void
 */
void ADC_voidInit(void);


/*
 * Name   		: ADC_u8StartConversionSynchronous
 * Description 	: If ADC is not busy, Start conversion and Poll untill it is done
 * Arguments   	: Copy_u8ChannelNum:  takes only DIO_PORTA, DIO_PORTB, DIO_PORTC,  DIO_PORTD
 * return      	: returns the 10 bits of the Digitalized Data
 */
u16 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNum);


u16 ADC_u16StartConversionAsynchronous(u8 Copy_u8ChannelNum);
void ADC_voidAssignDivisionFactor(u8 Copy_DivisionFactor);
void ADC_SetCallBack( void (*Copy_pvNotificationFunction) (void) );


#endif /* ADC_INTERFACE_H_ */

/**********************************************************************************************************************
*  END OF FILE: ADC_interface.h
*********************************************************************************************************************/

