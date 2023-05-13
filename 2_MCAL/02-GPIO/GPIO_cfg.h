/*********************************************************************************
 * @file    GPIO.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Common GPIO functions and constants.
 * @version 1.0.0
 * @date    2022-03-19
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                       DO NOT CHANGE THE FOLLOWING                              */
/*                                                                                */
/*--------------------------------------------------------------------------------*/
typedef enum PIN_t{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
    PIN_LENGTH
}PIN_t;

typedef enum PORT_t{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    PORT_G,
    PORT_LENGTH
}PORT_t;

typedef enum MODE_t{
    MODE_INPUT,
    MODE_OUTPUT_10MHZ,
    MODE_OUTPUT_2MHZ,
    MODE_OUTPUT_50MHZ,
    MODE_LENGTH
}MODE_t;

typedef enum CNF_t{
    CNF_INPUT_ANALOG            = 0,
    CNF_INPUT_FLOATING          = 1,
    CNF_INPUT_PUPD              = 2,
    CNF_OUTPUT_GP_PUSH_PULL     = 0,
    CNF_OUTPUT_GP_OPEN_DRAIN    = 1,
    CNF_OUTPUT_AF_PUSH_PULL     = 2,
    CNF_OUTPUT_AF_OPEN_DRAIN    = 3,
    CNF_LENGTH
}CNF_t;

typedef struct GPIO_PIN_cfg_t{
    GPIO_PIN_t  gpioPin;
    PIN_t       pin;
    PORT_t      port;
    MODE_t      mode;
    CNF_t       cnf;
    PUPD_t      pupd;
}GPIO_PIN_cfg_t;

typedef struct GPIO_PORT_cfg_t{
    GPIO_PORT_t gpioPort;
    PORT_t      port;
    MODE_t      mode;
    CNF_t       cnf;
    PUPD_t      pupd;
}GPIO_PORT_cfg_t;

extern GPIO_PIN_cfg_t gpioPinConfigs[];
extern u8_t gpioPinConfigsSize;

extern GPIO_PORT_cfg_t gpioPortConfigs[];
extern u8_t gpioPortConfigsSize;

#endif  /* GPIO_CFG_H */
