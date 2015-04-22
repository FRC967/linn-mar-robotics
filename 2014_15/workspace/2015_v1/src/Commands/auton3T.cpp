#include "auton3T.h"
auton3T::auton3T(): phase(1), turnRight(true), i(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void auton3T::Initialize()
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
void auton3T::Execute()
{
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool auton3T::IsFinished()
{
	return phase>=4;//21;
}

// Called once after isFinished returns true
void auton3T::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void auton3T::Interrupted()
{

}

//Changes the direction that the robot will turn after it picks up the tote/bin
void auton3T::setTurnRight(bool turnRight){
	this->turnRight=turnRight;
}

// Normal operation schedules the actions to be carried out. The integer "phase" is used to track what the program is doing now and
// what it will do next
void auton3T::normalElevatorOperation(){
	elevatorStep=1;
	phase++;
	currentElevatorState=ELEVATOR_NORMAL;
}
void auton3T::normalElevatorOperationLoop(){
	switch (phase){
	case 1:
		elevator->closeMag();
		elevator->lowGearElevator();
		phase++;
		break;
	case 2:
	//	moveHighElevatorToHeight(26);
		elevator->setElevator(.75);
		Wait(.5);
		phase++;
		break;
	case 3:
		elevator->setElevator(0);
		phase++;
		break;

/*	case 1:
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
		if (i>25){
			elevator->closeArms();
			elevator->lowGearElevator();
			if (i>40){
				phase++;
			}
		}
		break;
	case 12:
		moveElevatorToHeight(toteLowestHeight);
		break;
	case 13:
		elevator->highGearElevator();
		elevator->openArms();
		elevator->setRollers(0);
		moveElevatorToHeight(toteHoldHeight);
		break;
	case 17:
		elevator->setRollers(-1);
		break;
	case 18:
		elevator->closeArms();
		break;
	case 19:
		elevator->openMag();
		elevator->openArms();
		phase ++;
		break;*/
	default :
		elevator->setElevator(0);
	}
}

void auton3T::normalDriveOperation(){
	driveStep=1;
	phase++;
	currentDriveState=DRIVE_NORMAL;
}
void auton3T::normalDriveOperationLoop(){
	switch (phase){
/*	case 3:
		goToLocation(0,24);
		break;
	case 7:
		nav6->ZeroYaw();
		phase++;
		break;
	case 8:
		if (nav6->GetYaw()<131 && nav6->GetYaw()>-60){
			drive->Move(.55,-.45);
		}
		else {
			phase=10;
			drive->stopdrive();
		}
		break;
	case 9:
		if (nav6->GetYaw()<131 && nav6->GetYaw()>-60){
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
	case 13:
		advancedMove(-.3,-.3,-7);
		break;
	case 15:
		fastGoToLocation(30,40);
		break;
	case 16:
		goToLocation(-65,35);
		break;
	case 17:
		goToLocation(40,14);
		break;
	case 18:
		fastGoToLocation(70,105);
		break;
	case 20:
		fastGoToLocation(0,-10);
		break;*/
	default:
		drive->stopdrive();
		break;
	}
}

void auton3T::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void auton3T::normalAntennaeOperationLoop(){
	antennae->stop();
}
