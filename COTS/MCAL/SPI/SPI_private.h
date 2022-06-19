/*
 * SPI_private.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ahmad
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define CLOCK_RATE_MASK		0b11111100
#define DOUBLE_SPEED_MASK	0b11111110

/*$0D ($2D) SPCR */
#define SPCR   		(	*(volatile u8*)	(0x2D)	 )
/*$0E ($2E) SPSR */
#define SPSR   		(	*(volatile u8*)	(0x2E)	 )
/*$0F ($2F) SPDR */
#define SPDR   		(	*(volatile u8*)	(0x2F)	 )



/*SPCR: SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0*/
#define SPCR_SPIE		7
#define SPCR_SPE		6
#define SPCR_DORD		5
#define SPCR_MSTR		4
#define SPCR_CPOL		3
#define SPCR_CPHA		2
#define SPCR_SPR1		1
#define SPCR_SPR0		0
/*SPSR: SPIF WCOL – – – – – SPI2X */
#define SPSR_SPIF		7
#define SPSR_WCOL		6
#define SPSR_SPI2X		0

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
