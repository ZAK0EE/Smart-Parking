/*
 * PIR.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Ziad Gamalelden
 */

#ifndef HAL_PIR_H_
#define HAL_PIR_H_

typedef enum
{
	PIR_NOT_DETECTED,
	PIR_DETECTED
}e_PIRStatus_t;

#define PIR_GPIOx		GPIOA
#define PIR_ENTRY_PIN	GPIO_PIN_7
#define PIR_EXIT_PIN	GPIO_PIN_1


void PIR_init(void);

e_PIRStatus_t PIR_entry(void);

e_PIRStatus_t PIR_exit(void);




#endif /* HAL_PIR_H_ */
