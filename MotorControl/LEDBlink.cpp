#include <avr/io.h>

void Delay()
{
	long counter = 0;
	while (counter++ < 50000)
		asm("nop");
}

void MainLoop()
{
	DDRB |= (1 << 5);
	
	for (;;)
	{
		PORTB |= (1 << 5);
		Delay();
		PORTB &= ~(1 << 5);
		Delay();
	}
}

int main()
{
	MainLoop();
}