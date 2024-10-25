#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "config.h"
#include "gpio.h"
#include "timers.h"
#include "interrupt.h"
#include "lcd.h"

#pragma warning disable 520
#pragma warning disable 2020

void GPIO_Init(void);
void LCD_Initial_Screen(void);
void LCD_Update_Screen(uint8_t[], uint8_t, uint8_t[], uint8_t);

// use decrement and write_char

char low_state[] = 
{
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};

char high_state[] = 
{
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

int main(int argc, char** argv) {

    Clock_Init();
    GPIO_Init();
    LCD_Init();
    LCD_Initial_Screen();
    TIMER0_Init(FOSC_4, TIMER_16BIT_MODE, SYNCRONIZED, CKPS_1_1);
    TIMER0_Write(0xC1, 0x7F); // Timer de 1 ms
    INTERRUPT_Init();

    uint8_t input[2] = {0, 0};
    uint8_t output[2] = {0, 0};
    
    while(1)
    {
        input[0] = READ_BUTTON_INTERNAL();  
        input[1] = READ_BUTTON_EXTERNAL_1();
        output[0] = ~get_pin_value(PORT_F, 3);
        output[1] = get_pin_value(PORT_F, 2);
        
        LCD_Update_Screen(input, 2, output, 2);
        __delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}

void GPIO_Init()
{
    /*Configuración del LED de la Curiosity Nano (Q0.0)*/
    configure_pin(PORT_F, 3, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    LED_INTERNAL_OFF();
    
    /*Configuración del boton de la Curiosity Nano (I0.0)*/
    configure_pin(PORT_B, 4, INPUT, DIGITAL, PULLUP, TTL, SR_LIMITED, PUSHPULL);
    
    /*Configuración del led externo (Q0.1)*/
    configure_pin(PORT_F, 2, OUTPUT, DIGITAL, NOPULLUP, TTL, SR_LIMITED, PUSHPULL);
    set_pin_low(PORT_F, 2);
    
    /*Configuración del boton externo (Q0.2)*/
    configure_pin(PORT_B, 0, INPUT, DIGITAL, PULLUP, TTL, SR_LIMITED, PUSHPULL); 
}

void LCD_Initial_Screen()
{
    LCD_Add_Character(low_state, 0);
    LCD_Add_Character(high_state, 1); 
    LCD_Cursor_Set(1, 1);
    LCD_Write_String("Entradas: ");
    LCD_Write_Char(0);
    LCD_Cursor_Increment();
    LCD_Write_Char(0);
    LCD_Cursor_Set(2, 1);
    LCD_Write_String("Salidas:  ");
    LCD_Write_Char(0);
    LCD_Cursor_Increment();
    LCD_Write_Char(0);
}

void LCD_Update_Screen(uint8_t input[], uint8_t input_size, uint8_t output[], uint8_t output_size)
{
    /*Actualiza los valores de las entradas*/
    LCD_Cursor_Set(1, 11);
    
    for(uint8_t i = 0; i < input_size; ++i)
    {
        if(input[i] == 0) LCD_Write_Char(0);
        else LCD_Write_Char(1);
        LCD_Cursor_Increment();
    }
    
    /*Actualiza los valores de las salidas*/
    LCD_Cursor_Set(2, 11);
    
    for(uint8_t i = 0; i < output_size; ++i)
    {
        if(output[i] == 0) LCD_Write_Char(0);
        else LCD_Write_Char(1);
        LCD_Cursor_Increment();
    }
}