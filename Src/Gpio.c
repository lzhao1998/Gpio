/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */

#include "Gpio.h"

uint32_t *gpioGMode = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_MODE_OFF);
uint32_t *gpioGOType = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OTYPE_OFF);
uint32_t *gpioGOSpeed = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OSPEED_OFF);
uint32_t *gpioGPupd = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_PUPD_OFF);
uint32_t *gpioGOD = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OD_OFF);

void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed)
{
	*gpioGMode &= ~(3 << (pin * 2)); 	//Clear pin mode to 0 first
	*gpioGMode |= mode << (pin * 2);	//Set the pin mode

	*gpioGOSpeed &= ~(3 << (pin * 2));	//Clear pin speed to 0
	*gpioGOSpeed |= speed << (pin * 2);	//Set the pin speed

	*gpioGPupd &= ~(3 << (pin * 2));
	*gpioGPupd |= pullType << (pin * 2);	//Set pin pull type

	*gpioGOType &= ~(1 << pin);
	*gpioGOType |= outDriveType << pin;
}

void gpioGWrite(int pin, int state)
{
	if(state == 1)
	{
		*gpioGOD |= 1 << pin;
	}
	else
	{
		*gpioGOD &= ~(1 << pin);
	}
}
