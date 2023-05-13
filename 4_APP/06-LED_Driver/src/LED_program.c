/****************************************************************************/
/* Author		: MahmoudKaram												*/
/* Date			: 22/08/2020												*/
/* Version		: V1														*/
/* Description	: LED_Driver:	Functions: LED_ON	(PORT, PIN)				*/
/*										   LED_OFF	(PORT, PIN)				*/
/*										   LED_TOG	(PORT, PIN)				*/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "GPIO_interface.h"

u8 cnt = 0;

void LED_ON(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIOA:
		{
			MGPIO_voidSetPinDirection	(GPIOA, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOA, Copy_u8PIN , GPIO_HIGH);
		}break;
		case GPIOB:
		{
			MGPIO_voidSetPinDirection	(GPIOB, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOB, Copy_u8PIN , GPIO_HIGH);
		}break;
		case GPIOC:
		{
			MGPIO_voidSetPinDirection	(GPIOC, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOC, Copy_u8PIN , GPIO_HIGH);
		}break;
	}
}

void LED_OFF(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIOA:
		{
			MGPIO_voidSetPinDirection	(GPIOA, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOA, Copy_u8PIN , GPIO_LOW);
		}break;
		case GPIOB:
		{
			MGPIO_voidSetPinDirection	(GPIOB, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOB, Copy_u8PIN , GPIO_LOW);
		}break;
		case GPIOC:
		{
			MGPIO_voidSetPinDirection	(GPIOC, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			MGPIO_voidSetPinValue		(GPIOC, Copy_u8PIN , GPIO_LOW);
		}break;
	}
}

void LED_TOG(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIOA:
		{
			MGPIO_voidSetPinDirection	(GPIOA, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			Copy_u8PIN = MGPIO_voidGetPinValue(GPIOA_ODR, Copy_u8PIN);
			if(cnt == 0)
				MGPIO_voidSetPinValue(GPIOA, Copy_u8PIN , GPIO_LOW);

			TOG_BIT(GPIOA_ODR, Copy_u8PIN);
		}break;
		case GPIOB:
		{
			MGPIO_voidSetPinDirection	(GPIOB, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			Copy_u8PIN = MGPIO_voidGetPinValue(GPIOB_ODR, Copy_u8PIN);
			if(cnt == 0)
				MGPIO_voidSetPinValue(GPIOB, Copy_u8PIN , GPIO_LOW);

			TOG_BIT(GPIOB_ODR, Copy_u8PIN);
		}break;
		case GPIOC:
		{
			MGPIO_voidSetPinDirection	(GPIOC, Copy_u8PIN , OUTPUT_SPEED_10MHZ_PP);
			Copy_u8PIN = MGPIO_voidGetPinValue(GPIOC_ODR, Copy_u8PIN);
			if(cnt == 0)
				MGPIO_voidSetPinValue(GPIOC, Copy_u8PIN , GPIO_LOW);

			TOG_BIT(GPIOC_ODR, Copy_u8PIN);
		}break;
	}
	cnt++;
	if(cnt > 10)
		cnt = 1;
}
