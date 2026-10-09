#include "Arduino.h"
#include "env.hpp"

#include "LineControl.hpp"

static float lastError = 0.0f;

int normalize(int sensorReadings, int calMin, int calMax) {
  if(calMax <= calMin) return 0;

  int num = (sensorReadings - calMin) * 1000 / (calMax - calMin);

  if(num > 1000) num = 1000;

  if(num < 0) num = 0;

  return num;
}


float calculateError(int values[NUM_SENSORS]) {
  // média ponderada
  float sum         = 0.0f;
  float weightedSum = 0.0f;
  float weight      = 0.0f;

  for(int i = 0; i < NUM_SENSORS; i++) {
    // peso atribuido a cada sensor ( +5.5 a - 5.5 )
    // weight = (i - (NUM_SENSORS - 1) / 2.0f);

    // 0 - branco/ 1000 - preto
    if(values[i] >
       200) // Threshold detecção de linha (não sei que valor eh bom)
    {
      weightedSum += values[i] * (i * 10);
      sum += values[i];
    }
  }

  // positivo - linha a direia
  // negativo - linha a esquerda
  // if(sum > 0) {
  //   lastError = weightedSum / sum;
  //   return lastError;
  // }
}

float calculatePID(int values[NUM_SENSORS], float kp, float kd) {
  float currentError = calculateError(values);

  float derivativeError = currentError - lastError;

  lastError = currentError;

  return (kp * currentError) + (kp * derivativeError);
}
