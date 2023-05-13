/*
 * main.c
 *
 *  Created on: Sep 1, 2020
 *      Author: makar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

void main (void)
{
  	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);	/* Enable clock for GPIOA	*/

	/* Pin Modes	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);	/* Output PP 2MHz	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);	/* Output PP 2MHz	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);	/* Output PP 2MHz	*/

	/* Initialize NVIC. IPR: 2bits for group and 2 for subgroup	*/
	MNVIC_voidInit();

	/* Set Priority		*/
	MNVIC_voidSetPriority(6, 0b01000000);	/* EXTI0 Group1 Sub0	*/
	MNVIC_voidSetPriority(7, 0b00110000);	/* EXTI0 Group0 Sub3	*/

	/* Enable EXTI0 from NVIC	*/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);

	MNVIC_voidSetPendingFlag(6);

	while (1)
	{

	}
}

void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
}

void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
}

void EXTI2_IRQHandler(void)
{

}
