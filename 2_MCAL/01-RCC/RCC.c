/*********************************************************************************
 * @file    RCC.c
 * @author  Mahmoud Karam Emara (ma.karam272@gmail.com)
 * @brief   RCC driver implementation
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2023
*********************************************************************************/
#include "STD_TYPES.h"
#include "MATH.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "RCC.h"
#include "RCC_cfg.h"

/*********************************************************************************
 *                                                                               *
 *                         Static Functions Prototypes                           *
 *                                                                               *
*********************************************************************************/
static ERROR_t RCC_ControlClockSecurity(const STATE_t state);
static ERROR_t RCC_ControlPeripheral(const PERIPHERAL_t peripheral, const STATE_t state);
static ERROR_t RCC_InitClock(void);
static ERROR_t RCC_SetAHBPrescaler(void);
static ERROR_t RCC_SetAPB1Prescaler(void);
static ERROR_t RCC_SetAPB2Prescaler(void);
static ERROR_t RCC_ControlRTC(const STATE_t state, const RTC_CLOCK_t clock);


/*********************************************************************************
 *                                                                               *
 *                              Global Functions                                 * 
 *                                                                               *
*********************************************************************************/

ERROR_t RCC_Init(void) {
    ERROR_t error = ERROR_OK;

    error |= RCC_InitClock();


    /* Enable or disable clock security system                 : RCC_CR */
    
    /* Enable or disable MCO (Microcontroller Clock Output)    : RCC_CFGR */

    /* AHB, APB1, and APB2 prescaler selection                 : RCC_CFGR */
    error |= RCC_SetAHBPrescaler();
    error |= RCC_SetAPB1Prescaler();
    error |= RCC_SetAPB2Prescaler();

    /* Enable clocks interrupts                                : RCC_CIR */

    return error;
}

ERROR_t RCC_EnableClockSecurity(void) { 
    return RCC_ControlClockSecurity(HIGH);
}

ERROR_t RCC_DisableClockSecurity(void) {
    return RCC_ControlClockSecurity(LOW);
}

ERROR_t RCC_ResetPeripheral(const PERIPHERAL_t peripheral) {
    ERROR_t error = ERROR_OK;

    switch(peripheral)
    {    
    case TIM2:  case TIM3:  case TIM4:  case TIM5:  case TIM6:  case TIM7:  case TIM12:
    case TIM13: case TIM14: case WWDG:  case SPI2:  case SPI3:  case USART2:case USART3:    
    case UART4: case UART5: case I2C1:  case I2C2:  case USB:   case CAN:   case BKP:
    case PWR:   case DAC:
        SET_BIT(RCC->APB1RSTR, peripheral % 32);
        break;
    
    case AFIO:  case IOPA:  case IOPB:  case IOPC:  case IOPD:  case IOPE:  case IOPF:
    case IOPG:  case ADC1:  case ADC2:  case TIM1:  case SPI1:  case TIM8:  case USART1:
    case ADC3:  case TIM9:  case TIM10: case TIM11:
        SET_BIT(RCC->APB2RSTR, peripheral % 32);
        break;

    default:
        error = ERROR_NOK;
        break;
    }

    return error;
}

ERROR_t RCC_EnablePeripheral(const PERIPHERAL_t peripheral) {
    return RCC_ControlPeripheral(peripheral, HIGH);
}

ERROR_t RCC_DisablePeripheral(const PERIPHERAL_t peripheral) {
    return RCC_ControlPeripheral(peripheral, LOW);
}

ERROR_t RCC_HseBypass(const STATE_t bypass) {
    ERROR_t error = ERROR_OK;

    switch(bypass)
    {
    case HIGH:
        SET_BIT(RCC->CR, CR_HSEBYP);
        break;

    case LOW:
        CLR_BIT(RCC->CR, CR_HSEBYP);
        break;
    
    default:
        error = ERROR_NOK;
        break;
    }

    return error;
}

