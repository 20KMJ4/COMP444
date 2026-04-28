#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

float voltage = 0;
float degreesC = 0;
float degreesF = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(A0) * 0.004882813;
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0 / 5.0) + 32.0;

  Serial.println(degreesC);

  lcd.setCursor(0, 0);
  lcd.print(28);

  lcd.setCursor(14, 0);
  lcd.print(35);

  if (degreesC > 28) {
    lcd.setCursor(0, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(1, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 29) {
    lcd.setCursor(2, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(3, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 30) {
    lcd.setCursor(4, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(5, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 31) {
    lcd.setCursor(6, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(7, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 32) {
    lcd.setCursor(8, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(9, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 33) {
    lcd.setCursor(10, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(11, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 34) {
    lcd.setCursor(12, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(13, 1);
    lcd.write(255);  // full segment
  }
  if (degreesC > 35) {
    lcd.setCursor(14, 1);
    lcd.write(255);  // full segment
    lcd.setCursor(15, 1);
    lcd.write(255);  // full segment
  }
  if(degreesC < 28){
    lcd.setCursor(0, 1);
    lcd.write("                ");  // clear bottom row only
  }
  if(degreesC > 36){
    lcd.setCursor(0, 1);
    lcd.write("                ");  // clear bottom row only
  }

  delay(1000);
  lcd.clear();
}
