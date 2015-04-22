#include "auton1T.h"
auton1T::auton1T(): phase(1), turnRight(false)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void auton1T::Initialize()
{
//	drive->highGear();
	elevator->highGearElevator();
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	currentAntennaeState=ANTENNAE_NORMAL;
	turnRight=false;
}

// Called repeatedly when this Command is scheduled to run
void auton1T::Execute()
{
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool auton1T::IsFinished()
{
	return phase>=12;
}

// Called once after isFinished returns true
void auton1T::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void auton1T::Interrupted()
{

}

//Changes the direction that the robot will turn after it picks up the tote/bin
void auton1T::setTurnRight(bool turnRight){
	this->turnRight=turnRight;
}

// Normal operation schedules the actions to be carried out. The integer "phase" is used to track what the program is doing now and
// what it will do next
void auton1T::normalElevatorOperation(){
	elevatorStep=1;
	phase++;
	currentElevatorState=ELEVATOR_NORMAL;
}
void auton1T::normalElevatorOperationLoop(){
	switch (phase){
	case 1:
		elevator->closeMag();
		elevator->openArms();
		phase++;
		break;
	case 2:
		moveElevatorToHeight(18);
		break;
	case 3:
		moveElevatorToHeight(26);
		break;
	case 5:
		autoGetToteFD();
		break;
	case 6:
		autoLoadBin();
		break;
	case 10:
		autoEjectTote();
		break;
	default :
		elevator->setElevator(0);
		break;
	}
}

void auton1T::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void auton1T::normalDriveOperationLoop(){
	switch (phase){
	case 3:
		goToLocation(0,24);
		break;
	case 7:
		if (turnRight){
			goToLocation(90,0);
		}
		else {
			goToLocation(-90,0);
		}
		break;
	case 8:
		goToLocation(0,108);
		break;
	case 9:
		goToLocation(70,0);
		break;
	case 11:
		goToLocation(0,-12);
		break;
	default:
		drive->stopdrive();
	}
}

void auton1T::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void auton1T::normalAntennaeOperationLoop(){
	antennae->stop();
}
