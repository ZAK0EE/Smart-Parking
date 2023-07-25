/*
 * Servo_Motor.h
 *
 *  Created on: Nov 12, 2021
 *  Author:  Mostafa Mahmoud Elshiekh
 */


#ifndef HAL_SERVO_MOTOR_H_
#define HAL_SERVO_MOTOR_H_


#include "MCAL/stm32f103x6.h"
#include "MCAL/Stm32_F103C6_GPIO.h"
#include "MCAL/Stm32_F103C6_Timer.h"

typedef enum {
	SERVO_UP = 1,
	SERVO_DOWN = 2,
}e_ServoMotor_Direction_t;


void Servo1_Entry_Gate_Init(void);
void Servo1_Entry_Gate(e_ServoMotor_Direction_t Direction);

void Servo2_Exit_Gate_Init(void);
void Servo2_Exit_Gate(e_ServoMotor_Direction_t Direction);



#endif /* HAL_SERVO_MOTOR_H_ */
