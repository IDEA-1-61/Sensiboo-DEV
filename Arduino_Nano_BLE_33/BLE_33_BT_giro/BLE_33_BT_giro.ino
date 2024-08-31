

#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

float x, y, z;
int degreesX = 0;
int degreesY = 0;

BLEService gyroService("180F");
BLEFloatCharacteristic gyroXChar("2A5B", BLERead | BLENotify);
BLEFloatCharacteristic gyroYChar("2A5C", BLERead | BLENotify);
BLEFloatCharacteristic gyroZChar("2A5D", BLERead | BLENotify);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  BLE.setLocalName("GyroMonitor");
  BLE.setAdvertisedService(gyroService);
  gyroService.addCharacteristic(gyroXChar);
  gyroService.addCharacteristic(gyroYChar);
  gyroService.addCharacteristic(gyroZChar);
  BLE.addService(gyroService);

  BLE.advertise();
  Serial.println("Bluetooth device active, waiting for connections...");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  BLEDevice central = BLE.central();

  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    while (central.connected()) {
      if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(x, y, z);
        gyroXChar.writeValue(x);
        gyroYChar.writeValue(y);
        gyroZChar.writeValue(z);
      }
      delay(200);
    }
  }
}


