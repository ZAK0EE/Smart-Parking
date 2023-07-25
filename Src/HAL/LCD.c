/*
 * lcd.c
 *
 * Created: 22/07/31 10:02:04 AM
 *  Author: Ziad Gamalelden
 */
#include "HAL/LCD.h"
#include <string.h>


#ifdef LCD_4BIT_MODE
#define LCD_DATASHIFT 4
#else
#define LCD_DATASHIFT 0
#endif

static void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}

void LCD_KICK()
{
	//LCDCR_PORT |= (1 << LCD_EN); // Set EN pin
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_EN, GPIO_PIN_SET);
	// _delay_us(1);
	delay(1);
	//LCDCR_PORT &= ~(1 << LCD_EN); // Reset EN pin
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_EN, GPIO_PIN_RESET);


}

void LCD_Clear_Screen(void)
{
	LCD_Write_Comand(LCD_CLEAR_SCREEN);

}
void LCD_Is_Busy(void)
{

	//LCD_DDR &= ~(0xFF << LCD_DATASHIFT);
	LCD_PORT->CRL = (uint32_t)(0x88888888 << LCD_DATASHIFT);



	//LCDCR_PORT |= (1 << LCD_RW); // RW pin is read
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_SET);
	//LCDCR_PORT &= ~(1 << LCD_RS); // RS pin is write
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_RESET);

	LCD_KICK();

	//LCD_DDR = 0xFF;
	LCD_PORT->CRL = 0x88888888; // LCD D[0:7] as input
	// LCDCR_PORT &= ~(1 << LCD_RW);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);

}

void LCD_GotoXY(int line, int pos)
{

	if(line == 0)
	{
		if(pos > 15 || pos < 0)
			return;
		LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW + pos);
	}
	else if(line == 1)
	{
		if(pos > 15 || pos < 0)
			return;
		LCD_Write_Comand(LCD_BEGIN_AT_SECOND_RAW + pos);
	}
}

void LCD_Init(void)
{
	//_delay_ms(20);
	delay(1);
	LCD_Is_Busy();

	//LCDCR_DDR |= (1 << LCD_EN) | (1 << LCD_RW) | (1 << LCD_RS);
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber = LCD_EN;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCDCR_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_RW;
	MCAL_GPIO_Init(LCDCR_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_RS;
	MCAL_GPIO_Init(LCDCR_PORT, &PinConfig);


	// LCDCR_PORT &= ~((1 << LCD_EN) | (1 << LCD_RW) | (1 << LCD_RS));
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_EN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_RESET);
	// 	LCD_DDR = 0xFF;
	LCD_PORT->CRL = 0x88888888;
	LCD_Clear_Screen();

	//_delay_ms(15);
	delay(2);

#ifdef LCD_8BIT_MODE
	LCD_Write_Comand(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef LCD_4BIT_MODE
	LCD_Write_Comand(LCD_EN_4BIT);
	LCD_Write_Comand(LCD_FUNCTION_4BIT_2LINES);

#endif

	LCD_Write_Comand(LCD_ENTRY_MODE);
	LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Write_Comand(LCD_DISP_ON_CURSOR_BLINK);

}



void LCD_Write_Comand(unsigned char command)
{
	LCD_Is_Busy();

#ifdef LCD_8BIT_MODE
	//LCD_PORT = command;
	MCAL_GPIO_WritePort(LCD_PORT, command);

	//	LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_RESET);
	LCD_KICK();
#endif
#ifdef LCD_4BIT_MODE
	//LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0); 0xFFFFFFFF
	uint32_t LCDValue = MCAL_GPIO_ReadPort(LCD_PORT);
	LCDValue = (LCDValue & 0xFFFFFF0F) | (command & 0xFFFFFFF0);
	MCAL_GPIO_WritePort(LCD_PORT, LCDValue);

	//LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_RESET);

	LCD_KICK();
	//_delay_us(200);
	delay(1);

	//LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCDValue = MCAL_GPIO_ReadPort(LCD_PORT);
	LCDValue = (LCDValue & 0xFFFFFF0F) | (command << 4);
	MCAL_GPIO_WritePort(LCD_PORT, LCDValue);

	//LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_RESET);

	LCD_KICK();
	//_delay_ms(2);
	delay(2);


#endif
}



void LCD_Write_Char(unsigned char data)
{


#ifdef LCD_8BIT_MODE
	LCD_Is_Busy();
	//LCD_PORT = data;
	MCAL_GPIO_WritePort(LCD_PORT, data);
	//LCDCR_PORT &= ~(1 << LCD_RW);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);
	//LCDCR_PORT |= (1 << LCD_RS);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_SET);

	LCD_KICK();
#endif
#ifdef LCD_4BIT_MODE
	//LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	uint32_t LCDValue = MCAL_GPIO_ReadPort(LCD_PORT);
	LCDValue = (LCDValue & 0xFFFFFF0F) | (data & 0xFFFFFFF0);
	MCAL_GPIO_WritePort(LCD_PORT, LCDValue);

	//LCDCR_PORT &= ~(1 << LCD_RW);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);

	//LCDCR_PORT |= (1 << LCD_RS);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_SET);

	LCD_KICK();

	//LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCDValue = MCAL_GPIO_ReadPort(LCD_PORT);
	LCDValue = (LCDValue & 0xFFFFFF0F) | (data << 4);
	MCAL_GPIO_WritePort(LCD_PORT, LCDValue);

	//LCDCR_PORT &= ~(1 << LCD_RW);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RW, GPIO_PIN_RESET);

	//LCDCR_PORT |= (1 << LCD_RS);
	MCAL_GPIO_WritePin(LCDCR_PORT, LCD_RS, GPIO_PIN_SET);
	LCD_KICK();
	//_delay_us(100);
	delay(1);


#endif
}

void LCD_Write_CustomChar()
{
	LCD_Write_Comand(64);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);

	LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Write_Char(0);

}


void LCD_Write_String(char* data)
{
	int count = 0;
	while(*data != 0)
	{
		if(count == 16)
		{
			LCD_GotoXY(1, 0);
		}
		else if (count == 32)
		{
			LCD_Clear_Screen();
			count = 0;
			LCD_GotoXY(0, 0);
		}

		LCD_Write_Char(*data);
		count++;
		data++;


	}
}


