/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: GPIO Driver main file								*/
/* Date 	: 17 Jan 2021										*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8PinId , u8 Copy_u8Mode )
{
	if ((Copy_u8PinId <= 15 ) && (Copy_u8PinId >= 0 ))	/* Check corner cases	*/
	{
		switch(Copy_u8Port)
		{
			case GPIOA:
				if(Copy_u8PinId <= 7 )
				{
					GPIOA_CRL &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));
					GPIOA_CRL |=  (Copy_u8Mode	<< ( Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId -= 8;
					GPIOA_CRH &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));
					GPIOA_CRH |=  (Copy_u8Mode	<< ( Copy_u8PinId * 4));
					Copy_u8PinId += 8;
				}
				/* For Pul-Up and Pull-Down	*/
				if 		(Copy_u8Mode == INPUT_PU)
					SET_BIT(GPIOA_ODR, Copy_u8PinId);
				else if (Copy_u8Mode == INPUT_PU)
					CLR_BIT(GPIOA_ODR, Copy_u8PinId);
				break;
				
			case GPIOB:
				if(Copy_u8PinId <= 7 )
				{
					GPIOB_CRL &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));// R M W
					GPIOB_CRL |=  (Copy_u8Mode	<< ( Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId -= 8;
					GPIOB_CRH &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));
					GPIOB_CRH |=  (Copy_u8Mode 	<< ( Copy_u8PinId * 4));
					Copy_u8PinId += 8;
				}
				/* For Pul-Up and Pull-Down	*/
				if 		(Copy_u8Mode == INPUT_PU)
					SET_BIT(GPIOB_ODR, Copy_u8PinId);
				else if (Copy_u8Mode == INPUT_PU)
					CLR_BIT(GPIOB_ODR, Copy_u8PinId);
				break;
				
			case GPIOC:
				if(Copy_u8PinId <= 7 )
				{
					GPIOC_CRL &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));
					GPIOC_CRL |=  (Copy_u8Mode 	<< ( Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId -= 8;
					GPIOC_CRH &= ~( ( 0b1111 )	<< ( Copy_u8PinId * 4));
					GPIOC_CRH |=  (Copy_u8Mode 	<< ( Copy_u8PinId * 4));
					Copy_u8PinId += 8;
				}
				/* For Pul-Up and Pull-Down	*/
				if 		(Copy_u8Mode == INPUT_PU)
					SET_BIT(GPIOC_ODR, Copy_u8PinId);
				else if (Copy_u8Mode == INPUT_PU)
					CLR_BIT(GPIOC_ODR, Copy_u8PinId);
				break;
		}	/* End of switch	*/
	}
	else	/* Invalid PinId	*/
		asm("NOP");
}

void MGPIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8PinId , u8 Copy_u8Value )
{
	if ((Copy_u8PinId <= 15 ) && (Copy_u8PinId >= 0 ))	/* Check corner cases	*/
		switch(Copy_u8Port)
		{
			case GPIOA:
				if		( Copy_u8Value == GPIO_HIGH )
					GPIOA_BSRR = (1 << Copy_u8PinId);
				else if ( Copy_u8Value == GPIO_LOW )
					GPIOA_BRR  = (1 << Copy_u8PinId);
				break;
				
			case GPIOB:
				if		( Copy_u8Value == GPIO_HIGH )
					GPIOB_BSRR = (1 << Copy_u8PinId);
				else if ( Copy_u8Value == GPIO_LOW )
					GPIOB_BRR  = (1 << Copy_u8PinId);
				break;

			case GPIOC:
				if		( Copy_u8Value == GPIO_HIGH )
					GPIOC_BSRR = (1 << Copy_u8PinId);
				else if ( Copy_u8Value == GPIO_LOW )
					GPIOC_BRR  = (1 << Copy_u8PinId);
				break;
		}
	else	/* Invalid PinId	*/
		asm("NOP");
}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8PinId )
{
	u8 Local_u8Result = 0 ;

	if ((Copy_u8PinId <= 15 ) && (Copy_u8PinId >= 0 ))	/* Check corner cases	*/
	{
		switch(Copy_u8Port)
		{
			case GPIOA:
				Local_u8Result = GET_BIT( GPIOA_IDR , Copy_u8PinId );
				break;
			case GPIOB:
				Local_u8Result = GET_BIT( GPIOB_IDR , Copy_u8PinId );
				break;
			case GPIOC:
				Local_u8Result = GET_BIT( GPIOC_IDR , Copy_u8PinId );
				break;
		}
	}
	return Local_u8Result;
}

void MGPIO_voidSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8PinId, u8 Copy_u8Speed)
{
	if ((Copy_u8PinId <= 15 ) && (Copy_u8PinId >= 0 ))	/* Check corner cases	*/
		switch(Copy_u8Port)
		{
			case GPIOA:
				if(Copy_u8PinId <= 7 )
				{
					GPIOA_CRL &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOA_CRL |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId = Copy_u8PinId - 8;
					GPIOA_CRH &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOA_CRH |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				break;
				
			case GPIOB:
				if(Copy_u8PinId <= 7 )
				{
					GPIOB_CRL &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOB_CRL |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId = Copy_u8PinId - 8;
					GPIOB_CRH &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOB_CRH |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				break;
				
			case GPIOC:
				if(Copy_u8PinId <= 7 )
				{
					GPIOC_CRL &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOC_CRL |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				else
				{
					Copy_u8PinId = Copy_u8PinId - 8;
					GPIOC_CRH &= ~(	  0b11 		<< (Copy_u8PinId * 4));
					GPIOC_CRH |=  (Copy_u8Speed << (Copy_u8PinId * 4));
				}
				break;
		}
	else	/* Invalid PinId	*/
		asm("NOP");
}

void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8PinId)
{
	if (((Copy_u8PinId <= 15 ) && (Copy_u8PinId >= 0 )) || (Copy_u8PinId == GPIO_LOCK_ALL ))	/* Check corner cases	*/
		switch(Copy_u8Port)
		{
			case GPIOA:
				if (Copy_u8PinId <= 15 )
					SET_BIT(GPIOA_LCKR, Copy_u8PinId);	/* 0 to 15, GPIO_LOCK_ALL for all port	*/
				else 	/* Lock All	*/
					GPIOA_LCKR = 0x0F;
				/* Lock key writing sequence	*/
				SET_BIT(GPIOA_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOA_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOA_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOA_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOA_LCKR, 16);	/* Write	*/
				break;
			
			case GPIOB:
				if (Copy_u8PinId <= 15 )
					SET_BIT(GPIOB_LCKR, Copy_u8PinId);	/* 0 to 15, GPIO_LOCK_ALL for all port	*/
				else 	/* Lock All	*/
					GPIOB_LCKR = 0x0F;
				/* Lock key writing sequence	*/
				SET_BIT(GPIOB_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOB_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOB_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOB_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOB_LCKR, 16);	/* Write	*/
				break;
			
			case GPIOC:
				if (Copy_u8PinId <= 15 )
					SET_BIT(GPIOC_LCKR, Copy_u8PinId);	/* 0 to 15, GPIO_LOCK_ALL for all port	*/
				else 	/* Lock All	*/
					GPIOC_LCKR = 0x0F;
				/* Lock key writing sequence	*/
				SET_BIT(GPIOC_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOC_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOC_LCKR, 16);	/* Write	*/
				CLR_BIT(GPIOC_LCKR, 16);	/* Read		*/
				SET_BIT(GPIOC_LCKR, 16);	/* Write	*/
				break;
		}	/* End of Switch	*/
	else	/* Invalid PinID	*/
		asm("NOP");
}
