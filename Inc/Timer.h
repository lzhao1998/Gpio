/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user2
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#define TIMER1_BASE_ADDR		0x40010000
#define TIMER8_BASE_ADDR		0x40010400
#define Timer1				((TimerReg *)(TIMER1_BASE_ADDR))
#define Timer8				((TimerReg *)(TIMER8_BASE_ADDR))

typedef struct TimerReg TimerReg;
struct TimerReg {
	volatile uint32_t CR1;				//0h
	volatile uint32_t CR2;				//4h
	volatile uint32_t SMCR;				//8h
	volatile uint32_t DIER;				//ch
	volatile uint32_t SR;				//10h
	volatile uint32_t EGR;				//14h
	volatile uint32_t CCMR1;			//18h
	volatile uint32_t CCMR2;			//1ch
	volatile uint32_t CCER;				//20h
	volatile uint32_t CNT;				//24h
	volatile uint32_t PSC;				//28h
	volatile uint32_t ARR;				//2ch
	volatile uint32_t RCR;				//30h
	volatile uint32_t CCR1;				//34h
	volatile uint32_t CCR2;				//38h
	volatile uint32_t CCR3;				//3ch
	volatile uint32_t CCR4;				//40h
	volatile uint32_t BDTR;				//44h
	volatile uint32_t DCR;				//48h
	volatile uint32_t DMAR;				//4ch
};

void initTimer8(void);
void wait500ms(void);

#endif /* TIMER_H_ */
