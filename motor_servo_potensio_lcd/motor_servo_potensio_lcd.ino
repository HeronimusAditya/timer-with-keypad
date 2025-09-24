#include <Servo.h>
#include <LiquidCrystal.h>
Servo myServo;
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  myServo.attach(13);
}

void loop() {
  int analogValue = analogRead(A0);
  int angle = map(analogValue, 0, 1023, 0, 180);

  myServo.write(angle);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor Servo");
  lcd.setCursor(0, 1);
  lcd.print("Angle:");
  lcd.print(angle);
  
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print("Angle: ");
  Serial.println((angle));
}
