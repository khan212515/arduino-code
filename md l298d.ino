
#define l1s 4
#define l1d 8


void setup() {
  pinMode(l1s, OUTPUT);
  pinMode(l1d, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
 
  digitalWrite(l1s,255);
  digitalWrite(l1d,LOW);

delay(3000);

  digitalWrite(l1s,255);
  digitalWrite(l1d,HIGH);
}
