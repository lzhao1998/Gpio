/*
 * IWDG.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user2
 */

#ifndef IWDG_H_
#define IWDG_H_

#include <stdint.h>

//independent watchdog
#define IWDG_BASE_ADDR		0x40003000
#define IWDG				((IWDGReg *)(IWDG_BASE_ADDR))

typedef struct IWDGReg IWDGReg;
struct IWDGReg {
	volatile uint32_t KR;		//0x00		key register
	volatile uint32_t PR;		//0x04		prescalar register
	volatile uint32_t RLR;		//0x08		reload register
	volatile uint32_t SR;		//0x0c		status register
};


//window watchdog
#define WWDG_BASE_ADDR		0x40002C00
#define Wwdg				((WWDGReg *)(WWDG_BASE_ADDR))

typedef struct WWDGReg WWDGReg;
struct WWDGReg {
	volatile uint32_t CR;		//0x00		control register
	volatile uint32_t CFR;		//0x04		configuration register
	volatile uint32_t SR;		//0x08		status register
};

//IDWG
// Prescale
#define IWDG_DIV_4		0
#define IWDG_DIV_8		1
#define IWDG_DIV_16		2
#define IWDG_DIV_32		3
#define IWDG_DIV_64		4
#define IWDG_DIV_128	5
#define IWDG_DIV_256	6

//Status register
#define IWDG_RVU_ONGOING	(1 << 1)
#define IWDG_PVU_ONGOING	1

//Key register
#define IWDG_RESET_WD	0xAAAA
#define IWDG_START_WD	0XCCCC
#define IWDG_CONFIG_WD	0x5555

#define iwdgStartWatchdog()			(IWDG->KR = IWDG_START_WD)
#define iwdgEnableConfiguration()	(IWDG->KR = IWDG_CONFIG_WD)
#define iwdgResetWatchdog()			(IWDG->KR = IWDG_RESET_WD)
#define iwdgSetReloadValue(val)			(IWDG->RLR = (val))
#define iwdgSetPrescaleValue(val)		(IWDG->PR = (val))

//WWDG
//Control register (CR)
#define WATCGDOG_DISABLE	(0 << 7)
#define WATCGDOG_ENABLE		(1 << 7)

//Config register (CFR)
#define WWDG_DIV_1	(0 << 7)
#define WWDG_DIV_2	(1 << 7)
#define WWDG_DIV_4	(2 << 7)
#define WWDG_DIV_8	(3 << 7)
#define WWDG_T6		(1 << 6)

//Early wakeup interupt
#define WWDG_EWI	(1 << 9)

#define WWDG_EWIF	1

void waitCounterValueUpdate();
void waitPrescaleValueUpdate();
void configWWDG(int countDownVal);
void setWindowValue(int windowVal);
void clearEWIF();
void WwdgTimer500ms();
#endif /* IWDG_H_ */
