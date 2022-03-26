/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: EXTI Driver main file								*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit(u8 Copy_u8LineId, u8 Copy_u8Mode)
{
	if (Copy_u8LineId < NO_OF_EXTI)
	{
		switch(Copy_u8Mode)
		{
			case RISING   : SET_BIT(EXTI -> RTSR, Copy_u8LineId);		break;
			case FALLING  : SET_BIT(EXTI -> FTSR, Copy_u8LineId);		break;
			case ON_CHANGE: SET_BIT(EXTI -> RTSR, Copy_u8LineId);	
							SET_BIT(EXTI -> FTSR, Copy_u8LineId);		break;
		}
		CLR_BIT(EXTI -> IMR, Copy_u8LineId);	/* It's better to disable interrup when configueing it 	*/
	}
	else
		/* Invalid Line Number	*/
}

void MEXTI_voidEnable(u8 Copy_u8LineId)
{
	if (Copy_u8LineId < NO_OF_EXTI)
	{
		SET_BIT(EXTI -> IMR, Copy_u8LineId);
	}
	else
		/* Invalid Line Number	*/
}

void MEXTI_voidDisable(u8 Copy_u8LineId)
{
	if (Copy_u8LineId < NO_OF_EXTI)
	{
		CLR_BIT(EXTI -> IMR, Copy_u8LineId);
	}
	else
		/* Invalid Line Number	*/
}

void MEXTI_voidSwTrigger(u8 Copy_u8LineId)
{
	if (Copy_u8LineId < NO_OF_EXTI)
	{
		SET_BIT(EXTI -> SWIER, Copy_u8LineId);
	}
	else
		/* Invalid Line Number	*/
}

