#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
#include "../../lib/stdtypes.h"

void EXTI_voidInit(void);

void EXTI_voidINT0Status (u8 Copy_u8InterruptStatus);
void EXTI_voidINT1Status (u8 Copy_u8InterruptStatus);
void EXTI_voidINT2Status (u8 Copy_u8InterruptStatus);

void EXTI_voidSetINT0SenceControl (u8 Copy_u8Scence);
void EXTI_voidSetINT1SenceControl (u8 Copy_u8Scence);
void EXTI_voidSetINT2SenceControl (u8 Copy_u8Scence);

void EXTI_INT0SetCallBack( void (*Copy_pvNotificationFunction) (void) );
void EXTI_INT1SetCallBack( void (*Copy_pvNotificationFunction) (void) );
void EXTI_INT2SetCallBack( void (*Copy_pvNotificationFunction) (void) );

#define LOW_LEVEL		0
#define HIGH_LEVEL		1
#define RISING_EDGE		2
#define FALLING_EDGE	3

#define INT0_DISABLE	0
#define INT0_ENABLE		1

#define INT1_DISABLE	0
#define INT1_ENABLE		1

#define INT2_DISABLE	0
#define INT2_ENABLE		1

#endif
