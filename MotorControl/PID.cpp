#include "PID.h"
#include <avr/io.h>

#define F_CPU 16000000UL

#define USART_BAUDRATE 2400 
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 
PID::PID(PIDVal *val, IEncoder *encoder, IDCMotor *dcMotor)
{
	_encoder = encoder;
	_dcMotor = dcMotor;
	SetPIDValues(val);
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);    // Turn on the transmission and reception circuitry 
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);  // Use 8-bit character sizes 

	UBRR0H = (BAUD_PRESCALE >> 8);  // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
	UBRR0L = BAUD_PRESCALE;  // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
}

void PID::SetPIDValues(PIDVal * val)
{
	if (val->kp < 0) { // Checking for invalid kp,ki and kd values. This could be done in conditional express, but due to coverage, this has to be done
		_val.kp = 0;
	}
	else {
		_val.kp = val->kp;
	}
	if (val->ki < 0) {
		_val.ki = 0;
	}
	else {
		_val.ki = val->ki;
	}
	if (val->kd < 0) {
		_val.kd = 0;
	}
	else {
		_val.kd = val->kd;
	}

	_val.Max = val->Max;
	_val.Min = val->Min;
	_val.IntegratorLimit = val->IntegratorLimit;
}

void PID::GetPIDValues(PIDVal *val) {
	val->kp = _val.kp;
	val->ki = _val.ki;
	val->kd = _val.kd;

	val->Max = _val.Max;
	val->Min = _val.Max;
	val->IntegratorLimit = _val.IntegratorLimit;
}

float PID::GetIntegral()
{
	return _integral;
}

float PID::GetCorrection()
{
	return _correction;
}

float PID::Correction(float setpoint)
{

	float error = setpoint - GetMeasurement();
	float derivative = _firstTime == false ? error - _previousError : 0; //Ensuring that the code will have run twice before calculating derivative contribution
	_firstTime = false;
	_integral += error;
	if (_integral*_val.ki > _val.IntegratorLimit) {//Integral windup protection
		_integral = _val.IntegratorLimit/_val.ki;
	}
	else if (_integral*_val.ki < -_val.IntegratorLimit) {
		_integral = -_val.IntegratorLimit/_val.ki;
	}
	
	float tmpCorrection = error * _val.kp + _integral*_val.ki + derivative*_val.kd;
	
	if (tmpCorrection > _val.Max) {
		tmpCorrection = _val.Max;
	}
	else if (tmpCorrection < _val.Min) {
		tmpCorrection = _val.Min;
	}
	_correction = tmpCorrection;
	_previousError = error;
	return _correction;
}

float PID::GetMeasurement() {
	return _encoder->GetPosition();
}

void PID::Control(float setpoint)
{
	Correction(setpoint);
	_dir = _correction < 0 ? counterClockwise : clockwise;
	float numericCorrection = _correction < 0 ? _correction * -1 : _correction; // Making sure speed (voltage) is positive
	while((UCSR0A & (1 << UDRE0)) == 0) {}
	; // Do nothing until data have been received and is ready to be read from UDR 
     UDR0 = _correction;   // Fetch the received byte value into the variable "ByteReceived" 
	_dcMotor->SetSpeed(numericCorrection, _dir);
}


PID::~PID()
{
}
