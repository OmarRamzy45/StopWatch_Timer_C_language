#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char sec1 =0;
unsigned char sec2 =0;
unsigned char min1 =0;
unsigned char min2 =0;
unsigned char hour1 =0;
unsigned char hour2 =0;

ISR(TIMER1_COMPA_vect)
{
	if(sec1 == 9 && sec2 != 5)
	{
		sec1 =0;
		sec2 ++;

	}

	else if (sec1 == 9 && sec2 == 5)
	{
		sec1=sec2=0;
		min1++;
	}
	else
	{
		sec1 ++;
	}
	if (min1 ==9 && min2 !=5)
	{
		min1=0;
		min2 ++;
	}
	else if (min1 == 9 && min2 == 5)
	{
		min1=min2=0;
		hour1++;
	}
	if(hour1 ==9 && hour2 != 5)
	{
		hour1=0;
		hour2++;
	}
	else if(hour1 ==9 && hour2 == 5)
	{
		sec1 = sec2 = min1 = min2 =hour1 =hour2=0;
	}

}

ISR(INT0_vect)
{
	sec1 = sec2 = min1 = min2 =hour1 =hour2=0;
}

ISR(INT1_vect)
{
	TCCR1B &= 0xF8;
}

ISR(INT2_vect)
{
	TCCR1B |= (1<<CS10) | (1<<CS12);


}
void Timer1_Init(void)
{
	TCCR1B |= (1<<CS10) | (1<<CS12) | (1<<WGM12);
	OCR1A = 977;
	TIMSK |= (1<<OCIE1A);
}

void INT0_Init(void)
{
	DDRD  &= (~(1<<PD2));
	GICR |= (1<<INT0);
	MCUCR |= (1<<ISC01);
}

void INT1_Init(void)
{
	DDRD  &= (~(1<<PD3));
	GICR |= (1<<INT1);
	MCUCR |= (1<<ISC10) |(1<<ISC11);
}

void INT2_Init(void)
{
	DDRB  &= (~(1<<PB2));
	GICR |= (1<<INT2);
}

int main (void)
{
	SREG |= (1<<7);

	DDRC |= 0x0F;
	PORTC &= 0xF0;

	DDRA |= 0x3F;

	DDRD &= 0xF3;
	PORTD |= (1<<PD2);

	DDRB &= ~(1<<PB2);
	PORTB |= (1<<PB2);


	INT0_Init();
	INT2_Init();
	INT1_Init();

	Timer1_Init();

	while(1){
		PORTA &= ~(0x3F);
		PORTA |= (0x01);
		PORTC = (PORTC & 0xF0) | (sec1 & 0x0F);
		_delay_ms(2);
		PORTA &= ~(0x3F);
		PORTA |= (0x02);
		PORTC = (PORTC & 0xF0) | (sec2 & 0x0F);
		_delay_ms(2);
		PORTA &= ~(0x3F);
		PORTA |= (0x04);
		PORTC = (PORTC & 0xF0) | (min1 & 0x0F);
		_delay_ms(2);
		PORTA &= ~(0x3F);
		PORTA |= (0x08);
		PORTC = (PORTC & 0xF0) | (min2 & 0x0F);
		_delay_ms(2);
		PORTA &= ~(0x3F);
		PORTA |= (0x10);
		PORTC = (PORTC & 0xF0) | (hour1 & 0x0F);
		_delay_ms(2);
		PORTA &= ~(0x3F);
		PORTA |= (0x30);
		PORTC = (PORTC & 0xF0) | (hour2 & 0x0F);
		_delay_ms(2);

	}

}
