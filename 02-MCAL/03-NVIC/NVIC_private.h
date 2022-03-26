/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: NVIC Driver Private file							*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/***************NVIC Base Addresses***************/
	#define NVIC_Base_Address	0xE000E100

/***************NVIC Registers***************/
	/* Enable External Interrupts			*/
	#define		NVIC_ISER0		*((volatile u32*)(NVIC_Base_Address + 0x000))	/* From 0  to 31	*/
	#define		NVIC_ISER1		*((volatile u32*)(NVIC_Base_Address + 0x004))	/* From 32 to 63	*/
	#define		NVIC_ISER2		*((volatile u32*)(NVIC_Base_Address + 0x008))	/* From 64 to 95	*/
	/* Disable External Interrupts			*/	
	#define		NVIC_ICER0		*((volatile u32*)(NVIC_Base_Address + 0x080))	/* From 0  to 31	*/
	#define		NVIC_ICER1		*((volatile u32*)(NVIC_Base_Address + 0x084))   /* From 32 to 63	*/
	#define		NVIC_ICER2		*((volatile u32*)(NVIC_Base_Address + 0x088))   /* From 64 to 95	*/
	/* Set Pending flag of External Interrupts, For debug and testing*/
	#define		NVIC_ISPR0		*((volatile u32*)(NVIC_Base_Address + 0x100))	/* From 0  to 31	*/
	#define		NVIC_ISPR1		*((volatile u32*)(NVIC_Base_Address + 0x104))   /* From 32 to 63	*/
	#define		NVIC_ISPR2		*((volatile u32*)(NVIC_Base_Address + 0x108))   /* From 64 to 95	*/
	/* Clear Pending flag of External Interrupts, For debug and testing*/
	#define		NVIC_ICPR0		*((volatile u32*)(NVIC_Base_Address + 0x180))	/* From 0  to 31	*/
	#define		NVIC_ICPR1		*((volatile u32*)(NVIC_Base_Address + 0x184))   /* From 32 to 63	*/
	#define		NVIC_ICPR2		*((volatile u32*)(NVIC_Base_Address + 0x188))   /* From 64 to 95	*/
	
	/* Read if External Interrupts is ACTIVE or not, For debug and testing*/
	/* They are read only, so that volatile is required to avoid compiler optimization	*/
	#define		NVIC_IABR0		*((volatile u32*)(NVIC_Base_Address + 0x200))	/* From 0  to 31	*/
	#define		NVIC_IABR1		*((volatile u32*)(NVIC_Base_Address + 0x204))   /* From 32 to 63	*/
	#define		NVIC_IABR2		*((volatile u32*)(NVIC_Base_Address + 0x208))   /* From 64 to 95	*/
	/* Priority Register		*/
	#define		NVIC_IPR		((volatile u8*)(NVIC_Base_Address + 0x300))		// It's Byte accessible, deon't dereference it cuz we access it as an array
	/* Dividing bit of priority and subpriority	*/
	#define 	SCB_AIRCR		*((u32*)(00xE000ED00 + 0x0C))		
	
	#define		NVIC_STIR		*((volatile u32*)(NVIC_Base_Address + 0xE00))
/********************************************/

#endif