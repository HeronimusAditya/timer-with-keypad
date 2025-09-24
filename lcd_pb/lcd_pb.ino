#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 2, EN = 3, D4 = 7, D5 = 6, D6 = 5, D7 = 4;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const int buttonPin = 8;

void setup()
{
  lcd.begin(16, 2); // set up number of columns and rows
  pinMode(buttonPin, INPUT); // set button pin as input
}

void loop()
{
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    lcd.clear(); // clear previous content
    lcd.setCursor(0, 0);
    lcd.print("COBA");
    lcd.setCursor(0, 1);
    lcd.print("COBA");
  } else {
    lcd.clear(); // clear LCD when button not pressed
  }

  delay(100); // debounce delay
}
