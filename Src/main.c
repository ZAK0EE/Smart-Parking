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
