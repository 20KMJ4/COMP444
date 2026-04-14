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
    if (potentiometer > 0 && potentiometer <= 100)
      red();
    if (potentiometer > 100 && potentiometer <= 200)
      orange();
    if (potentiometer > 200 && potentiometer <= 300)
      yellow();
    if (potentiometer > 300 && potentiometer <= 400)
      lightGreen();
    if (potentiometer > 400 && potentiometer <= 500)
      green();
    if (potentiometer > 500 && potentiometer <= 600)
      cyan();
    if (potentiometer > 600 && potentiometer <= 700)
      blue();
    if (potentiometer > 700 && potentiometer <= 800)
      violet();
    if (potentiometer > 800 && potentiometer <= 900)
      magenta();
    if (potentiometer > 900)
      pink();
  } else {
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
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 45);
  analogWrite(BluePin, 0);
}
void yellow() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 150);
  analogWrite(BluePin, 0);
}
void lightGreen() {
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void green() {
  analogWrite(RedPin,0 );
  analogWrite(GreenPin, 255);
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
void violet() {
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void magenta() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void pink() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 128);
}
void turnOff() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
