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
    red();
    delay(500);
    red2();
    delay(500);
    red3();
    delay(500);
    orange();
    delay(500);
    orange2();
    delay(500);
    orange3();
    delay(500);
    yellow();
    delay(500);
    yellow2();
    delay(500);
    yellow3();
    delay(500);
    lightGreen();
    delay(500);
    lightGreen2();
    delay(500);
    lightGreen3();
    delay(500);
    green();
    delay(500);
    green2();
    delay(500);
    green3();
    delay(500);
    cyan();
    delay(500);
    cyan2();
    delay(500);
    cyan3();
    delay(500);
    blue();
    delay(500);
    blue2();
    delay(500);
    blue3();
    delay(500);
    violet();
    delay(500);
    violet2();
    delay(500);
    violet3();
    delay(500);
    magenta();
    delay(500);
    magenta2();
    delay(500);
    magenta3();
    delay(500);
    pink();
    delay(500);
    pink2();
    delay(500);
    pink3();
    delay(500);
  } else {
    turnOff();
  }
  delay(100);
}

void red() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void red2() {
  analogWrite(RedPin, 255 / 2);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void red3() {
  analogWrite(RedPin, 255 / 4);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 45);
  analogWrite(BluePin, 0);
}
void orange2() {
  analogWrite(RedPin, 255 / 2);
  analogWrite(GreenPin, 45 / 2);
  analogWrite(BluePin, 0);
}
void orange3() {
  analogWrite(RedPin, 255 / 4);
  analogWrite(GreenPin, 45 / 4);
  analogWrite(BluePin, 0);
}
void yellow() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 150);
  analogWrite(BluePin, 0);
}
void yellow2() {
  analogWrite(RedPin, 255 / 2);
  analogWrite(GreenPin, 150 / 2);
  analogWrite(BluePin, 0);
}
void yellow3() {
  analogWrite(RedPin, 255 / 4);
  analogWrite(GreenPin, 150 / 4);
  analogWrite(BluePin, 0);
}
// New colour
void lightGreen() {
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void lightGreen2() {
  analogWrite(RedPin, 128/2);
  analogWrite(GreenPin, 255/2);
  analogWrite(BluePin, 0);
}
void lightGreen3() {
  analogWrite(RedPin, 128/4);
  analogWrite(GreenPin, 255/4);
  analogWrite(BluePin, 0);
}
void green() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void green2() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255/2);
  analogWrite(BluePin, 0);
}
void green3() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255/4);
  analogWrite(BluePin, 0);
}
void cyan() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 255);
}
void cyan2() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255/2);
  analogWrite(BluePin, 255/2);
}
void cyan3() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255/4);
  analogWrite(BluePin, 255/4);
}
void blue() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void blue2() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/2);
}
void blue3() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/4);
}
// New colour
void violet() {
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void violet2() {
  analogWrite(RedPin, 128/2);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/2);
}
void violet3() {
  analogWrite(RedPin, 128/4);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/4);
}
void magenta() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void magenta2() {
  analogWrite(RedPin, 255/2);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/2);
}
void magenta3() {
  analogWrite(RedPin, 255/4);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255/4);
}
//New colour
void pink() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 128);
}
void pink2() {
  analogWrite(RedPin, 255/2);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 128/2);
}
void pink3() {
  analogWrite(RedPin, 255/4);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 128/4);
}
void turnOff() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}