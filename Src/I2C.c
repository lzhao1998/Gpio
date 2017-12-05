/*
 * I2C.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user2
 */

#include "I2C.h"
#include "Rcc.h"
#include "gpio.h"

void enableI2C1_as_Master(void)
{
	//enablei2c(I2C1_EN);
	i2c1->CR1 &= ~(0 << 1);			//set it to I2C
	i2c1->CR2 |= 10;				//10Mhz
	i2c2->CCR &= ~(1 << 15);		//set it to standard mode
	i2c2->CCR &= ~(4096);
	i2c2->CCR |= 0x1f4;				//CCR = 500
	i2c2->TRISE |= 0xb;				//TRISE = 11
	i2c1->SR2 |= (1 << 0);	 		//Master mode

}

void enableI2C2_as_Slave(void)
{
	//enablei2c(I2C1_EN);
	i2c2->CR1 &= ~(0 << 1);		//set it to I2C
	i2c2->SR2 |= (0 << 0);	 	//Slave mode
}

void initI2C(void)
{
	//I2Cs
	enablei2c(I2C1_EN);
	enablei2c(I2C1_EN);

	//for i2c1
	gpioConfig(GpioB, 6, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_PULL_UP, GPIO_HI_SPEED);
	gpioConfigAltFunc(GpioB,6,AF4);
	gpioConfig(GpioB, 7, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_PULL_UP, GPIO_HI_SPEED);
	gpioConfigAltFunc(GpioB,7,AF4);

	//for i2c2
	gpioConfig(GpioF, 0, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_PULL_UP, GPIO_HI_SPEED);
	gpioConfigAltFunc(GpioF,0,AF4);
	gpioConfig(GpioF, 1, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_PULL_UP, GPIO_HI_SPEED);
	gpioConfigAltFunc(GpioF,1,AF4);

	enableI2C1_as_Master();
	enableI2C2_as_Slave();

}
