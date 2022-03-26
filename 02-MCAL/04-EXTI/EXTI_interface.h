/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: EXTI Driver Interface file						*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void MEXTI_voidInit();
void MEXTI_voidEnable(u8 Copy_u8LineId);
void MEXTI_voidDisable(u8 Copy_u8LineId);
void MEXTI_voidSwTrigger(u8 Copy_u8LineId);

#endif	/* End of file guard	*/