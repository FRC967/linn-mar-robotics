#include "Drive.h"

Drive::Drive (uint8_t moduleNumber1, uint32_t channel1, uint8_t moduleNumber2, uint32_t channel2,
		uint8_t moduleNumber3, uint32_t channel3, uint8_t moduleNumber4, uint32_t channel4):
	drive1(moduleNumber1,channel1),
	drive2(moduleNumber2,channel2),
	drive3(moduleNumber3,channel3),
	drive4(moduleNumber4,channel4)
{
	deadband = .2;
	maxout = 1;
}

Drive::~Drive (){
	stopdrive();
}

void Drive::test_motors(){
	drive1.Set(.3);
	Wait(3);
	drive1.Set(0);
	Wait(3);
	drive2.Set(.3);
	Wait(3);
	drive2.Set(0);
	Wait(3);
	drive3.Set(.3);
	Wait(3);
	drive3.Set(0);
	Wait(3);
	drive4.Set(.3);
	Wait(3);
	drive4.Set(0);
}

void Drive::Move(float LeftSpeed, float RightSpeed){
	drive1.Set(LeftSpeed);
	drive2.Set(LeftSpeed);
	drive3.Set(RightSpeed);
	drive4.Set(RightSpeed);
}

void Drive::stopdrive(){
	drive1.StopMotor();
	drive2.StopMotor();
	drive3.StopMotor();
	drive4.StopMotor();
}

void Drive::TeleDrive(float Xbox_x, float Xbox_y){
	
	float x=Xbox_x;
	float y=Xbox_y;
	float RightSpeed=0;
	float LeftSpeed=0;
	
	//******ARCADE DRIVE CODE*****
	//square the controller inputs
	if (y<0){
		y = -(y*y);
	}
	else{
		y = y*y;
	}
	if (x<0){
		x = -(x*x);
	}
	else {
		x = x*x;
	}
	
	//calculate the power for each side of drive
	//up on y-axis is negative
	if(y >= deadband) {
		if(x > deadband) {
			LeftSpeed=(y-x)*maxout;
			RightSpeed=max(x,y)*maxout;
		}
		else if(x < -deadband){
			LeftSpeed=max(-x,y)*maxout;
			RightSpeed=(y+x)*maxout;
		}
		else {
			LeftSpeed = y*maxout;
			RightSpeed = y*maxout;
		}
	}
	else if(y <= -deadband){
		if(x > deadband) {
			LeftSpeed=-max(x,-y)*maxout;
			RightSpeed=(x+y)*maxout;
		}
		else if(x < -deadband) {
			LeftSpeed=(y-x)*maxout;
			RightSpeed=-max(-x,-y)*maxout;
		}
		else {
			LeftSpeed = y*maxout;
			RightSpeed = y*maxout;
		}
	}
	else {
		if(x > deadband) {
			LeftSpeed=-x*maxout;
			RightSpeed=x*maxout;
		}
		else if(x < -deadband){
			LeftSpeed=-x*maxout;
			RightSpeed=x*maxout;
		}
		else {
			LeftSpeed = 0;
			RightSpeed = 0;
		}
	}
	//make sure power is not* over one
	if(y>1){
		y=1;
	}
	else if(y<-1){
		y=-1;
	}
	if(x>1){
		x=1;
	}
	else if(x<-1){
		x=-1;
	}
	Move(-LeftSpeed,RightSpeed);
}

