#include "timers.h"

void TIMER0_Init(timerClockSource_t timer_clock_source, timerMode_t timer_mode, timerAsync_t timer_async, timerPrescaler_t timer_prescaler)
{
    T0CON1bits.CS = timer_clock_source;     // Fosc/4 como fuente de clock
    T0CON0bits.MD16 = timer_mode;           // Timer de 16 bits
    T0CON1bits.ASYNC = timer_async;         // Sincronizado con Fosc/4
    T0CON1bits.CKPS = timer_prescaler;      // Prescaler de 1:4096
    T0CON0bits.OUTPS = 0b0000;              // Postscaler de 1:1
}

void TIMER0_Write(uint8_t TMR0H_value, uint8_t TMR0L_value)
{
    TMR0H = TMR0H_value;               
    TMR0L = TMR0L_value;
    T0CON0bits.EN = 1;          // Habilitar TIMER 0
}