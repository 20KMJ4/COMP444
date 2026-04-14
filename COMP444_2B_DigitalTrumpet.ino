int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;

int buzzerPin = 10;

void setup() {
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(digitalRead(firstKeyPin)== LOW){
    tone(buzzerPin,262); //play C
    tone(buzzerPin,349); //CC play F
  }
  else if (digitalRead(secondKeyPin)==LOW){
    tone(buzzerPin,330); //play E
    tone(buzzerPin,440); //CC play A
  }
  else if (digitalRead(thirdKeyPin)==LOW){
    tone(buzzerPin,392); //play G
    tone(buzzerPin,523); //CC Play C5
  }
  else{
    noTone(buzzerPin);
  }
}