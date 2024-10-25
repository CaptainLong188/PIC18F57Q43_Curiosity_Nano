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
    
    /*Configuración de la interrupción externa INT1*/
    /*Por defecto en RB1, con PPS se cambiará a RB4*/
    INT1PPSbits.PORT = 0b001;    
    INT1PPSbits.PIN = 0b100;    // INT1 en el pin RB4
    INTCON0bits.INT1EDG = 0;    // Interrupción en el flanco de bajada
    PIR6bits.INT1IF = 0;        // Limpiar la bandera
    PIE6bits.INT1IE = 1;        // Habilitar la interrupción externa INT1
    IPR6bits.INT1IP = 1;        // Prioridad alta
    
    /*Tabla de vectores en la direccion 0x003008 (por defecto seria 0x000008)*/
    
    di(); // Deshabilitamos las interrupciones
    IVTBASEU = 0x00;
    IVTBASEH = 0x30;
    IVTBASEL = 0x08;
    ei(); // Habilitamos las interrupciones
}

void __interrupt(irq(IRQ_TMR0, IRQ_INT0, IRQ_INT1), base(0x3008)) INT_ISR(void)
{    
    /*Interrupción TIMER 0*/
    if(PIR3bits.TMR0IF == 1)
    {
        TMR0H = 0xC1;             
        TMR0L = 0x7F;
        PIR3bits.TMR0IF = 0;
        
        for(int i = 0; i < 2; ++i)
        {
            if(button_flag[i] == 1)
            {
                if(x[i] < 50)
                {
                    x[i]++;
                    
                    switch(i)
                    {
                        case(0):
                            
                            if(READ_BUTTON_EXTERNAL_1()) // Verificar que se presione el boton RB0
                            {
                                button_press_counter[0]++;
                            }
                            break;
                        
                        case(1):
                            
                            if(READ_BUTTON_INTERNAL()) // Verificar que se presione el boton RB4
                            {
                                button_press_counter[1]++;
                            }
                            break;
                        
                        default:
                            break;
                    }
                }
                else
                {
                    switch(i)
                    {
                        case(0):
                            
                            if(button_press_counter[0] > 30)
                            {
                                LED_INTERNAL_TOGGLE();
                            }
                            
                            button_press_counter[0] = 0;
                            break;
                        
                        case(1):
                            
                            if(button_press_counter[1] > 30)
                            {
                                LED_EXTERNAL_1_TOGGLE();
                            }
                            button_press_counter[1] = 0;
                            break;
                        
                        default:
                            break;
                    }
                    
                    button_flag[i] = 0;
                    x[i] = 0;
                }
            }
        }
    }
    
    /*Interrupción externa INT0*/
    if(PIR1bits.INT0IF == 1)
    {
        if(button_flag[0] == 0)
        {
            button_flag[0] = 1; // Indica que se presionó el boton RB0 
        }
        
        PIR1bits.INT0IF = 0;
    }

    /*Interrupción externa INT1*/
    if(PIR6bits.INT1IF == 1)
    {
        if(button_flag[1] == 0)
        {
            button_flag[1] = 1; // Indica que se presionó el boton RB4
        }
        
        PIR6bits.INT1IF = 0;
    }
}