const int trigPin = 11;
const int echoPin = 12;

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

float distance = 0;

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

  Serial.print(distance);
  Serial.println(" in");


  if (distance <= 10) { // 3B
  //if (distance <= 2) {  // CC Change the Limits
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    } else if (10 < distance && distance < 20) { // 3B
  //else if (2 < distance && distance < 10) { // CC Change the Limits
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
