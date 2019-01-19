#include <M5Stack.h>

#define LIGHT_SENSOR 35

int brightness;

void setup() {
  M5.begin();
  pinMode(LIGHT_SENSOR, INPUT);
}

void loop() {
  brightness = analogRead(LIGHT_SENSOR)/4;
  M5.Lcd.setBrightness(brightness);
}
