#define r1s 6
#define l2s 7
#define l1s 4
#define r2s 9
#define r1d 2
#define l2d 3
#define l1d 8
#define r2d 5 
char input = 0;
char l,r,f,b,linleft,linright,dlf,dlb,drf,drb,stp;

void setup() {
  pinMode(r1s, OUTPUT);
  pinMode(l2s, OUTPUT);
  pinMode(l1s, OUTPUT);
  pinMode(r2s, OUTPUT);
  pinMode(r1d, OUTPUT);
  pinMode(l2d, OUTPUT);
  pinMode(l1d, OUTPUT);
  pinMode(r2d, OUTPUT);
  Serial.begin(9600);
  
}
int l1=1, r1=1, f1=1, b1=1;
void loop() {

   if (Serial.available() > 0)
    {
      input = Serial.read();
      Serial.print(input);

    }
     
      if(input== 'l'){
        if(l1==1){
          stop();
          l1=0;
        }
        left();
        r1=1;
        f1=1;
        b1=1;
      }
      if (input=='r'){
        if(r1==1){
          stop();
          r1=0;
        }
        right();
        f1=1;
        l1=1;
        b1=1;
      }
      if (input=='f'){
        if(f1==1){
          stop();
          f1=0;
        }
        forward();
        r1=1;
        l1=1;
        b1=1;
      }
      if (input=='b'){
        if(b1==1){
          stop();
          b1=0;
        }
        backward();
        r1=1;
        l1=1;
        f1=1;
      }
      if (input== 'q'){
        linearleft();
      }
      if (input== 'x'){
        linearright();
      }
      if (input=='w'){
        d_right_f();
      }
      if (input=='t'){
      d_left_f();
      }
      if(input== 's'){
        stop();
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
