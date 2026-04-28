#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hello, world!"); //4A
  //lcd.print("May the force be"); //4A CC Change the Message

  lcd.setCursor(0,1);
  lcd.print(millis() / 1000);
  //lcd.print("with you!"); //4A CC Change the Message
}
