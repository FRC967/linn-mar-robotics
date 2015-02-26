#include "auton2T.h"
auton2T::auton2T(): phase(1), turnRight(false)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void auton2T::Initialize()
{
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	turnRight=true;
}

// Called repeatedly when this Command is scheduled to run
void auton2T::Execute()
{
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool auton2T::IsFinished()
{
	return phase==5;
}

// Called once after isFinished returns true
void auton2T::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void auton2T::Interrupted()
{

}

//Changes the direction that the robot will turn after it picks up the tote/bin
void auton2T::setTurnRight(bool turnRight){
	this->turnRight=turnRight;
}

// Normal operation schedules the actions to be carried out. The integer "phase" is used to track what the program is doing now and
// what it will do next
void auton2T::normalElevatorOperation(){
	elevatorStep=1;
	phase++;
	currentElevatorState=ELEVATOR_NORMAL;
}
void auton2T::normalElevatorOperationLoop(){
	switch (phase){
	case 2:
		autoGrabTote();
		break;
	case 4:
		autoEjectTote();
		break;
	}
}

void auton2T::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void auton2T::normalDriveOperationLoop(){
	switch (phase){
	case 1:
		goToLocation(0,27);
		break;
	case 2:
		drive->stopdrive();
		break;
	case 3:
		if (turnRight){
			goToLocation(-90,108);
		}
		else {
			goToLocation(90,108);
		}
		break;
	case 4:
		drive->stopdrive();
		break;
	}
}
