#include "../../../LIB/stdtypes.h"
#include "../../../LIB/bitmath.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"


void TIMER_voidInit(void)
{
	#if TIMER0_ENABLE == ENABLE
		
		//Interrupt Enable
		#if TIMER0_INTERRUPT_ENABLE == ENABLE
			
			//TIMSK Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
			SET_BIT( TIMSK , TIMSK_TOIE0 );

		#elif	TIMER0_INTERRUPT_ENABLE == DISABLE
			CLR_BIT( TIMSK , TIMSK_TOIE0 );
		#else
			#error " TIMER0_INTERRUPT_ENABLE Configuration Error "
		#endif
		
		//Mode Selection
		//TCCR0•Bit 6, 3 – WGM01:0: Waveform Generation Mode
		TCCR0 &= MODE_MASK;
		TCCR0 |= TIMER0_MODE;

#if TIMER0_MODE  == CTC
		OCR0 = OCR0_INIT;
#endif
		//Compare Output Mode Selection
		//TCCR0• Bit 5:4 – COM01:0: Compare Match Output Mode
		TCCR0 &= COMPARE_OUTPUT_MASK ;
		TCCR0 |= COMPARE_OUTPUT_MODE ;

		#if		TIMER0_OCI_ENABLE == ENABLE
			//Timer/Counter Interrupt Mask Register – TIMSK
			//• Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
			SET_BIT(TIMSK , TIMSK_OCIE0 );
		#elif	TIMER0_OCI_ENABLE == DISABLE
			CLR_BIT(TIMSK , TIMSK_OCIE0 );
		#else
			#error " TIMER0_OCI_ENABLE Configuration Error "
		#endif
		//Setting Prescaler
		//BitMasking CS02	CS01	CS00 
		TCCR0 &= PRESCALER_MASK;
		TCCR0 |= TIMER0_PRESCALER;
		


			
	#elif	TIMER0_ENABLE == DISABLE
		//Assgin
		//CS02	CS01	CS00 
		//	0 	 0 		 0 
		//No clock source (Timer/Counter stopped)
		TCCR0 &= PRESCALER_MASK;
	#else 
		#error "TIMER0_ENABLE Configuration Error"
	#endif
	
	#if TIMER1_ENABLE == ENABLE

		//Interrupt Enable
		#if TIMER1_INTERRUPT_ENABLE == ENABLE

			//TIMSK Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
			SET_BIT( TIMSK , TIMSK_TOIE0 );

		#elif	TIMER0_INTERRUPT_ENABLE == DISABLE
			CLR_BIT( TIMSK , TIMSK_TOIE0 );
		#else
			#error " TIMER0_INTERRUPT_ENABLE Configuration Error "
		#endif

		//Mode Selection
		//TCCR0•Bit 6, 3 – WGM01:0: Waveform Generation Mode
		TCCR0 &= MODE_MASK;
		TCCR0 |= TIMER0_MODE;


		//Setting Prescaler
		//BitMasking CS02	CS01	CS00
		TCCR0 &= PRESCALER_MASK;
		TCCR0 |= TIMER0_PRESCALER;


	#elif	TIMER1_ENABLE == DISABLE
		//Assgin
		//CS02	CS01	CS00
		//	0 	 0 		 0
		//No clock source (Timer/Counter stopped)
		//TCCR1 &= PRESCALER_MASK;
	#else
		#error "TIMER0_ENABLE Configuration Error"
	#endif
	
}

void TIMER_voidTimer0Init(u8 Copy_u8TimerMode)
{
	if(Copy_u8TimerMode == NORMAL || Copy_u8TimerMode == CTC || Copy_u8TimerMode == FAST_PWM ||Copy_u8TimerMode == PHASE_CORRECT_PWM)
	{	
		//Mode Selection
		//TCCR0•Bit 6, 3 – WGM01:0: Waveform Generation Mode
		TCCR0 &= MODE_MASK;
		TCCR0 |= Copy_u8TimerMode;
	}else{
		//return Error Status
	}
}

void TIMER_voidSetBusyWait( u8 Copy_u8Seconds )
{
	/*waits for the given times */


	//A holder to return OCR0 value as it was
	u8 OCR0_Holder = OCR0;

	//Set an assumed compare match value
	OCR0 = 100;
	//Calculate Tick Time = (Prescaler / CPU_Clock_Frequency )
//	u16 Prescaler = TCCR0 & (0b0000000000000111);
//	switch(Prescaler)
//	{
//		case 1 :
//			Prescaler = 1;
//			break;
//		case 2 :
//			Prescaler = 8;
//			break;
//		case 3 :
//			Prescaler = 64;
//			break;
//		case 4 :
//			Prescaler = 256;
//			break;
//		case 5 :
//			Prescaler = 1024;
//			break;
//
//		//if the prescaler bits are assigned otherwise
//		//Make the prescaler DIV_BY_8
//		default:
//			Prescaler = 8;
//			TCCR0 &= PRESCALER_MASK;
//			TCCR0 |= DIV_BY_8;
//			break;
//
//	}

	u8 Prescaler = 8;
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= DIV_BY_8;
	f32 TickTime = ( (f32) Prescaler / CPU_CLOCK_FREQ );
	//Calculate CTC tick time = TOP_value_OCR * TickTime
	f32 CTC_TickTime = OCR0 * TickTime ;
	//Number of ctc = (Required_Time / CTC ticktime)
	f32 C_ctc = ( Copy_u8Seconds / CTC_TickTime );
	u16 BusyWaitCounter = 0;
	//waits for the number of CTCs required
	while( BusyWaitCounter < C_ctc ){
		//The Flag is located at Timer Interrupt Flag Register
		//TIFR-Bit1 OCF0 Output Compare Flag 0


		//waits till the flag is down
		//which indicates one cycle
		while( GET_BIT(TIFR , TIFR_OCF0) == DOWN);
		SET_BIT(TIFR , TIFR_OCF0);
		BusyWaitCounter++;
	}
	//Once everything is done
	//Lets return OCR0 to its value
	OCR0 = OCR0_Holder ;
}

void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareValue)
{
	//Output Compare Register – OCR0
	OCR0 = Copy_u8CompareValue ;
}

void TIMER_Timer0SetTCNT(u8 Copy_u8TCNT)
{
	TCNT0 = Copy_u8TCNT;
}
void (*Global_pvTimerCallBack[4]) (void) = {NULL, NULL , NULL , NULL };

void TIMER_voidTimer0SetCallBack( void (*Copy_pvTimer0CallBack) (void) )
{

	Global_pvTimerCallBack[0] = Copy_pvTimer0CallBack ;
}


//ISR( TIMER0 COMPARE MATCH INTERUPT )
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvTimerCallBack[0] != NULL )
	{
		/*execute passed function*/
		Global_pvTimerCallBack[0]();
	}
	else
	{
		/*Do Nothing*/
	}
}
