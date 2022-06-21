/*
 * KEYPAD_program.c
 *
 *  Created on: Sep 6, 2021
 *      Author: ahmad
 */

#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

void KEYPAD_Init(void){
	DIO_SetPortDirection(DIO_PORTD, 0x0f);//define PORT and Connection
	DIO_SetPortValue(DIO_PORTD , 0xff);


}

u8 KEYPAD_LastPressedKey(void){
	u8 pressedKey = 0;
	for(int col = 0 ; col < 4 ; col++){
		//define columns as 4
		DIO_SetPinValue(DIO_PORTD, col, 0);
		for(int row = 0 ; row < 4 ; row++ ){
			//def rows as 4
			if(DIO_GetPinValue(DIO_PORTD, row + 4) == 0){
				pressedKey = (col+1) + (row*4) ;//no. of col as 4
			}
			while(DIO_GetPinValue(DIO_PORTD, row+4) == 0){}
			_delay_ms(9);
		}
		DIO_SetPinValue(DIO_PORTD, col, 1);
	}
	return pressedKey;

}

