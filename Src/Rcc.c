/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */
#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioG(void)
{
	*rccAhb1Rst &= ~(1 << 6);
	*rccAhb1En |= 1 << 6;
}

void enableGpioA(void)
{
	*rccAhb1Rst &= ~1;
	*rccAhb1En |= 1 << 6;
}

void enableGpioB(void)
{
	*rccAhb1Rst &= ~(1 << 1);
	*rccAhb1En |= 1 << 6;
}

void enableRng(void)
{
	Rcc->AHB2RSTR &= ~(1 << 6);
	Rcc->AHB2ENR |= 1<< 6;
}
