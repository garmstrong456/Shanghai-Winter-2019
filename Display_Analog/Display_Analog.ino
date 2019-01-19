#include <M5Stack.h>

#define LIGHT_SENSOR 35

void setup() {
  M5.begin();

  pinMode(LIGHT_SENSOR, INPUT);
}

void loop() {
  M5.Lcd.setCursor(120, 120);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(analogRead(LIGHT_SENSOR));
}
