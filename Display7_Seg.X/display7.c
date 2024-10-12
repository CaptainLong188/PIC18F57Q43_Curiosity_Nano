#include "display7.h"

void Display7Seg_Init(display7seg_t* d7s)
{
    // Configuramos los 7 pines del display de 7 segmentos como salidas 
    
    for(uint8_t i = 0; i < 7; ++i)
    {
        configure_pin((d7s -> display_pins[i]).port, (d7s -> display_pins[i]).pin, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    }
    
    Reset_Display7Seg(d7s);
}

void Write_Display7seg(display7seg_t* d7s, uint8_t val)
{
    
    if(val > 9) return;
    
    uint8_t data;
    
    if((d7s -> mode) == COMMON_CATHODE)
    {
        data = display7Seg_c[val];
    }
    else if((d7s -> mode) == COMMON_ANODE)
    {
        data = display7Seg_a[val];
    }
    else
    {
        return;
    }
    
    Reset_Display7Seg(d7s);
    
    for(uint8_t i = 0; i < 7; ++i)
    {
        if(data & (1 << i)) // Recorre desde a hasta g
        {
            set_pin_high((d7s -> display_pins[i]).port, (d7s -> display_pins[i]).pin);
        }
    }  

}

void Reset_Display7Seg(display7seg_t* d7s)
{
    for(uint8_t i = 0; i < 7; ++i)
    {
        set_pin_low((d7s -> display_pins[i]).port, (d7s -> display_pins[i]).pin);
    }
    
} 