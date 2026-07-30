#include <xc.h>
#include "inc/led_Led3.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_Led3_init (void)
{
	HAL_GPIO_PinCfg(Led3, GPIO_OUTPUT);
}




