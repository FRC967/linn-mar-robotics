################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlankPIDOutput.cpp \
../src/CommandBase.cpp \
../src/IMU.cpp \
../src/IMUAdvanced.cpp \
../src/IMUProcess.cpp \
../src/LIDAR.cpp \
../src/OI.cpp \
../src/Robot.cpp \
../src/myUltrasonic.cpp 

OBJS += \
./src/BlankPIDOutput.o \
./src/CommandBase.o \
./src/IMU.o \
./src/IMUAdvanced.o \
./src/IMUProcess.o \
./src/LIDAR.o \
./src/OI.o \
./src/Robot.o \
./src/myUltrasonic.o 

CPP_DEPS += \
./src/BlankPIDOutput.d \
./src/CommandBase.d \
./src/IMU.d \
./src/IMUAdvanced.d \
./src/IMUProcess.d \
./src/LIDAR.d \
./src/OI.d \
./src/Robot.d \
./src/myUltrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\FRC_2013\workspace\2015_v1/src" -IC:\Users\FRC_2013/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


