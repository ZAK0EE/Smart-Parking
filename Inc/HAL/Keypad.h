/*
 * Keypad.h
 *
 *  Created: 22/07/31 05:29:00 PM
 *  Author: Ziad Gamamelden
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_


#include "MCAL/Stm32_F103C6_GPIO.h"

#define KPAD_PORT GPIOB


// Keypad Rows
#define KPAD_R0 GPIO_PIN_0
#define KPAD_R1 GPIO_PIN_1
#define KPAD_R2 GPIO_PIN_3
#define KPAD_R3 GPIO_PIN_4

// Keypad Columns
#define KPAD_C0 GPIO_PIN_5
#define KPAD_C1 GPIO_PIN_6
#define KPAD_C2 GPIO_PIN_7

void KPAD_init();

char KPAD_Get_Char();

#endif /* HAL_KEYPAD_H_ */
