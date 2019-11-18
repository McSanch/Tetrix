#include <PRIZM.h>
#include <TELEOP.h>
PRIZM prizm;
PS4 ps4; 

int PowerM1;
int PowerM2;

void setup() {

  prizm.PrizmBegin();
  ps4.setDeadZone (LEFT,15);
  ps4.setDeadZone(RIGHT,15);
  prizm.setMotorInvert(1,1);
  prizm.setServoPosition(2,100);
  prizm.setServoPosition(1,180);
  Serial.begin(115200);
}

void loop() {
  ps4.getPS4();
  
  if(ps4.Connected){
      PowerM1 = ps4.Motor(LY);
      PowerM2 = ps4.Motor(RY);
      prizm.setMotorPowers(PowerM1, PowerM2);

} else {
  prizm.setMotorPowers(0,0);
  }
  
  if (ps4.Button(R2) == true) {
    prizm.setServoPosition(2,72);
  }

  if (ps4.Button(L2) == true) {
    prizm.setServoPosition(2,100);
  }
  if (ps4.Button(R1) == true) {
    prizm.setServoPosition(1,180);
  }

  if (ps4.Button(L1) == true) {
    prizm.setServoPosition(1,0);
  }
 
  if (prizm.readSonicSensorCM(4) < 20) {
  ps4.setRumble(SLOW);
  prizm.setRedLED(HIGH);
  } else {
    ps4.setRumble(STOP);
    prizm.setRedLED(LOW);
  }
  
}
