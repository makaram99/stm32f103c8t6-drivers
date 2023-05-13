/****************************************************************/
/* Author	: Mahmoud Karam										*/
/* Version	: 1													*/
/* Wiki		: NVIC Driver Private file							*/
/* Date 	: 24 Jan 2021										*/
/****************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/***************NVIC Base Addresses***************/
#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct NVIC_t{
    volatile u32_t ISER[8U];
    volatile u32_t RESERVED0[24U];
    volatile u32_t ICER[8U];
    volatile u32_t RSERVED1[24U];
    volatile u32_t ISPR[8U];
    volatile u32_t RESERVED2[24U];
    volatile u32_t ICPR[8U];
    volatile u32_t RESERVED3[24U];
    volatile u32_t IABR[8U];
    volatile u32_t RESERVED4[56U];
    volatile u8_t IPR[240U];
    volatile u32_t RESERVED5[644U];
    volatile u32_t STIR;
}NVIC_t;

#define NVIC ((NVIC_t *)NVIC_BASE_ADDRESS)

/***************NVIC Registers***************/
/* Enable External Interrupts			*/
#define NVIC_ISER0 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x000)) /* From 0  to 31	*/
#define NVIC_ISER1 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x004)) /* From 32 to 63	*/

/* Disable External Interrupts			*/
#define NVIC_ICER0 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x080)) /* From 0  to 31	*/
#define NVIC_ICER1 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x084)) /* From 32 to 63	*/

/* Set Pending flag of External Interrupts, For debug and testing*/
#define NVIC_ISPR0 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x100)) /* From 0  to 31	*/
#define NVIC_ISPR1 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x104)) /* From 32 to 63	*/

/* Clear Pending flag of External Interrupts, For debug and testing*/
#define NVIC_ICPR0 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x180)) /* From 0  to 31	*/
#define NVIC_ICPR1 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x184)) /* From 32 to 63	*/

/* Read if External Interrupts is ACTIVE or not, For debug and testing*/
/* They are read only, so that volatile is required to avoid compiler optimization	*/
#define NVIC_IABR0 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x200)) /* From 0  to 31	*/
#define NVIC_IABR1 *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0x204)) /* From 32 to 63	*/

/* Priority Register: It's Byte accessible, don't dereference it cuz we access it as an array		*/
#define NVIC_IPR ((volatile u8_t *)(NVIC_BASE_ADDRESS + 0x300))

/* Software Trigger Interrupt Register	*/
#define NVIC_STIR *((volatile u32_t *)(NVIC_BASE_ADDRESS + 0xE00))

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                  MACROS                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Copy_u32GroupSubGroub */
#define NVIC_GROUP_4_SUB_0			0x05FA0300  /* 4 bits for group, 0 for subpriority	*/
#define NVIC_GROUP_3_SUB_1			0x05FA0400  /* 3 bits for group, 1 for subpriority	*/
#define NVIC_GROUP_2_SUB_2			0x05FA0500  /* 2 bits for group, 2 for subpriority	*/
#define NVIC_GROUP_1_SUB_3			0x05FA0600  /* 1 bits for group, 3 for subpriority	*/
#define NVIC_GROUP_0_SUB_4			0x05FA0700  /* 0 bits for group, 4 for subpriority	*/

#endif
