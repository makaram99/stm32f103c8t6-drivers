/**********************************************************************************
 * @file        LED.c
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       LED Driver 
 * @version     1.0.0
 * @date        2022-02-01
 **********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO.h"

#include "LED.h"
#include "LED_cfg.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            PRIVATE FUNCTIONS PROTOTYPES                      */
/*                                                                              */
/*------------------------------------------------------------------------------*/
static ERROR_t LED_ReadIndex(const LED_t led, s8_t * const ptr_s8Index);

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            MACRO LIKE FUNCTIONS                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/
#define ASSERT_LED(led)         ( led < NUM_OF_LEDS )

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PUBLIC FUNCTIONS                                */
/*                                                                              */
/*------------------------------------------------------------------------------*/

ERROR_t LED_Init(void) {
    return ERROR_OK;
}

ERROR_t LED_SetClr(const LED_t led, const STATE_t state) { 
    ERROR_t error = ERROR_OK;
    s8_t i = 0;
    
    error |= LED_ReadIndex(led, &i);
    if(i >= 0) {
        error |= (state ? GPIO_SetPin(ledConfigs[i].pin) : GPIO_ClrPin(ledConfigs[i].pin));
    } else {
        error |= ERROR_NOK;
    }

    return error;
}

ERROR_t LED_Toggle(const LED_t led) {
    STATE_t state = LOW;
    ERROR_t error = ERROR_OK;
    s8_t i = 0;
    
    error |= LED_ReadIndex(led, &i);
    if(i < 0) {
        return ERROR_NOK;
    }

    error |= GPIO_GetPinValue(ledConfigs[i].pin, &state);

    /* Toggle the LED */
    error |= (state ? GPIO_ClrPin(ledConfigs[i].pin) : GPIO_SetPin(ledConfigs[i].pin));

    return error;
}

ERROR_t LED_Read(const LED_t led, STATE_t * const ptrToState) { 
    ERROR_t error = ERROR_OK;
    s8_t i = 0;
    
    if(NULL == ptrToState) {
        return ERROR_NOK;
    } 

    error |= LED_ReadIndex(led, &i);
    if(i >= 0) {
        error |= GPIO_GetPinValue(ledConfigs[i].pin, ptrToState);
    } else {
        error |= ERROR_NOK;
    }

    return error;
}

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PRIVATE FUNCTIONS                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/******************************************************************************
 * @brief Get the index of the led in the ledConfigs array
 * 
 * @param[in] led: The led to get the index of
 * @param[in] ptr_s8Index: The pointer to the index of the led. 
 *              Options:
 *                    -1: The led is not in the buttonsConfigs array
 *                  >= 0: The index of the led in the buttonsConfigs array
 * @return ERROR_t: The error status of the function.
 ******************************************************************************/
static ERROR_t LED_ReadIndex(const LED_t led, s8_t * const ptr_s8Index) {
    u8_t i = 0;

    if(NULL == ptr_s8Index) {
        return ERROR_NOK;
    }

    *ptr_s8Index = -1;

    if( !ASSERT_LED(led) ) {
        return ERROR_NOK;
    }

    for(i = 0; i < countLedsConfigured; ++i) {
        if(led == ledConfigs[i].led) {
            *ptr_s8Index = i;
        }
    }

    return ERROR_OK;
}

ERROR_t LED_SetAll(void) {
    ERROR_t error = ERROR_OK;
    LED_t i = 0;

    for(i = LED_0; i < NUM_OF_LEDS; ++i) {
        error |= LED_SetClr(i, HIGH);
    }

    return error;
}

ERROR_t LED_ClrAll(void) {
    ERROR_t error = ERROR_OK;
    LED_t i = 0;

    for(i = LED_0; i < NUM_OF_LEDS; ++i) {
        error |= LED_SetClr(i, LOW);
    }

    return error;
}