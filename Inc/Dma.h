/*
 * Dma.h
 *
 *  Created on: Dec 19, 2017
 *      Author: user2
 */

#ifndef DMA_H_
#define DMA_H_

#include <stdint.h>
#define DMA1_BASE_ADDR		0x40011000
#define DMA2_BASE_ADDR		0x40011000
#define dma1				((DmaReg *)(DMA1_BASE_ADDR))
#define dma2				((DmaReg *)(DMA2_BASE_ADDR))

typedef struct DmaStreamReg DmaStreamReg;
struct DmaStreamReg {
	volatile uint32_t CR;		//0x00
	volatile uint32_t NDTR;		//0x00
	volatile uint32_t PAR;		//0x00
	volatile uint32_t M0AR;		//0x00
	volatile uint32_t M1AR;		//0x00
	volatile uint32_t FCER;		//0x00
};


typedef struct DmaReg DmaReg;
struct DmaReg {
	volatile uint32_t LISR;		//0x00
	volatile uint32_t HISR;		//0x04
	volatile uint32_t LIFCR;		//0x08
	volatile uint32_t HIFCR;		//0x0c
	DmaStreamReg S[8];
};

dma1->LIFCR = ?;
dma1->S[4].M0AR = ?;

#endif /* DMA_H_ */
