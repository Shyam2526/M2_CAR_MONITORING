
#ifndef LCD16X2_4BIT_H_
#define LCD16X2_4BIT_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Dir DDRB
#define LCD_Port PORTB
#define RS PB0
#define EN PB1

void LCD_Init ();
void LCD_Clear();
void LCD_String (char *str);
void LCD_Char( unsigned char data );
void LCD_Command( unsigned char cmnd );
void LCD_String_xy (char row, char pos, char *str);

#endif
