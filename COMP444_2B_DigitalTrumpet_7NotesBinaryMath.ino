int firstKeyPin = 4;
int secondKeyPin = 3;
int thirdKeyPin = 2;

int buzzerPin = 10;

int total = 0;
int first = 0;
int second = 0;
int third = 0;

void setup() {
  Serial.begin(9600);

  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  first = 0;
  second = 0;
  third = 0;
  Serial.print("Total");
  Serial.println(total);
  Serial.print("First");
  Serial.println(first);
  Serial.print("Second");
  Serial.println(second);
  Serial.print("Third");
  Serial.println(third);


  if (digitalRead(firstKeyPin) == LOW) {
    first = 1;
  }
  if (digitalRead(secondKeyPin) == LOW) {
    second = 2;
  }
  if (digitalRead(thirdKeyPin) == LOW) {
    third = 4;
  }

  total = first + second + third;

  if (total > 0) {
    play(total);
  } else {
    noTone(buzzerPin);
  }
}

void play(int totalbinary) {
  int numBinary = 7;

  int binary[] = { 1, 2, 3, 4, 5, 6, 7};
  int frequencies[] = { 262, 294, 330, 349, 392, 440, 494};

  int currentFrequency = 0;

  for (int i = 0; i < numBinary; i++) {
    if (binary[i] == totalbinary) {
      currentFrequency = frequencies[i];
    }
  }

  tone(buzzerPin, currentFrequency);
}

/*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/
