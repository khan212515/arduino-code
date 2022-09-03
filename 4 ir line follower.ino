#define IR1 2
#define IR2 5
#define IR3 3
#define IR4 4

int En_R=11;
int En_L=6;
int L_Motor1=7;
int L_Motor2=8;
int R_Motor1=9;
int R_Motor2=10;
int Max=60;
int Min=45;


void Forward()
{
    analogWrite(En_L,Max);
    analogWrite(En_R,Max);
    digitalWrite(L_Motor1,HIGH);
    digitalWrite(L_Motor2,LOW);
    digitalWrite(R_Motor1,HIGH);
    digitalWrite(R_Motor2,LOW);
}

void Left()
{
    analogWrite(En_L,Min);
    analogWrite(En_R,Max);
    digitalWrite(L_Motor1,HIGH);
    digitalWrite(L_Motor2,LOW);
    digitalWrite(R_Motor1,HIGH);
    digitalWrite(R_Motor2,LOW);
}

void Right()
{
    analogWrite(En_L,Max);
    analogWrite(En_R,Min);
    digitalWrite(L_Motor1,HIGH);
    digitalWrite(L_Motor2,LOW);
    digitalWrite(R_Motor1,HIGH);
    digitalWrite(R_Motor2,LOW);
}

void E_Left()
{
    analogWrite(En_L,Min);
    analogWrite(En_R,Max);
    digitalWrite(L_Motor1,LOW);
    digitalWrite(L_Motor2,HIGH);
    digitalWrite(R_Motor1,HIGH);
    digitalWrite(R_Motor2,LOW);
}
void E_Right()
{
    analogWrite(En_L,Max);  
    analogWrite(En_R,Min);
    digitalWrite(L_Motor1,HIGH);
    digitalWrite(L_Motor2,LOW);
    digitalWrite(R_Motor1,LOW);
    digitalWrite(R_Motor2,HIGH);
}

void U_Turn()
{
    analogWrite(En_L,Max);
    analogWrite(En_R,Max);
    digitalWrite(L_Motor1,HIGH);
    digitalWrite(L_Motor2,LOW);
    digitalWrite(R_Motor1,LOW);
    digitalWrite(R_Motor2,HIGH);
}

void setup() 
{
  // put your setup code here, to run once:
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);

  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  

if(digitalRead(IR1)==1 && digitalRead(IR2)==1 && digitalRead(IR3)==1 && digitalRead(IR4)==1)  
  {
    U_Turn();
  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==0 && digitalRead(IR4)==1)
  {
    Forward();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==1 && digitalRead(IR3)==1 && digitalRead(IR4)==1)
  {
    Left();
  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==1 && digitalRead(IR4)==1)
  {
    Forward();
  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==1 && digitalRead(IR3)==0 && digitalRead(IR4)==1)
  {
    Forward();
  }
  else if(digitalRead(IR1)==1 && digitalRead(IR2)==1 && digitalRead(IR3)==1 && digitalRead(IR4)==0)
  {
    Right();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0 && digitalRead(IR3)==1 && digitalRead(IR4)==1)
  {
    
    Left();
  }
  

 
 else if(digitalRead(IR1)==1 && digitalRead(IR2)==1 && digitalRead(IR3)==0 && digitalRead(IR4)==0)
  {
    Right();
  }
  
  else if(digitalRead(IR1)==0 && digitalRead(IR2)==1 && digitalRead(IR3)==1 && digitalRead(IR4)==0)
  {
    Left();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0 && digitalRead(IR3)==0 && digitalRead(IR4)==1)
  {
    E_Left(); 
  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==0 && digitalRead(IR4)==0)
  {
    E_Right();
  }
  
  else if(digitalRead(IR1)==0 && digitalRead(IR2)==1 && digitalRead(IR3)==0 && digitalRead(IR4)==0)
  {
    Forward();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0 && digitalRead(IR3)==1 && digitalRead(IR4)==0)
  {
    Forward();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==1 && digitalRead(IR3)==0 && digitalRead(IR4)==1)
  {
    Forward(); 
  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==1 && digitalRead(IR4)==0)
  {
    Forward();
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0 && digitalRead(IR3)==0 && digitalRead(IR4)==0)
  {
    Left();
  }
}
