

int lm1=10;
int lm2=11;
void setup() {

  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);

  

}

void loop() {
  analogWrite(lm1,255);
  analogWrite(lm2,0);

  delay(100);
  }
