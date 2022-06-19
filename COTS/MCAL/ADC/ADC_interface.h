#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
#include "../../lib/stdtypes.h"

#define PRESCALAR_DIV_2			1
#define PRESCALAR_DIV_4			2
#define PRESCALAR_DIV_8			3
#define PRESCALAR_DIV_16		4
#define PRESCALAR_DIV_32		5
#define PRESCALAR_DIV_64		6
#define PRESCALAR_DIV_128		7

#define CHANNEL_0		0
#define CHANNEL_1		1
#define CHANNEL_2		2
#define CHANNEL_3		3
#define CHANNEL_4		4
#define CHANNEL_5		5
#define CHANNEL_6		6
#define CHANNEL_7		7

void ADC_voidInit(void);
u8 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNum);
u16 ADC_u16StartConversionAsynchronous(u8 Copy_u8ChannelNum);
void ADC_voidAssignDivisionFactor(u8 Copy_DivisionFactor);
void ADC_SetCallBack( void (*Copy_pvNotificationFunction) (void) );




#endif
