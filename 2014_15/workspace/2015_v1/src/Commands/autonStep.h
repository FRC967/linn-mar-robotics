#ifndef autonStep_H
#define autonStep_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "commandWithAutomation.h"

class autonStep: public commandWithAutomation
{
public:
	autonStep();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void normalElevatorOperation();
	void normalElevatorOperationLoop();
	void normalDriveOperation();
	void normalDriveOperationLoop();
	void normalAntennaeOperation();
	void normalAntennaeOperationLoop();

private:
	int phase;
};

#endif
