int photoresistor = A0;
int potentiometer = A1;
int threshold = 700;

int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);

  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  photoresistor = analogRead(A0);
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);
  Serial.print("   Potentiometer value:");
  Serial.println(potentiometer);

  if (photoresistor < threshold) {
    if (potentiometer > 0 && potentiometer <= 150)
      red();
    if (potentiometer > 150 && potentiometer <= 300)
      orange();
    if (potentiometer > 300 && potentiometer <= 450)
      yellow();
    if (potentiometer > 450 && potentiometer <= 600)
      green();
    if (potentiometer > 600 && potentiometer <= 750)
      cyan();
    if (potentiometer > 750 && potentiometer <= 900)
      blue();
    if (potentiometer > 900)
      magenta();
  } 
  else {
    turnOff();
  }
  delay(100);
}

void red() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 50);
  analogWrite(BluePin, 0);
}
void yellow() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void green() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void cyan() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void turnOff() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
