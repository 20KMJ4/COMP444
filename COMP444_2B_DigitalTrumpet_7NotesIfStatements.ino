int firstKeyPin = 4;
int secondKeyPin = 3;
int thirdKeyPin = 2;

int buzzerPin = 10;

int frequency = ' ';

void setup() {
  Serial.begin(9600);

  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  Serial.print("Frequency");
  Serial.println(frequency);
  /* Comments for Testing
   Serial.print("First button");
   Serial.print(digitalRead(firstKeyPin));
   Serial.print("     Second button");
   Serial.print(digitalRead(secondKeyPin));
   Serial.print("        Third button");
   Serial.println(digitalRead(thirdKeyPin));
   */

  if (digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW) {
    frequency = 262;  //play c
    tone(buzzerPin,frequency);
  } 
  else if (digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == LOW) {
    frequency = 294;  //play d
    tone(buzzerPin,frequency);
  } 
  else if (digitalRead(firstKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW) {
    frequency = 330;  //play e
    tone(buzzerPin,frequency);
  } 
  else if (digitalRead(secondKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW) {
    frequency = 349;  //play f
    tone(buzzerPin,frequency);
  } 
  else if (digitalRead(firstKeyPin) == LOW) {
    frequency = 392;  //Play g
    tone(buzzerPin,frequency);
  }
  else if (digitalRead(secondKeyPin) == LOW) {
    frequency = 440;  // play a
    tone(buzzerPin,frequency);
  }
  else if (digitalRead(thirdKeyPin) == LOW) {
    frequency = 494;  //play b
    tone(buzzerPin,frequency);
  }
  else {
    frequency = 0;
    noTone(buzzerPin);
  }
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
