    #include <Servo.h>
    Servo servo1;
    Servo servo2;
    int angle = 10;
    void setup() {
      servo1.attach(5);
      servo2.attach(6);
      servo1.write(angle);
      servo2.write(angle);
    }
    void loop() 
    { 
     // scan from 0 to 180 degrees
      for(angle = 10; angle < 180; angle++)  
      {                                  
        servo1.write(angle);  
        servo2.write(angle);              
        delay(15);                   
      }
      delay(2000); 
      // now scan back from 180 to 0 degrees
      for(angle = 180; angle > 10; angle--)    
      {                                
        servo1.write(angle);    
        servo2.write(angle);        
        delay(15);       
      } 
    }
