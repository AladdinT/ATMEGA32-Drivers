/*
 * BUT_program.c
 *
 *  Created on: Sep 6, 2021
 *      Author: ahmad
 */
#include "../DIO/DIO_interface.h"
#include "BUT_config.h"
#include <util/delay.h>

#define DELAY (_delay_ms(10))
void Buttons_Init(void){
	DIO_SetPinDirection(Button1_Pin, 0);
	DIO_SetPinDirection(Button2_Pin, 0);
	DIO_SetPinDirection(Button3_Pin, 0);

	DIO_SetPinValue(Button1_Pin, 1);
	DIO_SetPinValue(Button2_Pin, 1);
	DIO_SetPinValue(Button3_Pin, 1);


}
u8 Button_Pressed(void){
	u8 ret = 0;
	if( DIO_GetPinValue( Button1_Pin )== 0 ){
		while(DIO_GetPinValue(Button1_Pin)== 0){
		}
		DELAY;
		ret = 1;
	}else if( DIO_GetPinValue( Button2_Pin )== 0 ){
		while(DIO_GetPinValue( Button2_Pin )== 0){
		}
		DELAY;
		ret = 2;
	}else if( DIO_GetPinValue( Button3_Pin )== 0 ){
		while(DIO_GetPinValue( Button3_Pin )== 0){
		}
		DELAY;
		ret = 3;
	}
	return ret;

}


