#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h>
#include <stdint.h>

volatile uint8_t button_flag[2] = {};
volatile uint8_t x[2] = {};
volatile uint8_t button_press_counter[2] = {};

void INTERRUPT_Init(void);

#endif	/* INTERRUPT_H */

