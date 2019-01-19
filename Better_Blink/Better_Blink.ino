#include <M5Stack.h>

#define LED_PIN 2
#define LED_BLINK_TIME 500
#define SCREEN_BLINK_TIME 200

bool ledOnOrOff = LOW;
bool ledState = LOW;
bool screenState = LOW;
unsigned long currentTime;
unsigned long nextLEDBlinkTime;
unsigned long nextScreenBlinkTime;

void setup() {
  M5.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  M5.update();
  
  /*READ INPUTS*/
  currentTime = millis();   //number of milliseconds since the program started running
  if (M5.BtnA.wasPressed()) {
    ledOnOrOff = !ledOnOrOff;
  }

  /*UPDATE STATE*/
  if (currentTime >= nextLEDBlinkTime) {
    nextLEDBlinkTime = currentTime + LED_BLINK_TIME;
    ledState = !ledState;
  }
  if (currentTime >= nextScreenBlinkTime) {
    nextScreenBlinkTime = currentTime + SCREEN_BLINK_TIME;
    screenState = !screenState;
  }

  /*SET OUTPUTS*/
  if (ledOnOrOff) {
    digitalWrite(LED_PIN, ledState);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  if (screenState) {
    M5.Lcd.fillScreen(RED);
  } else {
    M5.Lcd.fillScreen(BLUE);
  }
}
