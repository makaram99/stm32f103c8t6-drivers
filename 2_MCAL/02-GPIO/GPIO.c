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
#include "GPIO_private.h"
#include "GPIO.h"
#include "GPIO_cfg.h"


/*********************************************************************************
 *                                                                               *
 *                         Static Functions Prototypes                           *
 *                                                                               *
*********************************************************************************/
static ERROR_t GPIO_SetMode(const PIN_t pin, const PORT_t port, const MODE_t mode);
static ERROR_t GPIO_SetCnf(const PIN_t pin, const PORT_t port, const CNF_t cnf);
static ERROR_t GPIO_GetPinMapping(const GPIO_PIN_t gpioPin, PIN_t * const pin, PORT_t * const port);
static ERROR_t GPIO_GetReg(const PORT_t port, GPIO_t ** const GPIO_reg);

/*********************************************************************************
 *                                                                               *
 *                               Macro Functions                                 *
 *                                                                               *
 *********************************************************************************/
#define ASSERT_PIN(pin, error)      do{if(pin >= PIN_LENGTH) { error |= ERROR_NOK; } }while(0)
#define ASSERT_PORT(port, error)    do{if(port >= PORT_LENGTH) { error |= ERROR_NOK; } }while(0)
#define ASSERT_MODE(mode, error)    do{if(mode >= MODE_LENGTH) { error |= ERROR_NOK; } }while(0)
#define ASSERT_CNF(cnf, error)      do{if(cnf >= CNF_LENGTH) { error |= ERROR_NOK; } }while(0)
#define ASSERT_ERROR(error)         do{if(error != ERROR_OK) { return error; } }while(0)
#define ASSERT_PUPD(pupd, error)    do{if(pupd >= PUPD_LENGTH) { error |= ERROR_NOK; } }while(0)
#define ASSERT_DIRECTION(direction, error) do{if(direction >= DIRECTION_LENGTH) { error |= ERROR_NOK; } }while(0)


/*********************************************************************************
 *                                                                               *
 *                              Global Functions                                 * 
 *                                                                               *
*********************************************************************************/

ERROR_t GPIO_Initialize(void) {
    ERROR_t error = ERROR_OK;
    u8_t i = 0, j = 0;

    /* Configuring gpioPins Array   */
    for (i = 0; i < gpioPinConfigsSize; ++i) {
        error |= GPIO_SetMode(gpioPinConfigs[i].pin, gpioPinConfigs[i].port, gpioPinConfigs[i].mode);
        error |= GPIO_SetCnf(gpioPinConfigs[i].pin, gpioPinConfigs[i].port, gpioPinConfigs[i].cnf);

        if(CNF_INPUT_PUPD == gpioPinConfigs[i].cnf) {
            error |= GPIO_SetPinPuPd(gpioPinConfigs[i].gpioPin, gpioPinConfigs[i].pupd);
        }

        ASSERT_ERROR(error);
    }

    /* Configuring gpioPorts Array   */
    for(i = 0; i < gpioPortConfigsSize; ++i) {
        for(j = 0; j < 32; ++j) {
            error |= GPIO_SetMode(j, gpioPortConfigs[i].port, gpioPortConfigs[i].mode);
            error |= GPIO_SetCnf(j, gpioPortConfigs[i].port, gpioPortConfigs[i].cnf);

            ASSERT_ERROR(error);
        }

        if(CNF_INPUT_PUPD == gpioPortConfigs[i].cnf) {
            error |= GPIO_SetPortPuPd(j, gpioPortConfigs[i].pupd);
        }

        ASSERT_ERROR(error);
    }

    return error;
}

ERROR_t GPIO_SetPinValue(const GPIO_PIN_t gpioPin, const STATE_t state) {
    ERROR_t error = ERROR_OK;
    GPIO_t * GPIO_reg = NULL;
    PIN_t pin = 0;
    PORT_t port = 0;

    error |= GPIO_GetPinMapping(gpioPin, &pin, &port);
    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    volatile u32_t val = GPIO_reg->BSRR;

    if(HIGH == state) {
        GPIO_reg->BSRR = 1 << pin;
    } else {
        GPIO_reg->BRR = 1 << pin;
    }

    return error;
}

ERROR_t GPIO_GetPinValue(const GPIO_PIN_t gpioPin, STATE_t * const state) {
    GPIO_t * GPIO_reg = NULL;
    PIN_t pin = 0;
    PORT_t port = 0;
    ERROR_t error = ERROR_OK;

    ASSERT_PTR(state);

    error |= GPIO_GetPinMapping(gpioPin, &pin, &port);
    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    *state = GET_BIT(GPIO_reg->IDR, pin);

    return error;
}

