#include "gpio.h"

void GPIO_Init(void)
{
    /*Configuración del pin asociado al LED interno*/
    
    ANSELFbits.ANSELF3 = 0; // Pin digital
    SLRCONFbits.SLRF3 = 1;  // Slew rate limitado
    INLVLFbits.INLVLF3 = 0; // TTL
    ODCONFbits.ODCF3 = 0;   // Push - Pull
    WPUFbits.WPUF3 = 0;     // Pull-Up deshabilitado
    TRISFbits.TRISF3 = 0;   // Salida
    
    /*Configuración del pin asociado al LED externo 1*/
    
    ANSELDbits.ANSELD0 = 0; // Pin digital
    SLRCONDbits.SLRD0 = 1;  // Slew rate limitado
    INLVLDbits.INLVLD0 = 0; // TTL
    ODCONDbits.ODCD0 = 0;   // Push - Pull
    WPUDbits.WPUD0 = 0;     // Pull-Up deshabilitado
    TRISDbits.TRISD0 = 0;   // Salida
    
    /*Configuración del pin asociado al LED externo 2*/
    
    ANSELDbits.ANSELD1 = 0; // Pin digital
    SLRCONDbits.SLRD1 = 1;  // Slew rate limitado
    INLVLDbits.INLVLD1 = 0; // TTL
    ODCONDbits.ODCD1 = 1;   // Open - Drain
    WPUDbits.WPUD1 = 0;     // Pull-Up deshabilitado
    TRISDbits.TRISD1 = 0;   // Salida

    /*Configuración del pin asociado al botón interno*/
    
    ANSELBbits.ANSELB4 = 0; // Pin digital
    SLRCONBbits.SLRB4 = 1;  // Slew rate limitado
    INLVLBbits.INLVLB4 = 0; // TTL
    ODCONBbits.ODCB4 = 1;   // Open - Drain
    WPUBbits.WPUB4 = 1;     // Pull-Up habilitado
    TRISBbits.TRISB4 = 1;   // Entrada
    
    /*Configuración del pin asociado al botón externo 1*/
    
    ANSELCbits.ANSELC4 = 0; // Pin digital
    SLRCONCbits.SLRC4 = 1;  // Slew rate limitado
    INLVLCbits.INLVLC4 = 0; // TTL
    ODCONCbits.ODCC4 = 1;   // Open - Drain
    WPUCbits.WPUC4 = 1;     // Pull-Up habilitado
    TRISCbits.TRISC4 = 1;   // Entrada

    /*Configuración del pin asociado al botón externo 2*/
    
    ANSELCbits.ANSELC5 = 0; // Pin digital
    SLRCONCbits.SLRC5 = 1;  // Slew rate limitado
    INLVLCbits.INLVLC5 = 0; // TTL
    ODCONCbits.ODCC5 = 1;   // Open - Drain
    WPUCbits.WPUC5 = 1;     // Pull-Up habilitado
    TRISCbits.TRISC5 = 1;   // Entrada
}

bool read_Button(button_t btn)
{  
    switch (btn) {
        case BUTTON_INTERNAL:
            return READ_BUTTON_INTERNAL();
        case BUTTON_EXTERNAL_1:
            return READ_BUTTON_EXTERNAL_1();
        case BUTTON_EXTERNAL_2:
            return READ_BUTTON_EXTERNAL_2();
        default:
            return false;
    }
}