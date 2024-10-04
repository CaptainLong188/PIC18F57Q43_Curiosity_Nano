#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "config.h"
#include "gpio.h"
#include "interrupt.h"

volatile uint8_t flag_INT0 = 0;
volatile uint8_t flag_INT1 = 0;
volatile uint8_t flag_IOCC2 = 0;
bool start = true; // para que el led externo 2 pueda empezar apagado

int main(int argc, char** argv) {
    
    Clock_Init();
    GPIO_Init();
    INTERRUPT_Init();
    start = false; 
    
    while(1)
    {
        if(flag_INT0)
        {
            LED_EXTERNAL_1_TOGGLE();
            flag_INT0 = 0;
        }
        
        if(flag_INT1)
        {
            LED_EXTERNAL_2_TOGGLE();
            flag_INT1 = 0;
        }
        
        // Por el momento con delays (No recomendado)
        if(flag_IOCC2)
        {
            __delay_ms(100);
            LED_INTERNAL_TOGGLE();
        }
        else
        {
            __delay_ms(1000);
            LED_INTERNAL_TOGGLE();
        }
    }
    
    return (EXIT_SUCCESS);
}