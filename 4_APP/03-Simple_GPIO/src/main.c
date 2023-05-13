/********************************************************************************/
/* Author		: Mahmoud Karam													*/
/* Date			: 21/08/2020													*/
/* Version		: V1															*/
/* Description	: Falsh All ports												*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

int main (void)
{
	RCC_voidInitSysClock();

	/* Enable clock for GPIOA	*/
	RCC_voidEnableClock(RCC_APB2, 2);

	/* Enable clock for GPIOB	*/
	RCC_voidEnableClock(RCC_APB2, 3);

	/* Enable clock for GPIOC	*/
	RCC_voidEnableClock(RCC_APB2, 4);
	/* PINA0 output push pull 10MHz	*/

	for (u8 i = 0 ; i <= 15 ; i++)
			MGPIO_voidSetPinDirection(GPIOA, i , OUTPUT_SPEED_10MHZ_PP);
	for (u8 i = 0 ; i <= 15 ; i++)
			MGPIO_voidSetPinDirection(GPIOB, i , OUTPUT_SPEED_10MHZ_PP);
	for (u8 i = 0 ; i <= 15 ; i++)
			MGPIO_voidSetPinDirection(GPIOC, i , OUTPUT_SPEED_10MHZ_PP);

	u16 w = 500;
	while(1)
	{
		/* Set PORT A, B, C	*/
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOA, i, GPIO_HIGH);
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOB, i, GPIO_HIGH);
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOC, i, GPIO_HIGH);
		/* Set Delay	*/
		for (u16 i = 0 ; i < w ; i++)
		{
			for (u16 j = 0 ; j < 500 ; j++)
				asm("NOP");
		}


		/* Clr Port A, B, C	*/
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOA, i , GPIO_LOW );
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOB, i , GPIO_LOW );
		for (u8 i = 0 ; i <= 15 ; i++)
					MGPIO_voidSetPinValue(GPIOC, i , GPIO_LOW );
		/* Set Delay	*/
		for (u16 i = 0 ; i < w ; i++)
		{
			for (u16 j = 0 ; j < 500 ; j++)
				asm("NOP");
		}
	}

	return 0;
}
