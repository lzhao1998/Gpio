/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */

#include "Gpio.h"


void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed)
{
	GpioG->mode &= ~(3 << (pin * 2)); 	//Clear pin mode to 0 first
	GpioG->mode |= mode << (pin * 2);	//Set the pin mode

	GpioG->outSpeed &= ~(3 << (pin * 2));	//Clear pin speed to 0
	GpioG->outSpeed |= speed << (pin * 2);	//Set the pin speed

	GpioG->pullType &= ~(3 << (pin * 2));
	GpioG->pullType |= pullType << (pin * 2);	//Set pin pull type

	GpioG->outType &= ~(1 << pin);
	GpioG->outType |= outDriveType << pin;
}

void gpioGWrite(int pin, int state)
{
	if(state == 1)
	{
		GpioG->outData |= 1 << pin;
	}
	else
	{
		GpioG->outData &= ~(1 << pin);
	}
}
