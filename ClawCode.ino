#include <PRIZM.h> 
PRIZM prizm;

int distance;
int distance2;
int verticalDistance;
bool isNear;

void setup() {
  prizm.PrizmBegin();
  prizm.setServoSpeed(1,100);
  prizm.setServoSpeed(2,15);
  distance = 0;
  Serial.begin(9600);
}

void openClaws() {
  prizm.setServoPosition(1,180);
}

void closeClaws() {
  prizm.setServoPosition(1,100);
}

void liftArm() {
  prizm.setServoPosition(2,50); 
}

void lowerArm() {
  prizm.setServoPosition(2,100); 
}

void setMovement(int y, int x) {
  prizm.setCRServoState(y, x);
}

void dropOffPart() {
  isNear = false;
  distance2 = prizm.readSonicSensorCM(2);
  setMovement(1, -100);
  setMovement(2, 100);
  while (isNear == false) {if (distance2 < 2) {isNear = true;} else {distance2 = prizm.readSonicSensorCM(2);}}
  setMovement(1,0);
  setMovement(2,0);
  lowerArm();
  delay(1000);
  openClaws();
}

void returnToStart() {
  isNear = false;
  liftArm();
  closeClaws();
  distance = prizm.readSonicSensorCM(4);
  Serial.print("TurnOn");
  setMovement(1, 100);
  setMovement(2, -100);
  while (isNear == false) {
    if (distance < 3) {
      isNear = true;
    }else{
      distance = prizm.readSonicSensorCM(4);
    }
  }
  setMovement(1,0);
  setMovement(2,0);
}

void loop() {
  closeClaws();
  liftArm();
  delay(2000);
  openClaws();
  delay(100);
  lowerArm();
  delay(1000);
  closeClaws();
  delay(500);
  liftArm();
  dropOffPart();
  delay(1000);
  returnToStart();
//  if (prizm.readSonicSensorCM(3) < 3) {
//    liftArm();
//    closeClaws();
//    dropOffPart();
//  }
}
