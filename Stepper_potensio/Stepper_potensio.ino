#include <Stepper.h> // Include the header file
// change this to the number of steps on your motor
#define STEPS 32
// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);
int Pval = 0;
int potVal = 0;
void setup() {
  Serial.begin(9600);
  stepper.setSpeed(500);
}
void loop() {
potVal = map(analogRead(A0),0,1023,0,500);
if (potVal>Pval)
  stepper.step(5);
if (potVal<Pval)
  stepper.step(-5);
Pval = potVal;
Serial.println(Pval); //for debugging
}
