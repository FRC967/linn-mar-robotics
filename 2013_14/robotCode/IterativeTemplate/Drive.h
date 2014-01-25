#ifndef DRIVE_H
#define DRIVE_H
#include "WPILib.h"

class Drive {
public:
	Drive (uint8_t moduleNumber1, uint32_t channel1, uint8_t moduleNumber2, uint32_t channel2,
			uint8_t moduleNumber3, uint32_t channel3, uint8_t moduleNumber4, uint32_t channel4);
	~Drive();
	void test_motors();
	void Move(float LeftSpeed, float RightSpeed);
	void stopdrive();
	void TeleDrive(float Xbox_x, float Xbox_y);
private:
	Talon drive1,drive2,drive3,drive4;
	float deadband;
	float maxout;
};

#endif
