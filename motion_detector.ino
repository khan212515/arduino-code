int pinSensor =2;
int pinBuzzer =6;
int pirSensor =0;
  
void setup()
{
  pinMode(pinSensor,   INPUT);
  pinMode(pinBuzzer, OUTPUT);
  
}

void loop()
{
  
  pirSensor = digitalRead(pinSensor);
  if (pirSensor == HIGH)
  {
    
    tone(pinBuzzer, 3000, 500);
    
  }
  else {
  
  }
  
  delay(5000);
}
