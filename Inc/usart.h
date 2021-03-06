/*
 * usart.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user2
 */

#ifndef USART_H_
#define USART_H_

#include "DbgMcu.h"
#include <stdint.h>
#include <stdarg.h>

#define USART1_BASE_ADDR		0x40011000
#define Usart1				((UsartReg *)(USART1_BASE_ADDR))

typedef struct UsartReg UsartReg;
struct UsartReg {
	volatile uint32_t SR;		//0x00
	volatile uint32_t DR;		//0x04
	volatile uint32_t BRR;		//0x08
	volatile uint32_t CR1;		//0x0c
	volatile uint32_t CR2;		//0x10
	volatile uint32_t CR3;		//0x14
	volatile uint32_t GTPR;		//0x18
};

//CR1 configure Over Sampling Mode
#define	OVER_SAMPLING_16	(0 << 15)
#define OVER_SAMPLING_8		(1 << 15)

//CR1 configure USART enable
#define USART_DISABLE	 (0 << 13)
#define USART_ENABLE	 (1 << 13)

//CR1 configure Word Length
#define DATA_BIT_8	(0 << 12)
#define	DATA_BIT_9	(1 << 12)

//CR1 configure Parity Control
#define PARITY_CONTROL_DISABLE	(0 << 10)
#define PARITY_CONTROL_ENABLE	(1 << 10)

//CR1 configure Parity Selection
#define EVEN_PARITY	(0 << 9)
#define ODD_PARITY	(1 << 9)

//CR1 configure Transmitter Enable
#define DISABLE_TRANSMIT	(0 << 3)
#define ENABLE_TRANSMIT		(1 << 3)

//CR1 configure Receiver Enable
#define DISABLE_RECEIVE	(0 << 2)
#define ENABLE_RECEIVE	(1 << 2)

//CR2 configure Stop bits
#define STOP_BIT_05		(0x00 << 12)
#define STOP_BIT_10		(0x01 << 12)
#define STOP_BIT_15		(0x11 << 12)
#define STOP_BIT_20		(0x10 << 12)

//CR3
#define UART_DMA_TX_EN	(1 << 7)
#define UART_DMA_Rx_EN	(1 << 6)

void configureUsart1(void);
void setBaudRate(int mantissa, int fraction);
void enableTransmit();
void enableReceive();
void writeData(char *data);
uint8_t ReceiveByte();
void stringReceive(char *message);
void UsartDmaTxEn();
void serialPrint(char *format, ...);

#endif /* USART_H_ */
