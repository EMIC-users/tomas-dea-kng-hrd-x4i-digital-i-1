#include <xc.h>
#include "inc/led_Led4.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_Led4_init (void)
{
	HAL_GPIO_PinCfg(Led4, GPIO_OUTPUT);
}




