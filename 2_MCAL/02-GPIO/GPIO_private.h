/*********************************************************************************
 * @file    GPIO_private.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Private data of GPIO.
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                   Registers                                    */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

typedef struct GPIO_t{
    volatile u32_t CRL;
    volatile u32_t CRH;
    volatile u32_t IDR;
    volatile u32_t ODR;
    volatile u32_t BSRR;
    volatile u32_t BRR;
    volatile u32_t LCKR;
}GPIO_t;

#define GPIOA_BASE_ADDRESS    0x40010800
#define GPIOA   ((GPIO_t *)GPIOA_BASE_ADDRESS)

#define GPIOB_BASE_ADDRESS    0x40010c00
#define GPIOB   ((GPIO_t *)GPIOB_BASE_ADDRESS)

#define GPIOC_BASE_ADDRESS    0x40011000
#define GPIOC   ((GPIO_t *)GPIOC_BASE_ADDRESS)

#define GPIOD_BASE_ADDRESS    0x40011400
#define GPIOD   ((GPIO_t *)GPIOD_BASE_ADDRESS)

#define GPIOE_BASE_ADDRESS    0x40011800
#define GPIOE   ((GPIO_t *)GPIOE_BASE_ADDRESS)

#define GPIOF_BASE_ADDRESS    0x40011C00
#define GPIOF   ((GPIO_t *)GPIOF_BASE_ADDRESS)

#define GPIOG_BASE_ADDRESS    0x40012000
#define GPIOG   ((GPIO_t *)GPIOG_BASE_ADDRESS)

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                               Registers Bits                                   */
/*                                                                                */
/*--------------------------------------------------------------------------------*/

enum {
    CR_HSION   = 0,
    CR_HSIRDY  = 1,
    CR_HSITRIM = 3,
    CR_HSICAL  = 8,
    CR_HSEON   = 16,
    CR_HSERDY  = 17,
    CR_HSEBYP  = 18,
    CR_CSSON   = 19,
    CR_PLLON   = 24,
    CR_PLLRDY  = 25,
};  /* CR register  */

enum {
    CFGR_SW    = 0,
    CFGR_SWS   = 2,
    CFGR_HPRE  = 4,
    CFGR_PPRE1 = 8,
    CFGR_PPRE2 = 11,
    CFGR_ADCPRE= 14,
    CFGR_PLLSRC= 16,
    CFGR_PLLXTPRE = 17,
    CFGR_PLLMUL = 18,
    CFGR_USBPRE = 22,
    CFGR_MCO    = 24,
};  /* CFGR register  */

enum {
    CIR_LSIRDYF = 0,
    CIR_LSERDYF = 1,
    CIR_HSIRDYF = 2,
    CIR_HSERDYF = 3,
    CIR_PLLRDYF = 4,
    CIR_CSSF    = 7,
    CIR_LSIRDYIE= 8,
    CIR_LSERDYIE= 9,
    CIR_HSIRDYIE= 10,
    CIR_HSERDYIE= 11,
    CIR_PLLRDYIE= 12,
    CIR_LSIRDYC = 16,
    CIR_LSERDYC = 17,
    CIR_HSIRDYC = 18,
    CIR_HSERDYC = 19,
    CIR_PLLRDYC = 20,
    CIR_CSSC    = 23,
};  /* CIR register  */

enum {
    BDCR_LSEON  = 0,
    BDCR_LSERDY = 1,
    BDCR_LSEBYP = 2,
    BDCR_RTCSEL = 8,
    BDCR_RTCEN  = 15,
    BDCR_BDRST  = 16,
};  /* BDCR register  */


#endif  /* GPIO_PRIVATE_H */
