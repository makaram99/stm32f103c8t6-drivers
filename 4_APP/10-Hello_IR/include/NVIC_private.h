/****************************************************************/
/* Author 	: Mahmoud Karam										*/
/* Date 	: 23/08/2020										*/
/* Version	: V1												*/
/****************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Base Address: 0xE000E100			*/
/* Number of external interrupts in stm32 doesn't exceed 60 interruprs	*/
#define 	NVIC_ISER0 		*((u32*)0xE000E100)		/* Enable External Interrupt from 0  to 31	*/
#define 	NVIC_ISER1 		*((u32*)0xE000E104)		/* Enable External Interrupt from 32 to 63	*/

#define 	NVIC_ICER0 		*((u32*)0xE000E180)		/* Disable External Interrupt from 0  to 31	*/
#define 	NVIC_ICER1 		*((u32*)0xE000E184)		/* Disable External Interrupt from 32 to 63	*/

#define 	NVIC_ISPR0 		*((u32*)0xE000E200)		/* Set   Pending Flag for External Interrupt from 0  to 31	*/
#define 	NVIC_ISPR1 		*((u32*)0xE000E204)		/* Set   Pending Flag for External Interrupt from 32 to 63	*/

#define 	NVIC_ICPR0 		*((u32*)0xE000E280)		/* Clear Pending Flag for External Interrupt from 0  to 31	*/
#define 	NVIC_ICPR1 		*((u32*)0xE000E284)		/* Clear Pending Flag for External Interrupt from 32 to 63	*/

#define 	NVIC_IABR0 		*((u32*)0xE000E300)		/* Active Flag for External Interrupt from 0  to 31	*/
#define 	NVIC_IABR1 		*((u32*)0xE000E304)		/* Active Flag for External Interrupt from 32 to 63	*/

#define 	MNVIC_GROUP_4_SUB_0		0x05FA0300
#define 	MNVIC_GROUP_3_SUB_1		0x05FA0400
#define 	MNVIC_GROUP_2_SUB_2		0x05FA0500
#define 	MNVIC_GROUP_1_SUB_3		0x05FA0600
#define 	MNVIC_GROUP_0_SUB_4		0x05FA0700

#define		MNVIC_IPR 		 ((volatile u8* )0xE000E100 + 0x300)
#define 	MSCB_ARICR		*((volatile u32*)0xE000ED00 + 0x0C )

#endif
