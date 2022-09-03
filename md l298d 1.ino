
#define IN1 9
#define IN2 6
#define IN3 5
#define IN4 3
#define EnA 10
#define EnB 11
#define Speed1 65
#define Speed2 58
#define Speed3 40




void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
}

void loop() {
   //forward 1
    analogWrite(EnA,Speed1);
    analogWrite(EnB,Speed1);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    delay(1000); 
    
    //Stop
    analogWrite(EnA,0);
    analogWrite(EnB,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    delay(1000);

    
    //right. 3
   
    analogWrite(EnA,Speed2);
    analogWrite(EnB,55);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
       
     delay(1000);

     //Stop
    analogWrite(EnA,0);
    analogWrite(EnB,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    delay(1000);
    
    //right backwards.
     analogWrite(EnA,50);
    analogWrite(EnB,70);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
     delay(1000);

     //Stop
    analogWrite(EnA,0);
    analogWrite(EnB,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    delay(1000);
} 
