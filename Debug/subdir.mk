################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../Color.cpp \
../Cone.cpp \
../Cylinder.cpp \
../Hyperboloid.cpp \
../Image.cpp \
../Light.cpp \
../Material.cpp \
../Point.cpp \
../Ray.cpp \
../Scene.cpp \
../Shape.cpp \
../Sphere.cpp \
../Unit.cpp \
../Vector.cpp \
../main.cpp \
../test_geomtypes.cpp \
../test_raytracer.cpp \
../utils.cpp 

CPP_DEPS += \
./Camera.d \
./Color.d \
./Cone.d \
./Cylinder.d \
./Hyperboloid.d \
./Image.d \
./Light.d \
./Material.d \
./Point.d \
./Ray.d \
./Scene.d \
./Shape.d \
./Sphere.d \
./Unit.d \
./Vector.d \
./main.d \
./test_geomtypes.d \
./test_raytracer.d \
./utils.d 

OBJS += \
./Camera.o \
./Color.o \
./Cone.o \
./Cylinder.o \
./Hyperboloid.o \
./Image.o \
./Light.o \
./Material.o \
./Point.o \
./Ray.o \
./Scene.o \
./Shape.o \
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
	-$(RM) ./Camera.d ./Camera.o ./Color.d ./Color.o ./Cone.d ./Cone.o ./Cylinder.d ./Cylinder.o ./Hyperboloid.d ./Hyperboloid.o ./Image.d ./Image.o ./Light.d ./Light.o ./Material.d ./Material.o ./Point.d ./Point.o ./Ray.d ./Ray.o ./Scene.d ./Scene.o ./Shape.d ./Shape.o ./Sphere.d ./Sphere.o ./Unit.d ./Unit.o ./Vector.d ./Vector.o ./main.d ./main.o ./test_geomtypes.d ./test_geomtypes.o ./test_raytracer.d ./test_raytracer.o ./utils.d ./utils.o

.PHONY: clean--2e-

