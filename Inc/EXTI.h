/*
 * EXTI.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user2
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>
#define EXTI_BASE_ADDR	0x40013C00
#define EXTI			((ExtiReg *)(EXTI_BASE_ADDR))

typedef struct ExtiReg ExtiReg;
struct ExtiReg
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
};

#define EXTI_INTR_UNMASK(bit)	(EXTI->IMR |= (1 << bit))
#define EXTI_INTR_MASK(bit)		(EXTI->IMR &= ~(1 << bit))
#define EXTI_EVENT_UNMASK(bit)	(EXTI->EMR |= (1 << bit))
#define EXTI_EVENT_MASK(bit)	(EXTI->EMR &= ~(1 << bit))
#define EXTI_RTSR_ENABLE(bit)	(EXTI->RTSR |= (1 << bit))
#define EXTI_RTSR_DISABLE(bit)	(EXTI->RTSR &= ~(1 << bit))
#define EXTI_FTSR_ENABLE(bit)	(EXTI->FTSR |= (1 << bit))
#define EXTI_FTSR_DISABLE(bit)	(EXTI->FTSR &= ~(1 << bit))
#define EXTI_SWIER_ENABLE(bit)	(EXTI->SWIER |= (1 << bit))
#define EXTI_SWIER_DISABLE(bit)	(EXTI->SWIER &= ~(1 << bit))
#define EXTI_PR_Clear(bit)		(EXTI->PR |= (1 << bit))
#define EXTI_PR_Unclear(bit)	(EXTI->PR &= ~(1 << bit))


#endif /* EXTI_H_ */
