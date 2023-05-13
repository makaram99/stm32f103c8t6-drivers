/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: EXTI Driver Private file							*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/***************EXTI Base Addresses***************/
	#define EXTI_Base_Address	0x40010400

/***************EXTI Registers***************/
typedef struct
{
	volatile u32 	IMR	;
	volatile u32    EMR	;
	volatile u32    RTSR;
	volatile u32	FTSR;
	volatile u32	SWIER;
	volatile u32	PR	;
}EXTI_T;

#define EXTI	((volatile EXTI_T *) EXTI_Base_Address)
/********************************************/

/* 		Interrupt Mode			*/
#define 	RISING		0
#define 	FALLING		1
#define 	ON_CHANGE	2

/* Number of External Peripherals: Set the number of available External interrupts in your MCU	*/
/* stm32f103c8t6 MCU has 16 EXTIs	*/
#define 	NO_OF_EXTI	16

#endif