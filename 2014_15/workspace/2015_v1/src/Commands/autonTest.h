#ifndef autonTest_H
#define autonTest_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "commandWithAutomation.h"

class autonTest: public commandWithAutomation
{
public:
	autonTest();
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
