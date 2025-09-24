#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(40, 42, 50, 48, 46, 44);

#define BUZZER 8
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','='},
  {'+','-','x','/'}
};
byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Kalkulator
String input = "";
bool calculated = false;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KalkulatorKeypad");
  pinMode(BUZZER, OUTPUT);
  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("Masukkan angka:");
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    
    tone(BUZZER, 1000, 100); // bunyi singkat
    delay(150);

    if (key == '*') {
      input = "";
      calculated = false;
      lcd.clear();
    } else if (key == '=') {
      if (!calculated) {
        String result = calculate(input);
        lcd.setCursor(0, 1);
        lcd.print(input + "=" + result);
        calculated = true;
      }
    } else {
      if (calculated) {
        input = "";
        lcd.clear();
        calculated = false;
      }
      if (input.length() < 16) {
        input += key;
        lcd.setCursor(0, 0);
        lcd.print(input);
      }
    }
  }
}

String calculate(String expr) {
  int opIndex = -1;
  char op = ' ';
  for (int i = 0; i < expr.length(); i++) {
    char c = expr.charAt(i);
    if (c == '+' || c == '-' || c == 'x' || c == '/') {
      op = c;
      opIndex = i;
      break;
    }
  }

  if (opIndex == -1) return "kosong";

  float num1 = expr.substring(0, opIndex).toFloat();
  float num2 = expr.substring(opIndex + 1).toFloat();
  float result = 0;

  switch (op) {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case 'x': result = num1 * num2; break;
    case '/': result = num2 != 0 ? num1 / num2 : 0; break;
  }

  if (op == '/' && num2 == 0) return "kosong";
  if (result == (int)result) return String((int)result);
  return String(result, 2); // 2 digit desimal
}
