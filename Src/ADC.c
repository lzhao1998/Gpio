/*
 * ADC.c
 *
 *  Created on: Jan 2, 2018
 *      Author: user2
 */

#include "ADC.h"

void ADC1Enable()
{
	Rcc->APB2RSTR &=  ~(1 << 8);
	Rcc->APB2ENR |= (1 << 8);
}

void ConfigADC()
{
	gpioConfig(GpioA,5,GPIO_MODE_AN,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHI_SPEED);	//channel 5 ADC1
	gpioConfig(GpioC,3,GPIO_MODE_AN,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHI_SPEED);	//channel 13 ADC1
	adc1->CR2 = DMA_MODE_DISABLE | RIGHT_ALIGN | CONTINUOUS_CONVERSION | ADC_ENABLE;
	adc1->SMPR2 |= (CYCLE_3 << 15);		//channel 5 with 3 cycle
	adc1->SMPR1 |= (CYCLE_480 << 9);	//channel 13 with 480 cycle
	adc1->SQR1 |= CONVERSION_2;			//total length is 2 (2 channel)
	adc1->SQR3 = CHANNEL_5 | CHANNEL_13;
	adc1->CR2 |= START_CONVERSION;
}
