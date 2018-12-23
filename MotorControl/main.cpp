#include <avr/io.h>

int main()
{
	DDRB = 0b11111111;
	while (true) {
		PORTB |= (1 << PB3);
		PORTB &= (0 << PB4);
	}
}