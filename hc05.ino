char input = 0;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
    {
      input = Serial.read();
      Serial.print(input);
      Serial.print("/n");
      if (input == '1')
        digitalWrite(LED_BUILTIN,HIGH);
      else if(input == '0')
        digitalWrite(LED_BUILTIN,LOW);
    }
}
