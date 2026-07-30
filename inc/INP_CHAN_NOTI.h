
#ifndef PIC_INP_CHAN_NOTI_H_
#define PIC_INP_CHAN_NOTI_H_

/*==================[inclusions]=============================================*/
#include <xc.h>
#include <stdint.h>

/*==================[macros]=================================================*/
#define ICN_MAX_CH        4        /* channels supported (4 digital inputs)  */

/* edge selector for ICN_addChannel/ICN_setEdge */
#define ICN_EDGE_FALLING  0
#define ICN_EDGE_RISING   1        /* default */
#define ICN_EDGE_BOTH     2

#define ICN_INVALID_CH    0xFF     /* returned by ICN_addChannel when full   */

/*==================[external functions declaration]=========================*/

uint8_t ICN_addChannel(uint8_t cnNum, uint16_t portBmask, uint8_t edge);

/* Changes the counted edge of an already-registered channel. */
void ICN_setEdge(uint8_t ch, uint8_t edge);

/* Atomically reads the accumulated edge count of a channel. */
uint32_t ICN_get(uint8_t ch);

uint32_t ICN_getAndClear(uint8_t ch);

/* Atomically clears a channel's counter. */
void ICN_clear(uint8_t ch);

/*==================[end of file]============================================*/
#endif /* PIC_INP_CHAN_NOTI_H_ */

