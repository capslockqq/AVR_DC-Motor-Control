#pragma once
#define OCR1A_data 0
#define OCR1B_data 1
#define ENCODER_VALUE_INDEX 0
#define REVOLUTION_VALUE_INDEX 1
class IGPIODriver {
public:
	virtual void Initialize() = 0;
	virtual void SetOutPut(int *data) = 0;
	virtual void GetInput(int *data) = 0;
};