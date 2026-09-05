#include "MotorDriver.hpp"
#include "Arduino.h"

#include "env.hpp"

MotorDriver::MotorDriver(uint8_t directionPin, uint8_t pwmPin,
                         uint8_t pwmChannel) {
  directionPin_stored = directionPin;
  pwmPin_stored       = pwmPin;
  pwm_channel         = pwmChannel;

  pinMode(directionPin_stored, OUTPUT);

  ledcSetup(pwm_channel, MOTOR_PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(pwmPin_stored, pwm_channel);
}

void MotorDriver::pwmOutput(int32_t value) {

  int32_t pulse = value;

  // Existe uma forma melhor de fazer isso, pero yo no se
  if(pulse >= 0) {
    digitalWrite(directionPin_stored, HIGH);
  } else {
    digitalWrite(directionPin_stored, LOW);
    pulse = -pulse;
  }

  pulse_stored = pulse;
  ledcWrite(pwm_channel, pulse_stored);
}

int32_t MotorDriver::getPulse() { pulse_stored; }
