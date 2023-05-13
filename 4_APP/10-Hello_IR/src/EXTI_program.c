/****************************************************************/
/* Author 	: Mahmoud Karam										*/
/* Date 	: 28/08/2020										*/
/* Version	: V1												*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL	(void *)0

static void (* EXTI0_callback)	(void) = NULL;

/* LINE and Mode	*/
void MEXTI_voidInit()
{
	#if		EXTI_LINE == LINE0
			SET_BIT(EXTI -> IMR , LINE0 );
	#elif	EXTI_LINE == LINE1
			SET_BIT(EXTI -> IMR , LINE1 );
	#elif	EXTI_LINE == LINE2
			SET_BIT(EXTI -> IMR , LINE2 );
	#else
		#error ("Wrong External Interrupt Line !")
	#endif

	#if		EXTI_MODE	==	RISING
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif 	EXTI_MODE	== 	FALLING
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elif 	EXTI_MODE	== 	ON_CHANGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#else
		#error	("Wrong External Interrupt Mode !")
	#endif
}

void MEXTI_voidEnableEXTI (u8 Copy_u8LINE)
{
	SET_BIT(EXTI -> IMR, Copy_u8LINE);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8LINE)
{
	CLR_BIT(EXTI -> IMR, Copy_u8LINE);
}

void MEXTI_voidSwTrigger(u8 Copy_u8LINE)
{
	SET_BIT(EXTI -> SWIER, Copy_u8LINE);
}

void MEXTI_voidSetSingleLatch(u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
		case RISING		:	SET_BIT(EXTI -> RTSR, EXTI_LINE);	break;
		case FALLING	:	SET_BIT(EXTI -> FTSR, EXTI_LINE);	break;
		case ON_CHANGE	:	SET_BIT(EXTI -> RTSR, EXTI_LINE);	break;
							SET_BIT(EXTI -> FTSR, EXTI_LINE);	break;
	}
}

void EXTI0_IRQHandler (void)
{
	EXTI0_callback();
	/* Clear pending bit	*/
	SET_BIT(EXTI -> PR, 0);
}

void MEXTI_voidSetCallBack	(void (*ptr) (void))
{
	EXTI0_callback = ptr;
}

