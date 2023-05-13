/******************************************************************************
 * @file        LED_cfg.c
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       Configuration source file for \ref LED.c
 * @version     1.0.0
 * @date        2022-03-20
 * @copyright   Copyright (c) 2022
 ******************************************************************************/
#include "STD_TYPES.h"
#include "MATH.h"
#include "GPIO.h"
#include "LED.h"
#include "LED_cfg.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                     CHANGE THE FOLLOWING TO YOUR NEEDS                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

LED_CONFIGS_t ledConfigs[] = {
    {LED_0, GPIO_PIN_LED0},
    {LED_1, GPIO_PIN_LED1},
    {LED_2, GPIO_PIN_LED2},
    {LED_3, GPIO_PIN_LED3},
    {LED_4, GPIO_PIN_LED4},
    {LED_5, GPIO_PIN_LED5},
    {LED_6, GPIO_PIN_LED6},
    {LED_7, GPIO_PIN_LED7},
};

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                     DO NOT CHANGE ANYTHING BELOW THIS LINE                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

const u8_t countLedsConfigured = sizeof(ledConfigs) / sizeof(ledConfigs[0]);
