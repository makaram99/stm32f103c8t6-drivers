/******************************************************************************
 * @file        AFIO_private.h
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       AFIO Driver Private file
 * @version     1.0.0
 * @date        6 Feb 2021	
 * @copyright   Copyright (c) 2022
 ******************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                    Registers                                   */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

#define AFIO_Base_Address	0x40010000

typedef struct AFIO_t{
	volatile u32_t 	EVCR;
	volatile u32_t 	MAPR1;
	volatile u32_t 	EXTICR[4];
	volatile u32_t 	MAPR2;
}AFIO_t;

#define AFIO	((volatile AFIO_t *) AFIO_Base_Address)

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            PRIVATE FUNCTIONS PROTOTYPES                      */
/*                                                                              */
/*------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            MACRO LIKE FUNCTIONS                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/

#endif
