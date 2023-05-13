/*********************************************************************************
 * @file    RCC_private.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Private data of RCC.
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef struct RCC_t{
    volatile u32_t CR;
    volatile u32_t CFGR;
    volatile u32_t CIR;
    volatile u32_t APB2RSTR;
    volatile u32_t APB1RSTR;
    volatile u32_t AHBENR;
    volatile u32_t APB2ENR;
    volatile u32_t APB1ENR;
    volatile u32_t BDCR;
    volatile u32_t CSR;
}RCC_t;

#define RCC_BASE_ADDRESS    0x40021000
RCC_t *RCC = (RCC_t *)RCC_BASE_ADDRESS;

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                      MACROS                                    */
/*                                                                                */
/*--------------------------------------------------------------------------------*/
#define HSI     1
#define HSE     2
#define PLL     3
#define HSEDEV2 4
#define HSIDEV2 5


#define HSE_CRYSTAL   1
#define HSE_RC        2

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                   Registers                                    */
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

enum {
    CSR_LSION   = 0,
    CSR_LSIRDY  = 1,
    CSR_RMVF    = 24,
    CSR_PINRSTF = 26,
    CSR_PORRSTF = 27,
    CSR_SFTRSTF = 28,
    CSR_IWDGRSTF= 29,
    CSR_WWDGRSTF= 30,
    CSR_LPWRRSTF= 31,
};  /* CSR register  */


#endif  /* RCC_PRIVATE_H */
