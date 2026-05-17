#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int buttonPin = 2;
int buzzerPin = 6;
int buttonPressTime = 0;

long timeLimit = 4000;
long startTime = 0;
int roundNumber = 0;
const int arraySize = 7;

// array changed again to small set, for quicker win sound
const char* words[arraySize] = { "red", "yellow", "blue", "green", "indigo",
                                 "orange", "violet" };

int sequence[] = { -1, -1, -1, -1, -1, -1, -1 };

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
  lcd.print("Colours");

  delay(5000);

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

  tone(buzzerPin, 65, 950);  // C2
  delay(950);
  tone(buzzerPin, 132, 400);  //C3
  delay(400);
  tone(buzzerPin, 156, 400);  // Eb3
  delay(800);
  tone(buzzerPin, 175, 450);  // F3
  delay(900);
  tone(buzzerPin, 185, 550);  // F#3
  delay(550);

  while (true) {}
}

void winner() {
  lcd.clear();

  lcd.setCursor(7, 0);
  lcd.print("YOU");

  lcd.setCursor(7, 1);
  lcd.print("WIN!");

  tone(buzzerPin, 1318, 500);  //E6
  delay(500);
  tone(buzzerPin, 988, 200);  //B5
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 1175, 500);  //D6
  delay(500);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 988, 200);  //B5
  delay(200);
  tone(buzzerPin, 880, 500);  //A5
  delay(500);
  tone(buzzerPin, 880, 200);  //A5
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 1318, 600);  //E6
  delay(600);
  tone(buzzerPin, 1175, 200);  //D6
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 988, 500);  //B5
  delay(500);
  tone(buzzerPin, 988, 200);  //B5
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 1175, 500);  //D6
  delay(500);
  tone(buzzerPin, 1318, 500);  //E6
  delay(500);
  tone(buzzerPin, 1046, 500);  //C6
  delay(500);
  tone(buzzerPin, 880, 500);  //A5
  delay(500);
  tone(buzzerPin, 880, 500);  //A5
  delay(800);

  tone(buzzerPin, 1175, 500);  //D6
  delay(500);
  tone(buzzerPin, 1397, 200);  //F6
  delay(200);
  tone(buzzerPin, 1760, 500);  //A6
  delay(500);
  tone(buzzerPin, 1568, 200);  //G6
  delay(200);
  tone(buzzerPin, 1397, 200);  //F6
  delay(200);
  tone(buzzerPin, 1318, 800);  //E6
  delay(800);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 1318, 500);  //E6
  delay(500);
  tone(buzzerPin, 1175, 200);  //D6
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 988, 500);  //B5
  delay(500);
  tone(buzzerPin, 988, 200);  //B5
  delay(200);
  tone(buzzerPin, 1046, 200);  //C6
  delay(200);
  tone(buzzerPin, 1175, 500);  //D6
  delay(500);
  tone(buzzerPin, 1318, 500);  //E6
  delay(500);
  tone(buzzerPin, 1046, 500);  //C6
  delay(500);
  tone(buzzerPin, 880, 500);  //A5
  delay(500);
  tone(buzzerPin, 880, 500);  //A5
  delay(500);

  while (true) {}
}
