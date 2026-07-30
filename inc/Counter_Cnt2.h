#ifndef COUNTER_Cnt2_H_
#define COUNTER_Cnt2_H_

#include <stdint.h>

void Counter_Cnt2_init(void);

void Counter_Cnt2_poll(void);

void Counter_Cnt2_setTimeBase(uint16_t ms, char mode);



void Counter_Cnt2_setEdge(uint8_t edge);



extern void Counter_Cnt2_onTimeBase(uint32_t count);

#endif /* COUNTER_Cnt2_H_ */

