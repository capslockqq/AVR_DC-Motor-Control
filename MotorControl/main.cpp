#include <avr/io.h>
#include "DCMotor12VoltsDriver.h"
#include "IDCMotor.h"
#include "PID.h"
#include "QuadratureEncoder.h"
#define F_CPU 16000000UL
#include <util/delay.h>

//include "test.h"

int main()
{
	IDCMotor *motor = new DCMotor12VoltsDriver();
	IEncoder *encoder = new QuadratureEncoder();
	
	PIDVal PIDValues; 
	PIDValues.kp = 0;
	PIDValues.ki = 0.01;
	PIDValues.kd = 0;
	PIDValues.Max = 12; //12 Volts is maximum
	PIDValues.Min = -12;//-12 volts is minimum (getting changed to direction instead)
	PIDValues.IntegratorLimit = PIDValues.Max; //Half of the maximum voltage to limit the integral part a bit
	
	PID controller(&PIDValues, encoder, motor);
	float i = 0;

	while(true) {
		controller.Control(20.0);
		_delay_ms(500);
		
	}
}