/***********************************************************************************
 *  @file     STD_TYPES.h
 *	@brief    Standard data types For ARM Microcontrollers
 *	@author   Mahmoud Karam (ma.karam272@gmail.com)
 *	@date	  2022-03-20
 *	@version  1.0.0
 ***********************************************************************************/
#ifndef STD_TYPES_H				
#define STD_TYPES_H

/* Signed integers	*/
typedef     signed long long int        s64_t;
typedef 	signed long int   	        s32_t;		
typedef 	signed short int 	        s16_t;		
typedef 	signed char                 s8_t;
  
/* Unsigned integers	*/
typedef     unsigned long long int      u64_t;
typedef 	unsigned long int	        u32_t;
typedef 	unsigned short int          u16_t;
typedef 	unsigned char 		        u8_t;
  
/* Float numbers	*/          
typedef 	float 				        f32_t;
typedef 	double 				        f64_t;

#undef HIGH
#undef LOW
typedef enum STATE_t{
  LOW,
  HIGH,
  NORMAL              /* Used for any normal state */
}STATE_t;

typedef enum ACTIVATION_STATUS_t{
    ACTIVE_LOW,       /*!< Active low means that the pin is pulled low when the pin is set to high */
    ACTIVE_HIGH       /*!< Active high means that the pin is pulled high when the pin is set to low */
}ACTIVATION_STATUS_t;

/* Boolean type	*/
#undef FALSE
#undef TRUE
typedef enum BOOL_t{
    FALSE,
    TRUE
}BOOL_t;

typedef enum ERROR_t{
    ERROR_NOK               = 0,            /*!< No error occured */
    ERROR_OK                = 0x1,          /*!< Error occured */
    ERROR_TIMEOUT           = 0x2,          /*!< Timeout occured */
    ERROR_NULL_POINTER      = 0x4,          /*!< Null pointer occured */
    ERROR_BUSY              = 0x8,          /*!< Busy state occured */
    ERROR_NOT_INITIALIZED   = 0x10,         /*!< Not initialized state occured */
    ERROR_ILLEGAL_PARAM     = 0x20,         /*!< Invalid input state occured */   
    ERROR_OUT_OF_RANGE      = 0x40          /*!< Out of range state occured */ 
}ERROR_t;

/* Pointers	*/
#undef NULL 
#define NULL ((void *)0)  /*!< NULL pointer */

#undef NULL_BYTE
#define NULL_BYTE  ('\0')

#define ASSERT_PTR(ptr)             do{if(NULL == ptr) { return ERROR_NOK; } }while(0)
#define ASSERT_ERROR(error)         do{ if(ERROR_OK != error){ return ERROR_NOK;} }while(0)

 #endif	  /* STD_TYPES_H */
