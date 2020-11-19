

int lm1=10;
int lm2=11;
int rm1=5;
int rm2=6;
int ls=2;
int rs=8;
void setup() {

  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(ls,INPUT);
  pinMode(rs,INPUT);
  

}

void loop() {
  int lsd=analogRead(ls);
  int rsd=analogRead(rs);
  if((lsd<=600) && (rsd<=600))
  {
    analogWrite(lm1,255);
    analogWrite(lm2,0);
    analogWrite(rm1,255);
    analogWrite(rm2,0);
  }
  if((ls>=600) && (rs<=600))
  {
    analogWrite(lm1,128);
    analogWrite(lm2,0);
    analogWrite(rm1,0);
    analogWrite(rm2,0);
    
  }
  if((ls<=600) && (rs>=600))
  {
    analogWrite(lm1,0);
    analogWrite(lm2,0);
    analogWrite(rm1,128);
    analogWrite(rm2,0);
  }
  else{
    analogWrite(lm1,0);
    analogWrite(lm2,0);
    analogWrite(rm1,0);
    analogWrite(rm2,0);
  }
  delay(100);
  }
