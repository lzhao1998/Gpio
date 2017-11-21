/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#include "Gpio.h"
#include "Rcc.h"
#include "Rng.h"
#include "Nvic.h"
#include "SysTick.h"
#include "EXTI.h"
#include "Timer.h"
#include "DbgMcu.h"
#include <stdio.h>

#define greenLedPin		13
#define redLedPin		14
#define blueButtonPin	0
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);


/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
	extern void initialise_monitor_handles(void);
/* USER CODE END PFP */
int PressCount = 0;
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
	//int i = 0;
	initialise_monitor_handles();
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  printf("HELLO WORLD!\n");

  //NVIC
 /* //Enable I2C1_Event Interrupt
  nvicEnableIrq(31);		//Enable
  nvicSetPriority(31,8);
  //Disable I2C1 Event Interrupt
  nvicDisableIrq(31);*/

  //Enable System Tick
  /*//sysTickIntrDisable();		//Disable interrupt
  sysTickIntrEnable();			//Enable interrupt
  sysTickSetReload(11250000);
  sysTickPrescaledSpeed();
  sysTickClrCounter();
  sysTickEnable();*/
  sysTickDisable();

  //Enable Gpio
  enableGpioA();
  enableGpioG();

  //Enable random number generator
  /*enableRng();*/

  //Enable RNG & HASH interrupt
  /*nvicEnableIrq(80);
  nvicSetPriority(80,4);*/

  //Enable RNG by using interrupt
  /*getRandomNumberByInterrupt();*/

  //Configure the Gpio
  gpioConfig(GpioA, blueButtonPin, GPIO_MODE_IN, 0, GPIO_NO_PULL, 0);
  gpioConfig(GpioG, redLedPin, GPIO_MODE_OU, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_HI_SPEED);
  gpioConfig(GpioG, greenLedPin, GPIO_MODE_OU, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_LOW_SPEED);


  //Configure GPIOA pin 8 as MCO1 (push-pull with no-pull at very
  //high speed output)
  /*gpioConfig(GpioA,8,GPIO_MODE_AF,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_HI_SPEED);
  gpioConfigAltFunc(GpioA,8,AF0);
  rccSelectMco1Src(MCO_HSE_SRC);
  rccSetMco1Prescaler(MCO_DIV_BY_5);*/

  //EXTI
  /*nvicEnableIrq(6); //enable EXTI in nvic which is in position 6
  nvicSetPriority(6,4);
  EXTI_INTR_UNMASK(blueButtonPin);
  EXTI_FTSR_ENABLE(blueButtonPin);
  EXTI_RTSR_DISABLE(blueButtonPin);*/

  //enable timer8
  wait500ms();
  haltTimer8WhenDebugging();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	gpioWrite(GpioG, redLedPin,1);
	waitTimer500ms();
	gpioWrite(GpioG, redLedPin,0);
	waitTimer500ms();

	//gpioWrite(GpioG, redLedPin,1);
	//__WFI();
	//gpioWrite(GpioG, redLedPin,0);
	//__WFI();
	//gpioWrite(GpioG, greenLedPin,0);

	  //int num = getRandomNumber();
	 // printf("(%d) 0x%x \n",i++,num);
	  /*
	 gpioWrite(GpioG, redLedPin,0);
	 gpioWrite(GpioG, greenLedPin,1);
	 HAL_Delay(200);
	 gpioWrite(GpioG, redLedPin,1);
	 HAL_Delay(200);
	 gpioLock(GpioG,greenLedPin);
	 gpioConfig(GpioG, greenLedPin, GPIO_MODE_IN, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_LOW_SPEED);
	*/

	  /*//without the interrupt of the sysTick
	  gpioWrite(GpioG, redLedPin,1);
	  while(!sysTickHasExpired());
	  gpioWrite(GpioG, redLedPin,0);
	  while(!sysTickHasExpired());
	*/

	  //using bluebuttonpin to control the LED
	 /* volatile int blueButtonState;

	  blueButtonState = gpioRead(GpioA, blueButtonPin);
	  if(blueButtonState == 1)
	  {
		  gpioWrite(GpioG, redLedPin,0);
		  gpioWrite(GpioG, greenLedPin,1);
		  HAL_Delay(200);
		  gpioWrite(GpioG, redLedPin,1);
		  HAL_Delay(200);
	  }
	  else
	  {
		  gpioWrite(GpioG, redLedPin,1);
		  gpioWrite(GpioG, greenLedPin,1);
		  HAL_Delay(200);
		  gpioWrite(GpioG, greenLedPin,0);
		  HAL_Delay(200);
	  }*/

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}


/* USER CODE BEGIN 4 */
void waitTimer500ms(void)
{
	while(!((Timer8->SR) & 0x01))
	{}
	Timer8->SR &= ~(0x01);
}

void My_SysTick_Handler(void)
{
	static int ledState = 0;
	//Just do nothing, but reading the CTRL register to clear the Counter Flag
	volatile int flags = Tick->CTRL;

	gpioWrite(GpioG, redLedPin,(ledState = !ledState));
}

void EXTI0_IRQHandler(void)
{
	EXTI_PR_Clear(blueButtonPin);
	gpioWrite(GpioG, greenLedPin,1);
	//gpioWrite(GpioG, greenLedPin,0);
	PressCount++;
}

void HASH_RNG_IRQHandler(void)
{
	volatile int rand =  Rng->DR;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
