/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: AFIO Driver Private file							*/
/* Date 	: 6 Feb 2021										*/
/****************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/***************AFIO Base Addresses***************/
	#define AFIO_Base_Address	0x40010000

/***************AFIO Registers***************/
typedef struct
{
	volatile u32 	EVCR;
	volatile u32 	MAPR1;
	volatile u32 	EXTICR[4];
	volatile u32 	MAPR2;
}AFIO_t;

#define AFIO	((volatile AFIO_t *) AFIO_Base_Address)
/********************************************/

/* Number of External Peripherals: Set the number of available External interrupts in your MCU	*/
/* stm32f103c8t6 MCU has 16 EXTIs	*/
#define 	NO_OF_EXTI	16

#define 	PINA	0b0000
#define 	PINB	0b0001
#define 	PINC	0b0010

#endif