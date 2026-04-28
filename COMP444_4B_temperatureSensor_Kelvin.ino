#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

float voltage = 0;
float degreesC = 0;
float degreesF = 0;
float degreesK = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  voltage = analogRead(A0) * 0.004882813;
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0 / 5.0) + 32.0;
  degreesK = degreesC + 273.15;

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print((char)223);  // code for degree symbol
  lcd.setCursor(1, 0);
  lcd.print("C:");
  lcd.print(degreesC);

  lcd.setCursor(9, 0);
  lcd.print("F:");
  lcd.print(degreesF);

  lcd.setCursor(0, 1);
  lcd.print("K:");
  lcd.print(degreesK);

  delay(1000);
}
