#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "gpio.h"

int main(int argc, char** argv) {
    
    Clock_Init();
    GPIO_Init();
    
    while(1)
    {
        LATFbits.LATF3 = 0; // Encender el LED interno
        LATDbits.LATD0 = 0; // Apagar el LED externo 1
        LATDbits.LATD1 = 1; // Apagar el LED externo 2 (alta impedancia)
        __delay_ms(2000);
        LATFbits.LATF3 = 1; // Apagar el LED interno
        LATDbits.LATD0 = 1; // Encender el LED externo 1
        LATDbits.LATD1 = 0; // Apagar el LED externo 2 (sinking current)
        __delay_ms(2000);
    }
    
    return (EXIT_SUCCESS);
}

