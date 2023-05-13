/*
 * main.c
 *
 *  Created on: Sep 13, 2020
 *      Author: makar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 DataArray[8] = {0, 124, 18, 18, 18, 124, 0, 0};
void main (void)
{
	/* RCC Initialization and Enable	*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);		/* GPIOA	*/
	RCC_voidEnableClock(RCC_APB2, 3);		/* GPIOB	*/

	/* Init SysTick						*/
	MSTK_voidInit();

	/* Init LED MAtrix					*/
	HLEDMRX_voidInit();

	/* Send Data to LED MAtrix			*/
	HLEDMRX_voidDisplay(DataArray);
}
