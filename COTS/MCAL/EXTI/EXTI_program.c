#include "../../lib/stdtypes.h"
#include "../../lib/bitmath.h"
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void EXTI_voidInit(void)
{
#if INT0_STATUS	==	EXTI_ENABLE	

	//ISC01 ISC00 1 0 The falling edge of INT0 generates an interrupt request.
	SET_BIT(MCUCR , MCUCR_ISC01);
	CLR_BIT(MCUCR , MCUCR_ISC00);
	
	//GICR Bit 6 – INT0: External Interrupt Request 0 Enable
	SET_BIT(GICR, GICR_INT0);
	
	//Enable Global Interrupt
	//	GIE_voidEnableGlobalInterrupt();


#elif	INT0_STATUS	==	EXTI_DISABLE
	//GICR Bit 6 – INT0: External Interrupt Request 0 Enable
	CLR_BIT(GICR, GICR_INT0);
#else
	#error "ERROR : INT0_STATUS"
#endif

#if INT1_STATUS	==	EXTI_ENABLE	
	//MCU Control Register – MCUCR
	//ISC11 ISC10
	//	1 	0
	//The falling edge of INT1 generates an interrupt request.
	SET_BIT(MCUCR , MCUCR_ISC11);
	CLR_BIT(MCUCR , MCUCR_ISC10);

//	General Interrupt Control Register – GICR
//• Bit 7 – INT1: External Interrupt Request 1 Enable
	SET_BIT(GICR, GICR_INT1);
	
	//Enable Global Interrupt
	GIE_voidEnableGlobalInterrupt();
#elif	INT1_STATUS	==	EXTI_DISABLE
//	General Interrupt Control Register – GICR
//• Bit 7 – INT1: External Interrupt Request 1 Enable
	CLR_BIT(GICR, GICR_INT1);
#else
	#error "ERROR : INT0_STATUS"
#endif


#if INT2_STATUS	==	EXTI_ENABLE	

	//MCU Control and Status Register – MCUCSR
	//• Bit 6 – ISC2: Interrupt Sense Control 2
	// If ISC2 is written to (zero), a
	//	falling edge on INT2 activates the interrupt.
	//, it is recommended to first disable INT2 by clearing
	//	its Interrupt Enable bit in the GICR Register.
	CLR_BIT(GICR, GICR_INT2);
	//	Then, the ISC2 bit can be changed
	CLR_BIT(MCUCSR , MCUCSR_ISC2);


	//General Interrupt Control Register – GICR
	//• Bit 5 – INT2: External Interrupt Request 2 Enable
	SET_BIT(GICR, GICR_INT2);
	
	
	//Enable Global Interrupt
	GIE_voidEnableGlobalInterrupt();

#elif	INT2_STATUS	==	EXTI_DISABLE
	//General Interrupt Control Register – GICR
	//• Bit 5 – INT2: External Interrupt Request 2 Enable
	CLR_BIT(GICR, GICR_INT2);

#else
	#error "ERROR : INT2_STATUS"

#endif
}



void EXTI_voidINT0Status (u8 Copy_u8InterruptStatus)
{
	if ( Copy_u8InterruptStatus	==	INT0_ENABLE	)
	{
		//GICR Bit 6 – INT0: External Interrupt Request 0 Enable
		SET_BIT(GICR, GICR_INT0);
	
	}
	else if( Copy_u8InterruptStatus	==	INT0_DISABLE)
	{
		//GICR Bit 6 – INT0: External Interrupt Request 0 Enable
		CLR_BIT(GICR, GICR_INT0);		
	}

}
void EXTI_voidINT1Status (u8 Copy_u8InterruptStatus)
{
	if ( Copy_u8InterruptStatus	==	INT1_ENABLE	)
	{
		//	General Interrupt Control Register – GICR
		//• Bit 7 – INT1: External Interrupt Request 1 Enable
		SET_BIT(GICR, GICR_INT1);
	}
	else if( Copy_u8InterruptStatus	==	INT1_DISABLE)
	{
		//	General Interrupt Control Register – GICR
		//• Bit 7 – INT1: External Interrupt Request 1 Enable
		CLR_BIT(GICR, GICR_INT1);
	}

}
void EXTI_voidINT2Status (u8 Copy_u8InterruptStatus)
{
	if ( Copy_u8InterruptStatus	==	INT1_ENABLE	)
	{
		//General Interrupt Control Register – GICR
		//• Bit 5 – INT2: External Interrupt Request 2 Enable
		SET_BIT(GICR, GICR_INT2);
	}
	else if( Copy_u8InterruptStatus	==	INT1_DISABLE)
	{
		//General Interrupt Control Register – GICR
		//• Bit 5 – INT2: External Interrupt Request 2 Enable
		CLR_BIT(GICR, GICR_INT2);
	}

}



void EXTI_voidSetINT0SenceControl (u8 Copy_u8Scence)
{
	switch(Copy_u8Scence)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
		case HIGH_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
	}
}
void EXTI_voidSetINT1SenceControl (u8 Copy_u8Scence)
{
	switch(Copy_u8Scence)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
			break;
		case HIGH_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
			break;
	}
}
void EXTI_voidSetINT2SenceControl (u8 Copy_u8Scence)
{
	/* If ISC2 is written to (zero), a (falling edge) on INT2 activates the interrupt.
	If ISC2 is written to (one), a (rising edge) on	INT2 activates the interrupt.
	Edges on INT2 are registered asynchronously*/
	switch(Copy_u8Scence){
		case RISING_EDGE:
			SET_BIT(MCUCSR, MCUCSR_ISC2);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
			break;
	}
}


//Global pointer to function
void (*Global_pvNotificationFunction[3]) (void) = { NULL , NULL , NULL};

//pv -> Pointer to void
void EXTI_INT0SetCallBack( void (*Copy_pvNotificationFunction) (void) )
{
		Global_pvNotificationFunction[0] = Copy_pvNotificationFunction;

}
void EXTI_INT1SetCallBack( void (*Copy_pvNotificationFunction) (void) )
{
		Global_pvNotificationFunction[1] = Copy_pvNotificationFunction;

}
void EXTI_INT2SetCallBack( void (*Copy_pvNotificationFunction) (void) )
{
		Global_pvNotificationFunction[2] = Copy_pvNotificationFunction;

}
//VectorNo. ProgAddress Source
//	1 			$002 	INT0

//InterruptServiceRoutine();
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(Global_pvNotificationFunction != NULL ){
		Global_pvNotificationFunction[0]();
	}
}

//VectorNo. ProgAddress Source
//	2 			$004 	INT1

//ISR();
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(Global_pvNotificationFunction != NULL ){
			Global_pvNotificationFunction[1]();
		}
}

//VectorNo. ProgAddress Source
//	3 			$006 	INT2

//ISR();
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(Global_pvNotificationFunction != NULL ){
			Global_pvNotificationFunction[2]();
		}
}

