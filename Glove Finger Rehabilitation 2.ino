#include <Servo.h>
Servo servo1,servo2,servo3,servo4,servo5;
int reading;
int mapVal;
int i;
int delay1 =100;
int minServo =-200;
int maxServo = 880;
int minSFlex=100;
int maxSFlex=520;
int minBFlex=20;
int maxBFlex=1020;
void setup(){
  servo1.attach(6);
  servo2.attach(10);
  servo3.attach(9);
  servo4.attach(11);
  servo5.attach(5);
}
void loop(){
  reading= analogRead(0);
  mapVal= map(reading,minSFlex,maxSFlex,minServo,maxServo);
  if(mapVal<minServo) mapVal=minServo;
  if(mapVal>maxServo)mapVal=maxServo;
  servo1.write(mapVal);
  delay(delay1);
  
}
