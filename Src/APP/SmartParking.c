/*
 * Smart Parking.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ziad Gamalelden
 */
#include <stdio.h>

#include "HAL/KPAD.h"
#include "HAL/LCD.h"
#include "HAL/RFID.h"
#include "HAL/Alarm.h"
#include "HAL/PIR.h"
#include "HAL/Servo_Motor.h"

#include "MCAL/Stm32_F103C6_Timer.h"

static int8_t AuthenticIDs[3] = {-1, -1, -1};
static uint8_t FreeSlots = 3;

void SmartParking_init(void)
{
	// Admin enters authentic IDs
	LCD_sendstring(&LCD_admin, (const char *)"Enter allowed ID");

	char string[17];
	for(int i = 0; i < 3; i++)
	{
		LCD_gotoxy(&LCD_admin, 0, i + 1);

		sprintf(string, "Enter ID[%d]: ", i);
		LCD_sendstring(&LCD_admin, (const char *)string);

		do
		{
			AuthenticIDs[i] = KPAD_Get_Char();
		}
		while(AuthenticIDs[i] == 0);

		LCD_sendchar(&LCD_admin, (unsigned char)AuthenticIDs[i], DATA);
	}

	// Shows entered IDs
	LCD_clearscreen(&LCD_admin);
	LCD_gotoxy(&LCD_admin, 0,0);

	LCD_sendstring(&LCD_admin, (const char *)"Allowed IDs:");
	for(int i = 0; i < 3; i++)
	{
		LCD_gotoxy(&LCD_admin, 0, i + 1);

		sprintf(string, "ID[%d]: %c", i, AuthenticIDs[i]);
		LCD_sendstring(&LCD_admin, (const char *)string);
	}


}
void SmartParking_main(void)
{
	while(1)
	{
		if(RFID_entry_isavailable())
		{
			SmartParking_entry();
		}
		else if(RFID_exit_isavailable())
		{
			SmartParking_exit();

		}
	}
}

