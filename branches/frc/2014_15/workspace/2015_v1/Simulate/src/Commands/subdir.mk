################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/ExampleCommand.cpp \
../src/Commands/autoSingle.cpp \
../src/Commands/auton1T.cpp \
../src/Commands/auton2T.cpp \
../src/Commands/auton3T.cpp \
../src/Commands/autonDriveIntoZone.cpp \
../src/Commands/autonomousCommand.cpp \
../src/Commands/commandWithAutomation.cpp \
../src/Commands/moveToLocation.cpp \
../src/Commands/pollLIDAR.cpp \
../src/Commands/telCompress.cpp \
../src/Commands/telControl.cpp \
../src/Commands/telMessages.cpp \
../src/Commands/teleopCommand.cpp \
../src/Commands/testCommand.cpp 

OBJS += \
./src/Commands/ExampleCommand.o \
./src/Commands/autoSingle.o \
./src/Commands/auton1T.o \
./src/Commands/auton2T.o \
./src/Commands/auton3T.o \
./src/Commands/autonDriveIntoZone.o \
./src/Commands/autonomousCommand.o \
./src/Commands/commandWithAutomation.o \
./src/Commands/moveToLocation.o \
./src/Commands/pollLIDAR.o \
./src/Commands/telCompress.o \
./src/Commands/telControl.o \
./src/Commands/telMessages.o \
./src/Commands/teleopCommand.o \
./src/Commands/testCommand.o 

CPP_DEPS += \
./src/Commands/ExampleCommand.d \
./src/Commands/autoSingle.d \
./src/Commands/auton1T.d \
./src/Commands/auton2T.d \
./src/Commands/auton3T.d \
./src/Commands/autonDriveIntoZone.d \
./src/Commands/autonomousCommand.d \
./src/Commands/commandWithAutomation.d \
./src/Commands/moveToLocation.d \
./src/Commands/pollLIDAR.d \
./src/Commands/telCompress.d \
./src/Commands/telControl.d \
./src/Commands/telMessages.d \
./src/Commands/teleopCommand.d \
./src/Commands/testCommand.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\FRC_2013\workspace\2015_v1/src" -IC:\Users\FRC_2013/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


