#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "gpio.h"
#include "timers.h"
#include "interrupt.h"

#pragma warning disable 520
#pragma warning disable 2020

void GPIO_Init(void);

int main(int argc, char** argv) {

    Clock_Init();
    GPIO_Init();
    TIMER0_Init(FOSC_4, TIMER_16BIT_MODE, SYNCRONIZED, CKPS_1_2048);
    TIMER0_Write(0xC2, 0xF6); // Timer de 2 seg
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