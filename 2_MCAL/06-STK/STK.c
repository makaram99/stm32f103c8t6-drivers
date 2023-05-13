/************************************************************/
/* Author	: Mahmoud Karam									*/
/* Date 	: 09/08/2020									*/
/* Version	: V1											*/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK.h"
#include "STK_private.h"
#include "STK_config.h"


/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8_t STK_ModeOfInterval;

ERROR_t STK_Init(void) {
    ERROR_t error = ERROR_OK;

    /* Disable STK  */
    STK_DeInit();

    /* Disable STK Interrupt */
    CLR_BIT(STK->CTRL, TICKINT);

    #if STK_CLK_SRC == STK_SRC_AHB
    /* Set clock source AHB */
	SET_BIT(STK->CTRL, CLKSOURCE);
    #elif STK_CLK_SRC == STK_SRC_AHB_8
    /* Set clock source AHB/8 */
	CLR_BIT(STK->CTRL, CLKSOURCE);
    #else
    #error "Wrong Choice of STK Clock Source"
    #endif

    return error;
}

ERROR_t STK_DeInit(void) {
    ERROR_t error = ERROR_OK;

	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, TICKINT);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, ENABLE);
	STK->LOAD = 0;
	STK->VAL  = 0;

    return error;
}

ERROR_t STK_SetBusyWait(const u32_t ticks) {
    ERROR_t error = ERROR_OK;

    if(ticks > 0x00FFFFFF) {
        return ERROR_NOK;
    }

	/* Load ticks to load register */
	STK->LOAD = ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, ENABLE);
	
	/* Wait till flag is raised */
	while(BIT_IS_CLEAR(STK->CTRL, COUNTFLAG));
	
	error |= STK_DeInit();
    
    return error;
}

ERROR_t STK_SetIntervalSingle(const u32_t ticks, void (* const callback)(void) ) {
    ERROR_t error = ERROR_OK;

    if(ticks > 0x00ffffff) {
        return ERROR_NOK;
    }

    ASSERT_PTR(callback);

	STK->LOAD = ticks;
	
	SET_BIT(STK->CTRL, ENABLE);
	
	STK_CallBack = callback;
	
	/* Set Mode to Single */
	STK_ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, TICKINT);

    return error;
}

ERROR_t STK_SetIntervalPeriodic(const u32_t ticks, void (*const callback)(void) ) {
    ERROR_t error = ERROR_OK;

    if(ticks > 0x00ffffff) {
        return ERROR_NOK;
    }

    ASSERT_PTR(callback);

	STK->LOAD = ticks;
	
	SET_BIT(STK->CTRL, ENABLE);
	
	STK_CallBack = callback;
	
	/* Set Mode to Single */
	STK_ModeOfInterval = STK_PERIOD_INTERVAL;
	
	SET_BIT(STK->CTRL, TICKINT);

    return error;
}

ERROR_t STK_GetElapsedTime(u32_t * const ElapsedTime) {
    ERROR_t error = ERROR_OK;

    ASSERT_PTR(ElapsedTime);
	
	*ElapsedTime = STK->LOAD - STK->VAL ;
	
	return error;
}

ERROR_t  STK_GetRemainingTime(u32_t * const RemainingTime) {
    ERROR_t error = ERROR_OK;

    ASSERT_PTR(RemainingTime);
	
	*RemainingTime = STK->VAL ;
	
	return error;
}

void SysTick_Handler(void) {
	volatile u8_t Local_Temporary;
	
	if(STK_ModeOfInterval == STK_SINGLE_INTERVAL) {
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, TICKINT);
	
		STK_DeInit();
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_Temporary = GET_BIT(STK->CTRL, COUNTFLAG);
}
