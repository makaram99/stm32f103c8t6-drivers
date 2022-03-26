/*********************************************************
*	Aurhor		: Mahmoud Karam							 *
*	Version		: V01									 *
*	Date		: 26/10/2020							 *
*********************************************************/
#ifndef RCC_INTERFACE_H
#define	RCC_INTERFACE_H

/* Macros Definitions	*/
	#define 	RCC_AHB		0
	#define 	RCC_APB2	1
	#define 	RCC_APB1	2

/* Functions Prototypes
	Arguments: 	Copy_u8BusId		: RCC_AHB, RCC_APB2, RCC_APB1
				Copy_u8PeripheralId	: AHBENR_DMA1, AHBENR_DMA2, AHBENR_SRAM, AHBENR_FLITF, AHBENR_CRC, AHBENR_FSMC, AHBENR_SDIO
				
									  APB1ENR_TIM2, APB1ENR_TIM3, APB1ENR_TIM4, APB1ENR_TIM5, APB1ENR_TIM6, APB1ENR_TIM7, APB1ENR_TIM12,
										APB1ENR_TIM13, APB1ENR_TIM14, APB1ENR_WWD, APB1ENR_SPI2, APB1ENR_SPI3, APB1ENR_USART2, APB1ENR_USART3,
										APB1ENR_USART4, APB1ENR_USART5, APB1ENR_I2C1, APB1ENR_I2C2, APB1ENR_USB, APB1ENR_CAN, 
										APB1ENR_BKP, APB1ENR_PWR, APB1ENR_DAC
										
									  APB2ENR_AFIO, APB2ENR_IOPA, APB2ENR_IOPB, APB2ENR_IOPC, APB2ENR_IOPD APB2ENR_IOPE, APB2ENR_IOPF, 
										APB2ENR_IOPG, APB2ENR_ADC1, APB2ENR_ADC2, APB2ENR_TIM1, APB2ENR_SPI1, APB2ENR_TIM8, APB2ENR_USART1, 
										APB2ENR_ADC3, APB2ENR_TIM9, APB2ENR_TIM10, APB2ENR_TIM11
								*/
	void RCC_voidInitSysClock(void);
	void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
	void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)

/* Enabling Peripherals Registers Bits	*/
{
	/* AHBENR	*/
	{
		#define AHBENR_DMA1		0
		#define AHBENR_DMA2		1
		#define AHBENR_SRAM		2
		#define AHBENR_FLITF	4
		#define AHBENR_CRC		6
		#define AHBENR_FSMC		8
		#define AHBENR_SDIO		10
	}
	/* APB1ENR	*/
	{
		#define APB1ENR_TIM2	0
		#define APB1ENR_TIM3	1
		#define APB1ENR_TIM4	2
		#define APB1ENR_TIM5	3
		#define APB1ENR_TIM6	4
		#define APB1ENR_TIM7	5
		#define APB1ENR_TIM12	6
		#define APB1ENR_TIM13	7
		#define APB1ENR_TIM14	8
		#define APB1ENR_WWD		11
		#define APB1ENR_SPI2	14
		#define APB1ENR_SPI3	15
		#define APB1ENR_USART2	17
		#define APB1ENR_USART3	18
		#define APB1ENR_USART4	19
		#define APB1ENR_USART5	20
		#define APB1ENR_I2C1	21
		#define APB1ENR_I2C2	22
		#define APB1ENR_USB		23
		#define APB1ENR_CAN		28
		#define APB1ENR_BKP		27
		#define APB1ENR_PWR		28
		#define APB1ENR_DAC		29	
	}	
	/* APB1ENR	*/
	{
		#define APB2ENR_AFIO	0
		#define APB2ENR_IOPA	2
		#define APB2ENR_IOPB	3
		#define APB2ENR_IOPC	4
		#define APB2ENR_IOPD	5
		#define APB2ENR_IOPE	6
		#define APB2ENR_IOPF	7
		#define APB2ENR_IOPG	8
		#define APB2ENR_ADC1	9
		#define APB2ENR_ADC2	10
		#define APB2ENR_TIM1	11
		#define APB2ENR_SPI1	12
		#define APB2ENR_TIM8	13
		#define APB2ENR_USART1	14
		#define APB2ENR_ADC3	15
		#define APB2ENR_TIM9	19
		#define APB2ENR_TIM10	20
		#define APB2ENR_TIM11	21
	}
}
#endif