int button[] = { 2, 4, 6, 8 };
int led[] = { 3, 5, 7, 9 };
int tones[] = { 262, 330, 392, 494 };

int roundsToWin = 10;
int buttonSequence[16];

int buzzerPin = 10;

int pressedButton = 4;
int roundCounter = 1;

long startTime = 0;
long timeLimit = 2000;

boolean gameStarted = false;


void setup() {
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);
  pinMode(button[3], INPUT_PULLUP);

  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (gameStarted == false) {
    startSequence();
    roundCounter = 0;
    delay(1500);
    gameStarted = true;
  }

  for (int i = 0; i <= roundCounter; i++) {
    flashLED(buttonSequence[i]);
    delay(200);
    allLEDoff();
    delay(200);
  }

  for (int i = 0; i <= roundCounter; i++) {

    startTime = millis();

    while (gameStarted == true) {

      pressedButton = buttonCheck();

      if (pressedButton < 4) {
        flashLED(pressedButton);

        if (pressedButton == buttonSequence[i]) {
          delay(250);
          allLEDoff();
          break;
        } else {
          loseSequence();
          break;
        }
      } else {
        allLEDoff();
      }

      if (millis() - startTime > timeLimit) {
        loseSequence();
        break;
      }
    }
  }
  if (gameStarted == true) {
    roundCounter = roundCounter + 1;
    if (roundCounter >= roundsToWin) {
      winSequence();
    }
    delay(500);
  }
}

//--------------------FUNCTIONS----------------------------

void flashLED(int ledNumber) {
  digitalWrite(led[ledNumber], HIGH);
  tone(buzzerPin, tones[ledNumber]);
}

void allLEDoff() {
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);

  noTone(buzzerPin);
}

int buttonCheck() {
  if (digitalRead(button[0]) == LOW) {
    return 0;
  } else if (digitalRead(button[1]) == LOW) {
    return 1;
  } else if (digitalRead(button[2]) == LOW) {
    return 2;
  } else if (digitalRead(button[3]) == LOW) {
    return 3;
  } else {
    return 4;
  }
}

void startSequence() {

  randomSeed(1);  //  randomSeed(analogRead(A0));

  for (int i = 0; i <= roundsToWin; i++) {
    buttonSequence[i] = round(random(0, 4));
  }

  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 131, 300);  //C3
  delay(300);
  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 117, 50);  //Bb2
  delay(50);
  tone(buzzerPin, 123, 100);  //B2
  delay(200);
  tone(buzzerPin, 98, 300);  //G
  delay(1000);
  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 131, 300);  //C3
  delay(300);
  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 117, 50);  //Bb2
  delay(50);
  tone(buzzerPin, 123, 100);  //B2
  delay(200);
  tone(buzzerPin, 98, 300);  //G
  delay(1000);
  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 131, 300);  //C3
  delay(300);
  tone(buzzerPin, 98, 300);  //G2
  delay(300);
  tone(buzzerPin, 117, 50);  //Bb2
  delay(50);
  tone(buzzerPin, 123, 100);  //B2
  delay(200);
  tone(buzzerPin, 98, 300);  //G
  delay(400);

  /* Attempt at Windows XP startup sound
  tone(buzzerPin,1245,400); //Eb6
  delay(100);
  tone(buzzerPin,622,200);//Eb5
  delay(100);
  tone(buzzerPin,932,1000);//Bb
  delay(100);
  tone(buzzerPin,622,400);
  delay(100);
  tone(buzzerPin,831,400);//Ab
  delay(100);
  tone(buzzerPin,622,400);
  delay(100);
  tone(buzzerPin,1245,400);
  delay(100);
  tone(buzzerPin,932,1000);
  delay(100);
  */

  for (int i = 0; i <= 3; i++) {

    //tone(buzzerPin, tones[i], 200);

    digitalWrite(led[0], HIGH);
    digitalWrite(led[1], HIGH);
    digitalWrite(led[2], HIGH);
    digitalWrite(led[3], HIGH);

    delay(100);

    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
    digitalWrite(led[3], LOW);

    delay(100);
  }
}

void winSequence() {

  for (int j = 0; j <= 3; j++) {
    digitalWrite(led[j], HIGH);
  }

  tone(buzzerPin, 196, 150);  //G3
  delay(175);
  tone(buzzerPin, 262, 150);  // C4
  delay(175);
  tone(buzzerPin, 330, 150);  // E4
  delay(175);
  tone(buzzerPin, 392, 150);  //G4
  delay(175);
  tone(buzzerPin, 523, 150);  //C5
  delay(175);
  tone(buzzerPin, 659, 150);  //E5
  delay(175);
  tone(buzzerPin, 784, 400);  //G5
  delay(475);
  tone(buzzerPin, 659, 150);  //E5
  delay(300);


  tone(buzzerPin, 208, 150);  //Ab3
  delay(175);
  tone(buzzerPin, 262, 150);  // C4
  delay(175);
  tone(buzzerPin, 311, 150);  // Eb4
  delay(175);
  tone(buzzerPin, 415, 150);  //Ab4
  delay(175);
  tone(buzzerPin, 523, 150);  //C5
  delay(175);
  tone(buzzerPin, 622, 150);  //Eb5
  delay(175);
  tone(buzzerPin, 831, 400);  //Ab5
  delay(475);
  tone(buzzerPin, 622, 150);  //Eb5
  delay(300);

  tone(buzzerPin, 233, 150);  //Bb3
  delay(175);
  tone(buzzerPin, 294, 150);  // D4
  delay(175);
  tone(buzzerPin, 349, 150);  // F4
  delay(175);
  tone(buzzerPin, 466, 150);  //Bb4
  delay(175);
  tone(buzzerPin, 587, 150);  //D5
  delay(175);
  tone(buzzerPin, 698, 150);  //F5
  delay(175);
  tone(buzzerPin, 932, 400);  //Bb5
  delay(475);
  tone(buzzerPin, 932, 150);  //Bb5
  delay(200);
  tone(buzzerPin, 932, 150);  //Bb5
  delay(200);
  tone(buzzerPin, 932, 150);  //Bb5
  delay(200);
  tone(buzzerPin, 1046, 1000);  //C6
  delay(1000);

  do {
    pressedButton = buttonCheck();
  } while (pressedButton > 3);
  delay(100);

  gameStarted = false;
}

void loseSequence() {
  for (int j = 0; j <= 3; j++) {
    digitalWrite(led[j], HIGH);
  }

  tone(buzzerPin, 73, 500);  //D
  delay(600);
  tone(buzzerPin, 69, 500);  //Db
  delay(600);
  tone(buzzerPin, 65, 500);  //C
  delay(600);
  tone(buzzerPin, 62, 1000);  //B
  delay(110);
  /*
    tone(buzzerPin, 58, 100);//Bb
  delay(110);
    tone(buzzerPin, 62, 100);//B
  delay(110);
    tone(buzzerPin, 58, 100);//Bb
  delay(110);
    tone(buzzerPin, 62, 100);//B
  delay(110);
*/
  do {
    pressedButton = buttonCheck();
  } while (pressedButton > 3);
  delay(200);

  gameStarted = false;
}