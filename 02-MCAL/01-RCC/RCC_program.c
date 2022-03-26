/*********************************************************
*	Aurhor		: Mahmoud Karam							 *
*	Version		: V01									 *
*	Date		: 26/10/2020							 *
*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR 		== RCC_HSI_CR;
			RCC_CFGR	== RCC_HSI_CFGR;

	#elif	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR 		== RCC_HSE_CRYSTAL_CR;
			RCC_CFGR	== RCC_HSE_CFGR;
	
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR 		== RCC_HSE_RC_CR;
			RCC_CFGR	== RCC_HSE_CFGR;
			
	#elif	RCC_CLOCK_TYPE == RCC_PLL
		#if 	RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR	== RCC_PLL_IN_HSI_DIV_2 | (RCC_PLL_MUL << 18);
			
		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFGR	== RCC_PLL_IN_HSE_DIV_2 | (RCC_PLL_MUL << 18);
			
		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CFGR	== 	RCC_PLL_IN_HSE		| (RCC_PLL_MUL << 18);
		#endif
		RCC_CR 		== RCC_PLL_CR;
	#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	/* check correct peripheral ID	*/
	if (Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB: 	SET_BIT(AHBENR ,Copy_u8PeripheralId); 	break;
			case RCC_APB2:	SET_BIT(APB2ENR,Copy_u8PeripheralId); 	break;
			case RCC_APB1:	SET_BIT(APB1ENR,Copy_u8PeripheralId); 	break;
		}
	}
	else
	{
		/* Error	*/
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	/* check correct peripheral ID	*/
	if (Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB: 	CLR_BIT(AHBENR,Copy_u8PeripheralId); 	break;
			case RCC_APB2:	CLR_BIT(APB2ENR,Copy_u8PeripheralId); 	break;
			case RCC_APB1:	CLR_BIT(APB1ENR,Copy_u8PeripheralId); 	break;
		}
	}
	
	else
	{
		/* Error	*/
	}
}