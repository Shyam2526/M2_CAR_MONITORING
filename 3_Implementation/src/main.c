#include <avr/io.h>
#include <util/delay.h>
#include "ultra.c"
#define F_CPU 16000000UL
#define LCD PORTB
#define EN 7
#define RS 5
#define RW 6
int16_t COUNTA = 0;
char SHOWA [16];
void lcdcmd(unsigned char cmd)
{
    PORTD &=~ (1<<RS);
    PORTD &=~ (1<<RW);
    LCD=cmd & 0xF0;
    PORTD |= (1<<EN);
    _delay_ms(1);
    PORTD &=~(1<<EN);

    LCD = cmd<<4;
    PORTD |= (1<<EN);
    _delay_ms(1);
    PORTD &=~(1<<EN);
}
void lcddata(unsigned char data)
{
    PORTD |= (1<<RS);
    PORTD &=~(1<<RW);
    LCD = data & 0xF0;
    PORTD |=(1<<EN);
    _delay_ms(1);
    PORTD &=~(1<<EN);

    LCD=data<<4;
    PORTD |= (1<<EN);
    _delay_ms(1);
    PORTD &=~(1<<EN);
}
void lcd_init(void)
{
    DDRB = 0xFF;
    DDRD = 0xFF;
    PORTD &=~ (1<<EN);

    lcdcmd(0x33);
    lcdcmd(0x32);
    lcdcmd(0x28);
    lcdcmd(0x0E);
    lcdcmd(0x01);
    _delay_ms(2);
}
void lcd_print(char *str)
{
    unsigned char i=0;
    while(str[i]!=0)
    {
        lcddata(str[i]);
        i++;
    }
}
void convertndisplay(unsigned char value);
unsigned char data;
int main(void)
{
    DDRB &=~ (1<<PB3);
    DDRB |=(1<<PB1);
    lcd_init();
    lcd_print("Temperature:");
    DDRC |= (1<<0);
    ADCSRA = 0x87;
    ADMUX = 0xE0;
    while(1)
    {
        ADCSRA |= (1<<ADSC);
        while((ADCSRA & (1<<ADIF))==0);
        data=ADCH;
        convertndisplay(data);
        _delay_ms(500);
        ultra();
        PORTD|=(1<<PIND0);
        _delay_us(15);
        PORTD &=~(1<<PIND0);

        COUNTA = pulse/58;
        itoa(COUNTA,SHOWA,10);
        LCD_String_xy(1,0,"DISTANCE:");
        LCD_String_xy(1, 10, SHOWA);
        LCD_String("cm");
    }
    return 0;
}
void convertndisplay(unsigned char value)
{
    unsigned char x,d1,d2;
    x=value/10;
    d1=x;
    d2=value%10;
    lcdcmd(0x8D);
    lcddata(d1+0x30);
    lcddata(d2+0x30);
    if(((d1*10)+d2)<20)
    {
        PORTB|=(1<<PB2);
        _delay_ms(2000);
    }
    else if(((d1*10)+d2)<50)
    {
        PORTB |= (1<<PB1);
        _delay_ms(2000);
    }
    else
    {
        PORTB |= (1<<PB3);
        _delay_ms(2000);
    }
}
