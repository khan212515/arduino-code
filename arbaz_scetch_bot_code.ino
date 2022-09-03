int En_R=3;
int En_L=10;
int L1=4;
int L2=7;
int R1=12;
int R2=5;

int Max=60;
int Min=30;

void Forward(){
  
  analogWrite(En_L,Max);
  analogWrite(En_R,Max);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
}

void Semcircle(){
  analogWrite(En_L,Max);
  analogWrite(En_R,Min);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  
  
}

void uturn(){
  analogWrite(En_L,Min);
  analogWrite(En_R,Min);
  digitalWrite(L1,LOW);
  digitalWrite(L2,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  

void setup()
{

  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);

   {
    Forward();
   }
    delay(5000);
  Semcircle();
    delay(5000);
  uturn();
    delay(2000);
  Forward();
    delay(4000);}
}
  


  
