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

	MGPIO_voidSetPinDirection(GPIOA, PIN0 , INPUT_PULL_UP_DOWN);
	/* For pull-up	*/
	MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);

	for(u8 i = 1 ; i <=15 ; i++)
		MGPIO_voidSetPinDirection(GPIOA, i , OUTPUT_SPEED_10MHZ_PP);

	while(1)
	{
		if (MGPIO_voidGetPinValue(GPIOA, PIN0) == 0)
			MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);

		else
			MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);
	}

	return 0;
}
