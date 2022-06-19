/*
 * WDT_program.c
 *
 *  Created on: Sep 30, 2021
 *      Author: ahmad
 */

#include "../../LIB/bitmath.h"
#include "../../LIB/stdtypes.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidEnable(void)
{


	/*Watchdog Timer Control Register */
	/*WDTCR•Bit 3 – WDE: Watchdog Enable */
	SET_BIT(WDTCR, WDTCR_WDE);

}

void WDT_voidDisable(void)
{
	WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE) ;//0b00011000
	/*within the next four clock cycles, write a logic 0 to WDE*/
	WDTCR = 0;
}

void WDT_voidSleep(u8 Copy_u8TimeOut)
{
	/*WDTCR•Bits 2:0 – WDP2,1,0: Watchdog Timer Prescaler*/
	WDTCR &= WDT_PRESCALER_MASK;
	WDTCR |= Copy_u8TimeOut;
}
