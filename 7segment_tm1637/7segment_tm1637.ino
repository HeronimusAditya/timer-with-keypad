#include <TM1637Display.h>
// Definisi pin
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f);
}

void loop() {
  for (int i = 0; i < 10000; i++) {
    display.showNumberDec(i, false);
    delay(1);
 
  }
  for (int i = 9999; i >= 0; i--) {
    display.showNumberDec(i, true);
    delay(1);
  }
}