ERROR_t GPIO_TogglePin(const GPIO_PIN_t gpioPin) {
    STATE_t state = 0;
    ERROR_t error = ERROR_OK;

    error |= GPIO_GetPinValue(gpioPin, &state);

    ASSERT_ERROR(error);

    error |= ( state ? GPIO_ClrPin(gpioPin) : GPIO_SetPin(gpioPin) );

    return error;
}

ERROR_t GPIO_SetPinPuPd(const GPIO_PIN_t gpioPin, const PUPD_t pupd) {
    ERROR_t error = ERROR_OK;
    PIN_t pin = 0;
    PORT_t port = 0;
    GPIO_t *GPIO_reg = NULL;

    error |= GPIO_GetPinMapping(gpioPin, &pin, &port);
    error |= GPIO_GetReg(port, &GPIO_reg);

    ASSERT_PORT(port, error);
    ASSERT_PUPD(pupd, error);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    if(pupd != PUPD_NO_PULL) {
        if(pupd == PUPD_PULL_UP)
            SET_BIT(GPIO_reg->ODR, pin);
        else
            CLR_BIT(GPIO_reg->ODR, pin);
    }

    return error;
}

ERROR_t GPIO_SetPortValue(const GPIO_PORT_t gpioPort, const u32_t value) {
    ERROR_t error = ERROR_OK;
    GPIO_t *GPIO_reg = NULL;

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    error |= GPIO_GetReg(gpioPort, &GPIO_reg);

    GPIO_reg->ODR = value;

    return error;
}

ERROR_t GPIO_GetPortValue(const GPIO_PORT_t gpioPort, u32_t * const value) {
    ERROR_t error = ERROR_OK;
    GPIO_t *GPIO_reg = NULL;

    ASSERT_PTR(value);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    error |= GPIO_GetReg(gpioPort, &GPIO_reg);

    *value = GPIO_reg->IDR;

    return error;
}

ERROR_t GPIO_SetPinDirection(const GPIO_PIN_t gpioPin, const DIRECTION_t direction) {
    ERROR_t error = ERROR_OK;
    PIN_t pin = 0;
    PORT_t port = 0;

    ASSERT_DIRECTION(direction, error);

    error |= GPIO_GetPinMapping(gpioPin, &pin, &port);

    switch(direction) {
        case DIRECTION_INPUT:
            error |= GPIO_SetMode(pin, port, MODE_INPUT);
            error |= GPIO_SetCnf(pin, port, CNF_INPUT_FLOATING);
            break;
        case DIRECTION_OUTPUT:
            error |= GPIO_SetMode(pin, port, MODE_OUTPUT_10MHZ);
            error |= GPIO_SetCnf(pin, port, CNF_OUTPUT_GP_PUSH_PULL);
            break;
        default:
            error |= ERROR_NOK;
            break;
    }
    
    return error;
}

ERROR_t GPIO_LockPin(const GPIO_PIN_t gpioPin) {
    ERROR_t error = ERROR_OK;
    GPIO_t * GPIO_reg = NULL;
    PIN_t pin = 0;
    PORT_t port = 0;

    error |= GPIO_GetPinMapping(gpioPin, &pin, &port);
    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    /* Set LCKK bit to lock the configuration of the selected pins */
    GPIO_reg->LCKR |= (1 << pin);

    /* Write sequence on LCKR bit 16 */
    SET_BIT(GPIO_reg->LCKR, 16);
    CLR_BIT(GPIO_reg->LCKR, 16);
    SET_BIT(GPIO_reg->LCKR, 16);
    GET_BIT(GPIO_reg->LCKR, 16);

    error |= ( GET_BIT(GPIO_reg->LCKR, 16) ? ERROR_OK : ERROR_NOK );

    return error;
}

ERROR_t GPIO_SetPortDirection(const GPIO_PORT_t gpioPort, const DIRECTION_t direction) {
    ERROR_t error = ERROR_OK;
    u8_t i = 0;

    ASSERT_DIRECTION(direction, error);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    switch(direction) {
        case DIRECTION_INPUT:
            for(i = 0; i < 32; ++i) {
                error |= GPIO_SetMode(i, gpioPort, MODE_INPUT);
                error |= GPIO_SetCnf(i, gpioPort, CNF_INPUT_FLOATING);
            }
            break;
        case DIRECTION_OUTPUT:
            for(i = 0; i < 32; ++i) {
                error |= GPIO_SetMode(i, gpioPort, MODE_OUTPUT_10MHZ);
                error |= GPIO_SetCnf(i, gpioPort, CNF_OUTPUT_GP_PUSH_PULL);
            }
            break;
        default:
            error |= ERROR_NOK;
            break;
    }

    return error;
}

