#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int buttonPin = 2;
int buzzerPin = 6;
int buttonPressTime = 0;

long timeLimit = 15000; // 4C
//long timeLimit = 6000; // 4C CC Change time limit
long startTime = 0;
int roundNumber = 0;
const int arraySize = 25;

const char* words[arraySize] = { "moose", "beaver", "bear", "goose", "dog", "cat", "squirrel",
                                 "bird", "elephant", "horse", "bull", "giraffe", "seal", "bat",
                                 "skunk", "turtle", "whale", "rhino", "lion", "monkey", "frog",
                                 "alligator", "kangeroo", "hippo", "rabbit" };

int sequence[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);

  generateRandomOrder();

  showStartSequence();
}

void loop() {
  for (int i = 0; i < arraySize; i++) {

    lcd.clear();

    roundNumber = i + 1;
    lcd.print(roundNumber);
    lcd.print(": ");
    lcd.print(words[sequence[i]]);

    startTime = millis();

    while (digitalRead(buttonPin) == HIGH) {

      int roundedTime = round((timeLimit - (millis() - startTime)) / 1000);
      lcd.setCursor(14, 1);
      lcd.print("  ");
      lcd.setCursor(14, 1);
      lcd.print(roundedTime);
      delay(15);

      if (millis() - startTime > timeLimit) {
        gameOver();
      }

      if (digitalRead(buttonPin) == LOW) {
        tone(buzzerPin, 272, 10);
      }
    }

    delay(500);
  }
  winner();
}


//-------------------------------------------------------------------
void showStartSequence() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Category:");

  lcd.setCursor(0, 1);
  lcd.print("Animals");

  delay(2000);

  lcd.clear();
  lcd.print("Get Ready!");
  delay(1000);

  lcd.clear();
  lcd.print("3");
  delay(1000);

  lcd.clear();
  lcd.print("2");
  delay(1000);

  lcd.clear();
  lcd.print("1");
  delay(1000);
}

void generateRandomOrder() {

  randomSeed(analogRead(0));

  for (int i = 0; i < arraySize; i++) {
    int currentNumber = 0;
    boolean match = false;

    do {
      currentNumber = random(0, arraySize);
      match = false;
      for (int i = 0; i < arraySize; i++) {
        if (currentNumber == sequence[i]) {
          match = true;
        }
      }
    } while (match == true);
    sequence[i] = currentNumber;
  }
}

void gameOver() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Game Over");

  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(roundNumber - 1);

  tone(buzzerPin, 130, 250);
  delay(275);
  tone(buzzerPin, 73, 250);
  delay(275);
  tone(buzzerPin, 65, 150);
  delay(175);
  tone(buzzerPin, 98, 500);
  delay(500);

  while (true) {}
}

void winner() {
  lcd.clear();

  lcd.setCursor(7, 0);
  lcd.print("YOU");

  lcd.setCursor(7, 1);
  lcd.print("WIN!");

  tone(buzzerPin, 1318, 150);
  delay(175);
  tone(buzzerPin, 1567, 150);
  delay(175);
  tone(buzzerPin, 2637, 150);
  delay(175);
  tone(buzzerPin, 2093, 150);
  delay(175);
  tone(buzzerPin, 2349, 150);
  delay(175);
  tone(buzzerPin, 3135, 500);
  delay(500);

  while (true) {}
}
