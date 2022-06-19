#ifndef _GIE_PRIVATE_H_
#define _GIE_PRIVATE_H_

//GLOBAL INTERUPT ENABLE 
//$3F ($5F) SREG I T H S V N Z C 8
#define SREG (*( (volatile u8*) (0x5F)   ))

//SREG I T H S V N Z C 
#define SREG_I 	7
#define SREG_T 	6
#define SREG_H 	5
#define SREG_S 	4
#define SREG_V 	3
#define SREG_N 	2
#define SREG_Z 	1
#define SREG_C 	0






#endif