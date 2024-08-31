

#include <ArduinoBLE.h>

// randomly generated UUIDs
const char * serviceUUID = "5ac1d00e-1ce6-4e53-b904-0822cd136d05";
const char * characteristicUUID = "43ada7f1-7ec0-4e14-a4af-920859b5a9e5";
const char * myName = "DataProvider";

const int payloadSize = 15;         // max payload size for BLE
char payload[payloadSize] = "";     // start with empty string

BLEService dataService(serviceUUID);
BLECharacteristic dataCharacteristic(characteristicUUID, BLERead | BLENotify, payloadSize + 1); // remote clients will be able to get notifications if this characteristic changes

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected

  Serial.begin(115200); while (!Serial);

  if (!BLE.begin()) {
    Serial.println(F("starting BLE failed!"));
    while (true) yield();
  }

  dataCharacteristic.writeValue((const char*) payload, strlen(payload));   // set the initial value for the characeristic
  dataService.addCharacteristic(dataCharacteristic);    // add the characteristic to the service

  BLE.setLocalName(myName);                             // set advertised local name
  BLE.addService(dataService);                          // Add the data service
  BLE.setAdvertisedService(dataService);                // set advertised service UUID
  BLE.advertise();                                      // start advertising
  Serial.println(F("Ready to serve!"));
}

void loop() {
  static uint32_t previousMillis = 0;

  BLEDevice central = BLE.central();
  if (central) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Connected to central: "); Serial.println(central.address());

    while (central.connected()) {
      uint32_t currentMillis = millis();
      if (currentMillis - previousMillis >= 10) { // update every 10ms
        snprintf(payload, payloadSize, "%6.2f s", millis() / 1000.0);
        dataCharacteristic.writeValue((const char*) payload, strlen(payload));
        previousMillis = currentMillis;
      }
    }
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Disconnected from central");
  }
}