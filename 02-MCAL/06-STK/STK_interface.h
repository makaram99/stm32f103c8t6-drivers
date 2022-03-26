/************************************************************/
/* Author	: Mahmoud Karam									*/
/* Date 	: 09/08/2020									*/
/* Version	: V1											*/
/************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* 	Apply clock choice from configuration file
	Disable Systick interrupt
	Disable Systick								*/
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait			(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle		(u32 Copy_u32Ticks, void (*ptr) (void));
void MSTK_voidSetIntervalPeriodic	(u32 Copy_u32Ticks, void (*ptr) (void));
u32	 MSTK_u32GetRemainingTime(void);
u32	 MSTK_u32GetElapsedTime(void);
void MSTK_voidStopInterval(void);

#endif 	STK_INTERFACE_H