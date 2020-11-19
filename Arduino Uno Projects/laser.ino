int green = 2;
int yellow = 3;
int red = 4;
int ldr = A0;
int buzzer = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
pinMode(green,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(red,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);

}
void laser(){

}
void loop() {
  // put your main code here, to run repeatedly:
//   laser();
int laser = analogRead(ldr);
  digitalWrite(8,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(green,LOW);
digitalWrite(yellow,HIGH);
delay(3000);
digitalWrite(yellow,LOW);
digitalWrite(red,HIGH);
  if(red == HIGH )
{
  if(laser < 100)
  {
    digitalWrite(buzzer,HIGH);
    Serial.print("High");
    delay(2000);
    digitalWrite(buzzer,LOW);
  }
}
digitalWrite(red,LOW);

}
