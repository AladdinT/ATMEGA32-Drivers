/*
 * SPI_interface.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ahmad
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/*Data Order Parameters*/
#define LSB_1ST			0
#define MSB_1ST			7

/*Clock Polarity Parameters*/
#define LEADING_EDGE_RISING				0
#define TRAILING_EDGE_FALLING			0
#define LEADING_EDGE_FALLING			1
#define TRAILING_EDGE_RISING			1

/*Clock Phase Parameters*/
#define LEADING_EDGE_SAMPLE				0
#define TRAILING_EDGE_SETUP				0
#define LEADING_EDGE_SETUP				1
#define TRAILING_EDGE_SAMPLE			1

/*SPI Clock Rate*/
#define Fosc_DIV_BY_4					0
#define Fosc_DIV_BY_16					1
#define Fosc_DIV_BY_64					2
#define Fosc_DIV_BY_128					3

/*Double SPI Speed*/
#define ENABLE 				1
#define DISABLE 			0

void SPI_voidSlaveInit(void);
void SPI_voidMasterInit(void);
u8	 SPI_u8Transceive(u8 Copy_u8DataToSend);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
