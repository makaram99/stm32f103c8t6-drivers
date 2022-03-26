/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: GPIO Driver interface file						*/
/* Date 	: 17 Jan 2021										*/
/****************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH    1
#define GPIO_LOW     0

#define GPIO_LOCK_ALL			50	/* Used with Lock Function	*/

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

/* I/P Pins Modes for SetPinDirection Function ==> CNF  1:0		*/	
	#define INPUT_ANALOG			0b0000
	#define INPUT_FLOAT				0b0100
	#define INPUT_PU				0b1000
	#define INPUT_PD				0b1000


/* O/P Pins Mode for SetPinDirection Function  ==> CNF 1:0, MODE 1:0	*/
	/* For Speed 10	*/
	#define OUTPUT_SPEED_10MHZ_PP     0b0001
	#define OUTPUT_SPEED_10MHZ_OD     0b0101
	#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
	#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

	/* For Speed 2	*/
	#define OUTPUT_SPEED_2MHZ_PP      0b0010
	#define OUTPUT_SPEED_2MHZ_OD      0b0110
	#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
	#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

	/* For Speed 50	*/
	#define OUTPUT_SPEED_50MHZ_PP     0b0011
	#define OUTPUT_SPEED_50MHZ_OD     0b0111
	#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
	#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

/* Functions Prototypes	*/
	/* Arguments:
		Copy_u8Port		: GPIOA, GPIOB, GPIOC
		Copy_u8PinId	: 0 to 15 for all func, GPIO_LOCK_ALL for LockPin Func to lock all port
		Copy_u8Mode		: Above ^
		Copy_u8Value	: 0 or 1
		Copy_u8Speed	: 2MHZ, 10MHZ, 50MHZ		*/
	void MGPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8PinId , u8 Copy_u8Mode );
	void MGPIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8PinId , u8 Copy_u8Value );
	u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8PinId );
	void MGPIO_voidSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8PinId, u8 Copy_u8Speed);
	void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8PinId);	

#endif	/* End of file guard	*/
