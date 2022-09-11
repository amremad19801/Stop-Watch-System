#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned int uint8;

uint8 g_Flag = 0;

uint8 Num1 = 0;
uint8 Num2 = 0;
uint8 Num3 = 0;
uint8 Num4 = 0;
uint8 Num5 = 0;
uint8 Num6 = 0;

void INT0_Init(void)
{
	MCUCR &= ~(1 << ISC00);
	MCUCR |= (1 << ISC01);
	GICR |= (1 << INT0);
	SREG |= (1 << 7);
}

void INT1_Init(void)
{
	MCUCR |= (1 << ISC10);
	MCUCR |= (1 << ISC11);
	GICR |= (1 << INT1);
	SREG |= (1 << 7);
}

void INT2_Init(void)
{
	MCUCSR |= (1 << ISC2);
	GICR |= (1 << INT2);
	SREG |= (1 << 7);
}

void Timer1_Init(void)
{
	TCCR1A = (1 << FOC1A);
	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS12);
	TCNT1 = 0;
	OCR1A = 1000;
	SREG |= (1 << 7);
	TIMSK |=  (1 << OCIE1A);
}

ISR(INT0_vect)
{
	Num1 = 0;
	Num2 = 0;
	Num3 = 0;
	Num4 = 0;
	Num5 = 0;
	Num6 = 0;

	Timer1_Init();
}

ISR(INT1_vect)
{
	TCCR1B &= ~(1 << CS10);
	TCCR1B &= ~(1 << CS12);
}

ISR(INT2_vect)
{
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS12);
}

ISR(TIMER1_COMPA_vect)
{
	g_Flag = 1;
}

void Display_7_Segment(void)
{
	PORTA = (PORTA & 0xC0) | (1 << 5);
	PORTC = (PORTC & 0xF0) | (Num1 & 0x0F);
	_delay_us(2);
	PORTA = (PORTA & 0xC0) | (1 << 4);
	PORTC = (PORTC & 0xF0) | (Num2 & 0x0F);
	_delay_us(2);
	PORTA = (PORTA & 0xC0) | (1 << 3);
	PORTC = (PORTC & 0xF0) | (Num3 & 0x0F);
	_delay_us(2);
	PORTA = (PORTA & 0xC0) | (1 << 2);
	PORTC = (PORTC & 0xF0) | (Num4 & 0x0F);
	_delay_us(2);
	PORTA = (PORTA & 0xC0) | (1 << 1);
	PORTC = (PORTC & 0xF0) | (Num5 & 0x0F);
	_delay_us(2);
	PORTA = (PORTA & 0xC0) | (1 << 0);
	PORTC = (PORTC & 0xF0) | (Num6 & 0x0F);
	_delay_us(2);
}

int main(void)
{
	/* Initialization */

	INT0_Init();
	INT1_Init();
	INT2_Init();

	Timer1_Init();

	DDRA |= 0x3F;

	DDRC |= 0x0F;
	PORTC &= 0xF0;

	DDRD &= 0xF3;
	PORTD |= (1 << PD2);

	DDRB &= ~(1 << PB2);
	PORTB |= (1 << PB2);

	while(1)
	{
		/* Code */

		if(g_Flag == 1)
		{
			if(((PORTC & 0x0F) | (Num1 & 0x0F)) == 9)
			{
				Num1 = 0;

				if(((PORTC & 0x0F) | (Num2 & 0x0F)) == 5)
				{
					Num2 = 0;

					if(((PORTC & 0x0F) | (Num3 & 0x0F)) == 9)
					{
						Num3 = 0;

						if(((PORTC & 0x0F) | (Num4 & 0x0F)) == 5)
						{
							Num4 = 0;

							if(((PORTC & 0x0F) | (Num5 & 0x0F)) == 9)
							{
								Num5 = 0;

								if(((PORTC & 0x0F) | (Num6 & 0x0F)) == 2)
								{
									Num6 = 0;
								}
								else
								{
									Num6++;
								}
							}
							else
							{
								Num5++;
							}
						}
						else
						{
							Num4++;
						}
					}
					else
					{
						Num3++;
					}
				}
				else
				{
					Num2++;
				}
			}
			else
			{
				Num1++;
			}
			Display_7_Segment();
			g_Flag = 0;
		}
		else
		{
			Display_7_Segment();
		}
	}
}
