/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: makar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

volatile u8 	u8StartFlag 		= 0;
volatile u32 	u32FrameData[50] 	= {0};
volatile u8		u8EdgeCounter		= 0;
volatile u8 	u8Data				= 0;

void voidPlay (void)
{
	switch (u8Data)
	{
	case 70: MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);	break;
	case 69: MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW ); break;
	}
}

void voidTakeAction(void)
{
	u8 i = 0;
	u8Data = 0;

	if(	(u32FrameData[0] >= 10000) && (u32FrameData[0] <= 15000) )
		for (i = 0; i < 8; i++)
		{
			if( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300) )
			{
				SET_BIT(u8Data, i);
			}
			else
			{
				CLR_BIT(u8Data, i);
			}
		}
	else
	{
		/* Invalid Frame	*/
	}
	u8StartFlag 		= 0;
	u32FrameData[0] 	= 0;
	u8EdgeCounter		= 0;
}

void voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer	*/
		MSTK_voidSetIntervalSingle(1000000, voidTakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000, voidTakeAction);	/* Reset Timer	*/
		u8EdgeCounter++;
	}
}

void main (void)
{
	/* RCC Initialize	*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);	/* GPIOA Enable	*/

	/* IO Pins Initialization	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN0, 0b0100);		/* A0 Input Floating	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN1, 0b0010);		/* A1 Output PP	"RED"	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN2, 0b0010);		/* A2 Output PP	"GREEN"	*/
	MGPIO_voidSetPinDirection(GPIOA, PIN3, 0b0010);		/* A3 Output PP	"BLUE"	*/

	/* EXTI Initialization	*/
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit();	/* A0 EXTI0 Enabled / Falling Edge	*/

	/* Enable NVIC	*/
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);	/* Enable interrupt EXTI0	*/

	/* Initialize SysTick	*/
	MSTK_voidInit();	/* Enable SysTick AHB/8 = 1MHz	*/

}
