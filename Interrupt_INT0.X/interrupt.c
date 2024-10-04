#include "interrupt.h"
#include "config.h"

void INTERRUPT_Init(void)
{
    
    INTCON0bits.IPEN = 1;       // Habilitar prioridades en las interrupciones
    INTCON0bits.GIEH = 1;       // Habilitar las interrupciones de prioridad alta
    INTCON0bits.GIEL = 1;       // Habilitar las interrupciones de prioridad baja
    
    /*Configuración de la interrupcion INT0*/
    
    ANSELBbits.ANSELB0 = 0; // Pin digital
    SLRCONBbits.SLRB0 = 1;  // Slew rate limitado
    INLVLBbits.INLVLB0 = 0; // TTL
    ODCONBbits.ODCB0 = 0;   // Push-Pull
    WPUBbits.WPUB0 = 1;     // Pull-Up habilitado
    TRISBbits.TRISB0 = 1;   // Entrada

    INTCON0bits.INT0EDG = 0;    // Interrupcion en el flanco de bajada    
    PIR1bits.INT0IF = 0;        // Limpiar la bandera 
    PIE1bits.INT0IE = 1;        // Habilitar la interrupcion externa INT0
    IPR1bits.INT0IP = 1;        // Prioridad alta 
    
    /*Configuración de la interrupcion INT1*/
    
    ANSELBbits.ANSELB1 = 0; // Pin digital
    SLRCONBbits.SLRB1 = 1;  // Slew rate limitado
    INLVLBbits.INLVLB1 = 0; // TTL
    ODCONBbits.ODCB1 = 0;   // Push-Pull
    WPUBbits.WPUB1 = 1;     // Pull-Up habilitado
    TRISBbits.TRISB1 = 1;   // Entrada
        
    INTCON0bits.INT1EDG = 1; // Interrupcion en el flanco de subida
    PIR6bits.INT1IF = 0;     // Limpiar la bandera
    PIE6bits.INT1IE = 1;     // Habilitar la interrupcion externa INT1
    IPR6bits.INT1IP = 0;     // Prioridad baja

    /*Configuración de la interrupción IOC*/
    
    ANSELCbits.ANSELC2 = 0; // Pin digital
    SLRCONCbits.SLRC2 = 1;  // Slew rate limitado
    INLVLCbits.INLVLC2 = 0; // TTL
    ODCONCbits.ODCC2 = 0;   // Push-Pull
    WPUCbits.WPUC2 = 1;     // Pull-Up habilitado
    TRISCbits.TRISC2 = 1;   // Entrada
    
    IOCCNbits.IOCCN2 = 1;   // Interrupcion en flanco de bajada habilitada
    IOCCPbits.IOCCP2 = 1;   // Interrupcion en flanco de subidad habilitada
    IOCCFbits.IOCCF2 = 0;   // Limpiar la bandera
    PIE0bits.IOCIE = 1;     // Habiltar interrupciones IOC
    IPR0bits.IOCIP = 1;     // Alta prioridad
    /*PIR0bits.IOCIF only read*/
    
    /*Tabla de vectores en la direccion 0x003008 (por defecto seria 0x000008)*/
    
    di(); // Deshabilitamos las interrupciones
    IVTBASEU = 0x00;
    IVTBASEH = 0x30;
    IVTBASEL = 0x08;
    ei(); // Habilitamos las interrupciones
}

void __interrupt(irq(IRQ_INT0, IRQ_INT1, IRQ_IOC), base(0x3008)) INT_ISR(void)
{    
    if(PIR1bits.INT0IF) // Lógica para la interrupción INT0
    {
        __delay_ms(20);
        
        if(PORTBbits.RB0 == 0) // Verificar que siga presionado el boton 
        { 
            flag_INT0 = 1;
        }
        
        PIR1bits.INT0IF = 0;
    }
    
    if(PIR6bits.INT1IF) // Lógica para la interrupción INT1
    {
        __delay_ms(20);
        
        if(PORTBbits.RB1 == 1&& !start) // Verificar que no siga presionado
        {
            flag_INT1 = 1;
        }
        
        if(start) {start = false; }
        
        PIR6bits.INT1IF = 0;
    }
    
    if(PIR0bits.IOCIF) // Lógica para la interrupción IOC
    {
        __delay_ms(20);
        
        if(PORTCbits.RC2 == 0) // Verificar que siga presionado el boton 
        { 
            flag_IOCC2 = 1;
        }
        else
        {
            flag_IOCC2 = 0;
        }
        
        IOCCFbits.IOCCF2 = 0;
    }
}