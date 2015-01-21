#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/teleopCommand.h"
#include "CommandBase.h"
#include "Commands/autoSingle.h"
//#include "Commands/ExampleCommand.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *telCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new autoSingle();
		telCommand = new teleopCommand();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		if (telCommand != NULL)
			telCommand->Cancel();
	}

	void AutonomousInit()
	{

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
//		if (autonomousCommand != NULL)
//			autonomousCommand->Cancel();
		if (telCommand != NULL)
			telCommand->Start();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
