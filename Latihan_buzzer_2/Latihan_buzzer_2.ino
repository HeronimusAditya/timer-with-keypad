const int pb   = 3;
const int buzz = 2;
int tombol     = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  tombol = digitalRead(pb);
  if (tombol == HIGH) {
    for (int i = 0; i < 2; i++) {
      tone(buzz, 1000);
      delay(500);
      noTone(buzz);
      delay(500);
    }
 
  }
}
