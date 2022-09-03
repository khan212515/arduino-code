#include <LiquidCrystal.h> 
LiquidCrystal lcd(1,2,4,5,6,7); 
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
void setup() {
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(10,OUTPUT);
  
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  lcd.setCursor(0, 0); 
  lcd.print("Distance: "); 
  lcd.print(distanceCm); 
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");

  
  lcd.print(distanceInch);
  
    
    
  
  lcd.print(" inch");
  delay(10);

if(distanceInch==8){
  
  digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }
 
}
