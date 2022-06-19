#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

#define ENABLE		1
#define DISABLE		0

#define DIV_BY_0		0
#define DIV_BY_1		1
#define DIV_BY_8		2
#define DIV_BY_64		3
#define DIV_BY_256		4
#define DIV_BY_1024		5

#define RISING			1
#define FALLING			0

#define NORMAL						0
									//b76543210
#define PHASE_CORRECT_PWM			(0b01000000)
#define CTC							(0b00001000)
#define FAST_PWM					(0b01001000)

#define SET_ON_TOP					(0b00100000)
#define CLR_ON_TOP					(0b00110000)



void TIMER_voidInit(void);
void TIMER_voidTimer0Init (u8 Copy_u8TimerMode);
void TIMER_voidSetBusyWait( u8 Copy_u8Seconds );
void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareValue);
void TIMER_Timer0SetTCNT(u8 Copy_u8TCNT);
void TIMER_voidTimer0SetCallBack( void (*Copy_pvTimer0CallBack) (void) );



#endif
