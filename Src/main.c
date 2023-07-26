// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "APP/SmartParking.h"

int main(void)
{
	MCAL_init();
	HAL_init();
	SmartParking_init();
	SmartParking_main();
}
