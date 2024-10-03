#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*Macros para la escritura de los estados de los LED's*/
#define LED_INTERNAL_ON()         (LATFbits.LATF3 = 0)
#define LED_INTERNAL_OFF()        (LATFbits.LATF3 = 1)
#define LED_EXTERNAL_1_ON()       (LATDbits.LATD0 = 1)
#define LED_EXTERNAL_1_OFF()      (LATDbits.LATD0 = 0)
#define LED_EXTERNAL_2_ON()       (LATDbits.LATD1 = 0)
#define LED_EXTERNAL_2_OFF()      (LATDbits.LATD1 = 1)

/*Macros para lectura de los botones*/
#define READ_BUTTON_INTERNAL()   (PORTBbits.RB4 == 0)
#define READ_BUTTON_EXTERNAL_1() (PORTCbits.RC4 == 0)
#define READ_BUTTON_EXTERNAL_2() (PORTCbits.RC5 == 0)

typedef enum
{
    BUTTON_INTERNAL,
            BUTTON_EXTERNAL_1,
            BUTTON_EXTERNAL_2
} button_t; 

void GPIO_Init(void);
bool read_Button(button_t button);

#endif	/* GPIO_H */

