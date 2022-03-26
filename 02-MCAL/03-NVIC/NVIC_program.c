/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: NVIC Driver main file								*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID < 96)			// 3 ISER u8 is always positive. So, checking for bigger than zero is not useful
	{
		if(Copy_u8InterruptID < 32)			// 32 is the number of Register bits
		{
			// Write on ISER0
			NVIC_ISER0 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISER registers
		}
		else if(Copy_u8InterruptID < 64)
		{
			Copy_u8InterruptID -= 32;
			// Write on ISER1
			NVIC_ISER1 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISER registers
		}
		else
		{
			Copy_u8InterruptID -= 64;
			// Write on ISER2
			NVIC_ISER2 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISER registers
		}
	}
	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
	
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID < 96)			// 3 ICER u8 is always positive. So, checking for bigger than zero is not useful
	{
		if(Copy_u8InterruptID < 32)			// 32 is the number of Register bits
		{
			// Write on ICER0
			NVIC_ICER0 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICER registers, Faster than SET_BIT
		}
		else if(Copy_u8InterruptID < 64)
		{
			Copy_u8InterruptID -= 32;
			// Write on ICER1
			NVIC_ICER1 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICER registers, Faster than SET_BIT
		}
		else
		{
			Copy_u8InterruptID -= 64;
			// Write on ICER2
			NVIC_ICER2 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICER registers, Faster than SET_BIT
		}
	}
	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID < 96)			// 3 ISPR u8 is always positive. So, checking for bigger than zero is not useful
	{
		if(Copy_u8InterruptID < 32)			// 32 is the number of Register bits
		{
			// Write on ISPR0
			NVIC_ISPR0 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISPR registers, Faster than SET_BIT
		}                                                                      
		else if(Copy_u8InterruptID < 64)                                       
		{                                                                      
			Copy_u8InterruptID -= 32;                                          
			// Write on ISPR1                                                  
			NVIC_ISPR1 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISPR registers, Faster than SET_BIT
		}                                                                     
		else                                                                  
		{                                                                     
			Copy_u8InterruptID -= 64;                                         
			// Write on ISPR2                                                 
			NVIC_ISPR2 = (1 << Copy_u8InterruptID);		// 0 has no effect on ISPR registers, Faster than SET_BIT
		}
	}
	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID < 96)			// 3 ICPR u8 is always positive. So, checking for bigger than zero is not useful
	{
		if(Copy_u8InterruptID < 32)			// 32 is the number of Register bits
		{
			// Write on ICPR0
			NVIC_ICPR0 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICPR registers, Faster than SET_BIT
		}                                                                      
		else if(Copy_u8InterruptID < 64)                                       
		{                                                                      
			Copy_u8InterruptID -= 32;                                          
			// Write on ICPR1                                                  
			NVIC_ICPR1 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICPR registers, Faster than SET_BIT
		}                                                                     
		else                                                                  
		{                                                                     
			Copy_u8InterruptID -= 64;                                         
			// Write on ICPR2                                                 
			NVIC_ICPR2 = (1 << Copy_u8InterruptID);		// 0 has no effect on ICPR registers, Faster than SET_BIT
		}
	}
	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID < 96)			// 3 IABR u8 is always positive. So, checking for bigger than zero is not useful
	{
		if(Copy_u8InterruptID < 32)			// 32 is the number of Register bits
		{
			// Read IABR0
			return GET_BIT(NVIC_IABR0, Copy_u8InterruptID);
		}                                                                      
		else if(Copy_u8InterruptID < 64)                                       
		{                                                                      
			Copy_u8InterruptID -= 32;                                          
			// Read IABR1                                                  
			return GET_BIT(NVIC_IABR1, Copy_u8InterruptID);
		}                                                                     
		else                                                                  
		{                                                                     
			Copy_u8InterruptID -= 64;                                         
			// Read IABR2                                                 
			return GET_BIT(NVIC_IABR0, Copy_u8InterruptID);
		}
	}
	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
}

void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group)
{
	/*	((Copy_u32Group - GROUP3) / 256) 	find nunmber of steps to shift the group priority	
		the orring with the sub priority which is start from LSB	*/
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32Group - GROUP3) / 256));	// 256 is the step = 0x100
	
	/* Core peripherals		*/
	if (Copy_s8InterruptID < 0)	
	{
		
	}
	
	/* External peripherals are positiver	*/
	if (Copy_s8InterruptID >= 0)		
	{
		NVIC_IPR[Copy_s8InterruptID] = Local_u8Priority << 4;	/* the first 4 LSBs are reserved		*/
	}
	
	SCB_AIRCR = Copy_u32Group;

	else
	{
		/* Error: Out of range (you have onle 3 Registers of up to 96 interrupts)	*/
	}
}