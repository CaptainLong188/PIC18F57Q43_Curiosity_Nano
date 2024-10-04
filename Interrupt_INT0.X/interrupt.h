#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

extern volatile uint8_t flag_INT0;
extern volatile uint8_t flag_INT1;
extern volatile uint8_t flag_IOCC2;
extern bool start;


void INTERRUPT_Init(void);

#endif	/* INTERRUPT_H */

