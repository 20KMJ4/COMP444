#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int redPin = 6;
int greenPin = 5;
int bluePin = 3;

float voltage = 0;
float degreesC = 0;
float degreesF = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  voltage = analogRead(A0) * 0.004882813;
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0 / 5.0) + 32.0;

  lcd.clear();


  lcd.setCursor(0, 0);
  lcd.print((char)223);  // code for degree symbol

  lcd.setCursor(1, 0);
  lcd.print("C: ");
  lcd.print(degreesC);

  if (degreesC >= 50) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Too hot");
  } else if (degreesC < 50 && degreesC >= 40) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 25);
    analogWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Hot");
  } else if (degreesC < 40 && degreesC >= 30) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 75);
    analogWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Warm");
  } else if (degreesC < 30 && degreesC >= 20) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Nice");
  } else if (degreesC < 20 && degreesC >= 10) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    lcd.setCursor(0, 1);
    lcd.print("Cool");
  } else if (degreesC < 0 && degreesC >= 10) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    lcd.setCursor(0, 1);
    lcd.print("Cold");
  } else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Too Cold");
  }

  delay(1000);
}
