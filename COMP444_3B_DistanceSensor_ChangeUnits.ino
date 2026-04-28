const int trigPin = 11;
const int echoPin = 12;

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

float distance = 0;
float distanceFt = 0;
float distanceCm = 0;
float distancem = 0;
float distanceMm = 0;
float distanceum = 0;
float distanceGm = 0;
float distancePm = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  distance = getDistance();
  distanceFt = distance / 12;
  distanceCm = distance * 2.54;
  distancem = distanceCm / 100;
  distanceMm = distancem * pow(10, -6);
  distanceum = distancem * pow(10, 6);
  distanceGm = distancem * pow(10, -9);
  distancePm = distancem * pow(10, 12);

  Serial.print(distance);
  Serial.println(" in");

  Serial.print(distanceFt);
  Serial.println(" ft");

  Serial.print(distanceCm, 12);
  Serial.println(" cm");

  Serial.print(distancem, 12);
  Serial.println(" m");

  Serial.print(distanceMm, 12);
  Serial.println(" Mm");

  Serial.print(distanceum, 12);
  Serial.println(" um");

  Serial.print(distanceGm, 12);
  Serial.println(" gm");

  Serial.print(distancePm, 12);
  Serial.println(" pm");

  if (distance <= 2) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  } else if (2 < distance && distance < 10) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);
  } else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }

  delay(50);
}
//-----------------------------------------------------------
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
