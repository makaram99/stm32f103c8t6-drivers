/********************************************************************/
/* Author 		: Mahmoud Karam										*/
/* Version		: V1												*/
/* Date			: 18/08/2020										*/
/********************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

/* Interfaced Functions	*/
void RCC_voidInitSysClock(void);
void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);


/* End of the guard */
#endif
