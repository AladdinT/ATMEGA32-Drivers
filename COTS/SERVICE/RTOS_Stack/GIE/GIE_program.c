#include "../../../LIB/stdtypes.h"
#include "../../../LIB/bitmath.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnableGlobalInterrupt(void)
{
	//Enables Global Interrupt
	SET_BIT(SREG, SREG_I);
}

void GIE_voidDisableGlobalInterrupt(void)
{
	//Disables Global Interrupt
	CLR_BIT(SREG, SREG_I);
}
