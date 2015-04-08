#include "autonStep.h"

autonStep::autonStep()
{
	phase=1;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autonStep::Initialize()
{
	drive->highGear();
	elevator->highGearElevator();
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	currentAntennaeState=ANTENNAE_NORMAL;
}

// Called repeatedly when this Command is scheduled to run
void autonStep::Execute()
{
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool autonStep::IsFinished()
{
	return phase>=5;
}

// Called once after isFinished returns true
void autonStep::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autonStep::Interrupted()
{

}

// Normal operation schedules the actions to be carried out. The integer "phase" is used to track what the program is doing now and
// what it will do next
void autonStep::normalElevatorOperation(){
	elevatorStep=1;
	phase++;
	currentElevatorState=ELEVATOR_NORMAL;
}
void autonStep::normalElevatorOperationLoop(){

}

void autonStep::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void autonStep::normalDriveOperationLoop(){
	switch (phase){
	case 1:
		goToLocation(0,-17);
		break;
	case 3:
		advancedMove(.25,.25,108);
		break;
	case 4:
		drive->stopdrive();
		phase++;
		break;
	}
}

void autonStep::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void autonStep::normalAntennaeOperationLoop(){
	switch(phase){
	case 1:
		lowerAntennae();
		break;
	}
}
