
int lm1=10;
int lm2=11;
int rm1=5;
int rm2=6;


void setup() {
  // put your setup code here, to run once:
pinMode(lm1,OUTPUT);

Serial.begin(9600);

}

void loop() 
{
 while(Serial.available())
  {char x=Serial.read();
 
if(x=='F')           // for the apps forward button
  {
         // condtitions for the motor movement.
  }
  if(x=='R')         // for the apps right turn button
  {
   
  }
  if(x=='B')         // for the apps reverse button
  {
    
  }
  if(x=='L')              //for the apps left turn button
  {
    
    
  }
  
    if(x=='S')
  {
    
  
  }
   if(x=='G')           // for the diaganols
  {
    
  
  }
    if(x=='I')            // for the diaganols
  {
    
  
  }
    if(x=='H')             // for the diaganols
  {
    
  
  }
    if(x=='J')              // for the diaganols
  {
  
  
  }
  }
  
  } 
