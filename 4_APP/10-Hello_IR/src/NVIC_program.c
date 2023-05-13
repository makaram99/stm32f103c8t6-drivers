/****************************************************************/
/* Author 	: Mahmoud Karam										*/
/* Date 	: 23/08/2020										*/
/* Version	: V1												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit()
{
	#define SCB_AIRCR *((u32*)0xE000E008 + 0x0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}
void MNVIC_voidEnableInterrupt	(u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 |= (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;		/* To get range from 0 to 31 ==> Register has 32-bits	*/
		NVIC_ISER1 |= (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error	*/
	}
}

void MNVIC_voidDisableInterrupt	(u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 |= (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;		/* To get range from 0 to 31 ==> Register has 32-bits	*/
		NVIC_ICER1 |= (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error	*/
	}
}

void MNVIC_voidSetPendingFlag	(u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 |= (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;		/* To get range from 0 to 31 ==> Register has 32-bits	*/
		NVIC_ISPR1 |= (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error	*/
	}
}

void MNVIC_voidClearPendingFlag	(u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 |= (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;		/* To get range from 0 to 31 ==> Register has 32-bits	*/
		NVIC_ICPR1 |= (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error	*/
	}
}

u8 MNVIC_u8ReadActiveFlagFlag	(u8  Copy_u8IntNumber)
{
	u8 LOC_u8Result = 0;
	if (Copy_u8IntNumber <= 31)
	{
		LOC_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;		/* To get range from 0 to 31 ==> Register has 32-bits	*/
		LOC_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else
	{
		/* Return Error	*/
	}
	return LOC_u8Result;
}

/* Eng. Ahmed Atia	*/
/*
void MNVIC_voidSetPriority(s8 Copy_s8IntId, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group)
{
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32Group - 0x05FA0300)/256));
	*/
	/* Core peripheral	*/

	/* External Peripheral	*/
/*
	if(Copy_s8IntId >= 0)
	{
		NVIC_IPR[Copy_s8IntId] = Local_u8Priority << 4;

	}
	SCB_AIRCR = Copy_u32Group;
}
*/
/* Eng. Ahmed Assaf	*/
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority)
{
	if(Copy_u8PeripheralIdx < 60)
		MNVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority;

	else
	{
		/* Retunr Error*/
	}
}

