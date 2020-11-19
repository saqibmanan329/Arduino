void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(A0,INPUT);

}
// light intensity is high resistance in low 

void loop() {
  // put your main code here, to run repeatedly:
int adc_read = analogRead(A0);
Serial.print("ADC RAW VALUE :");
Serial.println(adc_read);
float adc_val =(adc_read*3.3)/1023.0;
Serial.print("ADC VOLTAGE");
Serial.println(adc_val);
delay(1000);
}
