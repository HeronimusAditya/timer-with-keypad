#include <Servo.h>
Servo servo;
int angle = 0;

void setup() {
  servo.attach(2);
  servo.write(angle);
}
void loop() 
{ 
  for(angle = 0; angle <= 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(10);                   
  } 
  for(angle = 180; angle >= 0; angle--)    
  {                                
    servo.write(angle);           
    delay(10);       
  } 
}
