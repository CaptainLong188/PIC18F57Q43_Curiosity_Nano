#include "interrupt.h"
#include "gpio.h"
#include "uart.h"

void INTERRUPT_Init(void)
{
    
    INTCON0bits.IPEN = 1;       // Habilitar prioridades en las interrupciones
    INTCON0bits.GIEH = 1;       // Habilitar las interrupciones de prioridad alta
    INTCON0bits.GIEL = 1;       // Habilitar las interrupciones de prioridad baja
    
    /*Configuración de la interrupcion de recepción UART1*/
    
    PIR4bits.U1RXIF = 1;        // Limpiar la bandera 
    PIE4bits.U1RXIE = 1;        // Habilitar la interrupcion TMR0
    IPR4bits.U1RXIP = 1;        // Prioridad alta
    
    /*Tabla de vectores en la direccion 0x003008 (por defecto seria 0x000008)*/
    
    di(); // Deshabilitamos las interrupciones
    IVTBASEU = 0x00;
    IVTBASEH = 0x30;
    IVTBASEL = 0x08;
    ei(); // Habilitamos las interrupciones
}

void __interrupt(irq(IRQ_U1RX), base(0x3008)) INT_ISR(void)
{    
    if(PIR4bits.U1RXIF == 1)
    {
        char dataRx = UART1_Read_Char();
        
        switch (dataRx)
        {
            case 'a':
                LED_INTERNAL_ON();
                break;
            case 'b':
                LED_INTERNAL_OFF();
                break;
            default:
                break;
        }
        
        PIR4bits.U1RXIF = 0;
    }
}