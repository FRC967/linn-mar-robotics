#include "Commands/autonomousCommand.h"

autonomousCommand::autonomousCommand()
{
	switch (CommandBase::prefs->GetInt("Autonomous",1)){
	case 0:
		CommandBase::dash->PutString ("Autonomous", "Nothing");
		AddSequential(new autonNothing());
		break;
	case 1:
		CommandBase::dash->PutString ("Autonomous", "1 Tote");
		AddSequential(new auton1T());
		break;
	case 2:
		CommandBase::dash->PutString ("Autonomous", "2 Tote");
		AddSequential(new auton2T());
		break;
	case 3:
		CommandBase::dash->PutString ("Autonomous", "3 Tote");
		AddSequential(new auton3T());
		break;
	case 10:
		CommandBase::dash->PutString ("Autonomous", "Auton Bin");
		AddSequential(new autonBin());
		break;
	case 20:
		CommandBase::dash->PutString ("Autonomous", "Auton Step");
		AddSequential(new autonStep());
		break;
	case 100:
		CommandBase::dash->PutString ("Autonomous", "Test");
		AddSequential(new autonTest());
		break;
	default:
		CommandBase::dash->PutString ("Autonomous", "Drive into Zone");
		AddSequential(new autonDriveIntoZone());
		break;
	}
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
