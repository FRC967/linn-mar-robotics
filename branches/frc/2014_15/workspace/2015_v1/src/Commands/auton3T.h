#ifndef auton3T_H
#define auton3T_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "commandWithAutomation.h"

class auton3T: public commandWithAutomation
{
	//Basically gonna be scrapped. This is all old stuff
public:
	auton3T();
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
