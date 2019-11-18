
  #include <PRIZM.h>    //include the PRIZM Library
  PRIZM prizm;  

bool ClawsClosed = false;

void setup() {          //this code runs once

  prizm.PrizmBegin();   //initialize PRIZM
  prizm.setMotorInvert(1,1);
  prizm.setServoPosition(2,110);
  prizm.setServoSpeed(2,100);
  
}

void loop() {           //this code repeats in a loop  
if (prizm.readSonicSensorCM(5) < 3 && ClawsClosed == false){
 closeClaws(); 
 ClawsClosed = true;
}
FollowLine();
}


void FollowLine() {
if (prizm.readLineSensor(3) == LOW) {prizm.setMotorPowers(12,25); prizm.setRedLED(LOW);}

if (prizm.readLineSensor(3) == HIGH) {prizm.setMotorPowers(25,12); prizm.setRedLED(HIGH);}

 }

 void closeClaws(){
  prizm.setServoPosition(2,72);
 }
