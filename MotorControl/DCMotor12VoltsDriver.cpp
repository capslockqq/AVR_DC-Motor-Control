#include "DCMotor12VoltsDriver.h"

DCMotor12VoltsDriver::DCMotor12VoltsDriver(IGPIODriver *pwm)
{
	_pwm = pwm;
	_pwm->Initialize();
}

void DCMotor12VoltsDriver::SetSpeed(float voltage, Direction dir)
{ 
	int output = MapVoltage2PWM(voltage);
	int outputData[2] = {0, 0};
	if (dir == clockwise) {
		outputData[OCR1B_data] = output;
		_pwm->SetOutPut(outputData);
	}
	else {
		outputData[OCR1A_data] = output;
		_pwm->SetOutPut(outputData);
	}
}


DCMotor12VoltsDriver::~DCMotor12VoltsDriver()
{
}

void DCMotor12VoltsDriver::PortSetup()
{
	
}


int DCMotor12VoltsDriver::MapVoltage2PWM(float voltage)
{
	//Validation check restricted to motor specifications
	voltage = (voltage <= MAX_VOLTAGE) ? voltage : MAX_VOLTAGE;
	voltage = (voltage >= MIN_VOLTAGE) ? voltage : MIN_VOLTAGE;
	
	//int inputStart = MIN_VOLTAGE;   //0V since that's the lowest voltage the motor is capable of
	//int inputEnd = MAX_VOLTAGE;   //12V since that's the maximum voltage the motor will output
	//int outputStart = 35;  // 50 on the couter is equvilent to 3V
	//int outputEnd = 1023;  // Highest values of pwm (100% duty cycle)
	
	//float slope = 1.0 * (outputEnd - outputStart) / (inputEnd - inputStart);
	//return outputStart + round(slope * (voltage - inputStart));
	
	return voltage;
}
