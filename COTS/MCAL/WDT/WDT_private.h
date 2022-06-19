/*
 * WDT_private.h
 *
 *  Created on: Sep 30, 2021
 *      Author: ahmad
 */

#ifndef MCAL_WDT_WDT_PRIVATE_H_
#define MCAL_WDT_WDT_PRIVATE_H_


#define WDT_PRESCALER_MASK	0b11111000;
//$21 ($41) WDTCR
#define WDTCR 	( *(volatile u8*) (0x41) )


//WDTCR – – – WDTOE WDE WDP2 WDP1 WDP0

#define WDTCR_WDTOE 	4
#define WDTCR_WDE		3
#define WDTCR_WDP2		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0



#endif /* MCAL_WDT_WDT_PRIVATE_H_ */
