/*
 * HAL_LCD.h
 *
 * Created: 22/07/31 10:01:55 AM
 *  Author: Ziad Gamalelden
 */

#ifndef LCD_H_
#define LCD_H_


#include <stdint.h>

#include "MCAL/Stm32_F103C6_GPIO.h"

#define LCD_PORT GPIOA
//#define LCD_DDR DDRA

#define LCDCR_PORT GPIOB
//#define LCDCR_DDR DDRB

#define LCD_RS GPIO_PIN_10
#define LCD_RW GPIO_PIN_1
#define LCD_EN GPIO_PIN_0

//#define LCD_8BIT_MODE
#define LCD_4BIT_MODE

#define LCD_REGISTER_SELECT_PIN						(0)
#define LCD_READ_WRITE_PIN							(1)
#define LCD_ENABLE_PIN								(2)
#define LCD_REGISTER_SELECT_ENABLE					(1)
#define LCD_REGISTER_SELECT_DISABLE					(0)
#define READ_FROM_LCD								(1)
#define WRITE_TO_LCD								(0)
#define LCD_ENABLE									(1)
#define LCD_DISABLE									(0)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_EN_4BIT									(0x02)


void LCD_Init(void);
void LCD_Write_Comand(unsigned char command);
void LCD_Write_Char(unsigned char data);
void LCD_Write_String(char* data);
void LCD_Write_CustomChar(void);
void LCD_Is_Busy(void);
void LCD_Clear_Screen(void);

#endif /* LCD_H_ */
