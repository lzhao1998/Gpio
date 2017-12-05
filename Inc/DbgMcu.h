/*
 * DbgMcu.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user2
 */

#ifndef DBGMCU_H_
#define DBGMCU_H_

#include <stdint.h>
#define DBGMCU_APB1_FZ		(*(uint32_t*)(0xE0042008))
#define DBGMCU_APB2_FZ		(*(uint32_t*)(0xE004200C))
#define DBG_TIM8_STOP		(1 << 1)

#define haltTimer8WhenDebugging()	(DBGMCU_APB2_FZ |= DBG_TIM8_STOP)

//I2C
#define DBG_I2C1_SMBUS_TIMEOUT (1 << 21)
#define DBG_I2C2_SMBUS_TIMEOUT (1 << 22)
#define DBG_I2C3_SMBUS_TIMEOUT (1 << 23)
#define haltI2C1WhenDebug()	(DBGMCU_APB1_FZ |= DBG_I2C1_SMBUS_TIMEOUT)
#define haltI2C2WhenDebug()	(DBGMCU_APB1_FZ |= DBG_I2C2_SMBUS_TIMEOUT)
#define haltI2C3WhenDebug()	(DBGMCU_APB1_FZ |= DBG_I2C3_SMBUS_TIMEOUT)

#endif /* DBGMCU_H_ */
