#include "auton2T.h"
auton2T::auton2T(): phase(1), turnRight(true), i(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void auton2T::Initialize()
{
	drive->highGear();
	elevator->highGearElevator();
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	currentAntennaeState=ANTENNAE_NORMAL;
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
	return phase>=17;
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
	case 1:
		elevator->closeMag();
		phase++;
		break;
	case 2:
		moveElevatorToHeight(13);
		break;
	case 3:
		moveElevatorToHeight(26);
		break;
	case 5:
		autoGrabTote();
		break;
	case 6:
		elevator->openArms();
		moveElevatorToHeight(toteLowestHeight);
		break;
	case 8:
		moveElevatorToHeight(toteHoldHeight);
		break;
	case 10:
		elevator->setRollers(-1);
		i=0;
		break;
	case 11:
		i++;
		if (i>30){
			elevator->closeArms();
			elevator->lowGearElevator();
			if (i>45){
				phase++;
			}
		}
		break;
	case 15:
		elevator->setRollers(0);
		autoEjectTote();
		break;
	default:
		elevator->setElevator(0);
	}
}

void auton2T::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void auton2T::normalDriveOperationLoop(){
	switch (phase){
	case 3:
		goToLocation(0,24);
		break;
	case 7:
		nav6->ZeroYaw();
		phase++;
		break;
	case 8:
		if (nav6->GetYaw()<130 && nav6->GetYaw()>-60){
			drive->Move(.55,-.45);
		}
		else {
			phase=10;
			drive->stopdrive();
		}
		break;
	case 9:
		if (nav6->GetYaw()<130 && nav6->GetYaw()>-60){
			drive->Move(.55,-.45);
		}
		else {
			phase=10;
			drive->stopdrive();
		}
		break;
	case 10:
		advancedMove(.8,.8,47);
		break;
	case 12:
		advancedMove(-.3,-.3,-7);
		break;
	case 13:
		if (turnRight){
			goToLocation(90,105); 	//Supposed to be (90,108)
		}
		else {
			goToLocation(-90,105);	//Supposed to be (-90,108)
		}
		break;
	case 14:
		goToLocation(70,0);
		break;
	case 16:
		fastGoToLocation(0,-12);
		break;
	default :
		drive->stopdrive();
		break;
	}
}

void auton2T::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void auton2T::normalAntennaeOperationLoop(){
	antennae->stop();
}
