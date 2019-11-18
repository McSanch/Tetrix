
  #include <PRIZM.h>
  PRIZM prizm;
  
void setup() {

  prizm.PrizmBegin();
  
  prizm.setMotorInvert(1,1);
  
  prizm.setServoSpeed(1,100);

  prizm.setServoPosition(1,0);
  

}
 
void loop() {                         //Loop this code  

if(prizm.readSonicSensorCM(3) < 25)   //If the sonic sensor reads and object less than 25cm away dont move and set the red led on 
{
  prizm.setMotorPower(0,0);
  prizm.setRedLED(HIGH);
}
else                                  //if not then just drive and do the smooth turn off of the road  
{
  prizm.setMotorPowers(25,25);
  delay(1000); 
  prizm.setServoPosition(1,90);
  delay(100);
  prizm.setRedLED(HIGH);
  delay(250);
  prizm.setRedLED(LOW);
  delay(250);
  prizm.setRedLED(HIGH);
  delay(250);
  prizm.setRedLED(LOW);
  delay(250);
  prizm.setMotorPowers(30,15);
  delay(750);
  prizm.setMotorPowers(30,30);
  delay(1000);
  prizm.setMotorPowers(15,30);
  delay(950);
  prizm.setServoPosition(1,0);
  delay(100);
  prizm.setMotorPowers(20,20);
  delay(1000);
  prizm.PrizmEnd();
}
}
 
