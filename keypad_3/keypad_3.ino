#include <Keypad.h>
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
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
char inputBuffer[4] = {' ', ' ', ' ', ' '};
int index = 0;


void setup() {
  Serial.begin(9600);
  display.clear();
  display.setBrightness(7);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    for (int i = 0; i < 3; i++) {
      inputBuffer[i] = inputBuffer[i + 1];
    }
    inputBuffer[3] = key;

    uint8_t segments[4];

    for (int i = 0; i < 4; i++) {
      segments[i] = charToSegment(inputBuffer[i]);
    }
    display.setSegments(segments);
  }
}
uint8_t charToSegment(char c) {
  switch (c) {
    case '0': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F;
    case '1': return SEG_B | SEG_C;
    case '2': return SEG_A | SEG_B | SEG_D | SEG_E | SEG_G;
    case '3': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_G;
    case '4': return SEG_B | SEG_C | SEG_F | SEG_G;
    case '5': return SEG_A | SEG_C | SEG_D | SEG_F | SEG_G;
    case '6': return SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case '7': return SEG_A | SEG_B | SEG_C;
    case '8': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case '9': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G;
    case 'A': return SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case 'B': return SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'C': return SEG_A | SEG_D | SEG_E | SEG_F;
    case 'D': return SEG_B | SEG_C | SEG_D | SEG_E | SEG_G;
    case 'E': return SEG_A | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'F': return SEG_A | SEG_E | SEG_F | SEG_G;
    case '*': return SEG_A | SEG_C | SEG_E | SEG_G; 
    case '#': return SEG_B | SEG_C | SEG_E | SEG_F | SEG_G; 
    case ' ': return 0x00; 
    default:  return 0x00; 
  }
}
