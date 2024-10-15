#include "timers.h"

void TIMER0_Init(void)
{
    /*
     * Para timer de 16 bits ->  TMR0 = 65535 - tiempo * Fosc / (4 * Prescaler * Postscaler) 
     * Para timer de 8 bits  ->  TMR0H = tiempo * Fosc / (4 * Prescaler * Postcaler)
     */
    
    T0CON1bits.CS = 0b010;      // Fosc/4 como fuente de clock
    T0CON1bits.ASYNC = 0;       // Sincronizado con Fosc/4
    T0CON1bits.CKPS = 0b1100;   // Prescaler de 1:4096
    T0CON0bits.MD16 = 1;        // Timer de 16 bits
    T0CON0bits.OUTPS = 0b0001;  // Postscaler de 1:2
    TMR0H = 0xF3;               // Tiempo : ??
    TMR0L = 0xE7;
    T0CON0bits.EN = 1;          // Habilitar TIMER 0
}