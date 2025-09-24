#include <Servo.h>

Servo myServo;  
void setup() {
  Serial.begin(9600);
  myServo.attach(2);  
}

void loop() {
  int analogValue = analogRead(A0);
  int angle = map(analogValue, 0, 1023, 0, 180);

  myServo.write(angle); 
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Angle: ");
  Serial.println((angle));
}
