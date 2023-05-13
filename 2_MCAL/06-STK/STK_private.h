/************************************************************/
/* Author	: Mahmoud Karam									*/
/* Date 	: 09/08/2020									*/
/* Version	: V1											*/
/************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct STK_t{
	volatile u32_t CTRL  ;
	volatile u32_t LOAD  ;
	volatile u32_t VAL   ;
}STK_t;

#define     STK    ((volatile STK_t *)0xE000E010)

enum {
    ENABLE,
    TICKINT,
    CLKSOURCE,
    COUNTFLAG = 16
};  /* STK_CTRL Register */

/* STK clock source options */
#define     STK_SRC_AHB           1
#define     STK_SRC_AHB_8         2

/* STK modes    */
#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1


#endif
