#include "interrupt.h"
#include "gpio.h"

void INTERRUPT_Init(void)
{
    
    INTCON0bits.IPEN = 1;       // Habilitar prioridades en las interrupciones
    INTCON0bits.GIEH = 1;       // Habilitar las interrupciones de prioridad alta
    INTCON0bits.GIEL = 1;       // Habilitar las interrupciones de prioridad baja
    
    /*Configuración de la interrupcion TMR0*/
    
    PIR3bits.TMR0IF = 1;        // Limpiar la bandera 
    PIE3bits.TMR0IE = 1;        // Habilitar la interrupcion TMR0
    IPR3bits.TMR0IP = 1;        // Prioridad alta 
    
    /*Tabla de vectores en la direccion 0x003008 (por defecto seria 0x000008)*/
    
    di(); // Deshabilitamos las interrupciones
    IVTBASEU = 0x00;
    IVTBASEH = 0x30;
    IVTBASEL = 0x08;
    ei(); // Habilitamos las interrupciones
}

void __interrupt(irq(IRQ_TMR0), base(0x3008)) INT_ISR(void)
{    
    LED_INTERNAL_TOGGLE();
    TMR0H = 0xF3;             
    TMR0L = 0xE7;
    PIR3bits.TMR0IF = 0;
}