/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user2
 */
#include "Rng.h"

/*
 * Non-Blocking function
 */

void generateRandomNumber(void)
{
	Rng->CR = RNG_RNGEN;
}

/*
 * Find out if Rng has produced a random number
 * Return:
 * 	0 if not ready
 * 	1 if ready
 */
int isRandomNumberAvailable(void)
{
	return Rng->SR & RNG_DRDY;
}

/*
 * Find out if RNG has encountered any error
 * Return:
 * 	0 if no error
 * 	non-zero if error
 */
int isAnyError(void)
{
	return Rng->SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLK);
}

/*
 * Find out if RNG has encountered faulty random sequence
 * Return:///////////
 * 	0 if no error
 * 	non-zero if error
 */
int isFaultyRandomSequence(void)
{
	return Rng->SR & RNG_FAULTY_SEQUENCE;
}


/*
 * Get a random number. Blocking function.
 */
int getRandomNumber(void)
{
	do{
		generateRandomNumber();
		while(!isRandomNumberAvailable());
	}while(isFaultyRandomSequence());
	return Rng->DR;
}

void getRandomNumberByInterrupt(void)
{
	Rng->CR |= RNG_RNGEN | RNG_IE;
}
