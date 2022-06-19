/*
 * WDT_interface.h
 *
 *  Created on: Sep 30, 2021
 *      Author: ahmad
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

#define TIMEOUT_16_3ms			0
#define TIMEOUT_32_5ms			1
#define TIMEOUT_65_0ms			2
#define TIMEOUT_0_13s			3
#define TIMEOUT_0_26s			4
#define TIMEOUT_0_52s			5
#define TIMEOUT_1_0s			6
#define TIMEOUT_2_1s			7


void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleep(u8 Copy_u8TimeOut);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
