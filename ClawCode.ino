#include <PRIZM.h> 
PRIZM prizm;

int distance;
int distance2;
int verticalDistance;
bool isNear;

void setup() {
  prizm.PrizmBegin();
  prizm.setServoSpeed(1,100);
  prizm.setServoSpeed(2,355);|
  distance = 0;
  Serial.begin(9600);
}

void openClaws() {
  prizm.setServoPosition(1,180);
}

void closeClaws() {
  prizm.setServoPosition(1,100);
}

void moveArm(int a) {
  prizm.setServoPosition(2,a); 
}

void setMovement(int y, int x) {
  prizm.setCRServoState(y, x);
}

void dropOffPart() {
  isNear = false;
  distance2 = prizm.readSonicSensorCM(2);
  setMovement(1, -100);
  setMovement(2, 100);
  while (isNear == false) {if (distance2 < 1) {isNear = true;} else {distance2 = prizm.readSonicSensorCM(2);}}
  setMovement(1,0);
  setMovement(2,0);
  moveArm(120);
  delay(2000);
  openClaws();
}

//lift 50
//lower 100
void returnToStart() {
  isNear = false;
  moveArm(50);
  delay(500);
  closeClaws();
  distance = prizm.readSonicSensorCM(4);
  setMovement(1, 100);
  setMovement(2, -100);
  while (isNear == false) {
    if (distance < 1) {
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
  moveArm(50);
  delay(2000);
  openClaws();
  delay(100);
  moveArm(100);
  delay(1000);
  closeClaws();
  delay(500);
  moveArm(50);
  dropOffPart();
  moveArm(50);
  delay(2000);
  returnToStart();
//  if (prizm.readSonicSensorCM(3) < 3) {
//    liftArm();
//    closeClaws();
//    dropOffPart();
//  }
}
