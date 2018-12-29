#pragma once
#include "IEncoder.h"
#include "IGPIODriver.h"
#include "operators.h"
#define HIGH 1
#define LOW 0
class QuadratureEncoder : public IEncoder
{
public:
	QuadratureEncoder(IGPIODriver *interrupt);
	float GetPosition();
	~QuadratureEncoder();
	
private:
	IGPIODriver *_interrupt;
	int _data[2] = { 0, 0 };
	int _encoderPinALast = 0;
	int _encoderPos = 0;
	int _revolutions = 0;
};

