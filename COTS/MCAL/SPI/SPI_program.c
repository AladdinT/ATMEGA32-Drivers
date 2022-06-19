/*
 * SPI_program.c
 *
 *  Created on: Oct 11, 2021
 *      Author: ahmad
 */

#include "../../LIB/bitmath.h"
#include "../../LIB/stdtypes.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidSlaveInit(void)
{

	/*Set Data Order*/
	#if	DATA_ORDER	==	LSB_1ST
		SET_BIT(SPCR , SPCR_DORD);
	#elif DATA_ORDER	==	MSB_1ST
		CLR_BIT(SPCR , SPCR_DORD);
	#else
		#error "INVALID DATA ORDER"
	#endif

	/*Clock Polarity*/
	#if CLOCK_POLARITY	    ==	LEADING_EDGE_RISING
		CLR_BIT(SPCR , SPCR_CPOL);
	#elif	CLOCK_POLARITY	==	LEADING_EDGE_FALLING
		SET_BIT(SPCR , SPCR_CPOL);
	#else
		#error "INVALID CLOCK POLARITY"
	#endif

	/*Clock Phase Functionality*/
	#if CLOCK_PHASE	    ==	LEADING_EDGE_SAMPLE
		CLR_BIT(SPCR , SPCR_CPHA);
	#elif	CLOCK_PHASE	==	LEADING_EDGE_SETUP
		SET_BIT(SPCR , SPCR_CPHA);
	#else
		#error "INVALID CLOCK PHASE"
	#endif

	/*SPI mode : Slave*/
	CLR_BIT(SPCR , SPCR_MSTR);


	/*Enable SPI*/
	SET_BIT(SPCR , SPCR_SPE);

}

void SPI_voidMasterInit(void)
{

	/*Set Data Order*/
	#if	DATA_ORDER	==	LSB_1ST
		SET_BIT(SPCR , SPCR_DORD);
	#elif DATA_ORDER	==	MSB_1ST
		CLR_BIT(SPCR , SPCR_DORD);
	#else
		#error "INVALID DATA ORDER"
	#endif

	/*Clock Polarity*/
	#if CLOCK_POLARITY	    ==	LEADING_EDGE_RISING
		CLR_BIT(SPCR , SPCR_CPOL);
	#elif	CLOCK_POLARITY	==	LEADING_EDGE_FALLING
		SET_BIT(SPCR , SPCR_CPOL);
	#else
		#error "INVALID CLOCK POLARITY"
	#endif

	/*Clock Phase Functionality*/
	#if CLOCK_PHASE	    ==	LEADING_EDGE_SAMPLE
		CLR_BIT(SPCR , SPCR_CPHA);
	#elif	CLOCK_PHASE	==	LEADING_EDGE_SETUP
		SET_BIT(SPCR , SPCR_CPHA);
	#else
		#error "INVALID CLOCK PHASE"
	#endif

	/*SPI Clock Rate (Prescaler) */
	SPCR  &= CLOCK_RATE_MASK;
	SPCR  |= CLOCK_RATE;

	/*Double SPI Speed*/
	SPSR &=	DOUBLE_SPEED_MASK;
	SPSR |= DOUBLE_SPEED;

	/*Maximum Frequency Exceeded*/
	#if	(CLOCK_RATE == Fosc_DIV_BY_4) && (DOUBLE_SPEED == ENABLE)
		#warning " When SPI is configured as Slave, it is only guaranteed to work at fosc/4 or lower "
	#endif

	/*SPI mode : Master*/
	SET_BIT(SPCR , SPCR_MSTR);


	/*Enable SPI*/
	SET_BIT(SPCR , SPCR_SPE);

}

u8	 SPI_u8Transceive(u8 Copy_u8DataToSend)
{
	/*Send Data*/
	SPDR  = Copy_u8DataToSend;

	/*Wait until transfer is complete*/
	while( GET_BIT(SPSR , SPSR_SPIF) == 0);

	/*Return received data*/
	return SPDR;
}


void __vector_12 (void)	__attribute__((signal));
void __vector_12 (void)
{

}

