/*
 * keypad.c
 *
 * Created: 22/07/31 05:29:15 PM
 *  Author: Ziad Gamalelden
 */

#include "keypad.h"

uint16_t Col[4] = {KPAD_C0, KPAD_C1, KPAD_C2, KPAD_C3};
uint16_t Row[4] = {KPAD_R0, KPAD_R1, KPAD_R2, KPAD_R3};

char KPAD_Chars[4][4] = {
							{'7', '8', '9', '/'},
							{'4', '5', '6', '*'},
							{'1', '2', '3', '-'},
							{'c', '0', '=', '+'}
						};



void KPAD_Init()
{

	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PD;
	for(int Ri = 0; Ri < 4; Ri++)
	{
		PinConfig.GPIO_PinNumber = Row[Ri];
		MCAL_GPIO_Init(KPAD_PORT, &PinConfig);

	}

	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;

	for(int Ci = 0; Ci < 4; Ci++)
	{
		PinConfig.GPIO_PinNumber = Col[Ci];
		MCAL_GPIO_Init(KPAD_PORT, &PinConfig);
	}


	for(int Ci = 0; Ci < 4; Ci++)
		MCAL_GPIO_WritePin(KPAD_PORT, Col[Ci], GPIO_PIN_SET);
	for(int Ri = 0; Ri < 4; Ri++)
		MCAL_GPIO_WritePin(KPAD_PORT, Row[Ri], GPIO_PIN_SET);
}

char KPAD_Get_Char()
{
	int Ri, Ci;
	for(Ci = 0; Ci < 4; Ci++)
	{
		// All columns HIGH
		MCAL_GPIO_WritePin(KPAD_PORT, KPAD_C0, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KPAD_PORT, KPAD_C1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KPAD_PORT, KPAD_C2, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KPAD_PORT, KPAD_C3, GPIO_PIN_SET);

		// Ground once column
		MCAL_GPIO_WritePin(KPAD_PORT, Col[Ci], GPIO_PIN_RESET);
		for(Ri = 0; Ri < 4; Ri++)
		{
			if(!MCAL_GPIO_ReadPin(KPAD_PORT, Row[Ri]))
			{
				// Key is still pressed
				while(!(MCAL_GPIO_ReadPin(KPAD_PORT, Row[Ri])));
				return KPAD_Chars[Ri][Ci];

			}
		}
	}

	return 0;

}
