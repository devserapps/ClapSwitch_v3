#define CLAP_RANGE 1000
#define SOUND_PIN 6
#define NUM_DEVICES 4

#include "Device.h"

Device devices[] = {
  Device(2, "Fan", 2),
  Device(3, "Bulb 1", 3),
  Device(4, "Bulb 2", 4),
  Device(5, "Lamp", 5)
};

void setup() {
  for (uint8_t i = 0; i < NUM_DEVICES; i++) {
    pinMode(devices[i].getPin(), OUTPUT);
  }
  pinMode(SOUND_PIN, INPUT);
}

uint8_t count = 0;
unsigned long lastClapMillis = 0;

void loop() {
  if (millis() - lastClapMillis > CLAP_RANGE) {
    if (count >= minNeedClaps()) {
      for (uint8_t i = 0; i < NUM_DEVICES; i++) {
        if (devices[i].getNeedClaps() == count) {
          const uint8_t pin = devices[i].getPin();
          digitalWrite(pin, !digitalRead(pin));
          break;
        }
      }
    }
    count = 0;
  }

  if (digitalRead(SOUND_PIN)) {
    count += 1;
    lastClapMillis = millis();
    delay(250);
  }
}

uint8_t minNeedClaps() {
  uint8_t min = 0;
  for (uint8_t i = 0; i < NUM_DEVICES; i++) {
    if (min > devices[i].getNeedClaps()) {
      min = devices[i].getNeedClaps();
    }
  }
}
