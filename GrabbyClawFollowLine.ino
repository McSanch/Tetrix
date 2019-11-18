
  #include <PRIZM.h>    //include the PRIZM Library
  PRIZM prizm;  

bool ClawsClosed = false; //set the bool "ClawsClosed" to false

void setup() {          //this code runs once

  prizm.PrizmBegin();   //initialize PRIZM
  prizm.setMotorInvert(1,1); //invert the right or left wheel
  prizm.setServoPosition(2,110); //set the sencond servo position to 110
  prizm.setServoSpeed(2,100); // set the second servos speed to 100%
  
}

void loop() {           //this code repeats in a loop  
if (prizm.readSonicSensorCM(5) < 3 && ClawsClosed == false){ //if the distance is less than 3 cm and clawsClosed is flase 
 closeClaws();  // Do "closeClaws"
 ClawsClosed = true; //Set ClawsClosed to true
}
FollowLine(); //  Do "FollowLine"
}


void FollowLine() { //Follow the line by doing slow turns and go the other way when it sees the line
if (prizm.readLineSensor(3) == LOW) {prizm.setMotorPowers(12,25); prizm.setRedLED(LOW);}  //If it doesnt sense a line slowly turn right

if (prizm.readLineSensor(3) == HIGH) {prizm.setMotorPowers(25,12); prizm.setRedLED(HIGH);}  //If it does sense a line slowly turn right

 }

 void closeClaws(){ //Close the claws or "Grabber"
  prizm.setServoPosition(2,72); // set the second servos position to 72
 }-+
