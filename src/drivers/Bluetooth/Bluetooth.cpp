#include "Bluetooth.hpp"

Stm32SerialBridge NuSerial;

void bluetoothSetup() { NuSerial.begin(115200); }

void bluetoothLoop() {}
