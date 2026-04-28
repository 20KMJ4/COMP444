#include <Servo.h>

const int trigPin = 11;
const int echoPin = 12;

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

const int buzzerPin = 10;

float distance = 0;

Servo myservo;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  myservo.attach(9);
}

void loop() {
  distance = getDistance();

  Serial.print(myservo);
  Serial.println(" in");

  if (distance <= 10) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    tone(buzzerPin, 272);
    myservo.write(160);
    delay(300);

    myservo.write(100);
    delay(300);

  } else if (10 < distance && distance < 20) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);
    
    tone(buzzerPin, 272);
    delay(250);
    noTone(buzzerPin);
    delay(250);

  } else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);

    tone(buzzerPin, 272);
    delay(100);
    noTone(buzzerPin);
    delay(500);
  }

  delay(50);
}

//------------------------------------------

float getDistance() {
  float echoTime;
  float calculatedDistance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

  calculatedDistance = echoTime / 148.0;

  return calculatedDistance;
}
