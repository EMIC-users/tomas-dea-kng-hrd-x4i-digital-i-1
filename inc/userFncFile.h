#ifndef USERFNCFILE_H
#define USERFNCFILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// includes type definitions
#include "streamOut.h"
#include "streamIn.h"

/* Function Prototypes */
void onReset();
void Counter_Cnt1_onTimeBase(uint32_t count);
void Counter_Cnt2_onTimeBase(uint32_t count);
void Counter_Cnt3_onTimeBase(uint32_t count);

#endif /* USERFNCFILE_H */

