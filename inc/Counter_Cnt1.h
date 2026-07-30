#ifndef COUNTER_Cnt1_H_
#define COUNTER_Cnt1_H_

#include <stdint.h>

void Counter_Cnt1_init(void);

void Counter_Cnt1_poll(void);

void Counter_Cnt1_setTimeBase(uint16_t ms, char mode);



void Counter_Cnt1_setEdge(uint8_t edge);



extern void Counter_Cnt1_onTimeBase(uint32_t count);

#endif /* COUNTER_Cnt1_H_ */

