/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user2
 */

#include "Timer.h"


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

void initTimer8ForInputCaptureAndOutputCompare()
{
	enableTimer8();
	Timer8->CCER &= ~(CC1E_ON | CC3E_ON | CC4E_ON);	//disable CC for configure
	Timer8->CR1 &= ~(1 << 0);	//counter disable for configure
	Timer8->SMCR &= ~(7 <<0);	//slave mode disabled
 	Timer8->CCER &= ~(OC1_ch1_active_low);		//OC1 pin active high polarity
	Timer8->CR2 &= ~(auto_reload_preload);		//No auto reload preload for OC
	Timer8->CCMR1 = 0;							//CH1 configured as output
	Timer8->CCMR2 |= (IC4_mapped_TI3 | IC3_mapped_TI3);		//IC4 mapped to TI3, IC3 mapped to IC3
	Timer8->CCER |= (CC3P_RISE | CC4P_FALL);	//Channel3 capture rising edge,Channel 4 capture falling edge
	Timer8->PSC = 2;							//prescale 2
	Timer8->BDTR |= MOE_ON; 					// MOE bit in BDTR register
	Timer8->ARR = 126;			//ARR value
	Timer8->CR1 &= (0x00 <<8);	//Tdts = Tck
	Timer8->CR1 |= (1 << 7);	//ARR enable
	Timer8->CR1 &= ~(1 << 4);	//used upcounter
	Timer8->CR1 |= (1 << 0);	//counter enable
	Timer8->CCER |= (CC1E_ON | CC3E_ON | CC4E_ON);	//enable CC
}

void forceOutCompareChannel1High()
{
	Timer8->CCMR1 &= ~(7 << 4);				//clear bit 4-6 in CCMR1
	Timer8->CCMR1 |= OC1M_force_active;		//set bit 4-6 to 5 which is force active level
}

void forceOutCompareChannel1Low()
{
	Timer8->CCMR1 &= ~(7 << 4);				//clear bit 4-6 in CCMR1
	Timer8->CCMR1 |= OC1M_force_inactive;	//set bit 4-6 to 4 which is force inactive level
}

void toggleOutCompareChannel1WithForce(int i)
{
	//forceOutCompareChannel1High();		//force to high
	//forceOutCompareChannel1Low();		//force to low
	while(i == 1){
		if((Timer8->CNT) < 12)
		{
			forceOutCompareChannel1Low();
		}
		if((Timer8->CNT) >= 12)
		{
			forceOutCompareChannel1High();
		}
	}
	while(i == 0)
	{
		if((Timer8->CNT) >= 12)
		{
			forceOutCompareChannel1Low();
		}
		if((Timer8->CNT) < 12)
		{
			forceOutCompareChannel1High();
		}
	}
}

void initTimer8ForDMA()
{
	enableTimer8();
	forceOutCompareChannel1High();			//force active
	Timer8->CCER |= CC1E_ON ;				//enable OC pin
	Timer8->CCER &= ~(OC1_ch1_active_low);	//active high polarity (CC1P)
	Timer8->CCMR1 &= ~(7 << 4);
	Timer8->CCMR1 |= OC1M_toggle;			//toggle mode
	Timer8->PSC = 2;			//prescale 2
	Timer8->ARR = 126;						//set ARR
	Timer8->CR1 |= (1 << 7);	//ARR enable
	Timer8->CCR1 = (Timer8->ARR);			//CCR1 = ARR
	Timer8->CNT	= ((Timer8->ARR) - 1);		// CNT = ARR -1
	Timer8->CR1 |= (1 << 0);				//counter enable
	Timer8->DIER |= (1 << 9);				//enable DMA request for CH1
}

void sendBitPattern(uint8_t data)
{
	//10101101
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
