#pragma once
#include "IGPIODriver.h"
#include <avr/io.h>
class PWMDriver : public IGPIODriver
{
public:
	PWMDriver();
	
	void Initialize();
	virtual void SetOutPut(int *data);
	virtual void GetInput(int *data);
	~PWMDriver();
};

