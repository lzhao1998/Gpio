/*
 * IWDG.c
 *
 *  Created on: Jan 9, 2018
 *      Author: user2
 */

#include "IWDG.h"

void waitCounterValueUpdate()	//IWDG
{
	while((IWDG->SR & IWDG_RVU_ONGOING));
}

void waitPrescaleValueUpdate()	//IWDG
{
	while((IWDG->SR & IWDG_PVU_ONGOING));
}

void configWWDG(int countDownVal)
{
	//Enable watchdog and timer value
	Wwdg->CR = countDownVal  | WATCGDOG_ENABLE | WWDG_T6;
}

void setWindowValue(int windowVal)
{
	//Set window value and prescale
	Wwdg->CFR = (windowVal|WWDG_T6|WWDG_DIV_2);
}

void WwdgTimer500ms()
{
	int i = 0;
	setWindowValue(28);
	configWWDG(55);		//total time is 10ms
	clearEWIF();
	while(i++ < 50) 		//to get 500ms, 500/10 = 50
	{
		while(!(Wwdg->SR & WWDG_EWIF));
		{
			configWWDG(55);
			clearEWIF();
		}
	}
}

void clearEWIF()
{
	Wwdg->SR = 0;
}

