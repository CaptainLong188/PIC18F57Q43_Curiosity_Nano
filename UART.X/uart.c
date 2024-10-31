#include "uart.h"
#include "gpio.h"

void UART1_Init(uint32_t baud)
{  
    /* Para normal speed -> baudRate = Fosc / (16 * UBRG + 1)  */
    /*        high speed -> baudRate = Fosc / (4 * UBRG + 1) */
    U1CON0bits.BRGS = 0;        // Normal Speed
    U1BRG = (uint16_t)((_XTAL_FREQ/16UL/baud) - 1UL);
    U1CON0bits.MODE = 0b0000;   // UART Async 8-bit
    U1CON2bits.TXPOL = 0;       // Salida no invertida
    U1CON1bits.ON = 1;          // Habilitar el puerto serial
    U1CON0bits.TXEN = 1;        // Transmitter habilitado
    U1CON0bits.RXEN = 1;        // Receiver habilitado
    
    /*Direccionamiento de Tx y Rx*/
    // Tx -> RF0
    RF0PPS = 0x20;
    configure_pin(PORT_F, 0, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    
    // Rx -> RF1
    U1RXPPSbits.PORT = 0b101;
    U1RXPPSbits.PIN  = 0b001;
    configure_pin(PORT_F, 1, INPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
}

void UART1_Write_Char(char ch)
{
    while(U1ERRIRbits.TXMTIF == 0); // Esperar que TSR este vacío
    U1TXB = ch;
}

void UART1_Write_String(char* str)
{
    while(*str != '\0')
    {
        UART1_Write_Char(*str++);
    }
}

void putch(char dataTx)
{
    UART1_Write_Char(dataTx);
}

char UART1_Read_Char(void)
{
    while(U1FIFObits.RXBE == 1);
    return U1RXB;
}