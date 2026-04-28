#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int seconds = 0;
int minutes = 0;
int hours = 0;
long lastTime = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(millis() / (60000 * 60));  // hours
  lcd.setCursor(1, 0);
  lcd.print("h");

  lcd.setCursor(3, 0);
  lcd.print(millis() / 60000);  // minutes
  lcd.setCursor(6, 0);
  lcd.print("m");


  lcd.setCursor(8, 0);
  lcd.print(millis() / 1000);  //seconds
  lcd.setCursor(15, 0);
  lcd.print("s");

  // inspo from Simon Says: if (millis() - startTime > timeLimit)
  if (millis() - lastTime >= 1000) {
    lastTime += 1000;
    seconds += 1;
  }
  if (seconds % 60 == 0 && seconds >= 1) {
    minutes += 1;
    seconds = 0;
    lcd.setCursor(6, 1);
    lcd.print(" ");
  }
  if (minutes % 60 == 0 && minutes > 1) {
    hours += 1;
    minutes = 0;
    lcd.setCursor(3, 2);
    lcd.print(" ");
  }
  lcd.setCursor(0, 1);
  lcd.print(hours);  // hours
  lcd.setCursor(1, 1);
  lcd.print("h");

  lcd.setCursor(3, 1);
  lcd.print(minutes);  // minutes
  lcd.setCursor(5, 1);
  lcd.print("m");

  lcd.setCursor(7, 1);
  lcd.print(seconds);  //seconds
  lcd.setCursor(9, 1);
  lcd.print("s");

  /*
// Testing printing on a larger number of rows than available to see what happens
// commented out lines 59-62 above, and uncommented this section of code (between /* and */)
  lcd.setCursor(0, 2);
  lcd.print(seconds);  //seconds
  lcd.setCursor(1, 2);
  lcd.print("s");
  */
}