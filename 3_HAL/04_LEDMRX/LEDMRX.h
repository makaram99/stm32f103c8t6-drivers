/****************************************************************************/
/* Author		: MahmoudKaram												*/
/* Date			: 13/09/2020												*/
/* Version		: V1														*/
/****************************************************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

ERROR_t LEDMRX_Init(void);
ERROR_t LEDMRX_Display(const u8_t data[8]); /* 8 ROWS   */


#endif  /* LEDMRX_INTERFACE_H  */