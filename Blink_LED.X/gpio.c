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
}