ERROR_t RCC_SetClockStatus(const RCC_CLOCK_t clock, const STATE_t state) {
    ERROR_t error = ERROR_OK;

    switch(clock) {
        case RCC_CLOCK_HSI:
            CTRL_BIT(RCC->CR, CR_HSION, state);
            if (state == HIGH) {
                while(BIT_IS_CLEAR(RCC->CR, CR_HSIRDY));
            }
            break;
        case RCC_CLOCK_HSE:
            CTRL_BIT(RCC->CR, CR_HSEON, state);
            if (state == HIGH) {
                while(BIT_IS_CLEAR(RCC->CR, CR_HSERDY));
            }
            break;
        case RCC_CLOCK_PLL:
            CTRL_BIT(RCC->CR, CR_PLLON, state);
            if (state == HIGH) {
                while(BIT_IS_CLEAR(RCC->CR, CR_PLLRDY));
            }
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t RCC_GetClockStatus(const RCC_CLOCK_t clock, STATE_t * const state) {
    ERROR_t error = ERROR_OK;

    ASSERT_PTR(state);

    switch(clock) {
        case HSI:
            *state = GET_BIT(RCC->CR, CR_HSIRDY);
            break;
        case HSE:
            *state = GET_BIT(RCC->CR, CR_HSERDY);
            break;
        case PLL:
            *state = GET_BIT(RCC->CR, CR_PLLRDY);
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t RCC_GetClockSource(RCC_CLOCK_t * const clock) {
    ERROR_t error = ERROR_OK;
    u8_t sws = 0;

    ASSERT_PTR(clock);

    sws = GET_BIT(RCC->CFGR, CFGR_SWS) | ( GET_BIT(RCC->CFGR, CFGR_SWS + 1) << 1);
    switch(sws) {
        case 0b00:
            *clock = RCC_CLOCK_HSI;
            break;
        case 0b01:
            *clock = RCC_CLOCK_HSE;
            break;
        case 0b10:
            *clock = RCC_CLOCK_PLL;
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t RCC_SetClockSource(const RCC_CLOCK_t clock) {
    ERROR_t error = ERROR_OK;

    switch(clock) {
        case RCC_CLOCK_HSI:
            CLR_BIT(RCC->CFGR, CFGR_SW);
            CLR_BIT(RCC->CFGR, CFGR_SW + 1);
            break;
        case RCC_CLOCK_HSE:
            SET_BIT(RCC->CFGR, CFGR_SW);
            CLR_BIT(RCC->CFGR, CFGR_SW + 1);
            break;
        case RCC_CLOCK_PLL:
            CLR_BIT(RCC->CFGR, CFGR_SW);
            SET_BIT(RCC->CFGR, CFGR_SW + 1);
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t RCC_EnableMCO(const RCC_MCO_t mco) {
    ERROR_t error = ERROR_OK;

    switch(mco) {
        case RCC_MCO_NOCLOCK:
            CLR_BIT(RCC->CFGR, CFGR_MCO);
            CLR_BIT(RCC->CFGR, CFGR_MCO + 1);
            CLR_BIT(RCC->CFGR, CFGR_MCO + 2);
            break;
        case RCC_MCO_SYSCLK:
            CLR_BIT(RCC->CFGR, CFGR_MCO);
            CLR_BIT(RCC->CFGR, CFGR_MCO + 1);
            SET_BIT(RCC->CFGR, CFGR_MCO + 2);
            break;
        case RCC_MCO_HSI:
            SET_BIT(RCC->CFGR, CFGR_MCO);
            CLR_BIT(RCC->CFGR, CFGR_MCO + 1);
            SET_BIT(RCC->CFGR, CFGR_MCO + 2);
            break;
        case RCC_MCO_HSE:
            CLR_BIT(RCC->CFGR, CFGR_MCO);
            SET_BIT(RCC->CFGR, CFGR_MCO + 1);
            SET_BIT(RCC->CFGR, CFGR_MCO + 2);
            break;
        case RCC_MCO_PLL_DIV2:
            SET_BIT(RCC->CFGR, CFGR_MCO);
            SET_BIT(RCC->CFGR, CFGR_MCO + 1);
            SET_BIT(RCC->CFGR, CFGR_MCO + 2);
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t RCC_EnableRTC(const RTC_CLOCK_t clock) {
    return RCC_ControlRTC(HIGH, clock);
}

ERROR_t RCC_DisableRTC(void) {
    return RCC_ControlRTC(LOW, 0);
}

/*********************************************************************************
 *                                                                               *
 *                             Static Functions                                  *
 *                                                                               *
*********************************************************************************/

static ERROR_t RCC_ControlClockSecurity(const STATE_t state) {
    ERROR_t error = ERROR_OK;
    switch(state)
    {
    case HIGH:
        SET_BIT(RCC->CR, CR_CSSON);
        break;

    case LOW:
        CLR_BIT(RCC->CR, CR_CSSON);
        break;
    
    default:
        error = ERROR_NOK;
        break;
    }

    return error;
}

static ERROR_t RCC_ControlPeripheral(const PERIPHERAL_t peripheral, const STATE_t state) {
    ERROR_t error = ERROR_OK;
    u8_t i = 0;

    switch(peripheral)
    {
    case DMA1:  case DMA2:  case SRAM:  case FLITF: case CRCE:  case FSMC:  case SDIO:
        CTRL_BIT(RCC->AHBENR, peripheral % 32, state);
        break;
    
    case TIM2:  case TIM3:  case TIM4:  case TIM5:  case TIM6:  case TIM7:  case TIM12:
    case TIM13: case TIM14: case WWDG:  case SPI2:  case SPI3:  case USART2:case USART3:    
    case UART4: case UART5: case I2C1:  case I2C2:  case USB:   case CAN:   case BKP:
    case PWR:   case DAC:
        CTRL_BIT(RCC->APB1ENR, peripheral % 32, state);
        break;
    
    case AFIO:  case IOPA:  case IOPB:  case IOPC:  case IOPD:  case IOPE:  case IOPF:
    case IOPG:  case ADC1:  case ADC2:  case TIM1:  case SPI1:  case TIM8:  case USART1:
    case ADC3:  case TIM9:  case TIM10: case TIM11:
        CTRL_BIT(RCC->APB2ENR, peripheral % 32, state);
        break;

    default:
        error = ERROR_NOK;
        break;
    }

    /* Delay for some time to enable correctly	*/
    for(i = 0; i < 255; ++i);

    return error;
}

static ERROR_t RCC_InitClock(void) {
    /* Calibrate the configured clock                          : RCC_CR */

    /* Trim the configured clock                               : RCC_CR */

    /* PLL mutiplier                                           : RCC_CFGR */
    #if SYS_CLK_SRC == PLL

    #endif

    /* Turn on the configured clock */
    #if SYS_CLK_SRC == HSE
        #if HSE_TYPE == HSE_CRYSTAL
            SET_BIT(RCC->CR, CR_HSEON);
            while(BIT_IS_CLEAR(RCC->CR, CR_HSERDY));
        #elif HSE_TYPE == HSE_RC
            SET_BIT(RCC->CR, CR_HSEBYP);    /* HSEBYP must be set before HSEON */
            SET_BIT(RCC->CR, CR_HSEON);
            while(BIT_IS_CLEAR(RCC->CR, CR_HSERDY));
        #else
            #error "HSE_TYPE is not defined"
        #endif

    #elif SYS_CLK_SRC == HSI
        SET_BIT(RCC->CR, CR_HSION);
        while(BIT_IS_CLEAR(RCC->CR, CR_HSIRDY));

    #elif SYS_CLK_SRC == PLL
        #if PLL_SRC == HSE
            SET_BIT(RCC->CR, CR_HSEON);
            while(BIT_IS_CLEAR(RCC->CR, CR_HSERDY));
        #elif PLL_SRC == HSE_DIV_2
            SET_BIT(RCC->CR, CR_HSEON);
            SET_BIT(RCC->CR, CFGR_PLLXTPRE);
            while(BIT_IS_CLEAR(RCC->CR, CR_HSERDY));
        #elif PLL_SRC == HSI_DIV_2
            SET_BIT(RCC->CR, CR_HSION);
            while(BIT_IS_CLEAR(RCC->CR, CR_HSIRDY));
        #else
            #error "PLL_SRC is not defined"
        #endif
        SET_BIT(RCC->CR, CR_PLLON);
        while(BIT_IS_CLEAR(RCC->CR, CR_PLLRDY));

    #else 
        #error "Invalid System Clock Source"
    #endif

    /* Select system clock source */
	RCC->CFGR &= ~(0x3 << CFGR_SW);
    #if SYS_CLK_SRC == PLL
	RCC->CFGR |= (SYS_CLK_SRC << CFGR_SW) | (RCC_PLL_MUL << 18);
    #else
    RCC->CFGR |= (SYS_CLK_SRC << CFGR_SW);
    #endif

    return ERROR_OK;
}

static ERROR_t RCC_SetAHBPrescaler(void) {
    ERROR_t error = ERROR_OK;
    
    RCC->CFGR &= ~(0xF << CFGR_HPRE);
    RCC->CFGR |= (AHB_PRESCALER << CFGR_HPRE);

    return error;
}

static ERROR_t RCC_SetAPB1Prescaler(void) {
    ERROR_t error = ERROR_OK;
    
    RCC->CFGR &= ~(0x7 << CFGR_PPRE1);
    RCC->CFGR |= (APB1_PRESCALER << CFGR_PPRE1);

    return error;
}

static ERROR_t RCC_SetAPB2Prescaler(void) {
    ERROR_t error = ERROR_OK;
    
    RCC->CFGR &= ~(0x7 << CFGR_PPRE2);
    RCC->CFGR |= (APB2_PRESCALER << CFGR_PPRE2);

    return error;
}

static ERROR_t RCC_ControlRTC(const STATE_t state, const RTC_CLOCK_t clock) {
    ERROR_t error = ERROR_OK;

    switch(clock) {
        case RTC_CLOCK_LSI:
            CTRL_BIT(RCC->CSR, CSR_LSION, state);
            if (state == HIGH) {
                while(BIT_IS_CLEAR(RCC->CSR, CSR_LSIRDY));

                CLR_BIT(RCC->BDCR, BDCR_RTCSEL);
                SET_BIT(RCC->BDCR, BDCR_RTCSEL + 1);
            }

            CTRL_BIT(RCC->BDCR, BDCR_RTCEN, state);
            break;
        case RTC_CLOCK_LSE:
            CTRL_BIT(RCC->BDCR, BDCR_LSEON, state);
            if (state == HIGH) {
                while(BIT_IS_CLEAR(RCC->BDCR, BDCR_LSERDY));

                SET_BIT(RCC->BDCR, BDCR_RTCSEL);
                CLR_BIT(RCC->BDCR, BDCR_RTCSEL + 1);
            }

            CTRL_BIT(RCC->BDCR, BDCR_RTCEN, state);
            break;
        default:
            error = ERROR_NOK;
            break;
    }

    return error;
}


