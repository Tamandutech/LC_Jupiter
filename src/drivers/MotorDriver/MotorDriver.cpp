#include "MotorDriver.hpp"
#include "Arduino.h"

#include "env.hpp"

MotorDriver::MotorDriver(uint8_t directionPin, uint8_t pwmPin,
                         uint8_t pwmChannel) {
  directionPin_stored = directionPin;
  pwmPin_stored       = pwmPin;
  pwm_channel         = pwmChannel;

  pinMode(directionPin_stored, OUTPUT);

  // STM32 Arduino: PWM vem do timer do pino, nao de canais LEDC do ESP32.
  analogWriteResolution(MOTOR_PWM_BITS);
  analogWriteFrequency(MOTOR_PWM_FREQUENCY);
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

  if(pulse > MOTOR_PWM_MAX) {
    pulse = MOTOR_PWM_MAX;
  }

  pulse_stored = pulse;
  analogWrite(pwmPin_stored, pulse_stored);
}

int32_t MotorDriver::getPulse() { return pulse_stored; }
