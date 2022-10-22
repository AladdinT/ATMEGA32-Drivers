#include "../../lib/stdtypes.h"
#include "../../lib/bitmath.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
void ADC_voidInit(void)
{
//ADMUX
	//Bit 5 – ADLAR: ADC Left Adjust Result
	SET_BIT(ADMUX , ADMUX_ADLAR );

#if VOLTAGE_REFERENCE == AVCC
	//REFS1 REFS0 Voltage Reference Selection
	//0 1 AVCC with external capacitor at AREF pin
	CLR_BIT( ADMUX , ADMUX_REFS1);
	SET_BIT( ADMUX , ADMUX_REFS0);
#elif VOLTAGE_REFERENCE == AREF
	CLR_BIT( ADMUX , ADMUX_REFS1);
	CLR_BIT( ADMUX , ADMUX_REFS0);
#elif VOLTAGE_REFERENCE ==	INTERNAL_2_56V
	SET_BIT( ADMUX , ADMUX_REFS1);
	SET_BIT( ADMUX , ADMUX_REFS0);
#endif

	//Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits	
	ADCSRA &= PRESCALAR_MASK;	//Clear Last 3-Bits
	ADCSRA |= ADC_PRESCALAR;	//Sets the last 3-Bits as prescalar value

//ADCSRA
	//Bit 7 – ADEN: ADC Enable
	SET_BIT( ADCSRA , ADCSRA_ADEN );
	//Bit 3 – ADIE: ADC Interrupt Enable
	SET_BIT( ADCSRA , ADCSRA_ADIE );


}


void ADC_voidAssignDivisionFactor(u8 Copy_DivisionFactor)
{
	if(Copy_DivisionFactor <= 7)
	{
		//Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
		
		ADCSRA &= PRESCALAR_MASK;	//Clear Last 3-Bits
		ADCSRA |= Copy_DivisionFactor;	//Sets the last 3-Bits as prescalar value
	}
}

u8 Global_AdcState = NOT_BUSY;

u16 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNum)
{
	if(Global_AdcState == BUSY){
		return 0;
	}else{
		u16 Local_u16DigitalOutput = 0 ;
		u8 ADCH_v;
		u8 ADCL_v;

		Global_AdcState = BUSY ;
		//Assign Channel Number to ADMUX Register BY BIT MASKING
		ADMUX 	&= 	MULTIPLIXER_MASK;	//Clear Last 5-Bits`
		ADMUX 	|= 	Copy_u8ChannelNum;	//Sets the last 5-Bits as ChannelNum 

		//ADCSRA
		//Bit 6 – ADSC: ADC Start Conversion
		SET_BIT( ADCSRA , ADCSRA_ADSC );
		
		//Busy wait 
		//wait until conversion is done (when ADC flag is raised)
		//ADCSRA - Bit 4 – ADIF: ADC Interrupt Flag
		while(GET_BIT(ADCSRA , ADCSRA_ADIF) == 0);
		
		//Clear Flag
		SET_BIT(ADCSRA , ADCSRA_ADIF);
		
		Global_AdcState = NOT_BUSY ;
		
		/*Return all of the 10 bits*/
		ADCL_v = ADCL;
		ADCH_v = ADCH;


		Local_u16DigitalOutput = (ADCH_v << 2) | (ADCL_v >> 6);
		
		return Local_u16DigitalOutput;
	}
	

}

u16 ADC_u16StartConversionAsynchronous(u8 Copy_u8ChannelNum)
{
	//ADCSRA
	//Bit 6 – ADSC: ADC Start Conversion
	SET_BIT( ADCSRA , ADCSRA_ADSC );
	return 0;
}

//Global pointer to function
void (*Global_pvNotificationFunction) (void) =  NULL;

//pv -> Pointer to void
void ADC_SetCallBack( void (*Copy_pvNotificationFunction) (void) )
{
		Global_pvNotificationFunction = Copy_pvNotificationFunction;

}
//Vector P.Address  Source  	Interrupt Definition
//  16 	   $020	   	 ADC 		ADC Conversion Complete
//InterruptServiceRoutine();
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(Global_pvNotificationFunction != NULL ){
		Global_pvNotificationFunction();
	}
}

