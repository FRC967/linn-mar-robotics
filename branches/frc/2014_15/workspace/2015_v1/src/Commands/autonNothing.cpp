#include "autonNothing.h"

autonNothing::autonNothing()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autonNothing::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autonNothing::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool autonNothing::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void autonNothing::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autonNothing::Interrupted()
{

}
