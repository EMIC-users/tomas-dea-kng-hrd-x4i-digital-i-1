#include <xc.h>
#include "inc/systemConfig.h"

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
#include "inc/system.h"
#include "inc/userFncFile.h"

#include "system.c"

int main(void)
{
	initSystem();
	systemTimeInit();
	LEDs_Status_init();
	LEDs_Led2_init();
	LEDs_Led3_init();
	LEDs_Led4_init();
	LEDs_Led5_init();
	init_digIn();
	Counter_Cnt1_init();
	Counter_Cnt2_init();
	Counter_Cnt3_init();
	Counter_Cnt4_init();
	EMICBus_init();
	do
	{
		digInPoll();
		Counter_Cnt1_poll();
		Counter_Cnt2_poll();
		Counter_Cnt3_poll();
		Counter_Cnt4_poll();
		poll_EMICBus();
	}
	while(1);
}

