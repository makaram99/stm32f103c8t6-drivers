/**********************************************************************************
 * @file        EXTI_program.c
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       AFIO Driver main file
 * @version     1.0.0
 * @date        6 Feb 2021
 **********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI.h"

#include "AFIO.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PUBLIC FUNCTIONS                                */
/*                                                                              */
/*------------------------------------------------------------------------------*/
ERROR_t AFIO_Init(void) {
    /* Do nothing */

    return ERROR_OK;
}

ERROR_t AFIO_SetEXTIConfigurations(const EXTI_t exti, const AFIO_EXTI_t PortMap) {
    ERROR_t error = ERROR_OK;

	if(exti < NO_OF_EXTI) {
		AFIO->EXTICR[exti / 4] &= ~(0xf << ((exti % 4) * 4));
		AFIO->EXTICR[exti / 4] |= (PortMap << ((exti % 4) * 4));
	} else {
        error = ERROR_NOK;
    }

    return error;
}

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PRIVATE FUNCTIONS                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/
