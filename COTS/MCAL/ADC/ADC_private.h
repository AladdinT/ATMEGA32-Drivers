
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
//ADC Multiplexer Selection Register
//$07 ($27) ADMUX
#define ADMUX  ( *( (volatile u8*) (0x27) ) )

//ADMUX REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0
#define ADMUX_REFS1		7
#define ADMUX_REFS0		6
#define ADMUX_ADLAR		5
#define ADMUX_MUX4		4
#define ADMUX_MUX3		3
#define ADMUX_MUX2		2
#define ADMUX_MUX1		1
#define ADMUX_MUX0		0

//ADC Control and Status Register A
//$06 ($26)  ADCSRA
#define ADCSRA  ( *( (volatile u8*) (0x26) ) )

//ADCSRA ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0
#define ADCSRA_ADEN			7
#define ADCSRA_ADSC			6
#define ADCSRA_ADATE		5
#define ADCSRA_ADIF			4
#define ADCSRA_ADIE			3
#define ADCSRA_ADPS2		2
#define ADCSRA_ADPS1		1
#define ADCSRA_ADPS0		0

//The ADC Data Registers
//$05 ($25) ADCH ADC Data Register High Byte
#define ADCH  ( *( (volatile u8*) (0x25) ) )

//$04 ($24) ADCL ADC Data Register Low Byte 215
#define ADCL  ( *( (volatile u8*) (0x24) ) )

//Special FunctionIO Register – SFIOR
//$30 ($50) SFIOR
#define SFIOR  ( *( (volatile u8*) (0x50) ) )

//SFIOR ADTS2 ADTS1 ADTS0
#define SFIOR_ADTS2			7
#define SFIOR_ADTS1			6
#define SFIOR_ADTS0			5


//Define the NULL pointer
#define NULL	((void*)0)


#define PRESCALAR_MASK		0xf8//0b1111 1000
#define	MULTIPLIXER_MASK	0b11100000
#define BUSY     			1
#define NOT_BUSY			0
#endif
