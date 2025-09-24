#include <Keypad.h>
#include <LiquidCrystal.h>
const int RS = 2, EN = 3, D4 = 7, D5 = 6, D6 = 5, D7 = 4;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputBuffer = "";

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ketikkan Pesan:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    inputBuffer += key;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Output:");

    int len = inputBuffer.length();
    if (len <= 16) {
      lcd.setCursor(0, 1);
      lcd.print(inputBuffer);
    } else {
      lcd.setCursor(0, 1);
      lcd.print(inputBuffer.substring(len - 16));
    }
  }
}
