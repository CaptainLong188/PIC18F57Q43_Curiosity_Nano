#include "display7.h"

void Write_Display7seg(display7seg_t* d7s, uint8_t val)
{
    uint8_t data;
    
    if((d7s -> mode) == COMMON_CATHODE)
    {
        data = display7seg_c[val];
    }
    
    Reset_Display7Seg();
    
    if(data & 1 << 0) {LATA |= 1 << (d7s -> a);}
    if(data & 1 << 1) {LATA |= 1 << (d7s -> b);}
    if(data & 1 << 2) {LATE |= 1 << (d7s -> c);}
    if(data & 1 << 3) {LATC |= 1 << (d7s -> d);}
    if(data & 1 << 4) {LATD |= 1 << (d7s -> e);}
    if(data & 1 << 5) {LATD |= 1 << (d7s -> f);}
    if(data & 1 << 6) {LATD |= 1 << (d7s -> g);}

}

void Reset_Display7Seg(void)
{
    LATAbits.LATA3 = 0;
    LATAbits.LATA4 = 0;
    LATEbits.LATE2 = 0;
    LATCbits.LATC7 = 0;
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
} 