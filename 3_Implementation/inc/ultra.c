#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD16x2_4bit.c"

static volatile int pulse = 0;
static volatile int i = 0;

void ultra()
{
    DDRC = 0xFF;
    DDRB = 0xFF;
    DDRD = 0b11111011;
    _delay_ms(50);
    DDRB &=~ (1<<PB2);
    EIMSK|=(1<<INT0);
    EICRA|=(1<<ISC00);

    TCCR1A = 0;
    LCD_Init();
    LCD_Clear();
    LCD_String_xy(0,0,"ULTRASONIC-> ");

    sei();
}

ISR(INT0_vect)
{
    if (i==1)
    {
        TCCR1B=0;
        pulse=TCNT1;
        TCNT1=0;
        i=0;
    }
    if (i==0)
    {
        TCCR1B|=(1<<CS10);
        i=1;
    }
}
