#ifndef COUNTER_Cnt3_H_
#define COUNTER_Cnt3_H_

#include <stdint.h>

void Counter_Cnt3_init(void);

void Counter_Cnt3_poll(void);

void Counter_Cnt3_setTimeBase(uint16_t ms, char mode);



void Counter_Cnt3_setEdge(uint8_t edge);



extern void Counter_Cnt3_onTimeBase(uint32_t count);

#endif /* COUNTER_Cnt3_H_ */

