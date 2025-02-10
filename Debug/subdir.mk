################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../Canvas.cpp \
../Color.cpp \
../Light.cpp \
../Material.cpp \
../Point.cpp \
../Ray.cpp \
../Scene.cpp \
../Sphere.cpp \
../Unit.cpp \
../Vector.cpp \
../main.cpp \
../test_geomtypes.cpp \
../test_raytracer.cpp \
../utils.cpp 

CPP_DEPS += \
./Camera.d \
./Canvas.d \
./Color.d \
./Light.d \
./Material.d \
./Point.d \
./Ray.d \
./Scene.d \
./Sphere.d \
./Unit.d \
./Vector.d \
./main.d \
./test_geomtypes.d \
./test_raytracer.d \
./utils.d 

OBJS += \
./Camera.o \
./Canvas.o \
./Color.o \
./Light.o \
./Material.o \
./Point.o \
./Ray.o \
./Scene.o \
./Sphere.o \
./Unit.o \
./Vector.o \
./main.o \
./test_geomtypes.o \
./test_raytracer.o \
./utils.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++20 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Camera.d ./Camera.o ./Canvas.d ./Canvas.o ./Color.d ./Color.o ./Light.d ./Light.o ./Material.d ./Material.o ./Point.d ./Point.o ./Ray.d ./Ray.o ./Scene.d ./Scene.o ./Sphere.d ./Sphere.o ./Unit.d ./Unit.o ./Vector.d ./Vector.o ./main.d ./main.o ./test_geomtypes.d ./test_geomtypes.o ./test_raytracer.d ./test_raytracer.o ./utils.d ./utils.o

.PHONY: clean--2e-

