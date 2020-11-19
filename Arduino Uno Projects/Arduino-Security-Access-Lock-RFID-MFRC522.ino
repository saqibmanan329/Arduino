// WELCOME TO THE BACKBENCHERS YOUTUBE CHANNEL
// PLEASE SUBSCRIBE TO MY CHANNEL
// PRESS THE BELL ICON TO GET NOTIFIED MY LATEST VIDEO UPDATE
// THEANKS FOR WATCHING

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(6); //servo pin
   myServo.write(140);
    delay(7000);
  myServo.write(0); //servo start position

  Serial.println("Put your card to the reader...");
  Serial.println();
  pinMode(5,OUTPUT);

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "76 07 BA F8") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    myServo.write(140);
    delay(7000);
    myServo.write(0);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(5,HIGH);
    delay(1000);
    digitalWrite(5,LOW);
    delay(1000);
  }
}
