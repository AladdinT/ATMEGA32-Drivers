/*
 * SSD_program.c
 *	Seven Segment Display
 *  Created on: Aug 18, 2021
 *      Author: ahmad
 */

#include "../stdtypes.h"
#include <avr/io.h>

#include "SSD_config.h"
#include "SSD_private.h"

const u8 SSD_numbers[16] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
	0b01110111,
	0b01111100,
	0b00111001,
	0b01011110,
	0b01111001,
	0b01110001
};

void SSD_Init(void){
	SSD_DDR = 0xff ;
}

void SSD_Display( u8 n){
#if SSD_Type == COM_ANODE
	if( n<16 )
		SSD_PORT = ~SSD_numbers[n];
#elif SSD_Type == COM_CATHODE
	if( n<16 )
		SSD_PORT = SSD_numbers[n];
#endif
}
