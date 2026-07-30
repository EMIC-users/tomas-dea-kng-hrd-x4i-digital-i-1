#include "inc/INP_CHAN_NOTI.h"

/*==================[internal data declaration]==============================*/
static volatile uint32_t icn_count[ICN_MAX_CH];  /* edge count per channel   */
static uint16_t          icn_mask[ICN_MAX_CH];    /* PORTB bit mask per ch    */
static uint8_t           icn_edge[ICN_MAX_CH];    /* counted edge per ch      */
static volatile uint8_t  icn_last[ICN_MAX_CH];    /* last sampled pin level   */
static uint8_t           icn_nch = 0;             /* channels registered      */

/*==================[public functions]=======================================*/
uint8_t ICN_addChannel(uint8_t cnNum, uint16_t portBmask, uint8_t edge)
{
	uint8_t ch;

	if (icn_nch >= ICN_MAX_CH)
		return ICN_INVALID_CH;

	IEC1bits.CNIE = 0;

	ch = icn_nch;
	icn_mask[ch]  = portBmask;
	icn_edge[ch]  = edge;
	icn_count[ch] = 0;
	icn_last[ch]  = (PORTB & portBmask) ? 1 : 0;

	/* Enable Change Notification on this pin: CN0..CN15 -> CNEN1, CN16.. -> CNEN2. */
	if (cnNum <= 15)
		CNEN1 |= (uint16_t)(0x0001u << cnNum);
	else
		CNEN2 |= (uint16_t)(0x0001u << (cnNum - 16));

	icn_nch = ch + 1;

	/* (Re)arm the shared CN interrupt — idempotent across registrations. */
	IFS1bits.CNIF = 0;
	IEC1bits.CNIE = 1;

	return ch;
}

void ICN_setEdge(uint8_t ch, uint8_t edge)
{
	if (ch < ICN_MAX_CH)
		icn_edge[ch] = edge;
}

uint32_t ICN_get(uint8_t ch)
{
	uint32_t v;

	if (ch >= ICN_MAX_CH)
		return 0;

	/* Critical section: a 32-bit read is not atomic on the 16-bit PIC24. */
	IEC1bits.CNIE = 0;
	v = icn_count[ch];
	IEC1bits.CNIE = 1;
	return v;
}

uint32_t ICN_getAndClear(uint8_t ch)
{
	uint32_t v;

	if (ch >= ICN_MAX_CH)
		return 0;

	/* Read + clear in a single critical section: no edge is lost in between. */
	IEC1bits.CNIE = 0;
	v = icn_count[ch];
	icn_count[ch] = 0;
	IEC1bits.CNIE = 1;
	return v;
}

void ICN_clear(uint8_t ch)
{
	if (ch >= ICN_MAX_CH)
		return;

	IEC1bits.CNIE = 0;
	icn_count[ch] = 0;
	IEC1bits.CNIE = 1;
}

/*==================[interrupt service routine]==============================*/
void __attribute__((interrupt(auto_psv))) _CNInterrupt(void)
{
	uint16_t portb = PORTB;
	uint8_t  i;

	for (i = 0; i < icn_nch; i++)
	{
		uint8_t now = (portb & icn_mask[i]) ? 1 : 0;

		if (now != icn_last[i])
		{
			if ( icn_edge[i] == ICN_EDGE_BOTH ||
			    (icn_edge[i] == ICN_EDGE_RISING  && now == 1) ||
			    (icn_edge[i] == ICN_EDGE_FALLING && now == 0) )
			{
				icn_count[i]++;
			}
			icn_last[i] = now;
		}
	}

	IFS1bits.CNIF = 0;
}

/*==================[end of file]============================================*/

