int potPosition;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  potPosition = 2*analogRead(A0); // 1B CC Changing the Range
  //potPosition = analogRead(A0); //Circuit 1B
  Serial.println(potPosition);

  digitalWrite(13, HIGH);
  delay(potPosition);

  digitalWrite(13, LOW);
  delay(potPosition);
}
