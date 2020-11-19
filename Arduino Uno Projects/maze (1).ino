int lsens=9;
int rsens=3;
int msens=7;
int lm1=10;
int lm2=11;
int rm1=5;
int rm2=6;

void setup() {
  // put your setup code here, to run once:
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(lsens,INPUT);
pinMode(rsens,INPUT);
pinMode(msens,INPUT);
Serial.begin(9600);

}

void loop() {
  int ls = digitalRead(lsens);
  int rs = digitalRead(rsens);
  int ms = digitalRead(msens);

  Serial.println(ls);
  Serial.println(rs);
  Serial.println(ms);

  if(ls==HIGH& ms==LOW& rs==HIGH)
  { digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  if(ls==LOW& ms== LOW& rs== LOW )
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
     }
  if(ls==LOW& ms==LOW& rs==HIGH)
  { digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }if(ls==LOW& ms==HIGH& rs==LOW)
  { digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }if(ls==LOW& ms==HIGH& rs==HIGH)
  { digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }if(ls==HIGH& ms==LOW& rs==LOW)
  { digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
  }if(ls==HIGH& ms==HIGH& rs==LOW)
  { digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
  }if(ls==HIGH& ms==HIGH& rs==HIGH)
  { digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
  }

}
