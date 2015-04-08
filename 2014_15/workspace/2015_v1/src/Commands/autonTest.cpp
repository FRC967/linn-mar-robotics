#include "autonTest.h"

autonTest::autonTest()
{
	phase=1;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autonTest::Initialize()
{
	phase=1;
	currentElevatorState=ELEVATOR_NORMAL;
	currentDriveState=DRIVE_NORMAL;
	currentAntennaeState=ANTENNAE_NORMAL;
}

// Called repeatedly when this Command is scheduled to run
void autonTest::Execute()
{
	dash->PutNumber("Phase",phase);
	runCurrentLoop();
}

// Make this return true when this Command no longer needs to run execute()
bool autonTest::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void autonTest::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autonTest::Interrupted()
{

}

void autonTest::normalElevatorOperation(){

}
void autonTest::normalElevatorOperationLoop(){

}
void autonTest::normalDriveOperation(){

}
void autonTest::normalDriveOperationLoop(){
	switch (phase){
	case 1:
		nav6->ZeroYaw();
		advancedTurn(.55,-.45, 90);
		break;
	case 2:
		goToLocation(90,0);
		break;
	case 3:
		drive->stopdrive();
		break;
	}
}

void autonTest::normalAntennaeOperation(){
	phase++;
	currentAntennaeState=ANTENNAE_NORMAL;
}

void autonTest::normalAntennaeOperationLoop(){
	antennae->stop();
}
