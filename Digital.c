#include "inc/Digital.h"
#include "inc/gpio.h"
#include "inc/userFncFile.h"

void init_digIn (void)
{
	HAL_GPIO_PinCfg(DigIn1,GPIO_INPUT);
	HAL_GPIO_PinCfg(DigIn2,GPIO_INPUT);
	HAL_GPIO_PinCfg(DigIn3,GPIO_INPUT);
	HAL_GPIO_PinCfg(DigIn4,GPIO_INPUT);
}

uint8_t ReadDigiIn1(void)
{
	return HAL_GPIO_PinGet(DigIn1);
}

uint8_t ReadDigiIn2(void)
{
	return HAL_GPIO_PinGet(DigIn2);
}

uint8_t ReadDigiIn3(void)
{
	return HAL_GPIO_PinGet(DigIn3);
}

uint8_t ReadDigiIn4(void)
{
	return HAL_GPIO_PinGet(DigIn4);
}

void digInPoll(void)
{



}

