#ifndef DIGITAL_INPUT_H_
#define DIGITAL_INPUT_H_

#include <stdint.h>

void init_digIn (void);

uint8_t ReadDigiIn1(void);

uint8_t ReadDigiIn2(void);

uint8_t ReadDigiIn3(void);

uint8_t ReadDigiIn4(void);

void digInPoll(void);

#endif

