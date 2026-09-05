#include <Arduino.h>

#include "NimBLEDevice.h"
#include "NuSerial.hpp"

void bluetoothSetup() {
#define DEVICE_NAME "TT_JUPITER"

  Serial.begin(115200);

  NimBLEDevice::init(DEVICE_NAME);                      // inicializa bluetooth
  NimBLEDevice::getAdvertising()->setName(DEVICE_NAME); // mostra bluetooth
  NuSerial.begin(115200); // inicialza serial bluetooth na velocidade (X)
}

void bluetoothLoop() {
  // NimBLEServer *pServer = NimBLEDevice::getServer();

  /*
  if(NuSerial.isConnected()) {
    NuSerial.write((int)"A");
  }
    */
}