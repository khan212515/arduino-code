#include<LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);






void setup() {
  // put your setup code here, to run once:
    lcd.begin(16,2);
    pinMode(10,INPUT);
    pinMode(12,OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalRead(10);
   if(digitalRead(10)==1){
    
    lcd.setCursor(4,0);
    lcd.print("NO SIGNAL");
     
    delay(300);
     lcd.clear();
     delay(300);
   }
   else if (digitalRead(10)==0){
    lcd.setCursor(3,1);
    lcd.print("IR DETECTED");
    digitalWrite(12,HIGH);
    delay(300);
    lcd.clear();
     delay(300);
    
   }
   
    
}
