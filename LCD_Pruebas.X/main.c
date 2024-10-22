#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "config.h"
#include "gpio.h"
#include "lcd.h"

#pragma warning disable 520

void GPIO_Init(void);
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
    
    uint8_t input[2] = {0, 0};
    uint8_t output[2] = {0, 0};
    uint8_t previous_state_btn_1 = 0;
    uint8_t current_state_btn_1 = 0;
    
    while(1)
    {
        current_state_btn_1 = READ_BUTTON_INTERNAL();
        
        if(current_state_btn_1 != previous_state_btn_1)
        {
            if(current_state_btn_1 == 1)
            {
                LED_INTERNAL_ON();
                set_pin_high(PORT_F, 2);
                input[0] = 1;
                output[0] = 1;
                output[1] = 1;
            }
            else
            {
                LED_INTERNAL_OFF();
                set_pin_low(PORT_F, 2);
                input[0] = 0;
                output[0] = 0;
                output[1] = 0;
            }
            LCD_Update_Screen(input, 2, output, 2);  
        }
        
        previous_state_btn_1 = current_state_btn_1;
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
    configure_pin(PORT_B, 4, INPUT, DIGITAL, PULLUP, TTL, SR_LIMITED, PUSHPULL); 
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