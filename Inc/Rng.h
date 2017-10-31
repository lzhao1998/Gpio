/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user2
 */
#include <stdint.h>
#ifndef RNG_H_
#define RNG_H_

#define RNG_BASE_ADDR	0x50060800
#define Rng 			((RngReg *)(RNG_BASE_ADDR))

typedef struct RngReg RngReg;
struct RngReg {
	volatile uint32_t CR; //control register 	0h
	volatile uint32_t SR; //status register		4h
	volatile uint32_t DR; //data register		8h
};

//status register
#define RNG_FAULTY_SEQUENCE (1 << 2)
#define RNG_FAULTY_CLK		(1 << 1)
#define RNG_DRDY			1

//control register
#define RNG_RNGEN			(1 << 2)

//
#define RNG_IE				(1 << 3)

void generateRandomNumber(void);
int isRandomNumberAvailable(void);
int isAnyError(void);
int isFaultyRandomSequence(void);
int getRandomNumber(void);
void getRandomNumberByInterrupt(void);

#endif /* RNG_H_ */
