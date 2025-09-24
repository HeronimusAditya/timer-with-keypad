const int potPin = A0;     
const int ledPin = 2 ;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);               // Baca nilai potensiometer (0–1023)
  int pwmValue = map(potValue, 0, 1023, 0, 255);   // Konversi ke nilai PWM (0–255)

  analogWrite(ledPin, pwmValue);                   // Atur kecerahan LED

  // Tampilkan nilai di Serial Monitor
  Serial.print("Potensiometer: ");
  Serial.print(potValue);
  Serial.print(" => PWM: ");
  Serial.println(pwmValue);

  delay(100); // Delay kecil untuk stabilitas
}
