/*
 * ADC.h
 *
 *  Created on: Jan 2, 2018
 *      Author: user2
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <math.h>
#include "Rcc.h"
#include "Common.h"
#include "Gpio.h"

#define ADC1_BASE_ADDR			0x40012000
#define ADC2_BASE_ADDR			0x40012100
#define ADC3_BASE_ADDR			0x40012200
#define ADC_CONFIG_BASE_ADDR	0x40012300

#define adc1				((AdcReg *)(ADC1_BASE_ADDR))
#define adc2				((AdcReg *)(ADC2_BASE_ADDR))
#define adc3				((AdcReg *)(ADC3_BASE_ADDR))
#define adcConfig				((AdcConfigReg *)(ADC_CONFIG_BASE_ADDR))

typedef struct AdcReg AdcReg;  //adc 1 2 3
struct AdcReg {
	volatile uint32_t SR;				//0h
	volatile uint32_t CR1;				//4h
	volatile uint32_t CR2;				//8h
	volatile uint32_t SMPR1;			//ch
	volatile uint32_t SMPR2;			//10h
	volatile uint32_t JOFR1;			//14h
	volatile uint32_t JOFR2;			//18h
	volatile uint32_t JOFR3;			//1ch
	volatile uint32_t JOFR4;			//20h
	volatile uint32_t HTR;				//24h
	volatile uint32_t LTR;				//28h
	volatile uint32_t SQR1;				//2ch
	volatile uint32_t SQR2;				//30h
	volatile uint32_t SQR3;				//34h
	volatile uint32_t JSQR;				//38h
	volatile uint32_t JDR1;				//3ch
	volatile uint32_t JDR2;				//40h
	volatile uint32_t JDR3;				//44h
	volatile uint32_t JDR4;				//48h
	volatile uint32_t DR;				//4ch
};

typedef struct AdcConfigReg AdcConfigReg;
struct AdcConfigReg {
	volatile uint32_t CSR;		//0x00
	volatile uint32_t CCR;		//0x04
	volatile uint32_t CDR;		//0x08
};

//Resolution (CR1 register)							=> RES
#define RESOLUTION_12	(0 << 24)
#define RESOLUTION_10	(1 << 24)
#define RESOLUTION_8	(2 << 24)
#define RESOLUTION_6	(3 << 24)

//Enable watchdog in regular channel (CR1 register)	=> AWDEN
#define ANALOG_WATCHDOG_DIS	(0 << 23)
#define ANALOG_WATCHDOG_EN	(1 << 23)

/*
//input channel (CR1 register)						=> AWDCH
#define ADC_input_CH0 	 0
#define ADC_input_CH1 	 1
#define ADC_input_CH2	 2
#define ADC_input_CH3	 3
#define ADC_input_CH4  	 4
#define ADC_input_CH5  	 5
#define ADC_input_CH6  	 6
#define ADC_input_CH7  	 7
#define ADC_input_CH8  	 8
#define ADC_input_CH9 	 9
#define ADC_input_CH10   10
#define ADC_input_CH11   11
#define ADC_input_CH12   12
#define ADC_input_CH13   13
#define ADC_input_CH14   14
#define ADC_input_CH15   15
#define ADC_input_CH16   16
#define ADC_input_CH17   17
#define ADC_input_CH18   18*/

//Start Conversion regular channel (CR2 register)	=> SWSTART
#define RESET_STATE			(0 << 30)
#define START_CONVERSION	(1 << 30)

//Align data (CR2 register)							=> ALIGN
#define RIGHT_ALIGN	(0 << 11)
#define LEFT_ALIGN	(1 << 11)

//Enable DMA (CR2 register) for single DAC			=> DMA
#define DMA_MODE_DISABLE (0 << 8)
#define DMA_MODE_ENABLE	 (1 << 8)

//Continuous conversion (CR2 register)				=>CONT
#define SINGLE_CONVERSION		(0 << 1)
#define CONTINUOUS_CONVERSION	(1 << 1)

//Enable ADC (CR2 register)							=> ADON
#define ADC_DISABLE	0
#define ADC_ENABLE 	1

//Sample time register (SMPR1 register) channel 10 - 18
#define CYCLE_3			0
#define CYCLE_15		1
#define CYCLE_28		2
#define CYCLE_56		3
#define CYCLE_84		4
#define CYCLE_112		5
#define CYCLE_144		6
#define CYCLE_480		7

//Sequence length for regular channel (SQR1 register)
#define CONVERSION_1	(0 << 20)
#define CONVERSION_2	(1 << 20)
#define CONVERSION_3	(2 << 20)
#define CONVERSION_4	(3 << 20)
#define CONVERSION_5	(4 << 20)

//channel (SQR3 register)
#define CHANNEL_5	5
#define CHANNEL_13	(13 << 5)

//Enable DMA (CCR register) for multi DAC
#define DMA_DISABLE (0 << 14) //????

void ADC1Enable();
void ConfigADC();
#endif /* ADC_H_ */
