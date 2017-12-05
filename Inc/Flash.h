/*
 * Flash.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user2
 */

#ifndef FLASH_H_
#define FLASH_H_

#include <stdint.h>
#define FLASH_BASE_ADDR		0x40023C00
#define flash				((FlashReg *)(FLASH_BASE_ADDR))

typedef struct FlashReg FlashReg;
struct FlashReg {
	volatile uint32_t ACR;		//0x00
	volatile uint32_t KEYR;		//0x04
	volatile uint32_t OPTKEYR;	//0x08
	volatile uint32_t SR;		//0x0c
	volatile uint32_t CR;		//0x10
	volatile uint32_t OPTCR;	//0x14
	volatile uint32_t OPTCR1;	//0x18
};

//Size to write
#define BYTE_SIZE			0
#define HALFWORD_SIZE		1
#define WORD_SIZE			2
#define DOUBLE_WORD_SIZE	3

//Key to unlock flash
#define KEY1	0x45670123
#define KEY2	0xCDEF89AB

//End of Operation
#define EOP_INTERRUPT_DISABLE	0
#define EOP_INTERRUPT_ENABLE	1

#define MASS_ERASE		(1 << 2)
#define SECTOR_ERASE	(1 << 1)
#define FLASH_START		(1 << 16)

#define FLASH_PROGRAM_EN	1

int flashEraseSection(int sectionNum);
int writeMessage(char *message, char *memoryToWrite);
int flashEnableProgramming(int programSize);
int flashDisable(void);

#endif /* FLASH_H_ */
