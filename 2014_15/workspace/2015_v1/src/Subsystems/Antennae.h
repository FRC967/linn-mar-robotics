#ifndef Antennae_H
#define Antennae_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Antennae: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon aMotor;
public:
	Antennae(uint32_t channel);
	void InitDefaultCommand();
	void stop();
	void set(float power);
	float getSpeed();
};

#endif
