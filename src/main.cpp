// Framework
#include "Arduino.h"

// Env
#include "env.hpp"

// Drivers
#include "LineControl/LineControl.hpp"
#include "drivers/MotorDriver/MotorDriver.hpp"
#include "drivers/Multiplexer/Multiplexer.hpp"

// __________________________________________________________________

MotorDriver motorLeft(GPIO_DIRECTION_A, GPIO_PWM_A);
MotorDriver motorRight(GPIO_DIRECTION_B, GPIO_PWM_B);
Multiplexer multiplexer;

// armazena leitura dos sensores
int sensorReadings[NUM_SENSORS];

// __________________________________________________________________

void setup() { Serial.begin(115200); }


void loop() {
  delay(1000);

  multiplexer.readSensors(sensorReadings);           // le todos os 12 sensores;

  float PDcorrection = calculatePID(sensorReadings); // calcula o PD

  //
  int left_motorSpeed  = BASE_MOTOR_SPEED - (int)PDcorrection;
  int right_motorSpeed = BASE_MOTOR_SPEED + (int)PDcorrection;
}
