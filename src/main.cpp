// Framework
#include "Arduino.h"

// Env
#include "env.hpp"

// Drivers
#include "drivers/MotorDriver/MotorDriver.hpp"

/*
struct motorPins 
{
    uint8_t DIRECTION;
    uint8_t PWM;
}

motorPins pinLeft = 
{
    GPIO_DIRECTION_A;
    GPIO_PWM_A;
}

*/

MotorDriver motorLeft(GPIO_DIRECTION_A, GPIO_PWM_A );
MotorDriver motorRight(GPIO_DIRECTION_B, GPIO_PWM_B);

// MotorDriver motorSuccao()

void motorSpeed()
{
    motorLeft.pwmOutput(20);
    motorRight.pwmOutput(20);

}


void setup() {}


void loop() { delay(1000); }
