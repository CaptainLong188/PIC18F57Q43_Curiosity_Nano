#ifndef TIMERS_H
#define	TIMERS_H

#include <xc.h>
#include <stdint.h>

/*
 * Para timer de 16 bits ->  TMR0 = 65535 - tiempo * Fosc / (4 * Prescaler * Postscaler) 
 * Para timer de 8 bits  ->  TMR0H = tiempo * Fosc / (4 * Prescaler * Postcaler) 15625
 */
    
typedef enum
{
    T0CKIPPS_NON_INVERTED,
            T0CKIPPS_INVERTED,
            FOSC_4,
            HFINTOSC,
            LFINTOSC,
            MFINTOSC,
            SOSC,
            CLC1_OUT
}timerClockSource_t;

typedef enum
{
    TIMER_8BIT_MODE,
            TIMER_16BIT_MODE
}timerMode_t;

typedef enum
{
    SYNCRONIZED,
            NOT_SYNCRONIZED
}timerAsync_t;

typedef enum
{
    CKPS_1_1,
    CKPS_1_2,
    CKPS_1_4,
    CKPS_1_8,
    CKPS_1_16,
    CKPS_1_32,
    CKPS_1_64,
    CKPS_1_128,
    CKPS_1_256,
    CKPS_1_512,
    CKPS_1_1024,
    CKPS_1_2048,
    CKPS_1_4096,
    CKPS_1_8192,
    CKPS_1_16384,
    CKPS_1_32768
} timerPrescaler_t;

/**************************************************************************/
/*************************** Function prototypes **************************/
/**************************************************************************/

void TIMER0_Init(timerClockSource_t, timerMode_t, timerAsync_t, timerPrescaler_t);
void TIMER0_Write(uint8_t, uint8_t);

#endif	/* TIMERS_H */

