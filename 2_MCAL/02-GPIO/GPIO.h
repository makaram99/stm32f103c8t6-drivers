/*********************************************************************************
 * @file    GPIO.h
 * @author  Mahmoud Karam (ma.karam272@gmail.com)
 * @brief   Common GPIO functions and constants.
 * @version 1.0.0
 * @date    2023-04-20
 * @copyright Copyright (c) 2022
 **********************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/*--------------------------------------------------------------------------------*/
/*                                                                                */
/*                                       Types                                    */
/*                                                                                */
/*--------------------------------------------------------------------------------*/
typedef enum GPIO_PIN_t{
    /* LEDs         */
    GPIO_PIN_LED0,
	GPIO_PIN_LED1,
    GPIO_PIN_LED2,
    GPIO_PIN_LED3,
    GPIO_PIN_LED4,
    GPIO_PIN_LED5,
    GPIO_PIN_LED6,
    GPIO_PIN_LED7,

    /* Buttons      */
    GPIO_PIN_BUTTON_0,
    GPIO_PIN_BUTTON_1,
    GPIO_PIN_BUTTON_2,

    /* 7 Segment    */
    GPIO_PIN_SSEGMENT_A, 
    GPIO_PIN_SSEGMENT_B, 
    GPIO_PIN_SSEGMENT_C, 
    GPIO_PIN_SSEGMENT_D, 
    GPIO_PIN_SSEGMENT_E, 
    GPIO_PIN_SSEGMENT_F, 
    GPIO_PIN_SSEGMENT_G, 
    GPIO_PIN_SSEGMENT_DOT,
    GPIO_PIN_SSEGMENT_EN0,
    GPIO_PIN_SSEGMENT_EN1,

    /* LED Matrix   */
    GPIO_PIN_LEDMRX_ROW0,
    GPIO_PIN_LEDMRX_ROW1,
    GPIO_PIN_LEDMRX_ROW2,
    GPIO_PIN_LEDMRX_ROW3,
    GPIO_PIN_LEDMRX_ROW4,
    GPIO_PIN_LEDMRX_ROW5,
    GPIO_PIN_LEDMRX_ROW6,
    GPIO_PIN_LEDMRX_ROW7,
    GPIO_PIN_LEDMRX_COL0,
    GPIO_PIN_LEDMRX_COL1,
    GPIO_PIN_LEDMRX_COL2,
    GPIO_PIN_LEDMRX_COL3,
    GPIO_PIN_LEDMRX_COL4,
    GPIO_PIN_LEDMRX_COL5,
    GPIO_PIN_LEDMRX_COL6,
    GPIO_PIN_LEDMRX_COL7,

}GPIO_PIN_t;

typedef enum GPIO_PORT_t{
    GPIO_PORT_KEYPAD,
    GPIO_PORT_LENGTH
}GPIO_PORT_t;

typedef enum PUPD_t{
    PUPD_NO_PULL,
    PUPD_PULL_UP,
    PUPD_PULL_DOWN,
    PUPD_LENGTH
}PUPD_t;

typedef enum DIRECTION_t{
    DIRECTION_INPUT,
    DIRECTION_OUTPUT,
    DIRECTION_LENGTH
}DIRECTION_t;


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
ERROR_t GPIO_Initialize(void);
ERROR_t GPIO_SetPinValue(const GPIO_PIN_t gpioPin, const STATE_t state);
#define GPIO_SetPin(pin)    GPIO_SetPinValue(pin, HIGH)
#define GPIO_ClrPin(pin)    GPIO_SetPinValue(pin, LOW)
ERROR_t GPIO_GetPinValue(const GPIO_PIN_t pin, STATE_t * const state);
ERROR_t GPIO_TogglePin(const GPIO_PIN_t pin);
ERROR_t GPIO_SetPinPuPd(const GPIO_PIN_t pin, const PUPD_t pupd);
ERROR_t GPIO_SetPortValue(const GPIO_PORT_t gpioPort, const u32_t value);
ERROR_t GPIO_GetPortValue(const GPIO_PORT_t gpioPort, u32_t * const value);
ERROR_t GPIO_SetPortPuPd(const GPIO_PORT_t port, const PUPD_t pupd);
ERROR_t GPIO_SetPinDirection(const GPIO_PIN_t pin, const DIRECTION_t direction);
ERROR_t GPIO_LockPin(const GPIO_PIN_t pin);
ERROR_t GPIO_SetPortDirection(const GPIO_PORT_t port, const DIRECTION_t direction);
ERROR_t GPIO_LockPort(const GPIO_PORT_t port);

#endif  /* GPIO_H */
