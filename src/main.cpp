// Framework
#include "Arduino.h"

// Env
#include "env.hpp"

// Drivers
#include "LineControl/LineControl.hpp"
#include "drivers/Bluetooth/Bluetooth.hpp"
#include "drivers/MotorDriver/MotorDriver.hpp"
#include "drivers/Multiplexer/Multiplexer.hpp"

// __________________________________________________________________

MotorDriver motorLeft(GPIO_DIRECTION_A, GPIO_PWM_A, PWM_CHANNEL_MOTOR_A);
MotorDriver motorRight(GPIO_DIRECTION_B, GPIO_PWM_B, PWM_CHANNEL_MOTOR_B);
Multiplexer multiplexer;

enum class RobotState { STOPPED, RUNNING };
RobotState robotState = RobotState::STOPPED;

// armazena leitura dos sensores[]
int sensorReadings[NUM_SENSORS];

// valor maximo e minimo de calibracao dos sensores
int calibrationMin[NUM_SENSORS];
int calibrationMax[NUM_SENSORS];

int normalizedReadings[NUM_SENSORS];

// __________________________________________________________________

void setup() {
  Serial.begin(115200);

  for(int i = 0; i < NUM_SENSORS; i++) {
    sensorReadings[i]     = 0;
    calibrationMin[i]     = 0;
    calibrationMax[i]     = 0;
    normalizedReadings[i] = 0;
  };

  bluetoothSetup();

  Serial.println("Setup finalizado.");
}

void changePID(int values[NUM_SENSORS]) {}

// void calibration() {

//   for(int i = 0; i < NUM_SENSORS; i++) {
//     calibrationMin[i] =
//         4095; // Comeca o min com o maior valor possivel para ir diminuindo
//     calibrationMax[i] = 0; // O contrario do min
//   }

//   for(int j = 0; j < NUM_CALIBRATION; j++) {

//     multiplexer.readSensors(sensorReadings);

//     for(int i = 0; i < NUM_SENSORS; i++) {
//       if(sensorReadings[i] < calibrationMin[i]) {
//         calibrationMin[i] = sensorReadings[i];
//       }
//       if(sensorReadings[i] > calibrationMax[i]) {
//         calibrationMax[i] = sensorReadings[i];
//       }
//     }

//     delay(100);
//   }
// }


// faz o motor funfar
void applyMotorSpeeds(float PDCorrection) {
  int left_motorSpeed  = BASE_MOTOR_SPEED - (int)PDCorrection;
  int right_motorSpeed = BASE_MOTOR_SPEED + (int)PDCorrection;

  motorLeft.pwmOutput(left_motorSpeed);
  motorRight.pwmOutput(right_motorSpeed);
}


void loop() {

  // bluetoothLoop();

  if(NuSerial.isConnected()) {

    while(NuSerial.available()) {
      int serialMonitorChar = NuSerial.read();

      if(serialMonitorChar == '1') {
        // executar código de andar ou parar
        // fora do loop principal
        robotState = RobotState::RUNNING;

        NuSerial.println("Anda");
      } else if(serialMonitorChar == '0') {
        motorLeft.pwmOutput(0);
        motorRight.pwmOutput(0);
        robotState = RobotState::STOPPED;

        NuSerial.println("Para");
      } else if(serialMonitorChar == '2') {
        // calibration();
        NuSerial.println("Calibração Completa");
      }
    }
  }

  if(robotState == RobotState::RUNNING) {
    multiplexer.readSensors(sensorReadings); // le todos os 12 sensores;

    // for(int k = 0; k < NUM_SENSORS; k++)
    //   normalizedReadings[k] =
    //       normalize(sensorReadings[k], calibrationMin[k], calibrationMax[k]);

    for(int i = 0; i < NUM_SENSORS; i++) {
      Serial.print("i: ");
      Serial.print(
          normalize(sensorReadings[i], calibrationMin[i], calibrationMax[i]));
      Serial.print("; ");
    }
    Serial.println();

    // NuSerial.println(calibrationMin[0]);
    // NuSerial.println(calibrationMax[0]);
    // normalizedReadings[0] =
    //     normalize(sensorReadings[0], calibrationMin[0], calibrationMax[0]);

    //   float PDcorrection = calculatePID(normalizedReadings); // calcula o PD
    //   applyMotorSpeeds(PDcorrection);
  }
}
