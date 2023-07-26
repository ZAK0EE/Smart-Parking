/*
 * Alarm.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Ziad Gamalelden
 */

#ifndef HAL_ALARM_H_
#define HAL_ALARM_H_

#include "MCAL/Stm32_F103C6_GPIO.h"

#define ALARM_CORRECID_PORT GPIOA
#define ALARM_CORRECID_PIN GPIO_PIN_11

#define ALARM_WRONGID_PORT GPIOA
#define ALARM_WRONGID_PIN GPIO_PIN_0

#define ALARM_NUM_BLINKS 6
void Alarm_init();
