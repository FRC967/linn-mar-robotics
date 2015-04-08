#include "Antennae.h"
#include "../RobotMap.h"

Antennae::Antennae(uint32_t channel) :
		Subsystem("Antennae"),
		aMotor(channel)
{

}

void Antennae::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void Antennae::stop(){
	aMotor.Set(0);
}
void Antennae::set(float power){
	aMotor.Set(power);
}
float Antennae::getSpeed(){
	return aMotor.Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
