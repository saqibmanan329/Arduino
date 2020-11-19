
int lm1=9;
int lm2=10;
int rm1=5;
int rm2=6;


void setup() {
  // put your setup code here, to run once:
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
Serial.begin(9600);

}

void loop() 
{
 while(Serial.available())
  {char x=Serial.read();
 
if(x=='F')           // for the apps forward button
  {
    analogWrite(lm1,255);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  if(x=='R')         // for the apps right turn button
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
  }
  if(x=='B')         // for the apps reverse button
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
  }
  if(x=='L')              //for the apps left turn button
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    
  }
  
    if(x=='S')
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
  
  }
   if(x=='G')           // for the diaganols
  {
    analogWrite(lm1,140);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  
  }
    if(x=='I')            // for the diaganols
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(rm1,140);
    digitalWrite(rm2,LOW);
  
  }
    if(x=='H')             // for the diaganols
  {
    digitalWrite(lm1,LOW);
    analogWrite(lm2,140);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
  
  }
    if(x=='J')              // for the diaganols
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,LOW);
    analogWrite(rm2,140);
  
  }
  }
  
  } 
