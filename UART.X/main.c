#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "gpio.h"
#include "uart.h"
#include "interrupt.h"

#pragma warning disable 520
#pragma warning disable 2020

void GPIO_Init(void);

int main(int argc, char** argv) {

    Clock_Init();
    GPIO_Init();
    UART1_Init(9600);
    INTERRUPT_Init();
    
    while(1)
    {
        for(uint8_t i = 0; i < 10; ++i)
        {
            printf("Hola Mundo %u \r\n", i);
            __delay_ms(200);
        }
        __delay_ms(1000);
    }
    
    return (EXIT_SUCCESS);
}

void GPIO_Init(void)
{
    /*Configuración del LED Interno*/
    configure_pin(PORT_F, 3, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    LED_INTERNAL_OFF();
    
    /*Configuración del LED Externo 1*/
    configure_pin(PORT_D, 0, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    LED_EXTERNAL_1_OFF();
    
    /*Configuración del Boton Externo 1*/
    configure_pin(PORT_B, 0, INPUT, DIGITAL, PULLUP, TTL, SR_LIMITED, PUSHPULL);
}