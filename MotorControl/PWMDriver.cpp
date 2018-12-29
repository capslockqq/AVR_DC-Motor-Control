#include "PWMDriver.h"

PWMDriver::PWMDriver()
{
}

void PWMDriver::Initialize()
{
	DDRB = 0b11111111;
	// PD6 is now an output
	//PORTD &= ~(1 << DDD5);
	OCR1A = 0;
	OCR1B = 0;
	// set PWM for 50% duty cycle

	TCCR1A |= (1 << COM1A1);
	// set none-inverting mode
	
	TCCR1A |= (1 << COM1B1);
	// set none-inverting mode
	
	TCCR1B |= (1 << WGM01) | (1 << WGM00);

	TCCR1A |= (1 << WGM01) | (1 << WGM00);
	// set fast PWM Mode

	TCCR1B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
}


void PWMDriver::SetOutPut(int *data)
{
	OCR1A = data[0];
	OCR1B = data[1];
}

void PWMDriver::GetInput(int *data) {
}

PWMDriver::~PWMDriver()
{
}
