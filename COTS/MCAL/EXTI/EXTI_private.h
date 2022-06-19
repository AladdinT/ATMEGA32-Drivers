#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_
#include "../../lib/stdtypes.h"
//$35 ($55) MCUCR
#define MCUCR (*( (volatile u8*) (0x55)   ))
//MCUCR SE SM2 SM1 SM0 ISC11 ISC10 ISC01 ISC00
#define MCUCR_SE		7
#define MCUCR_SM2		6
#define	MCUCR_SM1		5
#define MCUCR_SM0		4
#define MCUCR_ISC11		3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0

//$34 ($54) MCUCSR
#define MCUCSR (*( (volatile u8*) (0x54)   ))
//MCUCSR JTD ISC2 – JTRF WDRF BORF EXTRF PORF
#define MCUCSR_JTD		7
#define MCUCSR_ISC2		6

#define MCUCSR_JTRF		4
#define MCUCSR_WDRF		3
#define MCUCSR_BORF		2
#define MCUCSR_EXTRF	1
#define MCUCSR_PORF		0

//$3B ($5B) GICR 
#define GICR (*( (volatile u8*) (0x5B)   ))
//GICR INT1 INT0 INT2 – – – IVSEL IVCE 
#define GICR_INT1	7
#define GICR_INT0	6
#define GICR_INT2	5

#define GICR_IVSEL	1
#define GICR_IVCE	0


//$3A ($5A) GIFR
#define GIFR (*( (volatile u8*) (0x5A)   ))
//GIFR INTF1 INTF0 INTF2 – – – – – 
#define GIFR_INTF1	7
#define GIFR_INTF0	6
#define GIFR_INTF2	5

//PRIVATE DEFINES
#define EXTI_DISABLE	0
#define EXTI_ENABLE		1

//Define the NULL pointer
#define NULL	((void*)0)

#endif
