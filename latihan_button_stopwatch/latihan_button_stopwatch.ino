#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
const int butonstrt = 7;
const int butonpaus = 6;
const int butonrest = 5;
int i   =  0;
int j   =  0;
bool wkt  = false;
bool rst  = false;
//bool str  = false;

void setup() {
  display.setBrightness(0x0f);
  pinMode (butonstrt, INPUT);
  pinMode (butonpaus, INPUT);
  pinMode (butonrest, INPUT);
  display.showNumberDec(0, true);

}

void loop() {

  if (digitalRead(butonstrt) == HIGH) {
    wkt = true;
  }
  if (digitalRead(butonpaus) == HIGH) {
    wkt = false;
    rst = true;
  }
  if (!wkt&&digitalRead(butonrest) == HIGH ) {
    j = 0;
    i = 0;
    rst = false;
    wkt = false;
    //str = false;
    display.showNumberDec(0, true);
  }
  if (wkt) {
    //for ( i = 0; i < 60; i++) {
    display.showNumberDecEx(j * 100 + i, 0b11100000, true); // Format MM:SS
    delay(10);
    i++;
    if (i >= 60) {
      i = 0;
      j++;
      if (j >= 60) {
        j = 0;
      }
    }
  }
}
