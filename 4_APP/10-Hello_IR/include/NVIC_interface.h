	/****************************************************************/
/* Author 	: Mahmoud Karam										*/
/* Date 	: 23/08/2020										*/
/* Version	: V1												*/
/****************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define 	GROPU3		0x05FA0300		/* 4 bits for group (IPR) => group				*/
#define 	GROPU4		0x05FA0400		/* 3 bits for group and 1 bit for sub priority	*/
#define 	GROPU5		0x05FA0500		/* 2 bits for group and 2 bit for sub priority	*/
#define 	GROPU6		0x05FA0600		/* 1 bits for group and 3 bit for sub priority	*/
#define 	GROPU7		0x05FA0700		/* 4 bits for sub priority						*/

/* Interfced Functions		*/
void MNVIC_voidInit();
void MNVIC_voidEnableInterrupt	(u8  Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt	(u8  Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag	(u8  Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag	(u8  Copy_u8IntNumber);
u8 MNVIC_u8ReadActiveFlagFlag	(u8  Copy_u8IntNumber);
/*void MNVIC_voidSetPriority(s8 Copy_s8IntId, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group);*/
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority);

#endif
