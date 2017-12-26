/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user2
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include "Rcc.h"
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
//CC4S and CC3S (CCMR2 register)
#define IC4_output 		(0 << 8)
#define IC4_mapped_TI4 	(1 << 8)
#define IC4_mapped_TI3 	(2 << 8)
#define IC4_mapped_TRC 	(3 << 8)
#define IC3_output 		(0 << 0)
#define IC3_mapped_TI3 	(1 << 0)
#define IC3_mapped_TI4 	(2 << 0)
#define IC3_mapped_TRC 	(3 << 0)

//OC1M for channel1(CCMR1 register)
#define OC1M_frozen			(0 << 4)
#define OC1M_active_level	(1 << 4)
#define OC1M_inactive_level	(2 << 4)
#define OC1M_toggle			(3 << 4)
#define OC1M_force_inactive	(4 << 4)
#define OC1M_force_active	(5 << 4)
#define OC1M_PWN_mode1		(6 << 4)
#define OC1M_PWN_mode2		(7 << 4)

//CC1P (CCER register)
#define OC1_ch1_active_high		(0 << 1)
#define OC1_ch1_active_low		(1 << 1)

//CCxE (CCER register)
#define CC1E_ON		(1 << 0)
#define CC2E_ON		(1 << 4)
#define CC3E_ON		(1 << 8)
#define CC4E_ON		(1 << 12)

//CCxP (CCER register)
#define CC3P_RISE	(0 << 9)
#define CC3P_FALL	(1 << 9)
#define CC4P_RISE	(0 << 13)
#define CC4P_FALL	(1 << 13)

//CCPC (CR2 register)
#define non_auto_reload_preload	(0 << 0)
#define auto_reload_preload		(1 << 0)

//MOE (BDTR)
#define MOE_ON 	(1 << 15)
#define MOE_OFF	(0 << 15)

void initTimer8(void);
void wait500ms(void);
void initTimer8ForInputCaptureAndOutputCompare();
void forceOutCompareChannel1High();
void forceOutCompareChannel1Low();
void toggleOutCompareChannel1WithForce(int i);
void initTimer8ForDMA();
void sendBitPattern(uint8_t data);
#endif /* TIMER_H_ */
