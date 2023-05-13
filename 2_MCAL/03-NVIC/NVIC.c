/**********************************************************************************
 * @file        NVIC_program.c
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       NVIC Driver main file
 * @version     1.0.0
 * @date        24 Jan 2021
 **********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC.h"
#include "NVIC_private.h"
#include "NVIC_cfg.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            PRIVATE FUNCTIONS PROTOTYPES                      */
/*                                                                              */
/*------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            MACRO LIKE FUNCTIONS                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                              PUBLIC FUNCTIONS                                */
/*                                                                              */
/*------------------------------------------------------------------------------*/

ERROR_t NVIC_Initialize(void) {
    ERROR_t error = ERROR_OK;

    /* 1. Set the Vector Table base address in NVIC_VTOR register */

    /* 2. Configure the NVIC Preemption Priority Bits */

    /* 3. Configure the NVIC Interrupt Priority Registers */

    /* 4. Enable the NVIC Interrupts */

    /* Set the classification of the priority group and sub group bits */
    #define SCB_AIRCR *((volatile u32_t *)(0xE000ED00 + 0x0C))
    SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;

    return error;
}

ERROR_t NVIC_EnableInterrupt(const NVIC_IRQ_t interruptID) {
    ERROR_t error = ERROR_OK;
    volatile u32_t * NVIC_ISER = NULL;

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
	if(interruptID <= NVIC_IRQ_MAX) {
		if(interruptID < 32) {
            NVIC_ISER = &(NVIC->ISER[0]);
		}
		else {
            NVIC_ISER = &(NVIC->ISER[1]);
		}

        /* 0 has no effect on ISER registers  */
        *NVIC_ISER = (1 << (interruptID % 32));
	} else {
        error = ERROR_NOK;
	}
	
    return error;
}

ERROR_t NVIC_DisableInterrupt(const NVIC_IRQ_t interruptID) {
    ERROR_t error = ERROR_OK;
    volatile u32_t * NVIC_ICER = NULL;

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
	if(interruptID <= NVIC_IRQ_MAX) {
		if(interruptID < 32) {
            NVIC_ICER = &(NVIC->ICER[0]);
		}
		else {
            NVIC_ICER = &(NVIC->ICER[1]);
		}

        /* 0 has no effect on ICER registers  */
        *NVIC_ICER = (1 << (interruptID % 32));
	} else {
        error = ERROR_NOK;
	}
	
    return error;
}

ERROR_t NVIC_SetPendingFlag(const NVIC_IRQ_t interruptID) {
    ERROR_t error = ERROR_OK;
    volatile u32_t * NVIC_ISPR = NULL;

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
	if(interruptID <= NVIC_IRQ_MAX) {
		if(interruptID < 32) {
            NVIC_ISPR = &(NVIC->ISPR[0]);
		}
		else {
            NVIC_ISPR = &(NVIC->ISPR[1]);
		}

        /* 0 has no effect on ISPR registers  */
        *NVIC_ISPR = (1 << (interruptID % 32));
	} else {
        error = ERROR_NOK;
	}
	
    return error;
}

ERROR_t NVIC_ClearPendingFlag(const NVIC_IRQ_t interruptID) {
    ERROR_t error = ERROR_OK;
    volatile u32_t * NVIC_ICPR = NULL;

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
	if(interruptID <= NVIC_IRQ_MAX) {
		if(interruptID < 32) {
            NVIC_ICPR = &(NVIC->ICPR[0]);
		}
		else {
            NVIC_ICPR = &(NVIC->ICPR[1]);
		}

        /* 0 has no effect on ICPR registers  */
        *NVIC_ICPR = (1 << (interruptID % 32));
	} else {
        error = ERROR_NOK;
	}
	
    return error;
}

ERROR_t NVIC_GetActiveFlag(const NVIC_IRQ_t interruptID, STATE_t * const state) {
    ERROR_t error = ERROR_OK;
    volatile u32_t * NVIC_IABR = NULL;

    ASSERT_PTR(state);

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
	if(interruptID <= NVIC_IRQ_MAX) {
		if(interruptID < 32) {
            NVIC_IABR = &(NVIC->IABR[0]);
		}
		else {
            NVIC_IABR = &(NVIC->IABR[1]);
		}

        *state = GET_BIT(*NVIC_IABR, (interruptID % 32));
	} else {
        error = ERROR_NOK;
	}
	
    return error;
}

ERROR_t NVIC_SetPriority(NVIC_IRQ_t interruptID, u8_t GroupPriority, u8_t SubPriority) {
    ERROR_t error = ERROR_OK;
    u8_t priority = SubPriority | (GroupPriority << ((NVIC_GROUP_SUB_DISTRIBUTION - NVIC_GROUP_4_SUB_0) / 256));	// 256 is the step = 0x100


    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
    if(interruptID <= NVIC_IRQ_MAX) {
        NVIC->IPR[interruptID] = priority << 4;	/* the first 4 LSBs are reserved	*/
    } else {
        error = ERROR_NOK;
    }

    return error;
}

ERROR_t NVIC_GetPriority(const NVIC_IRQ_t interruptID, u8_t * const priority) {
    ERROR_t error = ERROR_OK;

    /* We have NVIC_IRQ_MAX interrupts in STM32F103C8     */
    if(interruptID <= NVIC_IRQ_MAX) {
        *priority = NVIC->IPR[interruptID] >> 4;	/* the first 4 LSBs are reserved	*/
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


