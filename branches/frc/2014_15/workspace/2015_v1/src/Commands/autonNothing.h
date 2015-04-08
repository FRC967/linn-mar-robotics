#ifndef autonNothing_H
#define autonNothing_H

#include "../CommandBase.h"
#include "WPILib.h"

class autonNothing: public CommandBase
{
public:
	autonNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
