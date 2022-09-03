#define r1s 6
#define l2s 7
#define l1s 4
#define r2s 9
#define r1d 2
#define l2d 3
#define l1d 8
#define r2d 5 

//x box code

#include <XBOXONESBT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
BTD Btd(&Usb); 
XBOXONESBT Xbox(&Btd, PAIR);



void setup() {
  pinMode(r1s, OUTPUT);
  pinMode(l2s, OUTPUT);
  pinMode(l1s, OUTPUT);
  pinMode(r2s, OUTPUT);
  pinMode(r1d, OUTPUT);
  pinMode(l2d, OUTPUT);
  pinMode(l1d, OUTPUT);
  pinMode(r2d, OUTPUT);


//  xbox

   Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); 
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox One S Bluetooth Library Started"));
  }

void loop() {
//  Xbox

   Usb.Task();

  if (Xbox.connected()) {
    if (Xbox.getAnalogHat(ljx) > 7500 || Xbox.getAnalogHat(ljx) < -7500 || Xbox.getAnalogHat(ljy) > 7500 || Xbox.getAnalogHat(ljy) < -7500 || Xbox.getAnalogHat(rjx) > 7500 || Xbox.getAnalogHat(rjx) < -7500 || Xbox.getAnalogHat(rjy) > 7500 || Xbox.getAnalogHat(rjy) < -7500) {
      if (Xbox.getAnalogHat(ljx) > 7500 || Xbox.getAnalogHat(ljx) < -7500) {
        Serial.print(F("ljx: "));
        Serial.print(Xbox.getAnalogHat(ljx));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(ljy) > 7500 || Xbox.getAnalogHat(ljy) < -7500) {
        Serial.print(F("ljy: "));
        Serial.print(Xbox.getAnalogHat(ljy));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(rjx) > 7500 || Xbox.getAnalogHat(rjx) < -7500) {
        Serial.print(F("rjx: "));
        Serial.print(Xbox.getAnalogHat(rjx));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(rjy) > 7500 || Xbox.getAnalogHat(rjy) < -7500) {
        Serial.print(F("rjy: "));
        Serial.print(Xbox.getAnalogHat(rjy));
      }
      Serial.println();
    }

    if (Xbox.getButtonPress(LT) > 0 || Xbox.getButtonPress(RT) > 0) {
      if (Xbox.getButtonPress(LT) > 0) {
        Serial.print(F("LT: "));
        Serial.print(Xbox.getButtonPress(LT));
        Serial.print("\t");
      }
      if (Xbox.getButtonPress(RT) > 0) {
        Serial.print(F("RT: "));
        Serial.print(Xbox.getButtonPress(RT));
        Serial.print("\t");
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
}

//  conditions

if()

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
  analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}
void backward(){
  analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,LOW);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
}
void left(){
  analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,LOW);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}
  
void right(){
   analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
  
  
 
  
}
void d_right_b(){
   analogWrite(r1s,100);
  analogWrite(l2s,0);
  analogWrite(l1s,0);
  analogWrite(r2s,100);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,LOW);
}

void d_right_f(){
   analogWrite(r1s,100);
  analogWrite(l2s,1);
  analogWrite(l1s,0);
  analogWrite(r2s,100);
    digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r1d,HIGH);
  digitalWrite(r2d,HIGH);
}

void d_left_b(){
analogWrite(r1s,0);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,0);

  
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
}

void d_left_f(){
analogWrite(r1s,0);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,0);

  
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,HIGH);
}

void linearright(){
   
 analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,HIGH);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,LOW);
  digitalWrite(r2d,LOW);
  
}
void linearleft(){
   analogWrite(r1s,100);
  analogWrite(l2s,100);
  analogWrite(l1s,100);
  analogWrite(r2s,100);

  digitalWrite(r1d,LOW);
  digitalWrite(l2d,HIGH);
  digitalWrite(l1d,HIGH);
  digitalWrite(r2d,LOW);
  
}
