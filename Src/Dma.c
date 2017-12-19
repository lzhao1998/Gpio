/*
 * Dma.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user2
 */

#include "dma.h"

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

}

void dmaSetAddressesAndSize(uint32_t memoryAddr, uint32_t peripheralAddr, uint32_t size)
{

}
