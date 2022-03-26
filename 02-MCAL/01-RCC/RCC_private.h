/*********************************************************
*	Aurhor		: Mahmoud Karam							 *
*	Version		: V01									 *
*	Date		: 26/10/2020							 *
*********************************************************/
#ifndef RCC_PRIVATE_H
#define	RCC_PRIVATE_H

/* Base Address		*/
	#define RCC_BASE_ADDRESS 	0x40021000
	
/* Register Definitions	*/
{
	#define RCC_CR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
	#define RCC_CFGR		*((volatile u32 *)(RCC_BASE_ADDRESS + 0x04))
	#define RCC_CIR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
	#define RCC_APB2RSTR 	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x0C))
	#define RCC_APB1RSTR 	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x10))
	#define RCC_AHBENR   	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x14))
	#define RCC_APB2ENR  	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x18))
	#define RCC_APB1ENR	 	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x1C))
	#define RCC_BDCR		*((volatile u32 *)(RCC_BASE_ADDRESS + 0x20))
	#define RCC_CSR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x24))		
}

/* CLock Source Selection	*/
{
	#define 	RCC_HSI		0
	#define		RCC_HSE		1
	#define		RCC_PLL		2
}

/* Control Register  Selection	*/
{
	#define 	RCC_HSI_CR			0x00000081
	#define		RCC_HSE_CRYSTAL_CR	0x00010000
	#define		RCC_HSE_RC_CR		0x00050000
	#define		RCC_PLL_CR			0x01000000
}

/* Configuration Register  Selection	*/
{
	#define 	RCC_HSI_CFGR		0x00000000
	#define		RCC_HSE_CFGR		0x00000001
	/* PLL Input	*/
	#define RCC_PLL_IN_HSI_DIV_2	0x00000002
	#define RCC_PLL_IN_HSE_DIV_2	0x00030002
	#define RCC_PLL_IN _HSE			0x00010002
}

#endif
