#ifndef autonBin_H
#define autonBin_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "commandWithAutomation.h"

class autonBin: public commandWithAutomation
{
public:
	autonBin();
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
	void setTurnRight(bool turnRight);
private:
	int phase;
	bool turnRight;
	int i;
};


#endif
