#ifndef autonomousCommand_H
#define autonomousCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "auton1T.h"
#include "auton2T.h"
#include "auton3T.h"
#include "autonDriveIntoZone.h"
#include "autonNothing.h"
#include "../CommandBase.h"
#include "autonTest.h"
#include "autonStep.h"
#include "autonBin.h"

#include "telMessages.h"

class autonomousCommand: public CommandGroup
{
public:
	autonomousCommand();
};

#endif

/*
 *
#include <Commands/telControl.h>
#include "Commands/pollLIDAR.h"
#include "telCompress.h"
#include "telMessages.h"
 *
 */
