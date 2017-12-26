/*
 * Dma.h
 *
 *  Created on: Dec 19, 2017
 *      Author: user2
 */

#ifndef DMA_H_
#define DMA_H_

#include <stdint.h>
#include "Rcc.h"
#include "usart.h"

#define DMA1_BASE_ADDR		0x40026000
#define DMA2_BASE_ADDR		0x40026400
#define dma1				((DmaReg *)(DMA1_BASE_ADDR))
#define dma2				((DmaReg *)(DMA2_BASE_ADDR))

typedef struct DmaStreamReg DmaStreamReg;
struct DmaStreamReg {
	volatile uint32_t CR;		//0x00
	volatile uint32_t NDTR;		//0x04
	volatile uint32_t PAR;		//0x0c
	volatile uint32_t M0AR;		//0x00
	volatile uint32_t M1AR;		//0x00
	volatile uint32_t FCR;		//0x00
};


typedef struct DmaReg DmaReg;
struct DmaReg {
	volatile uint32_t LISR;		//0x00
	volatile uint32_t HISR;		//0x04
	volatile uint32_t LIFCR;		//0x08
	volatile uint32_t HIFCR;		//0x0c
	DmaStreamReg S[8];
};

//dma1->LIFCR = ?;
//dma1->S[4].M0AR = ?;

//DMA interrupt status register (CR)
#define DMA_FEIF 	(1 << 0)
#define DMA_DMEIF 	(1 << 2)
#define DMA_TEIF 	(1 << 3)
#define DMA_HTIF 	(1 << 4)
#define DMA_TCIF 	(1 << 5)

//Select channel(CR)
#define channel0 (0 << 25)
#define channel1 (1 << 25)
#define channel2 (2 << 25)
#define channel3 (3 << 25)
//#define channel4 (0x1 << 27)
#define channel4 (4 << 25)
#define channel5 (5 << 25)
#define channel6 (6 << 25)
#define channel7 (7 << 25)

//MBURST(CR)
#define Mburst_single 	(0 << 23)
#define Mburst_incr4 	(1 << 23)
//#define Mburst_incr8 	(0x1 << 24)
#define Mburst_incr8 	(2 << 23)
#define Mburst_incr16	(3 << 23)

//PBURST(CR)
#define Pburst_single 	(0 << 21)
#define Pburst_incr4 	(1 << 21)
#define Pburst_incr8 	(2 << 21)
#define Pburst_incr16	(3 << 21)

//double buffer mode(CR)
#define double_buffer_disable	(0 << 18)
#define double_buffer_enable	(1 << 18)

//Priority level(CR)
#define low_prio	(0 << 16)
#define medium_prio	(1 << 16)
//#define high_prio	(0x1 << 17)
#define high_prio	(2 << 16)
#define vhigh_prio	(3 << 16)

//MSIZE(CR)
#define Msize_byte		(0 << 13)
#define Msize_half_word	(1 << 13)
#define Msize_word		(2 << 13)
#define Msize_reserved	(3 << 13)

//PSIZE(CR)
#define Psize_byte		(0 << 11)
#define Psize_half_word	(1 << 11)
#define Psize_word		(2 << 11)
#define Psize_reserved	(3 << 11)

#define MemoryPointerIn (1 << 10)

//Circular mode(CR)
#define circular_mode_disable	(0 << 8)
#define circular_mode_enable	(1 << 8)

//Data transfer direction(CR)
#define Peripheral_to_memory	(0 << 6)
#define Memory_to_peripheral	(1 << 6)
#define Memory_to_memory		(2 << 6)
#define Data_transfer_reserved	(3 << 6)

//Peripheral flow controller(CR)
#define DMA_flow_counter 		(0 << 5)
#define peripheral_flow_counter	(1 << 5)

//Stream enable(CR)
#define stream_enable	(1 << 0)
#define stream_disable	(0 << 0)

//FIFO threshold selection(fcr)
#define full_fifo_1_4	(0x00 << 0)
#define full_fifo_1_2	(0x01 << 0)
#define full_fifo_3_4	(0x10 << 0)
#define full_fifo		(0x11 << 0)

void initDmaForUsart1();
void dmaSetAddressesAndSize(uint32_t memoryAddr, uint32_t peripheralAddr, uint32_t size);
int dmaStreamHasTransferCompledted(DmaReg *dma, int streamNum, int flag);
#endif /* DMA_H_ */
