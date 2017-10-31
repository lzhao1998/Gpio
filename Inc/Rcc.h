/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>
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

void enableGpioG(void);
void enableGpioA(void);
void enableGpioB(void);

void enableRng(void);

#endif /* RCC_H_ */
