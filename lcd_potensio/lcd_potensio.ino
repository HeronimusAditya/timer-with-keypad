#include <LiquidCrystal.h>

const int RS = 2, EN = 3, D4 = 7, D5 = 6, D6 = 5, D7 = 4;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Potensiometer pin
const int potPin = A0;

byte customChar[8] = {
  B01110,
  B10101,
  B10101,
  B10001,
  B11101,
  B00101,
  B11011,
  B11110
};

void setup() {
  lcd.begin(16, 2);         // set up number of columns and rows
  Serial.begin(9600);       // start serial communication
  lcd.createChar(0, customChar);
}

void loop() {
  int sensorValue = analogRead(potPin);        // read analog value (0-1023)
  float voltage = sensorValue * (5.0 / 1023.0); // convert to voltage (0-5V)

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltase:");
  lcd.setCursor(0, 1);
  lcd.print(voltage, 2); // show 2 decimal places
  lcd.print(" V");
  lcd.setCursor(9, 1);
  lcd.write((byte)0);

  // Display on Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V");
  
  delay(500); // update every 0.5 seconds
}
