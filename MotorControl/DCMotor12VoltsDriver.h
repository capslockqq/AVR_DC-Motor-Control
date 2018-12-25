#pragma once
#include "IDCMotor.h"
#include <avr/io.h>
#include <math.h>
#define MAX_VOLTAGE 12
#define MIN_VOLTAGE 0
class DCMotor12VoltsDriver : public IDCMotor
{
public:
	DCMotor12VoltsDriver();
	void SetSpeed(float voltage, Direction dir);
	~DCMotor12VoltsDriver();
	int MapVoltage2PWM(float voltage);

private:
	void PortSetup();
};

