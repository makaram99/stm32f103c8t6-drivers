/****************************************************************************/
/* Author		: MahmoudKaram												*/
/* Date			: 13/09/2020												*/
/* Version		: V1														*/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO.h"
#include "STK.h"

#include "LEDMRX.h"

/*********************************************************************************
 *                                                                               *
 *                         Static Functions Prototypes                           *
 *                                                                               *
*********************************************************************************/
static ERROR_t LEDMRX_DisableAllCols(void);
static ERROR_t LEDMRX_SetRowsValue(u8_t value);


/*********************************************************************************
 *                                                                               *
 *                              Global Functions                                 * 
 *                                                                               *
*********************************************************************************/
ERROR_t LEDMRX_Init(void) {
    /* Do nothing   */

    return ERROR_OK;
}

ERROR_t LEDMRX_Display(const u8_t data[8]) {
    ERROR_t error = ERROR_OK;

	while(1) {
		/* Enable Column 0	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL0);
		error |= LEDMRX_SetRowsValue(data[0]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		
		/* Enable Column 1	*/
		error |= LEDMRX_DisableAllCols();
        error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL1);
		error |= LEDMRX_SetRowsValue(data[1]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 2	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL2);
		error |= LEDMRX_SetRowsValue(data[2]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 3	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL3);
		error |= LEDMRX_SetRowsValue(data[3]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 4	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL4);
		error |= LEDMRX_SetRowsValue(data[4]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 5	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL5);
		error |= LEDMRX_SetRowsValue(data[5]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 6	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL6);
		error |= LEDMRX_SetRowsValue(data[6]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/
		
		/* Enable Column 7	*/
        error |= LEDMRX_DisableAllCols();
		error |= GPIO_ClrPin(GPIO_PIN_LEDMRX_COL7);
		error |= LEDMRX_SetRowsValue(data[7]);
		error |= STK_SetBusyWait(2500);/* 2.5 mSec  *********/

        ASSERT_ERROR(error);
	}

    return error;
}


/*********************************************************************************
 *                                                                               *
 *                             Static Functions                                  *
 *                                                                               *
*********************************************************************************/
static ERROR_t LEDMRX_DisableAllCols(void) {
    ERROR_t error = ERROR_OK;

	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL0);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL1);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL2);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL3);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL4);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL5);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL6);
	error |= GPIO_SetPin(GPIO_PIN_LEDMRX_COL7);

    return error;
}

static ERROR_t LEDMRX_SetRowsValue(const u8_t value) {
    ERROR_t error = ERROR_OK;
	
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW0, GET_BIT(value, 0));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW1, GET_BIT(value, 1));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW2, GET_BIT(value, 2));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW3, GET_BIT(value, 3));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW4, GET_BIT(value, 4));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW5, GET_BIT(value, 5));
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW6, GET_BIT(value, 6));	
	error |= GPIO_SetPinValue(GPIO_PIN_LEDMRX_ROW7, GET_BIT(value, 7));

    return error;
}
