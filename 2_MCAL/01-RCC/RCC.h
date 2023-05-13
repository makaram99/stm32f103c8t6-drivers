/*********************************************************************************
 * @file    RCC.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Common RCC functions and constants.
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef RCC_H
#define RCC_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                       Types                                    */
/*                                                                                */
/*--------------------------------------------------------------------------------*/
typedef enum RCC_CLOCK_t{
    RCC_CLOCK_HSI,
    RCC_CLOCK_HSE,
    RCC_CLOCK_PLL
}RCC_CLOCK_t;

typedef enum RTC_CLOCK_t{
    RTC_CLOCK_LSI,
    RTC_CLOCK_LSE
}RTC_CLOCK_t;

typedef enum RCC_MCO_t{
    RCC_MCO_NOCLOCK,
    RCC_MCO_SYSCLK,
    RCC_MCO_HSI,
    RCC_MCO_HSE,
    RCC_MCO_PLL_DIV2
}RCC_MCO_t;

typedef enum BUS_t{
    AHB  = 0,
    APB1 = 1,
    APB2 = 2
}BUS_t;

typedef enum PERIPHERAL_t{
    /* Peripherals on AHB bus       */
    DMA1   = (0 * 32) + 0,        /* (BUS_OFFSET * REGISTER_WIDTH) + BIT_NUMBER */
    DMA2   = (0 * 32) + 1,    
    SRAM   = (0 * 32) + 2,    
    FLITF  = (0 * 32) + 4,    
    CRCE   = (0 * 32) + 6,    
    FSMC   = (0 * 32) + 8,    
    SDIO   = (0 * 32) + 10, 

    /* Peripherals on APB1 bus      */
    TIM2   = (1 * 32) + 0, 
    TIM3   = (1 * 32) + 1, 
    TIM4   = (1 * 32) + 2, 
    TIM5   = (1 * 32) + 3, 
    TIM6   = (1 * 32) + 4, 
    TIM7   = (1 * 32) + 5, 
    TIM12  = (1 * 32) + 6,  
    TIM13  = (1 * 32) + 7,  
    TIM14  = (1 * 32) + 8,  
    WWDG   = (1 * 32) + 11, 
    SPI2   = (1 * 32) + 14, 
    SPI3   = (1 * 32) + 15, 
    USART2 = (1 * 32) + 17, 
    USART3 = (1 * 32) + 18, 
    UART4  = (1 * 32) + 19,  
    UART5  = (1 * 32) + 20, 
    I2C1   = (1 * 32) + 21, 
    I2C2   = (1 * 32) + 22, 
    USB    = (1 * 32) + 23, 
    CAN    = (1 * 32) + 25, 
    BKP    = (1 * 32) + 27, 
    PWR    = (1 * 32) + 28, 
    DAC    = (1 * 32) + 29,

    /* Peripherals on APB2 bus      */
    AFIO   = (2 * 32) + 0,
    IOPA   = (2 * 32) + 2,
    IOPB   = (2 * 32) + 3,
    IOPC   = (2 * 32) + 4,
    IOPD   = (2 * 32) + 5,
    IOPE   = (2 * 32) + 6, 
    IOPF   = (2 * 32) + 7, 
    IOPG   = (2 * 32) + 8, 
    ADC1   = (2 * 32) + 9, 
    ADC2   = (2 * 32) + 10,
    TIM1   = (2 * 32) + 11,
    SPI1   = (2 * 32) + 12,
    TIM8   = (2 * 32) + 13,
    USART1 = (2 * 32) + 14,
    ADC3   = (2 * 32) + 15,
    TIM9   = (2 * 32) + 19,
    TIM10  = (2 * 32) + 20,
    TIM11  = (2 * 32) + 21,


}PERIPHERAL_t;

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                     Functions                                  */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

/*********************************************************************************
 * @brief Get the <b>Clamp value between min and max. </b>
 * @param[in] value: The value to clamp.
 * @param[in] min: The minimum value.
 * @param[in] max: The maximum value.
 * @return The clamped value.
 * @par Example:
 *      @code CLAMP(1.0f, 0.0f, 1.0f);    // returns 1.0f    @endcode
 *      @code CLAMP(0.0f, 0.0f, 1.0f);    // returns 0.0f    @endcode
 *      @code CLAMP(-1.0f, 0.0f, 1.0f);   // returns 0.0f    @endcode
 *      @code CLAMP(2.0f, 0.0f, 1.0f);    // returns 1.0f    @endcode
 **********************************************************************************/

ERROR_t RCC_Init(void);
ERROR_t RCC_EnableClockSecurity(void);
ERROR_t RCC_DisableClockSecurity(void);
ERROR_t RCC_ResetPeripheral(const PERIPHERAL_t peripheral);
ERROR_t RCC_EnablePeripheral(const PERIPHERAL_t peripheral);
ERROR_t RCC_DisablePeripheral(const PERIPHERAL_t peripheral);
ERROR_t RCC_HseBypass(const STATE_t bypass);
ERROR_t RCC_SetClockStatus(const RCC_CLOCK_t clock, const STATE_t state);
ERROR_t RCC_GetClockStatus(const RCC_CLOCK_t clock, STATE_t * const state);
ERROR_t RCC_GetClockSource(RCC_CLOCK_t * const clock);
ERROR_t RCC_SetClockSource(const RCC_CLOCK_t clock);
ERROR_t RCC_EnableMCO(const RCC_MCO_t mco);
ERROR_t RCC_EnableRTC(const RTC_CLOCK_t clock);
ERROR_t RCC_DisableRTC(void);

#endif  /* RCC_H */
