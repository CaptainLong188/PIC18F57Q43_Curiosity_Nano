#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "gpio.h"
#include "timers.h"
#include "interrupt.h"

void GPIO_Init(void);

int main(int argc, char** argv) {

    Clock_Init();
    GPIO_Init();
    TIMER0_Init();
    INTERRUPT_Init();
    
    while(1)
    {
        
    }
    
    return (EXIT_SUCCESS);
}

void GPIO_Init(void)
{
    /*Configuración del LED Externo*/
    configure_pin(PORT_F, 3, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
}