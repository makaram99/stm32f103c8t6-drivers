/*********************************************************************************
 * @file    GPIO.c
 * @author  Mahmoud Karam Emara (ma.karam272@gmail.com)
 * @brief   GPIO driver implementation
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2023
*********************************************************************************/
#include "STD_TYPES.h"
#include "MATH.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_cfg.h"

GPIO_PIN_cfg_t gpioPinConfigs[] = {
    /* Testing Interrupts EXTI  */
    #if 0
    /* Buttons   */
    {
        .gpioPin    = GPIO_PIN_BUTTON_0,
        .pin        = PIN_0,
        .port       = PORT_B,
        .mode       = MODE_INPUT,
        .cnf        = CNF_INPUT_PUPD,
        .pupd       = PUPD_PULL_UP,
    },

    /* LEDs                                     */
    {
        .gpioPin    = GPIO_PIN_LED0,
        .pin        = PIN_0,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
		.pupd 		= PUPD_NO_PULL,
    },
	{
	    .gpioPin    = GPIO_PIN_LED1,
	    .pin        = PIN_1,
	    .port       = PORT_A,
	    .mode       = MODE_OUTPUT_2MHZ,
	    .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
		.pupd		= PUPD_NO_PULL,
	},
    {
        .gpioPin    = GPIO_PIN_LED2,
        .pin        = PIN_2,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LED3,
        .pin        = PIN_3,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LED4,
        .pin        = PIN_4,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LED5,
        .pin        = PIN_5,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LED6,
        .pin        = PIN_6,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LED7,
        .pin        = PIN_7,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd		= PUPD_NO_PULL,
    },
    #endif


    /* Testing LED Matrix   */
    #if 1
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW0,
        .pin        = PIN_0,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW1,
        .pin        = PIN_1,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW2,
        .pin        = PIN_2,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW3,
        .pin        = PIN_3,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW4,
        .pin        = PIN_4,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW5,
        .pin        = PIN_5,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW6,
        .pin        = PIN_6,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_ROW7,
        .pin        = PIN_7,
        .port       = PORT_A,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL0,
        .pin        = PIN_0,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL1,
        .pin        = PIN_1,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL2,
        .pin        = PIN_5,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL3,
        .pin        = PIN_6,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL4,
        .pin        = PIN_7,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL5,
        .pin        = PIN_8,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL6,
        .pin        = PIN_9,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },
    {
        .gpioPin    = GPIO_PIN_LEDMRX_COL7,
        .pin        = PIN_10,
        .port       = PORT_B,
        .mode       = MODE_OUTPUT_2MHZ,
        .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
        .pupd       = PUPD_NO_PULL,
    },

    #endif


};

GPIO_PORT_cfg_t gpioPortConfigs[] = {
    // {
    //     .gpioPort   = GPIO_PORT_KEYPAD,
    //     .port       = PORT_A,
    //     .mode       = MODE_OUTPUT_10MHZ,
    //     .cnf        = CNF_OUTPUT_GP_PUSH_PULL,
    //     .pupd		= PUPD_NO_PULL,
    // },
};

u8_t gpioPinConfigsSize = sizeof(gpioPinConfigs) / sizeof(gpioPinConfigs[0]);
u8_t gpioPortConfigsSize = sizeof(gpioPortConfigs) / sizeof(gpioPortConfigs[0]);
