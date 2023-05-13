/******************************************************************************
 * @file        AFIO_interface.h
 * @author      Mahmoud Karam (ma.karam272@gmail.com)
 * @brief       AFIO Driver Interface file
 * @version     1.0.0
 * @date        6 Feb 2021	
 * @copyright   Copyright (c) 2022
 ******************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                  TYPEDEFS                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
typedef enum AFIO_EXTI_t{
    AFIO_EXTI_PA = 0x0,
    AFIO_EXTI_PB = 0x1,
    AFIO_EXTI_PC = 0x2,
}AFIO_EXTI_t;



/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                  MACROS                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               API's PROTOTYPES                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
ERROR_t AFIO_Init(void);
ERROR_t AFIO_SetEXTIConfigurations(const EXTI_t exti, const AFIO_EXTI_t PortMap);

#endif	/* End of file guard	*/
