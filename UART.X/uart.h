#ifndef UART_H
#define	UART_H

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 64000000UL

void UART1_Init(uint32_t baud);
void UART1_Write_Char(char ch);
void UART1_Write_String(char* str);
char UART1_Read_Char(void);

#endif	/* UART_H */

