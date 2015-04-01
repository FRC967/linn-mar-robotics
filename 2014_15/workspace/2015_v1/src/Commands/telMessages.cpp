#include "telMessages.h"

telMessages::telMessages(): counter(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void telMessages::Initialize()
{
	counter=0;
}

// Called repeatedly when this Command is scheduled to run
void telMessages::Execute()
{
	counter++;

	//nav6 stuff
	dash ->PutNumber ("nav6 Yaw", nav6->GetYaw());

	//Encoder stuff
	dash ->PutNumber ("drive encoder distance", driveEncoder->GetDistance());
	dash ->PutNumber ("elevator encoder distance", elevatorEncoder->GetDistance());

	//LIDAR stuff
	dash ->PutNumber ("LIDAR Reading (Plz Work)", lidar->getCM());
	dash ->PutNumber ("LIDAR High", (double)lidar->getHigh());
	dash ->PutNumber ("LIDAR Low", (double)lidar->getLow());
	dash ->PutNumber ("LIDAR Status", (double)lidar->getLidarStatus());

	//Debug

	//Tests to make sure it works
	dash ->PutNumber ("counter", counter);
	dash ->PutString ("Test", "1");

	//Info Greyson might want
	dash ->PutNumber ("Drive High Gear", drive->isHighGear());
	dash ->PutNumber ("Elevator High Gear", elevator->isElevatorHighGear());
	dash ->PutBoolean("elevator limit switch", elevatorLimit->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool telMessages::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void telMessages::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void telMessages::Interrupted()
{

}
