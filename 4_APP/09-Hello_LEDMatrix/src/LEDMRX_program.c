/****************************************************************************/
/* Author		: MahmoudKaram												*/
/* Date			: 13/09/2020												*/
/* Version		: V1														*/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	/* Set all pins as output push pull 2MHz	*/
	/* Rows	*/
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, 0b0010);
	/* Cols	*/
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, 0b0010);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, 0b0010);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{	
	while(1)
	{
		/* Column 0	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 0	*/
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[0]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 1	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 1	*/
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[1]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 2	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 2	*/
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[2]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 3	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 3	*/
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[3]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 4	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 4	*/
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[4]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 5	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 5	*/
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[5]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 6	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 6	*/
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[6]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
		
		/* Column 7	*/
		HLEDMRX_voidDisableAllCols();
		/* Enable Column 7	*/
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
		HLEDMRX_voidSetRowsValue(Copy_u8Data[7]);
		MSTK_voidSetBusyWait(2500);	//2.5 MSEC
	}
}

static void HLEDMRX_voidDisableAllCols(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}

static void HLEDMRX_voidSetRowsValue(u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8Bit);	
	
	Local_u8Bit = GET_BIT(Copy_u8Value, 7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8Bit);
}
