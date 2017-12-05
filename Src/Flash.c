/*
 * Flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user2
 */


#include "Flash.h"
#include "string.h"

/*
 * Section erase the flash memory
 * Input : Section number that needed to erase
 * Return :
 * 	0	Fail to erase
 * 	1	Successful
 * Only valid for stm32f429ZI
*/
int flashEraseSection(int sectionNum)
{
	//Set the sector number to erase
	//Set to sector erase
	//Set parallelism size
	//Enable end of programming interrupt
	//Start Flash Erase
	if(sectionNum > 11)
		{sectionNum = sectionNum + 4;}
	flash->CR = ((sectionNum << 3) | SECTOR_ERASE | (EOP_INTERRUPT_ENABLE << 24));
	flash->CR |= FLASH_START;

	//Check for failure or success
	//Return value
	return 1;
	//idk how to check fail or not

}

//sector 13 address ???
int writeMessage(char *message, char *memoryToWrite)
{
	strcpy(memoryToWrite,message);
	return 1;
}

/*
 *	Enable flash programming with the stated program size
 *	Input:
 *		programSize is the size when writing into the flash:
 *			FLASH_BTYE_SIZE
 *			FLASH_HALFWORD_SIZE
 *			FLASH_WORD_SIZE
 *			FLASH_DOUBLE_WORD_SIZE
 */
int flashEnableProgramming(int programSize)
{
	//Unlock through KEYR
	flash->KEYR = KEY1;
	flash->KEYR = KEY2;

	//check unlock or not
	if(((flash->CR)&= 0x80000000) == 1)
	{
		printf("It's lock\n");
	}
	else
	{
		printf("It's unlock\n");
	}
	flash->CR = (programSize << 8) | FLASH_PROGRAM_EN;
	return 1;
}

int flashDisable()
{
	flash->CR = ~FLASH_PROGRAM_EN;
	return 1;
}
