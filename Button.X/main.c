#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "gpio.h"

void btn_led(button_t);

int main(int argc, char** argv) {
    
    Clock_Init();
    GPIO_Init();
    
    while(1)
    {
        btn_led(BUTTON_INTERNAL);
        btn_led(BUTTON_EXTERNAL_1);
        btn_led(BUTTON_EXTERNAL_2);        
    }
    
    return (EXIT_SUCCESS);
}

void btn_led(button_t btn)
{
    switch(btn)
    {
        case BUTTON_INTERNAL:
            
            if (read_Button(btn)) 
                LED_INTERNAL_ON();
            else 
                LED_INTERNAL_OFF();
            break;
        
        case BUTTON_EXTERNAL_1:
            
            if (read_Button(btn)) 
                LED_EXTERNAL_1_ON();
            else 
                LED_EXTERNAL_1_OFF();
            break;
            
        case BUTTON_EXTERNAL_2:
            
            if (read_Button(btn)) 
                LED_EXTERNAL_2_OFF();
            else 
                LED_EXTERNAL_2_ON();
            break;
    }
}
