/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: AFIO Driver main file								*/
/* Date 	: 6 Feb 2021										*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidInit(u8 Copy_u8LINEx, u8 Copy_u8PINx)
{
	if (Copy_u8LINEx < NO_OF_EXTIS)
	{
		AFIO -> EXTICR[Copy_u8LINEx / 4] &= ~(	0b1111 		<< (Copy_u8LINEx % 4));		// Reset
		AFIO -> EXTICR[Copy_u8LINEx / 4] &= ~(Copy_u8PINx 	<< (Copy_u8LINEx % 4));		// Set
	}
	else
		/* Invalid Line Number	*/
}
