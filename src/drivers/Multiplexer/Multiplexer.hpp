#ifndef MULTIPLEXER_HPP // se nao esta definido
#define MULTIPLEXER_HPP // define

#include "env.hpp"

#include <cstdint>


// classe responsável pela comunicacao com o multiplexer

class Multiplexer {
public:
  Multiplexer();                  // construor

  int readSensor(uint8_t sensor); // le um sensor e devolve valor lido

  void readSensors(int sensors[NUM_SENSORS]); // le todos os sensores

private:
  void selectChannel(uint8_t channel); // selecion o canal desejado
};

#endif
