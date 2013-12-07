#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     touchSensor,    sensorTouch)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     FrontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     BackLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     FrontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     BackRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     armMotor,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    basketServo,          tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//11/21/13
#include "joystickDriver.c"

//Defines values to substitute for names
#define SWEEPERONBUTTON 1
#define SWEEPEROFFBUTTON 2
#define SWEEPERREVBUTTON 3

#define ARMJOYSTICK joystick.joy2_y1

#define BASKETUPBUTTON 8
#define BASKETDOWNBUTTON 7

#define FLAGBUTTON 4

//Defines state values for basket state machine
#define OPEN 1
#define OPENING 2
#define CLOSING 3
#define CLOSED 4
#define FLAGSLOWBUTTON 6

#define SERVOTIME 1000 //In milliseconds

//This section defines the constaints used throughout the code
const int off=0;

const int sweeperOn=-80;

const int deadZone=5;
const int armMotorUp=60;
const int touchUnpressed=0;

const int basketServoDown=206;
const int basketServoUp=42;

const int flagMotorOn=100;
const int flagMotorSlow=20;

//Initializing the 'enabled variables globally
bool armEnabled=true;
bool sweeperEnabled=true;

//Tells compiler that the functions exist
void TankDrive();
int scaleMotor(int joyValue);

void Sweeper();
void BasketStateMachine();
void FlagMotor();

task main()
{
	//false=off
	servo[basketServo]=basketServoUp;

	while(true)
	{
		getJoystickSettings(joystick);

		//Calls the tank drive & sweeper functions
		TankDrive();
		Sweeper();

		//Arm motor control
		if(ARMJOYSTICK>deadZone && armEnabled==true)
		{
			motor[armMotor]=armMotorUp;
		}
		else if(ARMJOYSTICK<-deadZone && armEnabled==true)
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

		//Calls the functions
		BasketStateMachine();
		FlagMotor();
	}
}

//Riley's code
void TankDrive()
{
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
}
//End of Riley's code

//Sweeper control
void Sweeper()
{
	static bool sweeperState=false;

	if(sweeperEnabled==true)
	{
		if(joy2Btn(SWEEPEROFFBUTTON)==true)
		{
			motor[sweeper]=off;
			sweeperState=false;
		}
		else if(joy2Btn(SWEEPERONBUTTON)==true)
		{
			motor[sweeper]=sweeperOn;
			sweeperState=true;
		}

		//Reversing the sweeper direction
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
	}
}

//Atomatic controlling of the basket servo & sweeper
void BasketStateMachine()
{
	static int state=CLOSED;

	if(state==CLOSED &&
		 time1[T1]>=SERVOTIME &&
		(SensorValue[touchSensor]==1 || joy2Btn(BASKETDOWNBUTTON)==true))
	{
		motor[sweeper]=-sweeperOn;
		sweeperEnabled=false;
		servo[basketServo]=basketServoDown;
		ClearTimer(T1);
		armEnabled=false;

		state=OPENING;
	}
	else if(state==OPENING && time1[T1]>=SERVOTIME)
	{
		motor[sweeper]=off;
		sweeperEnabled=true;

		state=OPEN;
	}
	else if(state==OPEN && (ARMJOYSTICK>deadZone || joy2Btn(BASKETUPBUTTON)==true))
	{
		motor[sweeper]=sweeperOn;
		sweeperEnabled=false;
		servo[basketServo]=basketServoUp;
		ClearTimer(T1);

		state=CLOSING;
	}
	else if(state==CLOSING && time1[T1]>=SERVOTIME)
	{
		motor[sweeper]=off;
		sweeperEnabled=true;
		armEnabled=true;
		ClearTimer(T1);

		state=CLOSED;
	}
}

//Controlling of the flag motor
void FlagMotor()
{
		if(joy2Btn(FLAGBUTTON)==true)
		{
			motor[flagMotor]=flagMotorOn;
		}
		else if(joy2Btn(FLAGSLOWBUTTON)==true)
		{
			motor[flagMotor]=flagMotorSlow;
		}
		else
		{
			motor[flagMotor]=off;
		}
}

//logarithmic scale for motors
int scaleMotor(int joyValue)
{
	int direction=joyValue/abs(joyValue);
	float ratio=(joyValue*joyValue)/(128.0*128.0);
	int scaleMotor=(ratio*100)*direction;
	/***debug code**
	nxtDisplayTextLine(1, "%d", scaleMotor);
	wait1Msec(5000);
	*/
	return scaleMotor;
}
