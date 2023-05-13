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
#include "LED_interface.h"

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

	/*
	for(u8 i = 0 ; i <= 15 ; i++)
		{
			MGPIO_voidSetPinDirection	(GPIOA, i , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue(GPIOA, i, GPIO_LOW);
		}
	for(u8 i = 0 ; i <= 15 ; i++)
		{
			MGPIO_voidSetPinDirection	(GPIOB, i , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue(GPIOB, i, GPIO_LOW);
		}
	for(u8 i = 13 ; i <= 15 ; i++)
	{
		MGPIO_voidSetPinDirection	(GPIOC, i , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinValue(GPIOC, i, GPIO_LOW);
	}
	*/

	while(1)
	{
		LED_ON (GPIOA, PIN0 );
		LED_OFF(GPIOB, PIN1 );
		LED_TOG(GPIOB, PIN14);
		/* Delay	*/
		for(u16 i = 0 ; i <= 500 ; i++)
			for(u16 j = 0 ; j <= 500 ; j++)
				asm("NOP");

		LED_OFF(GPIOA, PIN0);
		LED_ON (GPIOB, PIN1 );
		LED_TOG(GPIOB, PIN14);
		/* Delay	*/
		for(u16 i = 0 ; i <= 500 ; i++)
			for(u16 j = 0 ; j <= 500 ; j++)
				asm("NOP");
	}

	return 0;
}
