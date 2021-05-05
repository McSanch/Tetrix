#include <PRIZM.h> 
PRIZM prizm;

int distance;
int closeSize;
int closeSpeed;

void setup() {
  prizm.PrizmBegin();
  prizm.setServoSpeed(1,100);
  distance = 50;
}

void openClaws() {
  prizm.setServoPosition(1,180);
}

void closeClaws() {
  prizm.setServoPosition(1,115);
}

void loop() {
  distance = prizm.readSonicSensorCM(2);
  closeSize = map(distance, 0, 25, 70, 180);
  closeSpeed = map(distance, 0, 25, 0, 100);
  if (distance < 26) {prizm.setServoPosition(1, closeSize); prizm.setServoSpeed(1,closeSpeed);};
}
