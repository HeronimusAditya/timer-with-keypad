#include <Stepper.h>
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);

void setup() {
  myStepper.setSpeed(15);
  Serial.begin(9600);
  Serial.println("Stepper Motor Ready");
}

void loop() {
  Serial.println("Rotating clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  Serial.println("Rotating counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
