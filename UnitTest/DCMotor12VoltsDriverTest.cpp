/*#include "../MotorControl/DCMotor12VoltsDriver.cpp"
#include "gmock/gmock.h"
class MotorTestFixture : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	MotorTestFixture() {
		// You can do set-up work for each test here.
	}

	virtual ~MotorTestFixture() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}


	// Objects declared here can be used by all tests in the test case for Project1.
	DCMotor12VoltsDriver motor;
};

TEST_F(MotorTestFixture, mappingVolts2DutyCycle) {
	int mapped = motor.MapVoltage2PWM(12);
	int expected = 1023;
	EXPECT_EQ(mapped, expected);
}*/