#include <Adafruit_Fingerprint.h>
  int can1=0;
  int can2=0;
  int can3=0;

SoftwareSerial mySerial(10, 11);
//SoftwareSerial mySerial2(12, 13);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);
  while (!Serial);  
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

uint8_t readnumber(void) {
  uint8_t num = 0;
  
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}


void loop()                     
{
  getFingerprintIDez();
  delay(50);            
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  

  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  

  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}


int getFingerprintIDez() {
  int vote;
 

  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  

  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  Serial.println("Enter the candidate number you want to vote for:");
  Serial.println("1 for Candidate 1");
  Serial.println("2 for candidate 2");
  Serial.println("3 for candidate 3");
  Serial.println("9 to publish result");
  
  
  vote = readnumber();
  if (vote == 1)
{can1=can1+1;
Serial.println("Vote recorded for candidate 1");
Serial.println("Waiting for valid finger to vote again or enter an valid finger and enter 9 to publish result");
return finger.fingerID;}
else if (vote == 2)
{can2=can2+1;
Serial.println("Vote recorded for candidate 2");
Serial.println("Waiting for valid finger to vote again or enter an valid finger and enter 9 to publish result");
return finger.fingerID;}
else if (vote == 3) 
{can3=can3+1;
Serial.println("Vote recorded for candidate 3");
Serial.println("Waiting for valid finger to vote again or enter an valid finger and enter 9 to publish result");
return finger.fingerID;}
else if (vote == 9)
goto here1;

  return finger.fingerID; 
  here1: if (can1>can2 && can1>can3)
 {Serial.println("");
  Serial.println("Candidate 1 wins");
 // SendSMS();
 }
  else if (can2>can3 && can2>can1)
  {Serial.println("");
    Serial.println("Candidate 2 wins");
   // SendSMS();
  }
  else if (can3>can1 && can3>can2)
  {Serial.println("");
    Serial.println("Candidate 3 wins");
   // SendSMS();
  }
  else {Serial.println("");
  Serial.println ("It's a tie");
 // SendSMS();
 }
}
/*void SendSMS()
{mySerial2.begin(9600);
  if (can1>can2 && can1>can3)
  {mySerial2.println("AT+CMGF=1");   
  delay(1000);
  mySerial2.println("AT+CMGS=\"+917006198663\"\r");  
  delay(1000);
  mySerial2.println("Candidate 1 wins");
  delay(200);
  mySerial2.println((char)26); 
  delay(1000);}
   else if (can2>can3 && can2>can1)
   {mySerial2.println("AT+CMGF=1");    
  delay(1000);
  mySerial2.println("AT+CMGS=\"+917006198663\"\r");  
  delay(1000);
  mySerial2.println("Candidate 2 wins");
  delay(200);
  mySerial2.println((char)26); 
  delay(1000);}
  else if (can3>can1 && can3>can2)
  {mySerial2.println("AT+CMGF=1");    
  delay(1000);
  mySerial2.println("AT+CMGS=\"+917006198663\"\r");  
  delay(1000);
  mySerial2.println("Candidate 3 wins");
  delay(200);
  mySerial2.println((char)26); 
  delay(1000);}
  else
  {mySerial2.println("AT+CMGF=1");    
  delay(1000);
  mySerial2.println("AT+CMGS=\"+917006198663\"\r");  
  delay(1000);
  mySerial2.println("It's a tie");
  delay(200);
  mySerial2.println((char)26);
  delay(1000);}
  
}*/
