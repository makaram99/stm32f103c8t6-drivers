/****************************************************************/
/* Author 	: Mahmoud Karam										*/
/* Date 	: 21/08/2020										*/
/* Version	: V1												*/
/****************************************************************/

/* Include Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include own driver files */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
			if (Copy_u8PIN <= 7)
			{
				/* Clearing Pin	*/
				GPIOA_CRL &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOA_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			else if (Copy_u8PIN <= 15)
			{
				/* Cuz CRH bits 0~32	*/
				Copy_u8PIN -= 8;
				
				/* Clearing Pin	*/
				GPIOA_CRH &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOA_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			break;
		case GPIOB:
			if (Copy_u8PIN <= 7)
			{
				/* Clearing Pin	*/
				GPIOB_CRL &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOB_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			else if (Copy_u8PIN <= 15)
			{
				/* Cuz CRH bits 0~32	*/
				Copy_u8PIN -= 8;
				
				/* Clearing Pin	*/
				GPIOB_CRH &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOB_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			break;
		case GPIOC:
			if (Copy_u8PIN <= 7)
			{
				/* Clearing Pin	*/
				GPIOC_CRL &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOC_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			else if (Copy_u8PIN <= 15)
			{
				/* Cuz CRH bits 0~32	*/
				Copy_u8PIN -= 8;
				
				/* Clearing Pin	*/
				GPIOC_CRH &= ~((0b1111) << (Copy_u8PIN*4));
				
				/* Set Pin	*/
				GPIOC_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN*4));
			}
			break;
	}
}

void MGPIO_voidSetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
		{
			/* Clearing Pin	*/
			if 		(Copy_u8Value == GPIO_LOW )
				CLR_BIT(GPIOA_ODR, Copy_u8PIN);
			
			/* Set Pin		*/
			else if (Copy_u8Value == GPIO_HIGH)
				SET_BIT(GPIOA_ODR, Copy_u8PIN);
		}
			break;
			
		case GPIOB:
		{
			/* Clearing Pin	*/
			if 		(Copy_u8Value == GPIO_LOW )
				CLR_BIT(GPIOB_ODR, Copy_u8PIN);
			
			/* Set Pin		*/
			else if (Copy_u8Value == GPIO_HIGH)
				SET_BIT(GPIOB_ODR, Copy_u8PIN);
		}
			break;
		
		case GPIOC:
		{
			/* Clearing Pin	*/
			if 		(Copy_u8Value == GPIO_LOW)
				CLR_BIT(GPIOC_ODR, Copy_u8PIN);
			
			/* Set Pin		*/
			else if (Copy_u8Value == GPIO_HIGH)
				SET_BIT(GPIOC_ODR, Copy_u8PIN);
		}
			break;

	}
}

u8 MGPIO_voidGetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	/* Declaration and definition of a variable	to get input value of bit */
	u8 LOC_u8Result = 0;
	switch (Copy_u8PORT)
	{
		case GPIOA:	LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);	break;
			
		case GPIOB:	LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);	break;
			
		case GPIOC:	LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);	break;	
	}
	return LOC_u8Result;
}