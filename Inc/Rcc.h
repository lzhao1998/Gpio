/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>
#include "Common.h"

#define RCC_BASE_ADDR		0x40023800
#define RCC_AHB1RST_OFF		0x10
#define RCC_AHB1EN_OFF		0x30
#define Rcc		((RccReg *)(RCC_BASE_ADDR))

typedef struct RccReg RccReg;
struct RccReg {
	volatile uint32_t CR;				//0h
	volatile uint32_t PLLCFGR;			//4h
	volatile uint32_t CFGR;				//8h
	volatile uint32_t CIR;				//ch
	volatile uint32_t AHB1RSTR;			//10h
	volatile uint32_t AHB2RSTR;			//14h
	volatile uint32_t AHB3RSTR;			//18h
	volatile uint32_t Reserved1[1];		//1ch
	volatile uint32_t APB1RSTR;			//20h
	volatile uint32_t APB2RSTR;			//24h
	volatile uint32_t Reserved2[2];		//28h~2ch
	volatile uint32_t AHB1ENR;			//30h
	volatile uint32_t AHB2ENR;			//34h
	volatile uint32_t AHB3ENR;			//38h
	volatile uint32_t Reserved3[1];		//3ch
	volatile uint32_t APB1ENR;			//40h
	volatile uint32_t APB2ENR;			//44h
	volatile uint32_t Reserved4[2];		//48h~4ch
	volatile uint32_t AHB1LPENR;		//50h
	volatile uint32_t AHB2LPENR;		//54h
	volatile uint32_t AHB3LPENR;		//58h
	volatile uint32_t Reserved5[1];		//5ch
	volatile uint32_t APB1LPENR;		//60h
	volatile uint32_t APB2LPENR;		//64h
	volatile uint32_t Reserved6[2];		//68h~6ch
	volatile uint32_t BDCR;				//70h
	volatile uint32_t CSR;				//74h
	volatile uint32_t Reserved7[2];		//78h~7ch
	volatile uint32_t SSCGR;			//80h
	volatile uint32_t PLLI2SCFGR;		//84h
};

extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAhb1En;

//MCO clock select
#define MCO_HSI_SRC		0
#define MCO_LSE_SRC		1
#define MCO_HSE_SRC		2
#define MCO_PLL_SRC		3

//MCO Prescale
#define MCO_NO_DIV		0
#define MCO_DIV_BY_2	4
#define MCO_DIV_BY_3	5
#define MCO_DIV_BY_4	6
#define MCO_DIV_BY_5	7

//I2C
#define I2C1_EN	21
#define I2C2_EN	22
#define I2C3_EN	23

//DMA
#define DMA1_DEV	0
#define DMA2_DEV	1

#define rccSelectMco1Src(x)		{	\
	Rcc->CFGR &= ~(3 << 21);		\
	Rcc->CFGR |= (x << 21);			\
}

#define rccSetMco1Prescaler(x)	{	\
	Rcc->CFGR &= ~(7 << 24);		\
	Rcc->CFGR |= (x << 24);			\
}

//enable timer8
void enableTimer8(void);

//enable gpio
void enableGpioG(void);
void enableGpioA(void);
void enableGpioB(void);
void enableGpioF(void);

//enable rng
void enableRng(void);

//enable i2c
void enablei2c(int num);

//enable and disable usart1
void enableUsart1(void);
void disableUsart1(void);

//enable and disable DMA1,DMA2
void enableDMA(int dmaNumber);
void disableDMA1andDMA2(void);

#endif /* RCC_H_ */
