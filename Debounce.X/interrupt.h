#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h>
#include <stdint.h>

volatile uint8_t button_flag = 0;
volatile uint8_t x = 0;
volatile uint8_t button_press_counter = 0;

void INTERRUPT_Init(void);

#endif	/* INTERRUPT_H */

