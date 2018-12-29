#pragma once
#include "gmock/gmock.h"
#include "../MotorControl/IGPIODriver.h"
class PWMDriverMock : public IGPIODriver {
public:
	MOCK_METHOD0(Initialize, void());
	MOCK_METHOD1(SetOutPut, void(int *data));
	MOCK_METHOD1(GetInput, void(int *data));

};