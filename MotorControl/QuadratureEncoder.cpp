#include "QuadratureEncoder.h"
#include "avr/io.h"


QuadratureEncoder::QuadratureEncoder(IGPIODriver *interrupt)
{
	_interrupt = interrupt;
	_interrupt->Initialize();	
}
float QuadratureEncoder::GetPosition()
{
	_interrupt->GetInput(_data);
	
	return _data[ENCODER_VALUE_INDEX];
}


QuadratureEncoder::~QuadratureEncoder()
{
}
