#define r1s 6
#define l2s 7
#define l1s 4
#define r2s 9
#define r1d 2
#define l2d 3
#define l1d 8
#define r2d 5 
#include <XBOXONESBT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
 int LeftTS;
    int RightTS;
USB Usb;
BTD Btd(&Usb);
XBOXONESBT Xbox(&Btd, PAIR);


void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); 
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox One S Bluetooth Library Started"));

  
  pinMode(r1s, OUTPUT);
  pinMode(l2s, OUTPUT);
  pinMode(l1s, OUTPUT);
  pinMode(r2s, OUTPUT);
  pinMode(r1d, OUTPUT);
  pinMode(l2d, OUTPUT);
  pinMode(l1d, OUTPUT);
  pinMode(r2d, OUTPUT);
}
void loop() {
  Usb.Task();

  if (Xbox.connected()) {
    if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500 || Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500 || Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500 || Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
      if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500) {
        Serial.print(F("LeftHatX: "));
        Serial.print(Xbox.getAnalogHat(LeftHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {
        Serial.print(F("LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500) {
        Serial.print(F("RightHatX: "));
        Serial.print(Xbox.getAnalogHat(RightHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
        Serial.print(F("RightHatY: "));
        Serial.print(Xbox.getAnalogHat(RightHatY));
      }
      Serial.println();
    }

    if (Xbox.getButtonPress(LT) > 0 || Xbox.getButtonPress(RT) > 0) {
      if (Xbox.getButtonPress(LT) > 0) {
        Serial.print(F("LT: "));
        Serial.print(Xbox.getButtonPress(LT));
        Serial.print("\t");
        LeftTS= Xbox.getButtonPress(LT)/4;
        Serial.print(LeftTS);
      }
      if (Xbox.getButtonPress(RT) > 0) {
        Serial.print(F("RT: "));
        Serial.print(Xbox.getButtonPress(RT));
        Serial.print("\t");
        RightTS= Xbox.getButtonPress(RT)/4;
        Serial.print(RightTS);
      }
      Serial.println();
    }
 
    // Set rumble effect
    static uint16_t oldLTValue, oldRTValue;
    if (Xbox.getButtonPress(LT) != oldLTValue || Xbox.getButtonPress(RT) != oldRTValue) {
      oldLTValue = Xbox.getButtonPress(LT);
      oldRTValue = Xbox.getButtonPress(RT);
      uint8_t leftRumble = map(oldLTValue, 0, 1023, 0, 255); // Map the trigger values into a byte
      uint8_t rightRumble = map(oldRTValue, 0, 1023, 0, 255);
      if (leftRumble > 0 || rightRumble > 0)
        Xbox.setRumbleOn(leftRumble, rightRumble, leftRumble, rightRumble);
      else
        Xbox.setRumbleOff();
    }
    
   
    if (Xbox.getButtonClick(UP))
      Serial.println(F("Up"));
    if (Xbox.getButtonClick(DOWN))
      Serial.println(F("Down"));
    if (Xbox.getButtonClick(LEFT))
      Serial.println(F("Left"));
    if (Xbox.getButtonClick(RIGHT))
      Serial.println(F("Right"));

    if (Xbox.getButtonClick(VIEW))
      Serial.println(F("View"));
    if (Xbox.getButtonClick(MENU))
      Serial.println(F("Menu"));
    if (Xbox.getButtonClick(XBOX)) {
      Serial.println(F("Xbox"));
      Xbox.disconnect();
    }

    if (Xbox.getButtonClick(LB))
      Serial.println(F("LB"));
    if (Xbox.getButtonClick(RB))
      Serial.println(F("RB"));
    if (Xbox.getButtonClick(LT))
      Serial.println(F("LT"));
    if (Xbox.getButtonClick(RT))
      Serial.println(F("RT"));
    if (Xbox.getButtonClick(L3))
      Serial.println(F("L3"));
    if (Xbox.getButtonClick(R3))
      Serial.println(F("R3"));

    if (Xbox.getButtonClick(A))
      Serial.println(F("A"));
    if (Xbox.getButtonClick(B))
      Serial.println(F("B"));
    if (Xbox.getButtonClick(X))
      Serial.println(F("X"));
    if (Xbox.getButtonClick(Y))
      Serial.println(F("Y"));
  }


  
if (LeftHatY<=-30000){
  forward();
}

else if (LeftHatY>=30000){
  backward();
}

else if (LeftHatX<=-30000){
  StrafeLeft();
}
else if (LeftHatX>=30000){
  StrafeRight();
}

else if (LeftHatX>=20000 && LeftHatY<=-23000){
  d_right_f();
}

else if (LeftHatX>=23000 && LeftHatY<=-23000){
  d_left_b();
}
else if (LeftHatX<=-24000 && LeftHatY<=-24000){
  d_left_f();
}
else if (LeftHatX>=19000 && LeftHatY>=25000){
  d_right_b();
}

else if (RightHatX>=23000){
  right();
  Serial.print("right");
}

else if (RightHatX<=-23000){
  left();
  Serial.print("left");
}

}



void stop(){
  
  analogWrite(r1s,0);
  analogWrite(l2s,0);
  analogWrite(l1s,0);
  analogWrite(r2s,0);
  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
  
}
void forward(){
  analogWrite(r1s,RightTS);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,RightTS);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}
void backward(){
  analogWrite(r1s,RightTS);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,RightTS);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,LOW);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
}
void left(){
  analogWrite(r1s,LeftTS);
  analogWrite(l2s,LeftTS);
  analogWrite(l1s,LeftTS);
  analogWrite(r2s,LeftTS);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,LOW);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}
  
void right(){
   analogWrite(r1s,LeftTS);
  analogWrite(l2s,LeftTS);
  analogWrite(l1s,LeftTS);
  analogWrite(r2s,LeftTS);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
  
  
 
  
}
void d_right_b(){
   analogWrite(r1s,RightTS);
  analogWrite(l2s,0);
  analogWrite(l1s,0);
  analogWrite(r2s,RightTS);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,LOW);
}

void d_right_f(){
   analogWrite(r1s,RightTS);
  analogWrite(l2s,1);
  analogWrite(l1s,0);
  analogWrite(r2s,RightTS);
    digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r1d,HIGH);
  digitalWrite(r2d,HIGH);
}

void d_left_b(){
analogWrite(r1s,0);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,0);

  
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
}

void d_left_f(){
analogWrite(r1s,0);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,0);

  
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}

void StrafeRight(){
   
 analogWrite(r1s,RightTS);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,RightTS);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
  
}
void StrafeLeft(){
   analogWrite(r1s,RightTS);
  analogWrite(l2s,RightTS);
  analogWrite(l1s,RightTS);
  analogWrite(r2s,RightTS);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,LOW);
  
}
