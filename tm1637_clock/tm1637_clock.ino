#include <TM1637Display.h>
// Definisi pin
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
int i =  0;
int j =  0;

void setup() {
  display.setBrightness(0x0f);
}

void loop() {
  for ( i = 0; i < 60; i++) {
    display.showNumberDecEx(i, 0b11100000, true, 2, 2); 
    delay(10);
    if (i >= 59) {
      display.showNumberDecEx(j, 0b11100000, true, 2, 0);
      j++;
      delay(10);
      if (j > 23) {
        j = 0;
        i = 0;
      }
    }
  }
}
