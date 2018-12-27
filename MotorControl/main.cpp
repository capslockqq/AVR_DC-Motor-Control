#include <avr/io.h>
#include "DCMotor12VoltsDriver.h"
#include "IGPIODriver.h"
#include "PWMDriver.h"
#include "IDCMotor.h"
#include "PID.h"
#include "QuadratureEncoder.h"
#define F_CPU 16000000UL
#include <util/delay.h>

//include "test.h"

int main()
{
	IGPIODriver *pwm = new PWMDriver();
	IDCMotor *motor = new DCMotor12VoltsDriver(pwm);
	IEncoder *encoder = new QuadratureEncoder();
	
	PIDVal PIDValues; 
	PIDValues.kp = 1;
	PIDValues.ki = 0;
	PIDValues.kd = 0;
	PIDValues.Max = 12; //12 Volts is maximum
	PIDValues.Min = -12;//-12 volts is minimum (getting changed to direction instead)
	PIDValues.IntegratorLimit = PIDValues.Max; //Half of the maximum voltage to limit the integral part a bit
	
	PID controller(&PIDValues, encoder, motor);
	float i = 0;

	while(true) {
		controller.Control(1.5);
		_delay_ms(500);
		
	}
}