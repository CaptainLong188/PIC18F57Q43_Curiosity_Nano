#ifndef DISPLAY7_H
#define	DISPLAY7_H

#include "gpio.h"
#include <xc.h>
#include <stdint.h>

#define COMMON_CATHODE  0
#define COMMON_ANODE    1

// 0x3F -> 0011 1111 -> xgfe dcba
const uint8_t display7Seg_c[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
const uint8_t display7Seg_a[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x90};

typedef struct
{
    pin_t display_pins[7];  // Arreglo para los 7 pines del display
    uint8_t mode;           // Catodo o anodo comun
} display7seg_t;

void Display7Seg_Init(display7seg_t* d7s);
void Write_Display7seg(display7seg_t* d7s, uint8_t val);
void Reset_Display7Seg(display7seg_t* d7s);

#endif	/* DISPLAY7_H */

