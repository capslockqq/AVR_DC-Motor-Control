#include "EncoderInterruptDriver.h"

uint8_t EncoderPosA = 0;
uint8_t EncoderPosB = 0;
int EncoderPos = 0;
uint8_t EncoderPinALast = 0;
uint8_t tmpA = 0;
uint8_t tmpB = 0;
int Revolutions = 0;

ISR(PCINT2_vect) {
	EncoderPosA = 0;
	EncoderPosB = 0;
	tmpA = PIND & (1 << OUTA);
	tmpB = PIND & (1 << OUTB);
	if (tmpA > 0) {
		EncoderPosA = 1;
	}
	if (tmpB > 0) {
		EncoderPosB = 1;
	}
	
	if ((EncoderPinALast == 0) && (EncoderPosA == 1)) {
		if (EncoderPosB == 0) {
			EncoderPos--;
			if (EncoderPos < -500) {
				PORTB |= (1 << PB5);
			}
		}
		else {
			EncoderPos++; 
			if (EncoderPos > 500) {
				PORTB |= (1 << PB5);
			}
		}
		if (EncoderPos % 1024 == 0) {
			Revolutions++;
			//PORTB |= (1 << PB5);
		}
	}
	EncoderPinALast = EncoderPosA;
}

EncoderInterruptDriver::EncoderInterruptDriver()
{
}

void EncoderInterruptDriver::Initialize()
{
	PCICR |= (1 << PCIE2); //Enabling interrupt for PCIE2 (PCINT21 and PCINT22)
	sei(); //Enabling global interrupts
	
	DDRD = 0b10011111; //PORTD to be inputs
	PORTD = 0b00000000;
	PCMSK2 |= (1 << PCINT21); //Enabling pin change interrupt on pin 5
	PCMSK2 |= (1 << PCINT22); //Enabling pin change interrupt on pin 6
}

void EncoderInterruptDriver::SetOutPut(int * data)
{
}

void EncoderInterruptDriver::GetInput(int *data)
{
	data[ENCODER_VALUE_INDEX] = EncoderPos;  //Getting data from OUTA
	data[REVOLUTION_VALUE_INDEX] = Revolutions;
}


EncoderInterruptDriver::~EncoderInterruptDriver()
{
}
