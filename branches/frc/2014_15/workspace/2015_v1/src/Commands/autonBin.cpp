#include "autonBin.h"
autonBin::autonBin(): phase(1), turnRight(true), i(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autonBin::Initialize()
{
	//drive->highGear();
	elevator->highGearElevator();
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	currentAntennaeState=ANTENNAE_NORMAL;
	turnRight=true;
}

// Called repeatedly when this Command is scheduled to run
void autonBin::Execute()
{
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool autonBin::IsFinished()
{
	return phase>=4;
}

// Called once after isFinished returns true
void autonBin::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autonBin::Interrupted()
{

}

//Changes the direction that the robot will turn after it picks up the tote/bin
void autonBin::setTurnRight(bool turnRight){
	this->turnRight=turnRight;
}
// Normal operation schedules the actions to be carried out. The integer "phase" is used to track what the program is doing now and
// what it will do next

void autonBin::normalElevatorOperation(){
	elevatorStep=1;
	phase++;
	currentElevatorState=ELEVATOR_NORMAL;
}
void autonBin::normalElevatorOperationLoop(){
	switch (phase){
	case 1:
		elevator->closeMag();
		phase++;
		break;
	case 2:
		moveHighElevatorToHeight(26);
		break;
	default:
		elevator->setElevator(0);
	}
}

void autonBin::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void autonBin::normalDriveOperationLoop(){
	switch (phase){
	case 3:
		goToLocation(0,-10);
		break;
	default :
		drive->stopdrive();
		break;
	}
}

void autonBin::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void autonBin::normalAntennaeOperationLoop(){
	antennae->stop();
}
