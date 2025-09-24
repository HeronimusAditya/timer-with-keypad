#include <Keypad.h>
#include <TM1637Display.h>


// Konfigurasi TM1637
#define CLK 10
#define DIO 11
TM1637Display display(CLK, DIO);

// Konfigurasi Keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};     // Baris keypad
byte colPins[COLS] = {5, 4, 3, 2};     // Kolom keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  display.setBrightness(0x0f); // Maksimal brightness
  display.clear();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key >= '0' && key <= '9') {
      display.showNumberDec(key - '0'); // Tampilkan angka
    } else {
      uint8_t segs[4] = {0, 0, 0, 0};
      segs[3] = encodeChar(key); // Tampilkan karakter di digit ke-4
      display.setSegments(segs);
    }
  }
}

uint8_t encodeChar(char c) {
  switch (c) {
    case 'A': return 0x77;
    case 'B': return 0x7C;
    case 'C': return 0x39;
    case 'D': return 0x5E;
    case '*': return 0x49;
    case '#': return 0x76;
    default: return 0x00;
  }
}
