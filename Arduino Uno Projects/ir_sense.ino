
int ss=A0;
void setup() {

  pinMode(13,OUTPUT);
  pinMode(ss,INPUT);
  

}

void loop() {
  
  int sd=analogRead(ss);
  if((sd>600))
  {
    digitalWrite(13,HIGH);
  }
  if((sd<600))
  {
    digitalWrite(13,LOW);
    
  }
  
  delay(100);
  }
