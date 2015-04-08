#ifndef commandWithAutomatedFunctions_H
#define commandWithAutomatedFunctions_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include "../BlankPIDOutput.h"
#include "../MyPID.h"

class commandWithAutomation: public CommandBase
{
public:
	enum elevatorState{
		ELEVATOR_NORMAL,
		MOVE_ELEVATOR_TO_HEIGHT,
		RESET_ELEVATOR,
		AUTO_LOAD_TOTE,
		AUTO_EJECT_TOTE,
		AUTO_GET_TOTE,
		AUTO_GRAB_TOTE,
		AUTO_LV2_LOAD_TOTE,

		AUTO_GET_TOTE_FD,
		MOVE_HIGH_ELEVATOR_TO_HEIGHT
	};

	enum driveState{
		DRIVE_NORMAL,
		GO_TO_LOCATION,
		FAST_GO_TO_LOCATION,
		ADVANCED_MOVE,
		ADVANCED_TURN
	};

	enum antennaeState{
		ANTENNAE_NORMAL,
		LOWER_ANTENNAE,
		RAISE_ANTENNAE
	};

	commandWithAutomation();
	virtual void Initialize()=0;
	virtual void Execute()=0;
	virtual bool IsFinished()=0;
	virtual void End()=0;
	virtual void Interrupted()=0;

	virtual void normalElevatorOperation()=0;
	virtual void normalDriveOperation()=0;
	virtual void normalAntennaeOperation()=0;
	void moveElevatorToHeight(float heightIN);
	void resetElevator();
	void autoLoadTote();
	void autoLv2LoadTote();
	void autoEjectTote();
	void autoGetTote();
	void autoGrabTote();
	void goToLocation(double angle, double distance);
	void fastGoToLocation(double angle, double distance);
	void advancedTurn(double L, double R, double yaw);
	void advancedMove(double L, double R, double distance);
	void raiseAntennae();
	void lowerAntennae();

	void autoGetToteFD();
	void moveHighElevatorToHeight(float heightIN);

	//Tasks that need to be performed every time the loop is run, such as managing the states
	void runCurrentLoop();

	const double toteLowestHeight=0.3;

	const double toteHoldHeight=20;
	const double toteLv2Height=11;
	const double toteLv2HoldHeight=37;
	const double toteLv3Height=23;
	const double toteMaxHeight=46;
	const double averageRollerSpeed=.5;
	const double averageConveyorSpeed=.5;
	const double antennaeTime=1.3;

protected:

	MyPID drivePID;
	const float deadband =.1;
	elevatorState currentElevatorState;
	driveState currentDriveState;
	antennaeState currentAntennaeState;

	//Target Angle/Distance in "goToLocation"
	double targetAngle;
	double targetDistance;
	//Initial conditions when running "goToLocation"
	double initialAngle;
	double initialDistance;

	double targetElevatorHeight;
	int elevatorStep;
	int driveStep;

	int i;

	bool limitClicked;

	std::clock_t elevatorTimer;
	std::clock_t driveTimer;
	std::clock_t antennaeTimer;

	//These should be run continuously in the execute loop
	//Returns false until the task is finished
	virtual void normalElevatorOperationLoop()=0;
	virtual void normalDriveOperationLoop()=0;
	virtual void normalAntennaeOperationLoop()=0;
	bool moveElevatorToHeightLoop();
	bool resetElevatorLoop();
	bool autoLoadToteLoop();
	bool autoEjectToteLoop();
	bool autoGetToteLoop();
	bool autoGrabToteLoop();
	bool autoLv2LoadToteLoop();
	bool goToLocationLoop();
	bool fastGoToLocationLoop();
	bool advancedTurnLoop();
	bool advancedMoveLoop();
	bool lowerAntennaeLoop();
	bool raiseAntennaeLoop();

	bool autoGetToteFDLoop();
	bool moveHighElevatorToHeightLoop();
};

#endif
