/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user2
 */

#include "Gpio.h"
void gpioConfig(GpioReg *gpio, int pin, int mode, int outDriveType, int pullType, int speed)
{
	gpio->mode &= ~(3 << (pin * 2)); 	//Clear pin mode to 0 first
	gpio->mode |= mode << (pin * 2);	//Set the pin mode

	gpio->outSpeed &= ~(3 << (pin * 2));	//Clear pin speed to 0
	gpio->outSpeed |= speed << (pin * 2);	//Set the pin speed

	gpio->pullType &= ~(3 << (pin * 2));
	gpio->pullType |= pullType << (pin * 2);	//Set pin pull type

	gpio->outType &= ~(1 << pin);
	gpio->outType |= outDriveType << pin;
}

void gpioWrite(GpioReg *gpio, int pin, int state)
{
	if(state == 1)
	{
		SET_PIN(gpio,pin);
		//gpio->outData |= 1 << pin;
	}
	else
	{
		RESET_PIN(gpio,pin);
		//gpio->outData &= ~(1 << pin);
	}
}

int gpioRead(GpioReg *gpio, int pin)
{
	return gpio->inData & (1 << pin);
}

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
		SET_PIN(GpioG,pin);
		//GpioG->outData |= 1 << pin;
	}
	else
	{
		RESET_PIN(GpioG,pin);
		//GpioG->outData &= ~(1 << pin);
	}
}

void gpioLock(GpioReg *gpio, int pin)
{
	int lockStatus;
	gpio->lock = (1<<16)|(1<<pin);
	gpio->lock = (0<<16)|(1<<pin);
	gpio->lock = (1<<16)|(1<<pin);
	lockStatus = gpio->lock;
}

void gpioConfigAltFunc(GpioReg *gpio,int pin,int AltFun){
	 if(pin<7)
		 gpio->altFuncLo =  AltFun << (pin*4);
	 else
		 gpio->altFuncHi = AltFun << (pin*4);
}
