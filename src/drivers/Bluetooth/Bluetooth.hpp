#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

#include <Arduino.h>

// O G474 nao tem radio BLE. NuSerial vira um alias da Serial USB
// (ST-Link VCP no Nucleo) para manter o mesmo protocolo 0/1/2 do main.
// Se no futuro houver um modulo BLE por UART, troque Serial por Serial1.
struct Stm32SerialBridge {
  void   begin(unsigned long baud) { Serial.begin(baud); }
  bool   isConnected() const { return true; }
  int    available() { return Serial.available(); }
  int    read() { return Serial.read(); }
  size_t write(uint8_t value) { return Serial.write(value); }

  template <typename T> size_t println(const T &value) {
    return Serial.println(value);
  }
};

extern Stm32SerialBridge NuSerial;

void bluetoothSetup();
void bluetoothLoop();

#endif
