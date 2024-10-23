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
    IPR3bits.TMR0IP = 0;        // Prioridad baja 
    
    /*Configuración de la interrupción externa INT0*/
    INTCON0bits.INT0EDG = 0;    // Interrupcion en el flanco de bajada    
    PIR1bits.INT0IF = 0;        // Limpiar la bandera 
    PIE1bits.INT0IE = 1;        // Habilitar la interrupcion externa INT0
    IPR1bits.INT0IP = 1;        // Prioridad alta 
    
    /*Tabla de vectores en la direccion 0x003008 (por defecto seria 0x000008)*/
    
    di(); // Deshabilitamos las interrupciones
    IVTBASEU = 0x00;
    IVTBASEH = 0x30;
    IVTBASEL = 0x08;
    ei(); // Habilitamos las interrupciones
}

void __interrupt(irq(IRQ_TMR0, IRQ_INT0), base(0x3008)) INT_ISR(void)
{    
    
    if(PIR3bits.TMR0IF == 1)
    {
        TMR0H = 0xC1;             
        TMR0L = 0x7F;
        PIR3bits.TMR0IF = 0; 
        
        if(button_flag == 1)
        {
            if(x < 50)
            {
                x++;
                
                if(READ_BUTTON_EXTERNAL_1())
                {
                    button_press_counter++;
                }
            }
            else
            {
                if(button_press_counter > 30)
                {
                    LED_INTERNAL_TOGGLE();
                    button_press_counter = 0;
                }
                
                button_flag = 0;
                x = 0;
            }
        }
    }
    
    if(PIR1bits.INT0IF == 1)
    {
        if(button_flag == 0)
        {
            button_flag = 1; // Indica que se presiono el boton
        }
        
        PIR1bits.INT0IF = 0;
    }

}