#include "DCMotor12VoltsDriver.h"

DCMotor12VoltsDriver::DCMotor12VoltsDriver()
{
	PortSetup();
}

void DCMotor12VoltsDriver::SetSpeed(float voltage, Direction dir)
{ 
	int output = MapVoltage2PWM(voltage);
	if (dir == clockwise) {
		OCR1A = 0; //Set duty cycle to 0%
		OCR1B = output; //Set duty cycle to the calculated value from voltage
	}
	else {
		OCR1A = output; //Set duty cycle to the calculated value from voltage
		OCR1B = 0; //Set duty cycle to 0%
	}
}


DCMotor12VoltsDriver::~DCMotor12VoltsDriver()
{
}

void DCMotor12VoltsDriver::PortSetup()
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


int DCMotor12VoltsDriver::MapVoltage2PWM(float voltage)
{
	//Validation check restricted to motor specifications
	voltage = (voltage <= MAX_VOLTAGE) ? voltage : MAX_VOLTAGE;
	voltage = (voltage >= MIN_VOLTAGE) ? voltage : MIN_VOLTAGE;
	
	int inputStart = MIN_VOLTAGE;   //0V since that's the lowest voltage the motor is capable of
	int inputEnd = MAX_VOLTAGE;   //12V since that's the maximum voltage the motor will output
	int outputStart = 35;  // 50 on the couter is equvilent to 3V
	int outputEnd = 1023;  // Highest values of pwm (100% duty cycle)
	
	float slope = 1.0 * (outputEnd - outputStart) / (inputEnd - inputStart);
	return outputStart + round(slope * (voltage - inputStart));
}
