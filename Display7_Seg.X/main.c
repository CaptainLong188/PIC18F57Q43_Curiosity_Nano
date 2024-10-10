#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "config.h"
#include "gpio.h"
#include "display7.h"

display7seg_t display1 = {3,4,2,7,0,1,2, COMMON_CATHODE};

int main(int argc, char** argv) {
    
    Clock_Init();
    GPIO_Init();
    Reset_Display7Seg();
    
    while(1)
    {
        for(uint8_t i = 0; i < 10; ++i)
        {
            Write_Display7seg(&display1, i);
            __delay_ms(1000);
        }
    }
    
    return (EXIT_SUCCESS);
}