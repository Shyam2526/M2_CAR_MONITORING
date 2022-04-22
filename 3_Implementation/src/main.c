#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
//#include "LCD16x2_4bit.c"
#include "LCD16x2_4bit.c"

static volatile int pulse = 0;
static volatile int i = 0;

int main(void)
{
    DDRC = 0xFF;
    DDRB = 0xFF;
    DDRD = 0b11111011;
    _delay_ms(50);
    DDRB &=~ (1<<PB2);
    EIMSK|=(1<<INT0);
    EICRA|=(1<<ISC00);

    TCCR1A = 0;

    int16_t COUNTA = 0;
    char SHOWA [16];

    LCD_Init();
    LCD_Clear();
    LCD_String_xy(0,0,"ULTRASONIC-> ");

    sei();

    while(1)
    {
        PORTD|=(1<<PIND0);
        _delay_us(15);
        PORTD &=~(1<<PIND0);

        COUNTA = pulse/52;
        itoa(COUNTA,SHOWA,10);
        LCD_String_xy(1,0,"DISTANCE:");
        LCD_String_xy(1, 10, SHOWA);
        LCD_String("cm");
        if(!(PIND & (1<<PD0)))
        {
            PORTB |= (1<<PB2);
            //_delay_us(10000);
        }
        else{
            PORTB &=~ (1<<PB2);
        }
    }
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
