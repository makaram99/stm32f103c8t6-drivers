/*********************************************************
*	Aurhor		: Mahmoud Karam							 *
*	Version		: V01									 *
*	Date		: 26/10/2020							 *
*********************************************************/
#ifndef RCC_CONFIG_H
#define	RCC_CONFIG_H

/*System Clock	
	Options: 	RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL		*/
#define 	RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL

/*PLL input	
	Options:	RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN _HSE			*/
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define 	RCC_PLL_INPUT 	RCC_PLL_IN_HSE_DIV_2
#endif

/*PLL Multiplier Factor	
	Options: 	0b0000: PLL input clock x 2
				0b0001: PLL input clock x 3
				0b0010: PLL input clock x 4
				0b0011: PLL input clock x 5
				0b0100: PLL input clock x 6
				0b0101: PLL input clock x 7
				0b0110: PLL input clock x 8
				0b0111: PLL input clock x 9
				0b1000: PLL input clock x 10
				0b1001: PLL input clock x 11
				0b1010: PLL input clock x 12
				0b1011: PLL input clock x 13
				0b1100: PLL input clock x 14
				0b1101: PLL input clock x 15
				0b1110: PLL input clock x 16
				0b1111: PLL input clock x 16		*/
#define		RCCC_PLL_MUL	0b0000	

#endif