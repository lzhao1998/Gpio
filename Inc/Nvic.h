/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user2
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>
#define NVIC_BASE_ADDR 	0xE000E100
#define Nvic			((NvicReg *)(NVIC_BASE_ADDR))

//(b-a)/4 -> turn decimal then minus num of bit being used = ans
typedef struct NvicReg NvicReg;
struct NvicReg
{
	volatile uint32_t ISER[3];			//Interrupt set-enable registers 	0h
	volatile uint32_t Reserved1[29];
	volatile uint32_t ICER[3];			//Interrupt clear-enable registers	80h
	volatile uint32_t Reserved2[29];
	volatile uint32_t ISPR[3];			//Interrupt set-pending registers	100h
	volatile uint32_t Reserved3[29];
	volatile uint32_t ICPR[3];			//Interrupt clear-pending registers	180h
	volatile uint32_t Reserved4[29];
	volatile uint32_t IABR[3];			//Interrupt active bit registers	200h
	volatile uint32_t Reserved5[61];
	volatile uint32_t IPR[21];			//Interrupt priority registers		300h
	volatile uint32_t Reserved6[683];
	volatile uint32_t STIR[1];			//Software trigger interrupt register	E00h
};

#define nvicEnableIrq(irqNum)		(Nvic->ISER[irqNum>>5] |= 1 << (irqNum & 0x1F))
#define nvicDisableIrq(irqNum)		(Nvic->ICER[irqNum>>5] |= 1 << (irqNum & 0x1F))
#define nvicSetPriority(irqNum,priority)	(Nvic->IPR[irqNum>>2] |= priority << ((irqNum & 0x3) * 8 + 4))

#endif /* NVIC_H_ */
