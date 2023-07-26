/**
 * @file Stm32_F103C6_gpio.h
 * @brief STM32F103C6 GPIO (General Purpose Input/Output) header file.
 * @date July 27, 2022
 * @author Ziad Gamalelden
 */

#ifndef STM32_F103C6_GPIO_H_
#define STM32_F103C6_GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "MCAL/stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

// Configuration structure

typedef struct
{
	uint16_t GPIO_PinNumber;  /*!< Specifies the GPIO pins to be configured.
                           	       This parameter can be any value of @ref GPIO_pins_define */

	uint8_t GPIO_Mode;	 	  /*!< Specifies the operating mode for the selected pins.
                           	   	   This parameter can be a value of @ref GPIO_mode_define */

	uint8_t GPIO_Speed;		  /*!< Specifies the speed for the selected pins.
                           	   	   This parameter can be a value of @ref GPIO_speed_define */

}GPIO_PinConfig_t;

// @ref GPIO_PIN_State
#define GPIO_PIN_SET 			1
#define GPIO_PIN_RESET			0

// @ref GPIO_RETURN_LOCK
#define GPIO_RETURN_OK 1
#define GPIO_RETURN_ERROR 0

//-----------------------------
//Macros Configuration References
//-----------------------------

//  @ref GPIO_pins_define
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */


/*
 * @ref GPIO_mode_define
	0: Analog mode
	1: Floating input (reset state)
	2: Input with pull-up
	3: Input pull-down
	4: General purpose output push-pull
	5: General purpose output Open-drain
	6: Alternate function output Push-pull
	7: Alternate function output Open-drain
	8: Alternate function input
 */

#define  GPIO_MODE_ANALOG                       0x00000000u   // Analog Mode
#define  GPIO_MODE_INPUT_FLO 					0x00000001u   // Input Floating Mode
#define  GPIO_MODE_INPUT_PU						0x00000002u   // Input Pull Mode
#define  GPIO_MODE_INPUT_PD						0x00000003u   // Input Pull Down Mode
#define  GPIO_MODE_OUTPUT_PP 					0x00000004u   // Output Push-Pull Mode
#define  GPIO_MODE_OUTPUT_OD  					0x00000005u   // Output Open-Drain Mode
#define  GPIO_MODE_OUTPUT_AF_PP                 0x00000006u   // Alternate Function Push-Pull Mode
#define  GPIO_MODE_OUTPUT_AF_OD					0x00000007u   // Alternate Function Open-Drain Mode
#define  GPIO_MODE_INPUT_AF						0x00000008u   // Alternate Function Input Mode



/*
 * @ref GPIO_speed_define
 * 00: Input mode (reset state)
 * 01: Output mode, max speed 10 MHz.
 * 10: Output mode, max speed 2 MHz.
 * 11: Output mode, max speed 50 MHz.
 */

#define GPIO_SPEED_10M 							0x00000001u  // Output mode, max speed 10 MHz
#define GPIO_SPEED_2M							0x00000002u  // Output mode, max speed 2 MHz
#define GPIO_SPEED_50M 							0x00000003u  // Output mode, max speed 50 MHz.

/*
 *
 *
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN_x);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN_x, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN_x);
void MCAL_GPIO_TogglePort(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WriteGroup(GPIO_TypeDef * GPIOx, uint16_t Vlaue, uint16_t mask);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN_x);

#endif /* STM32_F103C6_GPIO_H_ */
