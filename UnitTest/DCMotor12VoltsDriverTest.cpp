#include "../MotorControl/DCMotor12VoltsDriver.cpp"
#include "../gmock/gmock.h"
#include "PWMDriverMock.h"
#include <iostream>
using namespace std;
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
	PWMDriverMock pwm;

	//PWMDriverMock *pwm;
	// Objects declared here can be used by all tests in the test case for Project1.
	//DCMotor12VoltsDriver *motor = new DCMotor12VoltsDriver(pwm);
};

TEST_F(MotorTestFixture, mappingVolts2DutyCycle) {
	DCMotor12VoltsDriver motor = DCMotor12VoltsDriver(&pwm);
	int mapped = motor.MapVoltage2PWM(12);
	int expected = 1023;
	EXPECT_EQ(mapped, expected);

	mapped = motor.MapVoltage2PWM(0);
	expected = 35; // 35 is equivilent to 3V (which is zero for the motor)
	EXPECT_EQ(mapped, expected);
}