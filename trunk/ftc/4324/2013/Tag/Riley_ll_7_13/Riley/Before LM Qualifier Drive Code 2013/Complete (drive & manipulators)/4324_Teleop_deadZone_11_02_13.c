#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     touchSensor,    sensorTouch)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     FrontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     BackLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     FrontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     BackRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     armMotor,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    basketServo,          tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickDriver.c"

//Defines button values to substitute for names
#define SWEEPERONBUTTON 1
#define SWEEPEROFFBUTTON 2
#define SWEEPERREVBUTTON 3

#define ARMJOYSTICK joystick.joy2_y1

#define BASKETUPBUTTON 8
#define BASKETDOWNBUTTON 7

#define FLAGBUTTON 4

//This section defines the constaints used throughout the code
const int off=0;

const int sweeperOn=-80;

const int deadZone=5;
const int armMotorUp=100;
const int touchUnpressed=0;

const int basketServoStart=255;
const int basketServoUp=85;

const int flagMotorOn=100;

int scaleMotor(int joyValue);

task main()
{
	//false=off
	bool sweeperState=false;
	servo[basketServo]=basketServoUp;

	while(true)
	{
		getJoystickSettings(joystick);

	//Riley's code
		if(joystick.joy1_y1>deadZone || joystick.joy1_y1<-deadZone)
		{
			motor[FrontLeft]=scaleMotor(joystick.joy1_y1);
			motor[BackLeft]=scaleMotor(joystick.joy1_y1);
			/*
			nxtDisplayTextLine(1, "%d", scaleMotor);
			wait1Msec(5000);
			*/
		}
		else
		{
			motor[FrontLeft]=off;
			motor[BackLeft]=off;
		}
		if(joystick.joy1_y2>deadZone || joystick.joy1_y2<-deadZone)
		{
			motor[FrontRight]=scaleMotor(joystick.joy1_y2);
			motor[BackRight]=scaleMotor(joystick.joy1_y2);
		}
		else
		{
			motor[FrontRight]=off;
			motor[BackRight]=off;
		}
		//End of Riley's code

		//Toggling the sweeper
		if(joy2Btn(SWEEPERONBUTTON)==true && sweeperState==false)
		{
			motor[sweeper]=sweeperOn;
			sweeperState=true;
		}
		else if(joy2Btn(SWEEPEROFFBUTTON)==true && sweeperState==true)
		{
			motor[sweeper]=off;
			sweeperState=false;
		}

		//Reverses the sweeper direction while the button is pressed
		if(joy2Btn(SWEEPERREVBUTTON)==true)
		{
			motor[sweeper]=-sweeperOn;
		}
		else if(sweeperState==true)
		{
			motor[sweeper]=sweeperOn;
		}
		else if(sweeperState==false)
		{
			motor[sweeper]=off;
		}

		//Moving the arm up or down
		if(ARMJOYSTICK>deadZone)
		{
			motor[armMotor]=armMotorUp;
		}
		else if(ARMJOYSTICK<-deadZone)
		{
			//Checks if touchsensor is pressed before moving the arm
			if(SensorValue[touchSensor]==touchUnpressed)
			{
				motor[armMotor]=-armMotorUp;
			}
			else
			{
				motor[armMotor]=off;

			}
		}
		else
		{
			motor[armMotor]=off;
		}

		//Change the basket servo position
		if(joy2Btn(BASKETUPBUTTON)==true)
		{
			servo[basketServo]=basketServoUp;
		}
		else if(joy2Btn(BASKETDOWNBUTTON)==true)
		{
			servo[basketServo]=basketServoStart;
		}

		//Turns the flag motor on/off
		if(joy2Btn(FLAGBUTTON)==true /*&& flagState==false*/)
		{
			motor[flagMotor]=flagMotorOn;
			//flagState=true;
		}
		else /*if(joy2Btn(FLAGBUTTON)==true && flagState==true)*/
		{
			motor[flagMotor]=off;
			//flagState=false;
		}
	}
}
//logarithmic scale for motors
int scaleMotor(int joyValue)
{
	int direction=joyValue/abs(joyValue);
	float ratio=(joyValue*joyValue)/(128.0*128.0);
	int scaleMotor=(ratio*100)*direction;
	//debug code
	/*
	nxtDisplayTextLine(1, "%d", scaleMotor);
	wait1Msec(5000);
	*/
	return scaleMotor;
}
