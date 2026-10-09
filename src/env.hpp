#ifndef ENV_HPP
#define ENV_HPP

#define GPIO_LED_DEBUG (47)
#define NUM_LEDS_DEBUG (4)

#define GPIO_BATTERY_VOLTAGE (18)

// número de sensores
#define NUM_SENSORS (12)

// número de vezes que o sensor calibra
#define NUM_CALIBRATION (60)

#define BASE_MOTOR_SPEED (1000) // velocidade base dos motores (0 - 8191)

#define PWM_CHANNEL_MOTOR_A (0)
#define PWM_CHANNEL_MOTOR_B (1)

// MOTOR ESQUERDO
#define GPIO_DIRECTION_A (9) // pino direção
#define GPIO_PWM_A       (3) // pino pwm

// MOTOR DIREITO
#define GPIO_DIRECTION_B (37) // pino direção
#define GPIO_PWM_B       (38) // pino pwm

// MOTOR SUCÇÃO
#define GPIO_PWM_VACUUM (11)

// ENCODER (nem olhei ainda)
#define GPIO_ENCODER_LEFT_A  (7)
#define GPIO_ENCODER_LEFT_B  (6)
#define GPIO_ENCODER_RIGHT_A (12)
#define GPIO_ENCODER_RIGHT_B (13)

// MULTIPLEXER
#define GPIO_MULTIPLEXER_DIGITAL_ADDRESS \
  {39, 40, 41, 42} // pinos de selecao do mux (mux 0, 1, 2, 3)
#define GPIO_MULTIPLEXER_ANALOG_INPUT \
  (10)             // Entrada analogica dos sensores (outmux)
#define GPIO_MULTIPLEXER_LINE_SENSORS_INDEX \
  {13, 12, 11, 10, 9, 8, 5, 4, 3, 2, 1, 0} // Sensores
#define GPIO_MULTIPLEXER_SIDE_SENSORS_INDEX {15, 14, 6, 7}

#endif // ENV_HPP