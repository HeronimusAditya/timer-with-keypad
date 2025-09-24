float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue  = analogRead(A0);
  int analogValue1 = analogRead(A1);
  int analogValue2 = analogRead(A2);

  float voltage  = floatMap(analogValue,  0, 1023, 0, 5); // (0= min hambatan, 1230= max hambatan, 0 = min voltage, 5= max voltage
  float voltage1 = floatMap(analogValue1, 0, 1023, 0, 5);
  float voltage2 = floatMap(analogValue2, 0, 1023, 0, 5);

  Serial.print("Potensio 1: "); Serial.print(analogValue); Serial.print(" ("); Serial.print(voltage); Serial.print("V), ");
  Serial.print("Potensio 2: "); Serial.print(analogValue1); Serial.print(" ("); Serial.print(voltage1); Serial.print("V), ");
  Serial.print("Potensio 3: "); Serial.print(analogValue2); Serial.print(" ("); Serial.print(voltage2); Serial.println("V");

  delay(1000);
}
