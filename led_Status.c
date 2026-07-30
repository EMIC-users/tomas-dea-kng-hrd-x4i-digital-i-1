#include <xc.h>
#include "inc/led_Status.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_Status_init (void)
{
	HAL_GPIO_PinCfg(Led1, GPIO_OUTPUT);
}




