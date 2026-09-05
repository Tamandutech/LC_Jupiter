#ifndef LINE_CONTROL_HPP
#define LINE_CONTROL_HPP

#include "env.hpp"

#define KP (0.00f)
#define KD (0.00f)

int normalize(int sensorReadings, int calMin, int calMax);

float calculateError(int values[NUM_SENSORS]);
float calculatePID(int values[NUM_SENSORS]);

#endif