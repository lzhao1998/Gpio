/*
 * usart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user2
 */

#include "usart.h"
#include "string.h"
//#include  "stm32f4xx.h"
/*Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last*/

/* STM32 Pin 	Name   		| 	 CH340 Name
 * 		PA9 = TX(usart1)	|		RX
 * 		PA10 = RX(usart1)	|		TX
 * 				GND			|		GND
 * */

void configureUsart1(void)
{
	Usart1->CR1 &= ~OVER_SAMPLING_16;		//Over sampling 16
	Usart1->CR1 = (USART_ENABLE|DATA_BIT_9|PARITY_CONTROL_ENABLE|ODD_PARITY);
	/*Usart1->CR1 |= USART_ENABLE;			//Enable usart
	Usart1->CR1 |= DATA_BIT_9;				//Word length = 9 data bit
	Usart1->CR1 |= PARITY_CONTROL_ENABLE;	//Enable parity control
	Usart1->CR1 |= ODD_PARITY;				//Odd parity*/
	Usart1->CR2 |= STOP_BIT_20;				//2 stop bit
}

void setBaudRate(int mantissa, int fraction)
{
	Usart1->BRR |= fraction;
	Usart1->BRR |= (mantissa << 4);
}
void enableTransmit()
{
	Usart1->CR1 |= ENABLE_TRANSMIT;
}

void enableReceive()
{
	Usart1->CR1 |= ENABLE_RECEIVE;
}

void writeData(char *data)
{
	//when data is not transferred to the shift register
	//do nothing use the data is transferred (TXE)
	while(!(Usart1->SR & (1 << 7)));
	Usart1->DR = *data;
}

//max data size is 8 bit
uint8_t ReceiveByte(){
	//when data is not received
	//do nothing until the data is received (RXNE)
	//RXNE = 1 , return data to store in buffer
	while(!(Usart1->SR & (1 << 5)));
	return (uint8_t)Usart1->DR;
}

void stringReceive(char *message){
	//check data is ready to be read or not
	*(message) = ReceiveByte();
	//Receive data until the enter is press (0xA is the value of 'Enter')
	while(*(message)!=0xA){
		message++;
		*(message) = ReceiveByte();
	}
	*message=0;
}
