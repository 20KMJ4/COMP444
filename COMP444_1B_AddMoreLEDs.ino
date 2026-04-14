int potPosition;
int potPositionMultiply;
int potPositionDivide;
int potPositionAdd;
int potPositionSubtract;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  potPosition = analogRead(A0); //original
  Serial.println(potPosition);
  potPositionMultiply = 3*analogRead(A0); //multiplied by 3
  Serial.println(potPositionMultiply);
  potPositionDivide = analogRead(A0)/2; //divided by 2
  Serial.println(potPositionDivide);
  potPositionAdd = analogRead(A0) + 500; //added 500
  Serial.println(potPositionAdd);
  potPositionSubtract = analogRead(A0) - 200; //subtracted 200
  Serial.println(potPositionSubtract);
  

// Original potentiometer value
  digitalWrite(13, HIGH);
  delay(potPosition);

  digitalWrite(13, LOW);
  delay(potPosition);

  // Multiplied potentiometer value
  digitalWrite(11, HIGH);
  delay(potPositionMultiply);

  digitalWrite(11, LOW);
  delay(potPositionMultiply);

  // Divided potentiometer value
  digitalWrite(8, HIGH);
  delay(potPositionDivide);

  digitalWrite(8, LOW);
  delay(potPositionDivide);

  // Added potentiometer value
  digitalWrite(6, HIGH);
  delay(potPositionAdd);

  digitalWrite(6, LOW);
  delay(potPositionAdd);

  // Subtracted potentiometer value
  digitalWrite(2, HIGH);
  delay(potPositionSubtract);

  digitalWrite(2, LOW);
  delay(potPositionSubtract);
}
