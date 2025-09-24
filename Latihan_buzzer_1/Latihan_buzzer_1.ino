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
    digitalWrite(buzz, HIGH);
  } else {
    digitalWrite(buzz, LOW);
  }
}
