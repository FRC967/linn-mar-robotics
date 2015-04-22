#ifndef elevator_H
#define elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:

	Victor armMotorR;
	Victor armMotorL;
	Victor winchMotor;

	DoubleSolenoid winchShifter;
	DoubleSolenoid armShifter;
	Relay winchBrake;
	DoubleSolenoid magShifter;
	DoubleSolenoid binShifter;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
			//2, 3, 4, 	0, 	1, 6, 	3, 4, 0, 5, 2, 7, 0
	Elevator(uint32_t winchChannel, uint32_t armLChannel, uint32_t armRChannel,
			uint8_t pneumaticsModuleNumber, uint32_t winchShiftForwardChannel, uint32_t winchShiftReverseChannel,
			uint32_t armShiftForwardChannel, uint32_t armShiftReverseChannel,
			uint32_t winchBrakeChannel,
			uint32_t magShiftForwardChannel, uint32_t magShiftReverseChannel,
			uint32_t binShifterForwardChannel, uint32_t binShifterReverseChannel);

	~Elevator();

	void InitDefaultCommand();

	void setElevator(double power);
	void highGearElevator();
	void lowGearElevator();
	void shiftElevatorGear();
	bool isElevatorHighGear();
	void brakeElevator();
	void unbrakeElevator();

	void shiftBinArms();
	void openBinArms();
	void closeBinArms();
	bool isBinArmsOpen();

	void openArms();
	void closeArms();
	void shiftArms();
	bool isArmsOpen();

	void openMag();
	void closeMag();
	void shiftMag();
	bool isMagOpen();

	void setRollers(double power);
	void setLRollers(double power);
	void setRRollers(double power);

};

#endif
