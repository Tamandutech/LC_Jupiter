#include "Multiplexer.hpp"

#include "Arduino.h"
#include "env.hpp"

static const uint8_t muxPins[4] = GPIO_MULTIPLEXER_DIGITAL_ADDRESS; 
static const uint8_t lineSensors[NUM_SENSORS] = GPIO_MULTIPLEXER_LINE_SENSORS_INDEX;  // canais dos sensores (0 - mux 13; 1 - mux 12/ ...)


Multiplexer::Multiplexer()
{
    for(int i = 0; i < 4; i++)
    {
        pinMode(muxPins[i], OUTPUT); // define os 4 gpios como saida
        digitalWrite(muxPins[i], LOW);
    }

    pinMode(GPIO_MULTIPLEXER_ANALOG_INPUT, INPUT); // entrada analogica 

    for(int i = 0; i < NUM_SENSORS; i++)
    {
        sensorChannels_[i] = lineSensors[i];
    }
}

// sensores do array 
void Multiplexer::selectChannel(uint8_t channel)
{
        for(int i = 0; i < 4; i ++)
        {
            digitalWrite(muxPins[i], (channel >> i) & 1); // le da direita para a esquerda um numero binario 
        }   
}

// recebe o valor do sensor 
int Multiplexer::readSensor(uint8_t sensor)
{
    if(sensor >= NUM_SENSORS)
    {
        return 0;
    }

    selectChannel(lineSensors[sensor]);
    delayMicroseconds(5);

    return analogRead(GPIO_MULTIPLEXER_ANALOG_INPUT);
}

void Multiplexer::readSensors(int sensors[NUM_SENSORS])
{
    for(int i = 0; i < NUM_SENSORS; i++)
    {
        sensors[i] = readSensor(i);
    }
}

