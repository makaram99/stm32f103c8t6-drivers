/*
 * main.c
 *
 *  Created on: Aug 20, 2020
 *      Author: makar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#define PORTA_CRL *((u32*)0x40010800)
#define PORTA_ODR *((u32*)0x4001080C)

void main (void)
{
	/* Initialize Clock System */
	RCC_voidInitSysClock();

	/* Enable Peripheral 2 on APB2 (GPIOA) */
	RCC_voidEnableClock(RCC_APB2, 2);

	/* Configure A0 as push pull output/2MHz */
	PORTA_CRL = 0x00000002;

	/* Initialize A0 with High (1) */
	PORTA_ODR = 0x00000001;



	while (1)
	{

	}
}
