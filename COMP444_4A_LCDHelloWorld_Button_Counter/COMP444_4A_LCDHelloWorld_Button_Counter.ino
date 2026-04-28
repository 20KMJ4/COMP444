#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int buttonPin = 7;

int seconds = 0;
int minutes = 0;
int hours = 0;
int presses = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("# of presses:");
  lcd.setCursor(0, 1);
  lcd.print(presses);

  if (digitalRead(buttonPin) == LOW) {
    delay(200); //50 ms counts 2/3 presses //100 is ok but sometimes counts 2 presses //200 is good //500 is too long - does not register rapid pressing
    presses += 1;
  }
}
