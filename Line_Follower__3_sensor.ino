#define IRMid 5
#define IRLeft 2
#define IRRight 3

#define LENA 6
#define LIN1 8
#define LIN2 9


#define RENB 10
#define RIN3 12
#define RIN4 11


void setup() {
// put your setup code here, to run once: pinMode(IRMidR,INPUT); pinMode(IRLeft,INPUT); pinMode(IRRight,INPUT); pinMode(IRMidL,INPUT);

pinMode(IRMid,INPUT);
pinMode(IRLeft,INPUT);
pinMode(IRRight,INPUT);

pinMode(LIN1,OUTPUT);
pinMode(LIN2,OUTPUT);
pinMode(RIN3,OUTPUT);
pinMode(RIN4,OUTPUT);
pinMode(LENA, OUTPUT);
pinMode(RENB, OUTPUT);


}


void forward(){

  analogWrite(LENA, 65);
  analogWrite(RENB, 65);

  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);
  digitalWrite(RIN3, HIGH);
  digitalWrite(RIN4, LOW);
  }

void right(){

  analogWrite(LENA, 0);
  analogWrite(RENB, 55);
  
  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);
  digitalWrite(RIN3, HIGH);
  digitalWrite(RIN4, LOW);
  }

void left(){

  analogWrite(LENA, 55);
  analogWrite(RENB, 0);


  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);
  digitalWrite(RIN3, HIGH);
  digitalWrite(RIN4, LOW);
  }

void turn(){

  analogWrite(LENA, 55);
  analogWrite(RENB, 55);

  
  digitalWrite(LIN1, HIGH);
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN3, HIGH);
  digitalWrite(RIN4, LOW);
  
  }

  
void loop() {
  // put your main code here, to run repeatedly:
/*
    forward();
    delay(2000);

    left();
    delay(2000);

    right();
    delay(2000);

    turn();
    delay(2000);

  */

  if( ( digitalRead(IRLeft) == 0 && digitalRead(IRMid)==0 && digitalRead(IRRight)==0 ) ){
    
    left();   //JUNCTION
    
    }


  
  if( ( digitalRead(IRLeft) == 0 && digitalRead(IRMid)==0 && digitalRead(IRRight)==1 ) ){
    
    left();    
    
    }

  
  if( ( digitalRead(IRLeft) == 0 && digitalRead(IRMid)==1 && digitalRead(IRRight)==0 ) ){
    
    forward();
    
    }


  if( ( digitalRead(IRLeft) == 1 && digitalRead(IRMid)==0 && digitalRead(IRRight)==0 ) ){
    
    right();
    
    }


  if( ( digitalRead(IRLeft) == 0 && digitalRead(IRMid)==1 && digitalRead(IRRight)==1 ) ){
    
    left();
    
    }


  if( ( digitalRead(IRLeft) == 1 && digitalRead(IRMid)==1 && digitalRead(IRRight)==1 ) ){
    
    turn();
    
    }


  if( ( digitalRead(IRLeft) == 1 && digitalRead(IRMid)==1 && digitalRead(IRRight)==0 ) ){
    
    right();
    
    }


  if( ( digitalRead(IRLeft) == 1 && digitalRead(IRMid)==0 && digitalRead(IRRight)==1 ) ){
    
    forward();
    
    }



  
}
