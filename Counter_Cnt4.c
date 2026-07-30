#include <xc.h>
#include <stdint.h>
#include "inc/Counter_Cnt4.h"
#include "inc/gpio.h"            /* HAL_GPIO_* + pins.h (RPIN_/CN_ of DigIn4) */
#include "inc/systemTimer.h"     /* getSystemMilis()                          */
#include "inc/INP_CHAN_NOTI.h"   /* shared CN edge-counter driver             */

/*==================[internal data]==========================================*/
static uint8_t  cnt_ch      = ICN_INVALID_CH;  /* channel index in CN driver  */
static uint16_t cnt_window  = 0;               /* window length (ms); 0 = off */
static uint32_t cnt_tStamp  = 0;               /* window start timestamp      */
static char     cnt_mode    = 'A';             /* 'A'=continuous 'T'=one-shot */
static uint8_t  cnt_running = 0;               /* window active flag          */

/*==================[public functions]=======================================*/
void Counter_Cnt4_init(void)
{
	HAL_GPIO_PinCfg(DigIn4, GPIO_INPUT);
	cnt_ch = ICN_addChannel(CN_DigIn4, (uint16_t)(0x0001u << RPIN_DigIn4), ICN_EDGE_RISING);
}







void Counter_Cnt4_poll(void)
{
	if (cnt_running && cnt_window > 0)
	{
		if ((getSystemMilis() - cnt_tStamp) >= (uint32_t)cnt_window)
		{
			if (cnt_mode == 'T')
				cnt_running = 0;          /* single-shot: stop after one window */
			else
				cnt_tStamp = getSystemMilis();  /* continuous: re-arm */

			ICN_clear(cnt_ch);
		}
	}
}

/*==================[end of file]============================================*/

