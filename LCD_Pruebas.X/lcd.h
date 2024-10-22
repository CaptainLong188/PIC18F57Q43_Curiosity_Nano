/*
 * MIT License
 * 
 * Copyright (c) 2022 Ahmet Burak Irmak (https://youtube.com/Microesque)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


/* 
 * This library is made for communicating with LCDs (Liquid Crystal Display)
 * with PIC microcontrollers.
 *
 * The library is written to communicate with LCDs that are controlled by
 * the HD44780U chip from hitachi. It's written for the XC8 compiler, and is
 * intended to be used with MPLAB X IDE.
 *
 * All library functions are blocking, so there is no need for any peripherals.
 * 
 * Works with the common 4x20 and 2x16 LCD displays (should work with any LCD
 * that uses HD44780U).
 * 
 * For a comprehensive tutorial on how to use the library visit
 * "https://youtube.com/Microesque".
 * Actual video: https://www.youtube.com/watch?v=pR942IY54oo
 */

#ifndef LCD_H
    #define	LCD_H


    /**************************************************************************/
    /*************** Update the definitions below accordingly *****************/
    /**************************************************************************/
    
    #define LCD_RS_TRIS TRISCbits.TRISC0  //TRIS bit of the pin connected to "RS"
    #define LCD_EN_TRIS TRISCbits.TRISC1  //TRIS bit of the pin connected to "EN"
    #define LCD_D4_TRIS TRISFbits.TRISF4  //TRIS bit of the pin connected to "D4"
    #define LCD_D5_TRIS TRISFbits.TRISF5  //TRIS bit of the pin connected to "D5"
    #define LCD_D6_TRIS TRISFbits.TRISF6  //TRIS bit of the pin connected to "D6"
    #define LCD_D7_TRIS TRISFbits.TRISF7  //TRIS bit of the pin connected to "D7"

    #define LCD_RS_LAT LATCbits.LATC0  //LAT bit of the pin connected to "RS"
    #define LCD_EN_LAT LATCbits.LATC1  //LAT bit of the pin connected to "EN"
    #define LCD_D4_LAT LATFbits.LATF4  //LAT bit of the pin connected to "D4"
    #define LCD_D5_LAT LATFbits.LATF5  //LAT bit of the pin connected to "D5"
    #define LCD_D6_LAT LATFbits.LATF6  //LAT bit of the pin connected to "D6"
    #define LCD_D7_LAT LATFbits.LATF7  //LAT bit of the pin connected to "D7"

    #define _XTAL_FREQ 64000000UL  //Frequency of the sytem clock

    /**************************************************************************/
    /*************************** Necessary includes ***************************/
    /**************************************************************************/

    #include <xc.h>
    #include <stdint.h>
    
    /**************************************************************************/
    /*************************** Function prototypes **************************/
    /**************************************************************************/

    void LCD_Init(void);
    void LCD_Cursor_Set(uint8_t, uint8_t);
    void LCD_Cursor_Increment(void);
    void LCD_Cursor_Decrement(void);
    void LCD_Configure_Display(uint8_t);
    void LCD_Configure_Cursor_Display(uint8_t);
    void LCD_Configure_Cursor_Blink(uint8_t);
    void LCD_Clear(void);
    void LCD_Shift_Reset(void);
    void LCD_Shift_Left(void);
    void LCD_Shift_Right(void);    
    void LCD_Configure_Entry_ID(uint8_t);
    void LCD_Configure_Entry_Shift(uint8_t);
    void LCD_Add_Character(char*, uint8_t);
    
    void LCD_Write_String(char*);
    void LCD_Write_Char(char);
    void LCD_Write_Variable(int32_t, uint8_t);
    void LCD_Write_Float(float, uint8_t, uint8_t);
    
    
#endif	/* LCD_H */