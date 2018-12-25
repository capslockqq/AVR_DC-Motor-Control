#pragma once
typedef enum {
	counterClockwise,
	clockwise,
}Direction;
class IDCMotor{
public:
	virtual void SetSpeed(float voltage, Direction dir) = 0;
};