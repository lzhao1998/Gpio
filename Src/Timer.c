/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user2
 */

#include "Timer.h"
#include "Rcc.h"

void initTimer8()
{
	//enable timer8 -- unreset,enable clk
	//configure the maximum counter value by setting ARR
	//select the clock source(internal) --SMCR:SMS[2:0]
	//configure the prescaler by setting PSC
	//enable timer8 -- CR1:CEN = 1
	enableTimer8();
	Timer8->ARR = 0xFFFF;			//ARR
	Timer8->PSC = 0x4; 				//PSC (prescale)
	Timer8->SMCR &= ~(0x111);	 	//SMCR:SMS
	Timer8->CR1 |= 0x01; 			//CR1:CEN
}

void wait500ms()
{
	enableTimer8();
	Timer8->ARR = 5000;				//ARR
	Timer8->PSC = 18000; 				//PSC (prescale)
	Timer8->SMCR &= ~(0x111);	 	//SMCR:SMS
	Timer8->CR1 |= 0x01; 			//CR1:CEN
}

void initTimer8Channel1()
{
	//configure timer8 channel 1 pin(pc6) -- Enable portC and set pin as AltFunc3 Out-PP(gpio also need set as AF)
	//configure channel as output compare -- CCMR1s	:CC1S[1:0]=0
	//configure output as toggle .....

}

void initTimer8Channel3()
{
	//configure timer8 channel 3 pin(pc8) -- Enable portC and set pin as AltFunc3
	//input
}
