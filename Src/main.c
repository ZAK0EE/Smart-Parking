// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma
#include "MCAL/stm32f103x6.h"
#include "MCAL/Stm32_F103C6_GPIO.h"
#include "MCAL/Stm32_F103C6_USART.h"
#include "MCAL/Stm32_F103C6_Timer.h"
#include "HAL/LCD.h"
#include "HAL/KPAD.h"
#include "HAL/Servo_Motor.h"
#include "HAL/PIR.h"
#include "HAL/Alarm.h"
#include "HAL/RFID.h"

#include "MCAL/MCAL.h"
#include "HAL/HAL.h"



void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}


uint16_t ch = '5';
uint16_t ch2 = '6';
void x(void)
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	if(ch == '1')
	{
		Servo1_Entry_Gate(SERVO_UP);
		Alarm_correctID_blink();
	}
	else if(ch == '0')
	{
		if(PIR_exit() == PIR_NOT_DETECTED)
		{
			Servo1_Entry_Gate(SERVO_DOWN);
			Alarm_correctID_blink();
			Alarm_correctID_off();

		}
	}
	else
	{
		Alarm_wrongID_blink();
		Alarm_wrongID_off();

	}

	MCAL_UART_SendData(USART1, &ch, enable);

}

void yfunc(void)
{
	MCAL_UART_ReceiveData(USART2, &ch2, disable);
	LCD_clearscreen(&LCD_user);
	LCD_sendstring(&LCD_user, (char*)"Welcome bro");
	LCD_gotoxy(&LCD_user, 0, 1);
	LCD_sendstring(&LCD_user, (char*)"Name: ");
	LCD_gotoxy(&LCD_user, 0, 2);
	LCD_sendstring(&LCD_user, (char*)"Age: ");
	LCD_gotoxy(&LCD_user, 0, 3);
	LCD_sendstring(&LCD_user, (char*)"Degree: ");

	MCAL_UART_SendData(USART2, (uint16_t*)&x, enable);

}
int main(void)
{
	MCAL_init();
	HAL_init();





	while(1)
	{

		uint16_t x = RFID_exit_Read();
		LCD_sendchar(&LCD_user, (unsigned char)x, DATA);
	}

}
