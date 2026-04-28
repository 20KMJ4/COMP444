#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int photoresistor = 0;

float voltage = 0;
float degreesC = 0;
float degreesF = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  photoresistor = analogRead(A0);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("photoresistor: ");

  lcd.setCursor(0, 1);
  lcd.print(photoresistor);

  delay(1000);
}
