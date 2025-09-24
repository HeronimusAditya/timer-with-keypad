int digitalPin = 8;     // KY-028 digital interface
int analogPin = A0;     // KY-028 analog interface
int digitalVal;         // digital readings
int analogVal;          // analog readings

void setup()
{
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
 
  analogVal = analogRead(analogPin); 
  
  float voltage = analogVal * (5.0 / 1023.0);
  float temperatureC = voltage * 10.0;
  
  Serial.print("Analog Value: ");
  Serial.print(analogVal);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.println(" °C");

  delay(1000);
}
