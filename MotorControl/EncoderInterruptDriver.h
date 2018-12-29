#pragma once
#include "IGPIODriver.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#define OUTA PD5
#define OUTB PD6
class EncoderInterruptDriver : public IGPIODriver
{
public:
	EncoderInterruptDriver();
	void Initialize();
	void SetOutPut(int *data);
	void GetInput(int *data);
	~EncoderInterruptDriver();
	
};

