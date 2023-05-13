#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "SSEGMENT.h"
#include "SSEGMENT_cfg.h"

/**********************************************************************************
 * @brief   Equivalent codes for segment common cathode connection 
 * @note    This is used when no BCD IC is used 
 *********************************************************************************/
u8_t digitsConfigs[] = {
    0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110,             /* 0 ~ 4    */
    0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111,             /* 5 ~ 9    */
    0b1110111, 0b1111100, 0b0111001, 0b1011110, 0b1111001, 0b1110001  /* A ~ F    */
};

SSEGMENT_CONFIGS_t segmentsConfigs[] = {
    {
        .segment    = SSEGMENT_0, 
        .pinA       = GPIO_PIN_SSEGMENT_A,
        .pinB       = GPIO_PIN_SSEGMENT_B,
        .pinC       = GPIO_PIN_SSEGMENT_C,
        .pinD       = GPIO_PIN_SSEGMENT_D,
        .pinE       = GPIO_PIN_SSEGMENT_E,
        .pinF       = GPIO_PIN_SSEGMENT_F,
        .pinG       = GPIO_PIN_SSEGMENT_G,
        .pinDot     = GPIO_PIN_SSEGMENT_DOT,
        .pinEN      = GPIO_PIN_SSEGMENT_EN0,
        .anodeOrCathode = COMMON_CATHODE
    },
    {
        .segment    = SSEGMENT_1, 
        .pinA       = GPIO_PIN_SSEGMENT_A,
        .pinB       = GPIO_PIN_SSEGMENT_B,
        .pinC       = GPIO_PIN_SSEGMENT_C,
        .pinD       = GPIO_PIN_SSEGMENT_D,
        .pinE       = GPIO_PIN_SSEGMENT_E,
        .pinF       = GPIO_PIN_SSEGMENT_F,
        .pinG       = GPIO_PIN_SSEGMENT_G,
        .pinDot     = GPIO_PIN_SSEGMENT_DOT,
        .pinEN      = GPIO_PIN_SSEGMENT_EN1,
        .anodeOrCathode = COMMON_CATHODE
    },
};

u8_t countSegments = sizeof(segmentsConfigs) / sizeof(SSEGMENT_CONFIGS_t);
u8_t countDigits = sizeof(digitsConfigs) / sizeof(digitsConfigs[0]);
