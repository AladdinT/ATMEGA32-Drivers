/*
 * RTOS_private.h
 *
 *  Created on: Oct 20, 2021
 *      Author: ahmad
 */

#ifndef SERVICE_RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#define SERVICE_RTOS_STACK_RTOS_RTOS_PRIVATE_H_

typedef struct {

	u8	Priority;
	u16 Periodicity;
	void (*TaskFunction) (void) ;
}Tasks_t;

static void voidScheduler (void);

#define NULL (void*)0

#endif /* SERVICE_RTOS_STACK_RTOS_RTOS_PRIVATE_H_ */
