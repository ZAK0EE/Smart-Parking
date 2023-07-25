// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "MCAL/stm32f103x6.h"
#include "MCAL/Stm32_F103C6_EXTI.h"
#include "MCAL/Stm32_F103C6_GPIO.h"
#include "MCAL/Stm32_F103C6_USART.h"
#include "MCAL/Stm32_F103C6_Timer.h"
#include "HAL/LCD.h"
#include "HAL/Keypad.h"

void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	MCAL_Timer2_init();


	LCD_init(&LCD_admin);
	LCD_init(&LCD_entry);

	KPAD_init();




}

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
	//MCAL_Timer2_dms(5000);
	LCD_clearscreen(&LCD_admin);
	LCD_sendstring(&LCD_admin, (char*)"Welcome bro");
	LCD_gotoxy(&LCD_admin, 0, 1);
	LCD_sendstring(&LCD_admin, (char*)"Name: ");
	LCD_gotoxy(&LCD_admin, 0, 2);
	LCD_sendstring(&LCD_admin, (char*)"Age: ");
	LCD_gotoxy(&LCD_admin, 0, 3);
	LCD_sendstring(&LCD_admin, (char*)"Degree: ");

	MCAL_UART_SendData(USART1, &ch, enable);

}

void yfunc(void)
{
	MCAL_UART_ReceiveData(USART2, &ch2, disable);
	LCD_clearscreen(&LCD_entry);
	LCD_sendstring(&LCD_entry, (char*)"Welcome bro");
	LCD_gotoxy(&LCD_entry, 0, 1);
	LCD_sendstring(&LCD_entry, (char*)"Name: ");
	LCD_gotoxy(&LCD_entry, 0, 2);
	LCD_sendstring(&LCD_entry, (char*)"Age: ");
	LCD_gotoxy(&LCD_entry, 0, 3);
	LCD_sendstring(&LCD_entry, (char*)"Degree: ");

	MCAL_UART_SendData(USART2, (uint16_t*)&x, enable);

}
int main(void)
{

	clock_init();
	USART_Config_t uart_config;
	uart_config.BaudRate = UART_BaudRate_115200;
	uart_config.HwFlowCtl = UART_HwFlowCtl_NONE;
	uart_config.IRQ_Enable = UART_IRQ_Enable_NONE;
	uart_config.P_IRQ_CallBack = x;
	uart_config.Parity = UART_Parity_NONE;
	uart_config.Payload_Length = UART_Payload_Length_8B;
	uart_config.StopBits = UART_StopBits_1;
	uart_config.USART_Mode = UART_Mode_TX_RX;
	MCAL_UART_Init(USART1, &uart_config);
	MCAL_UART_GPIO_Set_Pins(USART1);


	USART_Config_t uart2CFG;

	uart2CFG.BaudRate = UART_BaudRate_115200;
	uart2CFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	uart2CFG.IRQ_Enable = UART_IRQ_Enable_NONE;
	uart2CFG.P_IRQ_CallBack = yfunc;
	uart2CFG.Parity = UART_Parity_NONE;
	uart2CFG.Payload_Length = UART_Payload_Length_8B;
	uart2CFG.StopBits = UART_StopBits_1;
	uart2CFG.USART_Mode = UART_Mode_TX_RX;
	MCAL_UART_Init(USART2, &uart2CFG);
	MCAL_UART_GPIO_Set_Pins(USART2);


	char x = 0;
	while(1)
	{
		do
		{
			x = KPAD_Get_Char();
		}
		while(x == 0);

		LCD_sendchar(&LCD_admin, x, DATA);

		//MCAL_UART_SendData(USART2, (uint16_t*)&x, enable);

	}

}
