#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int buttonPin = 7;

int seconds = 0;
int minutes = 0;
int hours = 0;
int counter = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {


  if (digitalRead(buttonPin) == LOW) {
    delay(200);
    counter += 1;
    lcd.clear();
  }
  if (counter > 9) {
    counter = 0;
  }
  if (counter == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Inigo: Hello!");
  }
  if (counter == 2) {
    lcd.setCursor(0, 0);
    lcd.print("My name is ");
    lcd.setCursor(0, 1);
    lcd.print("Inigo Montoya.");
  }
  if (counter == 3) {
    lcd.setCursor(0, 0);
    lcd.print("You killed ");
    lcd.setCursor(0, 1);
    lcd.print("my father.");
  }
  if (counter == 4) {
    lcd.setCursor(0, 0);
    lcd.print("Prepare to die.");
  }
  if (counter == 5) {
    lcd.setCursor(0, 0);
    lcd.print("6-fingered man:");
    lcd.setCursor(0, 1);
    lcd.print("Stop saying that");
  }
  if (counter == 6) {
    lcd.setCursor(0, 0);
    lcd.print("Inigo: HELLO!");
  }
  if (counter == 7) {
    lcd.setCursor(0, 0);
    lcd.print("MY NAME IS ");
    lcd.setCursor(0, 1);
    lcd.print("INIGO MONTOYA!");
  }
  if (counter == 8) {
    lcd.setCursor(0, 0);
    lcd.print("YOU KILLED ");
    lcd.setCursor(0, 1);
    lcd.print("MY FATHER!");
  }
  if (counter == 9) {
    lcd.setCursor(0, 0);
    lcd.print("PREPARE TO DIE!");
  }
}
