#ifndef DISPLAY7_H
#define	DISPLAY7_H

#include <xc.h>
#include <stdint.h>

#define COMMON_CATHODE  0
#define COMMON_ANODE    1

const uint8_t display7seg_c[] = {0x3F, 0X06 ,0X5B ,0x4f,0X66 ,0X6D, 0X7D, 0X07 ,0X7F, 0X67};

typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t g;
    uint8_t mode;
} display7seg_t;

void Write_Display7seg(display7seg_t* d7s, uint8_t val);
void Reset_Display7Seg(void);

#endif	/* DISPLAY7_H */

