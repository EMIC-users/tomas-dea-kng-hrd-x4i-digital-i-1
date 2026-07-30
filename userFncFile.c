#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Status.h"
#include "inc/led_Led2.h"
#include "inc/led_Led3.h"
#include "inc/led_Led4.h"
#include "inc/led_Led5.h"
#include "inc/timer_api1.h"
#include "inc/Digital.h"
#include "inc/Counter_Cnt1.h"
#include "inc/Counter_Cnt2.h"
#include "inc/Counter_Cnt3.h"
#include "inc/Counter_Cnt4.h"
#include "inc/conversionFunctions.h"
#include "inc/EMICBus.h"

/* User Variables */
uint16_t rpmAib = 0;
uint16_t rpmToma = 0;
uint16_t rpmMotor = 0;

void onReset()
{
    LEDs_Led2_blink(100, 400, 4);
    Counter_Cnt1_setEdge(1);
    Counter_Cnt1_setTimeBase(2000, 'A');
    Counter_Cnt2_setEdge(1);
    Counter_Cnt2_setTimeBase(2000, 'A');
    Counter_Cnt3_setEdge(1);
    Counter_Cnt3_setTimeBase(2000, 'A');
    LEDs_Status_state(1);
}


void Counter_Cnt1_onTimeBase(uint32_t count)
{
    LEDs_Led2_blink(60, 240, 1);
    rpmMotor = (uint16_t)(30 * count);
    pI2C("RPMMOTOR\t%u", rpmMotor);
}


void Counter_Cnt2_onTimeBase(uint32_t count)
{
    LEDs_Led3_blink(60, 240, 1);
    rpmToma = (uint16_t)(30 * count);
    pI2C("RPMTOMA\t%u", rpmToma);
}


void Counter_Cnt3_onTimeBase(uint32_t count)
{
    LEDs_Led4_blink(60, 240, 1);
    rpmAib = (uint16_t)(30 * count);
    pI2C("RPMAIB\t%u", rpmAib);
}



