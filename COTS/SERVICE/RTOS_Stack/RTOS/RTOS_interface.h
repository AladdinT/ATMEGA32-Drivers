/*
 * RTOS_interface.h
 *
 *  Created on: Oct 20, 2021
 *      Author: ahmad
 */

#ifndef SERVICE_RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#define SERVICE_RTOS_STACK_RTOS_RTOS_INTERFACE_H_



void RTOS_voidCreateTask( u8 Copy_u8Priority ,  u16 Copy_u16Periodicity , void (*Copy_pvTaskFunction) (void)  );

void RTOS_voidInit(void);

#endif /* SERVICE_RTOS_STACK_RTOS_RTOS_INTERFACE_H_ */
