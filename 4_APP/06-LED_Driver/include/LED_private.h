/****************************************************************************/
/* Author		: MahmoudKaram												*/
/* Date			: 22/08/2020												*/
/* Version		: V1														*/
/****************************************************************************/

#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

#define GPIOA_ODR 	*((u32*)(0x40010800 + 0x0C))
#define GPIOB_ODR 	*((u32*)(0x40010800 + 0x0C))
#define GPIOC_ODR 	*((u32*)(0x40010800 + 0x0C))

#endif