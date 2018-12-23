#pragma once
#include "gmock/gmock.h"
#include "../MotorControl/IDCMotor.h"
class DCMotorMock : public IDCMotor {
public:
	MOCK_METHOD2(SetSpeed, void(float speed, Direction dir));
};