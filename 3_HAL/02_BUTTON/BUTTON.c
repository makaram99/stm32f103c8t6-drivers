/******************************************************************************
 * @file        BUTTON.c
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       Button Management Module
 * @version     1.0.0
 * @date        2022-03-20
 * @copyright   Copyright (c) 2022
 ******************************************************************************/
#include "STD_TYPES.h"
#include "GPIO.h"
#include "LED.h"        /* For testing */
#include "BUTTON.h"
#include "BUTTON_cfg.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                        PRIVATE FUNCTIONS PROTOTYPES                          */
/*                                                                              */
/*------------------------------------------------------------------------------*/
static ERROR_t BUTTON_ReadIndex(const BUTTON_t button, s8_t * const ptr_s8Index);
static ERROR_t BUTTON_Debounce(const u8_t index, STATE_t * const ptrToState);

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                        MACRO LIKE FUNCTIONS                                  */
/*                                                                              */
/*------------------------------------------------------------------------------*/
#define ASSERT_BUTTON(button)       ( button < NUM_OF_BUTTONS )
#define ASSERT_PULLUP(pullup)       ( (PUPD_PULL_UP == pullup) || (PUPD_PULL_DOWN == pullup) )
#define ASSERT_DEBOUNCE(debounce)   ( (DEBOUNCE_ON == debounce) || (DEBOUNCE_OFF == debounce) )

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PUBLIC FUNCTIONS                                */
/*                                                                              */
/*------------------------------------------------------------------------------*/

ERROR_t BUTTON_Init(void) {
    return ERROR_OK;
}

ERROR_t BUTTON_Read(const BUTTON_t button, STATE_t * const ptrToState) {
    ERROR_t error = ERROR_OK;
    s8_t i = 0;

    if(NULL == ptrToState) {
        return ERROR_NOK;
    }
    
    error |= BUTTON_ReadIndex(button, &i);
    if(i < 0) {
        return ERROR_NOK;
    }

    if(DEBOUNCE_ON == buttonsConfigs[i].debounce) {
        error |= BUTTON_Debounce(i, ptrToState);
    }else {
        error |= GPIO_GetPinValue(buttonsConfigs[i].pin, ptrToState);
    }

    if(ACTIVE_LOW == buttonsConfigs[i].ActiveHighOrLow) {
        *ptrToState = !(*ptrToState);
    }

    return error;
}

ERROR_t BUTTON_SetClrPullup(const BUTTON_t button, const PUPD_t pullup) {
    ERROR_t error = ERROR_OK;
    s8_t i = 0;

    error |= BUTTON_ReadIndex(button, &i);
    if(i < 0) {
        return ERROR_NOK;
    }

    if( ASSERT_PULLUP(pullup) ) {
        error |= GPIO_SetPinPuPd(buttonsConfigs[i].pin, pullup);
    }else {
        error |= ERROR_NOK;
    }    

    return error;
}

ERROR_t BUTTON_SetClrDebounce(const BUTTON_t button, const DEBOUNCE_t debounce) {
    ERROR_t error = ERROR_OK;
    s8_t i = 0;

    error |= BUTTON_ReadIndex(button, &i);
    ASSERT_ERROR(error);

    if( ASSERT_DEBOUNCE(debounce) ) {
        buttonsConfigs[i].debounce = debounce;
    }else {
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
 * @brief       Get the index of the button in the buttonsConfigs array
 * 
 * @param[in]   button      The button to get the index of
 * @param[in]   ptr_s8Index The pointer to the index of the button. 
 *                  Options:
 *                    -1: The button is not in the buttonsConfigs array or
 *                        the button is not valid (button >= NUM_OF_BUTTONS)
 *                  >= 0: The index of the button in the buttonsConfigs array
 * PROTECTION:  This function protects the user from:
 *              - Passing NULL pointer to the ptr_s8Index
 *              - Passing an invalid button to the button parameter
 * @return      ERROR_t: The error status of the function.
 ******************************************************************************/
static ERROR_t BUTTON_ReadIndex(const BUTTON_t button, s8_t * const ptr_s8Index) {
    u8_t i = 0;

    if(NULL == ptr_s8Index) {
        return ERROR_NOK;
    } 
    
    *ptr_s8Index = -1;
    
    if( ASSERT_BUTTON(button) ) {
        for(i = 0; i < countButtonsConfigured; ++i) {
            if(button == buttonsConfigs[i].button) {
                *ptr_s8Index = i;
            }
        }
    }

    if(*ptr_s8Index < 0) {
        return ERROR_NOK;
    }
    
    return ERROR_OK;
}

/******************************************************************************
 * @brief       Read the button with debounce algorithm
 * 
 * @param[in]   index:      The index of the button in the buttonsConfigs array
 * @param[in]   ptrToState: The pointer to the state of the button. It will be 
 *                          set to HIGH or LOW.
 * @return      ERROR_t:    error code. See \ref ERROR_t for more information.
 ******************************************************************************/
static ERROR_t BUTTON_Debounce(const u8_t index, STATE_t * const ptrToState) {
    ERROR_t error = ERROR_OK;
    
    if(NULL == ptrToState) {
        return ERROR_NOK;
    }

    if(index >= countButtonsConfigured) {
        return ERROR_NOK;
    }

    error |= GPIO_GetPinValue(buttonsConfigs[index].pin, ptrToState);

    if( (STATE_t)(buttonsConfigs[index].ActiveHighOrLow) == *ptrToState) {
    	/* TODO: add delay_ms from ARM library	*/
//        _delay_ms(DEBOUNCE_TIME_MS);
        error |= GPIO_GetPinValue(buttonsConfigs[index].pin, ptrToState);
    }

    if(ACTIVE_LOW == buttonsConfigs[index].ActiveHighOrLow) {
        *ptrToState = !(*ptrToState);
    }

    return error;
}
