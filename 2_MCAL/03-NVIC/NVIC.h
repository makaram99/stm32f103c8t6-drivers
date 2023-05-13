/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: NVIC Driver Interface file						*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                  TYPEDEFS                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* IRQn_t */
typedef enum NVIC_IRQ_t{
    NVIC_IRQ_WWDG,
    NVIC_IRQ_PVD,
    NVIC_IRQ_TAMPER,
    NVIC_IRQ_RTC,
    NVIC_IRQ_FLASH,
    NVIC_IRQ_RCC,
    NVIC_IRQ_EXTI0,
    NVIC_IRQ_EXTI1,
    NVIC_IRQ_EXTI2,
    NVIC_IRQ_EXTI3,
    NVIC_IRQ_EXTI4,
    NVIC_IRQ_DMA1_Channel1,
    NVIC_IRQ_DMA1_Channel2,
    NVIC_IRQ_DMA1_Channel3,
    NVIC_IRQ_DMA1_Channel4,
    NVIC_IRQ_DMA1_Channel5,
    NVIC_IRQ_DMA1_Channel6,
    NVIC_IRQ_DMA1_Channel7,
    NVIC_IRQ_ADC1_2,
    NVIC_IRQ_USB_HP_CAN_TX,
    NVIC_IRQ_USB_LP_CAN_RX0,
    NVIC_IRQ_CAN_RX1,
    NVIC_IRQ_CAN_SCE,
    NVIC_IRQ_EXTI9_5,
    NVIC_IRQ_TIM1_BRK,
    NVIC_IRQ_TIM1_UP,
    NVIC_IRQ_TIM1_TRG_COM,
    NVIC_IRQ_TIM1_CC,
    NVIC_IRQ_TIM2,
    NVIC_IRQ_TIM3,
    NVIC_IRQ_TIM4,
    NVIC_IRQ_I2C1_EV,
    NVIC_IRQ_I2C1_ER,
    NVIC_IRQ_I2C2_EV,
    NVIC_IRQ_I2C2_ER,
    NVIC_IRQ_SPI1,
    NVIC_IRQ_SPI2,
    NVIC_IRQ_USART1,
    NVIC_IRQ_USART2,
    NVIC_IRQ_USART3,
    NVIC_IRQ_EXTI15_10,
    NVIC_IRQ_RTCAlarm,
    NVIC_IRQ_USBWakeUp,
    NVIC_IRQ_TIM8_BRK,
    NVIC_IRQ_TIM8_UP,
    NVIC_IRQ_TIM8_TRG_COM,
    NVIC_IRQ_TIM8_CC,
    NVIC_IRQ_ADC3,
    NVIC_IRQ_FSMC,
    NVIC_IRQ_SDIO,
    NVIC_IRQ_TIM5,
    NVIC_IRQ_SPI3,
    NVIC_IRQ_UART4,
    NVIC_IRQ_UART5,
    NVIC_IRQ_TIM6,
    NVIC_IRQ_TIM7,
    NVIC_IRQ_DMA2_Channel1,
    NVIC_IRQ_DMA2_Channel2,
    NVIC_IRQ_DMA2_Channel3,
    NVIC_IRQ_DMA2_Channel4_5,
    NVIC_IRQ_MAX
}NVIC_IRQ_t;


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               API's PROTOTYPES                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
ERROR_t NVIC_Initialize(void);
ERROR_t NVIC_EnableInterrupt(const NVIC_IRQ_t interruptID);
ERROR_t NVIC_DisableInterrupt(const NVIC_IRQ_t interruptID);
ERROR_t NVIC_SetPendingFlag(const NVIC_IRQ_t interruptID);
ERROR_t NVIC_ClearPendingFlag(const NVIC_IRQ_t interruptID);
ERROR_t NVIC_GetActiveFlag(const NVIC_IRQ_t interruptID, STATE_t * const state);
ERROR_t NVIC_SetPriority(NVIC_IRQ_t interruptID, u8_t GroupPriority, u8_t SubPriority);
ERROR_t NVIC_GetPriority(const NVIC_IRQ_t interruptID, u8_t * const priority);


#endif	/* End of file guard	*/
