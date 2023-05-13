/************************************************************/
/* Author	: Mahmoud Karam									*/
/* Date 	: 09/08/2020									*/
/* Version	: V1											*/
/************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

ERROR_t STK_Init(void);
ERROR_t STK_DeInit(void);
ERROR_t STK_SetBusyWait(const u32_t ticks);
ERROR_t STK_SetIntervalSingle(const u32_t ticks, void (* const callback)(void) );
ERROR_t STK_SetIntervalPeriodic(const u32_t ticks, void (*const callback)(void) );
ERROR_t STK_GetElapsedTime(u32_t * const ElapsedTime);
ERROR_t  STK_GetRemainingTime(u32_t * const RemainingTime);

#endif 		/* STK_INTERFACE_H	*/
