#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 2, EN = 3, D4 = 7, D5 = 6, D6 = 5, D7 = 4;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  lcd.begin(16, 2); // set up number of columns and rows

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("COBA");        // print message at (0, 0)
  lcd.setCursor(0, 1);         // move cursor to   (2, 1)
  lcd.print("COBA"); // print message at (2, 1)
}

void loop()
{
  
}
