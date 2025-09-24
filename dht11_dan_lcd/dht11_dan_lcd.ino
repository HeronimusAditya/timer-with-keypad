#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 13       
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);     
  dht.begin();         
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: ");
  lcd.print(kelembapan);
  lcd.print("%");

  delay(2000);
}
