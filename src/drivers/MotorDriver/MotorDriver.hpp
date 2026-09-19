#ifndef MOTOR_DRIVER_HPP
#define MOTOR_DRIVER_HPP

#include <cstdint>

// Código para controle de um motor;

#define MOTOR_PWM_FREQUENCY (2000) // frequência em Hertz PWM (conferir)
#define MOTOR_PWM_BITS \
  (13) // resolucao PWM (nao usar PWM_RESOLUTION: conflita com o core STM32)
#define MOTOR_PWM_MAX (8191) // duty maximo (2^13 - 1)

class MotorDriver {
public:
  MotorDriver(uint8_t directionPin, uint8_t pwmPin, uint8_t pwmChannel);

  // Controla a velocidade dos motores (em %)
  // sinal + frente
  // sinal - trás
  void pwmOutput(int32_t value);

  int32_t getPulse();

private:
  uint8_t directionPin_stored; // guarda o pino da direcao
  uint8_t pwmPin_stored;       // guarda o pino do PWM
  int32_t pulse_stored;        // guarda valor atual do PWM
  uint8_t pwm_channel;
};

#endif // MOTOR_DRIVER_HPP

       /* struct motorPins
       {
         uint8_t directionA;
         uint8_t pwmA;
         uint_t directionB;
         uint_t pwmB;
       }
       
       MotorPins Pin =
       {
         pino1;
         pino2;
         pino3;
         pino4;
       }
         */