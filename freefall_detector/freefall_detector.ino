#include <M5Stack.h>
#include "utility/MPU9250.h"
#include "Math.h"

MPU9250 IMU;

float acc_magnitude = 0;

void setup() {
  M5.begin();

  //Initialize the MPU
  Wire.begin();
  IMU.MPU9250SelfTest(IMU.SelfTest);
  IMU.calibrateMPU9250(IMU.gyroBias, IMU.accelBias);
  IMU.initMPU9250();  
}


//Read the acceleration data from the MPU
void updateIMU() {
  if (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
    IMU.readAccelData(IMU.accelCount);
    IMU.getAres();
    IMU.ax = (float)IMU.accelCount[0] * IMU.aRes;
    IMU.ay = (float)IMU.accelCount[1] * IMU.aRes;
    IMU.az = (float)IMU.accelCount[2] * IMU.aRes;
  }
}

void loop() {
  updateIMU();
  M5.update();

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10,10);
  M5.Lcd.print(IMU.ax);
  M5.Lcd.setCursor(10,40);
  M5.Lcd.print(IMU.ay);
  M5.Lcd.setCursor(10,70);
  M5.Lcd.print(IMU.az);

  acc_magnitude = sqrt(sq(IMU.ax) + sq(IMU.ay) + sq(IMU.az));

  if (acc_magnitude < 0.3) {
    M5.Lcd.fillScreen(RED);
  } else if (acc_magnitude > 1.5) {
    M5.Lcd.fillScreen(BLUE);
  } else {
    M5.Lcd.fillScreen(BLACK);
  }

}
