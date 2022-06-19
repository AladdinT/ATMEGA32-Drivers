#ifndef _TIMERS_PRIVATE_H_
#define _TIMERS_PRIVATE_H_



#define PRESCALER_MASK		(0b11111000)
#define MODE_MASK			(0b10110111)
#define COMPARE_OUTPUT_MASK	(0b11001111)

#define NULL  			((void*)0)
#define _8MHz			(8000000)

#define DOWN 			(0)

//Timer/Counter Control Register – TCCR0
//$33 ($53) TCCR0 
#define  TCCR0		( *( (volatile u8*) (0x53) ) )
//Timer/Counter Register – TCNT0
//$32 ($52) TCNT0 Timer/Counter0 (8 Bits)
#define  TCNT0		( *( (volatile u8*) (0x52) ) )
//Output Compare Register – OCR0
//$3C ($5C) OCR0 Timer/Counter0 Output Compare Register 
#define  OCR0		( *( (volatile u8*) (0x5C) ) )
//Timer/Counter Interrupt Mask Register – TIMSK
//$39 ($59) TIMSK 
#define  TIMSK		( *( (volatile u8*) (0x59) ) )
//Timer/Counter Interrupt Flag Register – TIFR
//$38 ($58) TIFR
#define  TIFR		( *( (volatile u8*) (0x58) ) )

//TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 
#define TCCR0_FOC0		7
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02		2
#define TCCR0_CS01		1
#define TCCR0_CS00		0

//TCNT0 Timer/Counter0 (8 Bits)
#define	TCNT_7			7
#define	TCNT_6			6
#define	TCNT_5			5
#define	TCNT_4			4
#define	TCNT_3			3
#define	TCNT_2			2
#define	TCNT_1			1
#define	TCNT_0			0


//TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 
#define TIMSK_OCIE2			7
#define TIMSK_TOIE2			6
#define TIMSK_TICIE1		5
#define TIMSK_OCIE1A		4
#define TIMSK_OCIE1B		3
#define TIMSK_TOIE1			2
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0

//TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 
#define	TIFR_OCF2		7
#define	TIFR_TOV2		6
#define	TIFR_ICF1		5
#define	TIFR_OCF1A		4
#define	TIFR_OCF1B		3
#define	TIFR_TOV1		2
#define	TIFR_OCF0		1
#define	TIFR_TOV0		0

#endif
