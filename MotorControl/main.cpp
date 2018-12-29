#include <avr/io.h>
#include <avr/interrupt.h>
#include "DCMotor12VoltsDriver.h"
#include "IGPIODriver.h"
#include "PWMDriver.h"
#include "IDCMotor.h"
#include "PID.h"
#include "QuadratureEncoder.h"
#include "EncoderInterruptDriver.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define USART_BAUDRATE 2400 
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 

//include "test.h"



int main()
{
	IGPIODriver *pwm = new PWMDriver();
	IGPIODriver *interrup = new EncoderInterruptDriver();
	IDCMotor *motor = new DCMotor12VoltsDriver(pwm);
	IEncoder *encoder = new QuadratureEncoder(interrup);
	
	PIDVal PIDValues; 
	PIDValues.kp = 1;
	PIDValues.ki = 0.001;
	PIDValues.kd = 0;
	PIDValues.Max = 1024; //12 Volts is maximum
	PIDValues.Min = -1024;//-12 volts is minimum (getting changed to direction instead)
	PIDValues.IntegratorLimit = PIDValues.Max; //Half of the maximum voltage to limit the integral part a bit
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);    // Turn on the transmission and reception circuitry 
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);  // Use 8-bit character sizes 

	UBRR0H = (BAUD_PRESCALE >> 8);  // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
	UBRR0L = BAUD_PRESCALE;  // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
	
	
	PID controller(&PIDValues, encoder, motor);
	
	float i = 0;
	uint8_t data;
	DDRB = 0b11111111;
	while(true) {
		controller.Control(1000);
		while ((UCSR0A & (1 << UDRE0)) == 0) {}
		; // Do nothing until UDR is ready for more data to be written to it 
		UDR0 = 1;  // Echo back the received byte back to the computer 
		_delay_ms(10);
	}
}