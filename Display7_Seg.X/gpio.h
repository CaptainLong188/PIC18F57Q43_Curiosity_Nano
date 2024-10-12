#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define INPUT   1
#define OUTPUT  0

#define DIGITAL 1
#define ANALOG  0

#define PULLUP      1
#define NOPULLUP    0

#define TTL 1
#define ST  0

#define SR_LIMITED  1
#define SR_MAXIMUM  0

#define PUSHPULL    1
#define OPENDRAIN   0

/*Macros para la escritura de los estados de los LED's*/
#define LED_INTERNAL_ON()         (LATFbits.LATF3 = 0)
#define LED_INTERNAL_OFF()        (LATFbits.LATF3 = 1)
#define LED_EXTERNAL_1_ON()       (LATDbits.LATD0 = 1)
#define LED_EXTERNAL_1_OFF()      (LATDbits.LATD0 = 0)
#define LED_EXTERNAL_2_ON()       (LATDbits.LATD1 = 0)
#define LED_EXTERNAL_2_OFF()      (LATDbits.LATD1 = 1)
#define LED_INTERNAL_TOGGLE()     (LATFbits.LATF3 ^= 1)
#define LED_EXTERNAL_1_TOGGLE()   (LATDbits.LATD0 ^= 1)
#define LED_EXTERNAL_2_TOGGLE()   (LATDbits.LATD1 ^= 1)

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

// Estructura para representar un pin

typedef struct
{
    char port;   // 'A', 'B', 'C', ...
    uint8_t pin; // (0 - 7)
}pin_t;

typedef enum {
    PORT_A = 'A',
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
}PortName_t;

void set_pin_input(PortName_t port_name, uint8_t pin_number);
void set_pin_output(PortName_t port_name, uint8_t pin_number);
void set_pin_digital_mode(PortName_t port_name, uint8_t pin_number);
void set_pin_analog_mode(PortName_t port_name, uint8_t pin_number);
void set_pin_pullup(PortName_t port_name, uint8_t pin_number);
void reset_pin_pullup(PortName_t port_name, uint8_t pin_number);
void set_pin_st(PortName_t port_name, uint8_t pin_number);
void set_pin_ttl(PortName_t port_name, uint8_t pin_number);
void set_pin_sr_limited(PortName_t port_name, uint8_t pin_number);
void set_pin_sr_maximum(PortName_t port_name, uint8_t pin_number);
void set_pin_push_pull(PortName_t port_name, uint8_t pin_number);
void set_pin_open_drain(PortName_t port_name, uint8_t pin_number);
void configure_pin(PortName_t port_name, uint8_t pin_number, bool is_input, 
                   bool is_digital, bool enable_pullup, bool use_ttl, bool slew_rate_limited,
                   bool use_push_pull);
void set_pin_high(PortName_t port_name, uint8_t pin_number);
void set_pin_low(PortName_t port_name, uint8_t pin_number);
void toggle_pin(PortName_t port_name, uint8_t pin_number);
bool get_pin_value(PortName_t port_name, uint8_t pin_number);

#endif	/* GPIO_H */

