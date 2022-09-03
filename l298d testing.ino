#define IN1 9
#define IN2 6
#define IN3 5
#define IN4 3
#define EnA 10
#define EnB 11
#define Speed1 65
#define Speed2 53
#define Speed3 40


void setup() {  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void forward(){
  analogWrite(EnA,Speed1);
  analogWrite(EnB,Speed1);
}

void wait(){
    analogWrite(EnA,0);
    analogWrite(EnB,0);
}

void right(){
    analogWrite(EnA,45);
    analogWrite(EnB,62);
}

void left(){
    analogWrite(EnA,62);
    analogWrite(EnB,0);
}

void loop() {
   forward();
   delay(1000);
   wait();
   delay(1000);
   right();
   delay(1600);
   wait();
   delay(2200);
   left();
   delay(950);
   wait();
   delay(1000);
   forward();
   delay(5000);
}