ERROR_t GPIO_SetPortPuPd(const GPIO_PORT_t gpioPort, const PUPD_t pupd) {
    ERROR_t error = ERROR_OK;
    GPIO_t *GPIO_reg = NULL;
    u8_t i = 0;

    ASSERT_PUPD(pupd, error);
    error |= GPIO_GetReg(gpioPort, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    if(pupd != PUPD_NO_PULL) {
        for(i = 0; i < 32; ++i) {
            CTRL_BIT(GPIO_reg->ODR, i, pupd);
        }
    }

    return error;
}


ERROR_t GPIO_LockPort(const GPIO_PORT_t gpioPort) {
    ERROR_t error = ERROR_OK;
    PORT_t port = 0;
    GPIO_t * GPIO_reg = NULL;
    u8_t i = 0;

    for(i = 0; i < gpioPortConfigsSize; ++i) {
        if(gpioPortConfigs[i].gpioPort == gpioPort) {
            port = gpioPortConfigs[i].port;
            break;
        }
    }

    if(i == gpioPortConfigsSize) {
        error |= ERROR_NOK;
    }

    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    /* Lock the configuration of the selected pins */
    GPIO_reg->LCKR = 0xff;

    /* Write sequence on LCKR bit 16 */
    SET_BIT(GPIO_reg->LCKR, 16);
    CLR_BIT(GPIO_reg->LCKR, 16);
    SET_BIT(GPIO_reg->LCKR, 16);
    GET_BIT(GPIO_reg->LCKR, 16);

    error |= ( GET_BIT(GPIO_reg->LCKR, 16) ? ERROR_OK : ERROR_NOK );

    return error;
}

/*********************************************************************************
 *                                                                               *
 *                             Static Functions                                  *
 *                                                                               *
*********************************************************************************/
static ERROR_t GPIO_SetMode(const PIN_t pin, const PORT_t port, const MODE_t mode) {
    ERROR_t error = ERROR_OK;
    GPIO_t *GPIO_reg = NULL;

    ASSERT_PIN(pin, error);
    ASSERT_PORT(port, error);
    ASSERT_MODE(mode, error);

    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    if(pin < PIN_8) {
        GPIO_reg->CRL &= ~(0b11 << (pin * 4));
        GPIO_reg->CRL |= (mode << (pin * 4));
    } else {
        GPIO_reg->CRH &= ~(0b11 << ((pin - 8) * 4));
        GPIO_reg->CRH |= (mode << ((pin - 8) * 4));
    }

    return error;
}

static ERROR_t GPIO_SetCnf(const PIN_t pin, const PORT_t port, const CNF_t cnf) {
    ERROR_t error = ERROR_OK;
    GPIO_t *GPIO_reg = NULL;

    ASSERT_PIN(pin, error);
    ASSERT_PORT(port, error);
    ASSERT_CNF(cnf, error);

    error |= GPIO_GetReg(port, &GPIO_reg);

    /* Assert error before processing   */
    ASSERT_ERROR(error);

    if(pin < PIN_8) {
        GPIO_reg->CRL &= ~(0b11 << (pin * 4 + 2));
        GPIO_reg->CRL |= (cnf << (pin * 4 + 2));
    } else {
        GPIO_reg->CRH &= ~(0b11 << ((pin - 8) * 4 + 2));
        GPIO_reg->CRH |= (cnf << ((pin - 8) * 4 + 2));
    }

    return error;
}

static ERROR_t GPIO_GetPinMapping(const GPIO_PIN_t gpioPin, PIN_t * const pin, PORT_t * const port) {
    ERROR_t error = ERROR_OK;
    u8_t i = 0;

    ASSERT_PTR(pin);
    ASSERT_PTR(port);

    for (i = 0; i < gpioPinConfigsSize; ++i) {
        if(gpioPinConfigs[i].gpioPin == gpioPin) {
            *pin = gpioPinConfigs[i].pin;
            *port = gpioPinConfigs[i].port;
            break;
        }
    }

    if(i == gpioPinConfigsSize) {
        error |= ERROR_NOK;
    }

    ASSERT_PIN(*pin, error);
    ASSERT_PORT(*port, error);

    ASSERT_ERROR(error);

    return error;
}

static ERROR_t GPIO_GetReg(const PORT_t port, GPIO_t ** const GPIO_reg) {
    ERROR_t error = ERROR_OK;

    ASSERT_PORT(port, error);
    ASSERT_PTR(GPIO_reg);

    switch(port) {
        case PORT_A:
            *GPIO_reg = GPIOA;
            break;
        case PORT_B:
            *GPIO_reg = GPIOB;
            break;
        case PORT_C:
            *GPIO_reg = GPIOC;
            break;
        case PORT_D:
            *GPIO_reg = GPIOD;
            break;
        case PORT_E:
            *GPIO_reg = GPIOE;
            break;
        case PORT_F:
            *GPIO_reg = GPIOF;
            break;
        case PORT_G:
            *GPIO_reg = GPIOG;
            break;
        default:
            error |= ERROR_NOK;
            break;
    }

    return error;
}
