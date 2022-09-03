int servopin = 9;    //Define servo interface digital interface 7
int angle =0;        //Angle of rotation of the servo

void servopulse(int angle)//Define an impulse function
{
  int pulsewidth=(angle*11)+500;  //The angle is converted to a pulse width value of 500-2480
  digitalWrite(servopin,HIGH);    //The servo interface level to the highest
  delayMicroseconds(pulsewidth);  //The number of microseconds of the delay pulse width value
  digitalWrite(servopin,LOW);     //The servo interface level to low
  delayMicroseconds(20000-pulsewidth); //20000 can be replaced: "frequency = 1 / (20000/1000000)"
}

void setup()
{
  pinMode(servopin,OUTPUT);//Set the servo interface as the output interface
}

void loop()
{
  for(angle=0;angle<=180;angle++){
      //Reference impulse function
      servopulse(angle);
      delay(20);
  }
//    for(angle=180;angle>=0;angle--){
//      //Reference impulse function
//      servopulse(angle);
//      delay(20);
//  }
}
