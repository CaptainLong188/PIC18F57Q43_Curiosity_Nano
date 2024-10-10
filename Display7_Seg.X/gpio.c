#include "gpio.h"

void GPIO_Init(void)
{
    /*Configuración del pin asociado al led a*/
    
    ANSELAbits.ANSELA3 = 0; // Pin digital
    SLRCONAbits.SLRA3 = 1;  // Slew rate limitado
    INLVLAbits.INLVLA3 = 0; // TTL
    ODCONAbits.ODCA3 = 0;   // Push - Pull
    WPUAbits.WPUA3 = 0;     // Pull-Up deshabilitado
    TRISAbits.TRISA3 = 0;   // Salida
    
    /*Configuración del pin asociado al led b*/
    
    ANSELAbits.ANSELA4 = 0; // Pin digital
    SLRCONAbits.SLRA4 = 1;  // Slew rate limitado
    INLVLAbits.INLVLA4 = 0; // TTL
    ODCONAbits.ODCA4 = 0;   // Push - Pull
    WPUAbits.WPUA4 = 0;     // Pull-Up deshabilitado
    TRISAbits.TRISA4 = 0;   // Salida
    
    /*Configuración del pin asociado al led c*/
    
    ANSELEbits.ANSELE2 = 0; // Pin digital
    SLRCONEbits.SLRE2 = 1;  // Slew rate limitado
    INLVLEbits.INLVLE2 = 0; // TTL
    ODCONEbits.ODCE2 = 0;   // Push - Pull
    WPUEbits.WPUE2 = 0;     // Pull-Up deshabilitado
    TRISEbits.TRISE2 = 0;   // Salida    
    
    /*Configuración del pin asociado al led d*/
    
    ANSELCbits.ANSELC7 = 0; // Pin digital
    SLRCONCbits.SLRC7 = 1;  // Slew rate limitado
    INLVLCbits.INLVLC7 = 0; // TTL
    ODCONCbits.ODCC7 = 0;   // Push - Pull
    WPUCbits.WPUC7 = 0;     // Pull-Up deshabilitado
    TRISCbits.TRISC7 = 0;   // Salida   
    
    /*Configuración del pin asociado al led e*/
    
    ANSELDbits.ANSELD0 = 0; // Pin digital
    SLRCONDbits.SLRD0 = 1;  // Slew rate limitado
    INLVLDbits.INLVLD0 = 0; // TTL
    ODCONDbits.ODCD0 = 0;   // Push - Pull
    WPUDbits.WPUD0 = 0;     // Pull-Up deshabilitado
    TRISDbits.TRISD0 = 0;   // Salida
    
    /*Configuración del pin asociado al led f*/
    
    ANSELDbits.ANSELD1 = 0; // Pin digital
    SLRCONDbits.SLRD1 = 1;  // Slew rate limitado
    INLVLDbits.INLVLD1 = 0; // TTL
    ODCONDbits.ODCD1 = 0;   // Push - Pull
    WPUDbits.WPUD1 = 0;     // Pull-Up deshabilitado
    TRISDbits.TRISD1 = 0;   // Salida
    
    /*Configuración del pin asociado al led g*/
    
    ANSELDbits.ANSELD2 = 0; // Pin digital
    SLRCONDbits.SLRD2 = 1;  // Slew rate limitado
    INLVLDbits.INLVLD2 = 0; // TTL
    ODCONDbits.ODCD2 = 0;   // Push - Pull
    WPUDbits.WPUD2 = 0;     // Pull-Up deshabilitado
    TRISDbits.TRISD2 = 0;   // Salida
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