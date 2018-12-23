#pragma once
#include "gmock/gmock.h"
#include "../MotorControl/IEncoder.h"
class EncoderMock : public IEncoder {
public:
	MOCK_METHOD0(GetPosition, float());
};
