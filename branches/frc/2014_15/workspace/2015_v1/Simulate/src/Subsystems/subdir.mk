################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Drive.cpp \
../src/Subsystems/Elevator.cpp \
../src/Subsystems/ExampleSubsystem.cpp \
../src/Subsystems/myCompressor.cpp 

OBJS += \
./src/Subsystems/Drive.o \
./src/Subsystems/Elevator.o \
./src/Subsystems/ExampleSubsystem.o \
./src/Subsystems/myCompressor.o 

CPP_DEPS += \
./src/Subsystems/Drive.d \
./src/Subsystems/Elevator.d \
./src/Subsystems/ExampleSubsystem.d \
./src/Subsystems/myCompressor.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\FRC_2013\workspace\2015_v1/src" -IC:\Users\FRC_2013/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


