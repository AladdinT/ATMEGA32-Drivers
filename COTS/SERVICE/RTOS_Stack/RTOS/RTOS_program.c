/*
 * RTOS_program.c
 *
 *  Created on: Oct 20, 2021
 *      Author: ahmad
 */



#include "../../../LIB/bitmath.h"
#include "../../../LIB/stdtypes.h"

#include "../GIE/GIE_interface.h"
#include "../TIMERS/TIMERS_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"


Tasks_t 		SystemTasks[SYSTEM_TASKS_NUMBER] = { {NULL} };

void RTOS_voidCreateTask( u8 Copy_u8Priority ,  u16 Copy_u16Periodicity , void (*Copy_pvTaskFunction) (void)  )
{
	SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunction = Copy_pvTaskFunction;

}

static void voidScheduler (void)
{
	static u16 Local_u16TaskCounter = 0 ;

	u8 Local_u8LoopCounter ;

	Local_u16TaskCounter++;

	for( Local_u8LoopCounter=0 ; Local_u8LoopCounter< SYSTEM_TASKS_NUMBER ; Local_u8LoopCounter++)
	{
		if( (Local_u16TaskCounter % SystemTasks[Local_u8LoopCounter].Periodicity ) == 0 )
		{
			if(SystemTasks[Local_u8LoopCounter].TaskFunction != NULL)
			{
				SystemTasks[Local_u8LoopCounter].TaskFunction();
			}
		}
	}
}
void RTOS_voidInit(void)
{

	TIMER_voidTimer0SetCompareMatchValue(125);
	TIMER_voidTimer0SetCallBack(&voidScheduler);

	GIE_voidEnableGlobalInterrupt();
	TIMER_voidInit();
}


