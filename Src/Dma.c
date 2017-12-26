/*
 * Dma.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user2
 */

#include "dma.h"
#include <stdio.h>

#define dataStreamHasTransferCompleted(d,s) 	    \
						dataStreamCheckFlag(d, s, DMA_TCIF)
#define dataStreamHasHalfTransferCompleted(d,s)	    \
						dataStreamCheckFlag(d, s, DMA_HCIF)
#define dataStreamISTransferError(d,s) 			    \
						dataStreamCheckFlag(d, s, DMA_TEIF)
#define dataStreamIsDirectModeError(d,s)		    \
						dataStreamCheckFlag(d, s, DMA_DMEIF)
#define dataStreamIsFifoError(d,s)					 \
						dataStreamCheckFlag(d, s, DMA_FEIF)

int lowFlags = (1 << 27);
int highFlags = (1 << 27) | (1 << 11);

/*
 * DMA2.stream2.channel4 = USART.Rx
 * DMA2.stream7.channel4 = USART.Tx
 *
 * PSIZE = 1 byte
 * MSIZE = 1 byte
 *
 * MBURST = in 4 beats increment
 * FIFO_BURST = 1/2 threshold
 *
 * PINC = no
 * MINC = yes
 *
 * Circular mode = no
 * Double buffer = no
 *
 * priority = high
 *
 * flow controller = DMA
 *
 * Transfer direction = memory-to-memory(Tx)
 * Transfer direction = peripheral-to-memory(Rx)
 *
 */
void initDmaForUsart1()
{
	char *str = "Hello World";
	dma2->S[2].CR &= ~(stream_enable);
	dma2->S[2].CR = channel4 | Mburst_incr8 | MemoryPointerIn | high_prio | Msize_byte |  Psize_byte | Peripheral_to_memory | DMA_flow_counter;
	dma2->S[2].CR |= circular_mode_enable;	//enable circular
	dma2->S[2].FCR = full_fifo_1_2;
	dma2->S[7].CR &= ~(stream_enable);
	dma2->S[7].CR = channel4 | Mburst_incr8 | MemoryPointerIn | high_prio | Msize_byte |  Psize_byte | Memory_to_peripheral | DMA_flow_counter;
	//dma2->S[7].CR |= circular_mode_enable;	//enable circular
	dma2->S[7].FCR = full_fifo_1_2;
	dma2->S[2].PAR = &(Usart1->DR);
	dma2->S[7].PAR = &(Usart1->DR);

	dma2->S[2].M0AR = str;
	dma2->S[7].M0AR = str;

	dma2->S[2].NDTR = strlen(str);
	dma2->S[7].NDTR = strlen(str);

	dma2->S[2].CR |= (stream_enable);
	dma2->S[7].CR |= (stream_enable);

}

void dmaSetAddressesAndSize(uint32_t memoryAddr, uint32_t peripheralAddr, uint32_t size)
{

}

int dmaStreamHasTransferCompledted(DmaReg *dma, int streamNum, int flag)
{
	int isUpper16 = FALSE;
	 	volatile uint32_t *intrStatusReg = dma->LISR;
	 	if(streamNum >= 4)
	 	{
	 		intrStatusReg = &dma->HISR;
	 		streamNum -= 4;
	 	}
	 	if(streamNum >= 2)
	 	{
	 		streamNum -= 2;
	 		isUpper16 = TRUE;
	 	}
	 	return *intrStatusReg & (flag << (6 * streamNum + 16*isUpper16));
}

