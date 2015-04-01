#ifndef telDrive_H
#define telDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Commands/CommandGroup.h"
#include "Commands/commandWithAutomation.h"
#include "../BlankPIDOutput.h"

class telControl: public commandWithAutomation
{
public:
	telControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void normalElevatorOperation();
	void normalDriveOperation();
	void normalAntennaeOperation();

protected:
	void normalElevatorOperationLoop();
	void normalDriveOperationLoop();
	void normalAntennaeOperationLoop();

private:
	const float conveyorSpeed=.75;
	bool elevatorOverride;
//	PIDController testPID;
//	BlankPIDOutput *PIDPlacebo;
};

#endif
