################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Vec.cpp \
../VecTester.cpp \
../tester.cpp \
../vecInterface.cpp 

OBJS += \
./Vec.o \
./VecTester.o \
./tester.o \
./vecInterface.o 

CPP_DEPS += \
./Vec.d \
./VecTester.d \
./tester.d \
./vecInterface.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


