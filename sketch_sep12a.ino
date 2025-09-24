#include <LiquidCrystal.h>
#include <Keypad.h>


// Inisialisasi pin LCD 1602
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pin buzzer
const int buzzerPin = 10; // Pin untuk buzzer

// Keypad setup
const byte ROWS = 4; // 4 baris
const byte COLS = 4; // 4 kolom

// Layout keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = { 47, 49, 51, 53 };
byte colPins[COLS] = { 39, 41, 43, 45 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int kondisi;
String kata;
int a,b;
int angka;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (kondisi == 0) {
    char key = keypad.getKey();

    if (key) {
      if (key == '0') {
        a = 0;
        kondisi = 1;
      }
      if (key == '1') {
        a = 1;
        kondisi = 1;
      }
      if (key == '2') {
        a = 2;
        kondisi = 1;
      }
      if (key == '3') {
        a = 3;
        kondisi = 1;
      }
      if (key == '4') {
        a = 4;
        kondisi = 1;
      }
      if (key == '5') {
        a = 5;
        kondisi = 1;
      }
      if (key == '6') {
        a = 6;
        kondisi = 1;
      }
      if (key == '7') {
        a = 7;
        kondisi = 1;
      }
      if (key == '8') {
        a = 8;
        kondisi = 1;
      }
      if (key == '9') {
        a = 9;
        kondisi = 1;
      }

      Serial.print("a : ");
      Serial.print(a);
      angka = a;
      Serial.print(" - angka : ");
      Serial.println(angka);
    }
  }


  if (kondisi == 1) {
    char key = keypad.getKey();

    if (key) {
      if (key == '0') {
        b = 0;
        kondisi = 0;
      }
      if (key == '1') {
        b = 1;
        kondisi = 0;
      }
      if (key == '2') {
        b = 2;
        kondisi = 0;
      }
      if (key == '3') {
        b = 3;
        kondisi = 0;
      }
      if (key == '4') {
        b = 4;
        kondisi = 0;
      }
      if (key == '5') {
        b = 5;
        kondisi = 0;
      }
      if (key == '6') {
        b = 6;
        kondisi = 0;
      }
      if (key == '7') {
        b = 7;
        kondisi = 0;
      }
      if (key == '8') {
        b = 8;
        kondisi = 0;
      }
      if (key == '9') {
        b = 9;
        kondisi = 0;
      }
      Serial.print("b : ");
      Serial.print(b);
      angka = (a*10) + b;
      Serial.print(" - angka : ");
      Serial.println(angka);
    }
  }
}
