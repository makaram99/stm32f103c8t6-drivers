/*********************************************************************************
 * @file    RCC.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Common RCC functions and constants.
 * @version 1.0.0
 * @date    2022-03-19
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef RCC_CFG_H
#define RCC_CFG_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                 Configurations                                 */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

/**
 * OPTIONS: HSE, HSI, PLL
 */
#define SYS_CLK_SRC     HSE

/**
 * OPTIONS: HSI_CRYSTAL, HSI_RC
 */
#define HSE_TYPE        HSE_CRYSTAL

/**
 * @brief used if PLL will be used as system clock source
 * OPTIONS: HSE, HSE_DIV2, HSI_DEV2
 */
#if SYS_CLK_SRC == PLL
#define PLL_SRC         HSE
#endif

/**
 * @brief   used if PLL will be used as system clock source
 *          PLL Multiplier Factor	
	OPTIONS: 	0b0000: PLL input clock x 2
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
#if SYS_CLK_SRC == PLL
#define PLL_MUL         0b0000
#endif

/**
 * @brief the AHB prescaler is used to divide the system clock (SYSCLK)
 * OPTIONS:
 *          0b0000: SYSCLK not divided
 *          0b1000: SYSCLK divided by 2
 *          0b1001: SYSCLK divided by 4
 *          0b1010: SYSCLK divided by 8
 *          0b1011: SYSCLK divided by 16
 *          0b1100: SYSCLK divided by 64
 *          0b1101: SYSCLK divided by 128
 *          0b1110: SYSCLK divided by 256
 *          0b1111: SYSCLK divided by 512
 */
#define AHB_PRESCALER   1

/**
 * @brief the APB2 prescaler is used to divide the AHB clock (HCLK)
 * OPTIONS: 
 *          0b000: HCLK not divided
 *          0b100: HCLK divided by 2
 *          0b101: HCLK divided by 4 
 *          0b110: HCLK divided by 8  
 *          0b111: HCLK divided by 16
 */
#define APB2_PRESCALER  1

/**
 * @brief the APB1 prescaler is used to divide the AHB clock (HCLK)
 * OPTIONS:
 *          0b000: HCLK not divided
 *          0b100: HCLK divided by 2
 *          0b101: HCLK divided by 4
 *          0b110: HCLK divided by 8
 *          0b111: HCLK divided by 16
 */
#define APB1_PRESCALER  1




/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                       DO NOT CHANGE THE FOLLOWING                              */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

/* Asserting System Clock source selection  */
#if (!defined SYS_CLK_SRC) || ( (SYS_CLK_SRC != HSE) && (SYS_CLK_SRC != HSI) && (SYS_CLK_SRC != PLL) && (SYS_CLK_SRC != LSI) )
    #if !defined SYS_CLK_SRC
        #error "System Clock Source is not defined"
    #else
        #error "Invalid System Clock Source"
    #endif
#endif

/* Asserting HSE type selection, in case of HSE used as system clock    */
#if (!defined HSE_TYPE) || ( (HSE_TYPE != HSE_CRYSTAL) && (HSE_TYPE != HSE_RC) )
    #if !defined HSE_TYPE
        #error "HSE type is not defined"
    #else
        #error "Invalid HSE type"
    #endif
#endif




#endif  /* RCC_CFG_H */
