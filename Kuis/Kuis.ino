const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int inPin   = 5;
const int inPin2  = 6;
const int inPin3  = 7;
int val1, val2, val = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
}

void loop()
{
  val1 = digitalRead(inPin2);
  if ( val1 == HIGH)
  {
    digitalWrite(ledPin3, HIGH);
    delay (200);
    digitalWrite(ledPin3, LOW);
    delay (200);
    digitalWrite(ledPin2, HIGH);
    delay (200);
    digitalWrite(ledPin2, LOW);
    delay(200);
    digitalWrite(ledPin1, HIGH);
    delay (200);
    digitalWrite(ledPin1, LOW);
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
