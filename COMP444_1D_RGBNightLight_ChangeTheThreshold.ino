int photoresistor = A0;
int potentiometer = A1;
//int threshold = 700;

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
  int threshold = potentiometer;

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);
  Serial.print("   Potentiometer value:");
  Serial.println(potentiometer);

  if (photoresistor < threshold) {
    if (threshold > 250 && threshold <= 500) {
      red();
      delay(1000);
      orange();
      delay(1000);
      yellow();
      delay(1000);
    }
    if (threshold > 500 && threshold <= 750) {
      lightGreen();
      delay(1000);
      green();
      delay(1000);
      cyan();
      delay(1000);
      blue();
      delay(1000);
    }
    if (threshold > 750) {
      violet();
      delay(1000);
      magenta();
      delay(1000);
      pink();
      delay(1000);
    } else {
      turnOff();
    }
    delay(100);
  }
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
  // New colour
  void lightGreen() {
    analogWrite(RedPin, 128);
    analogWrite(GreenPin, 255);
    analogWrite(BluePin, 0);
  }
  void green() {
    analogWrite(RedPin, 0);
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
  // New colour
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
  //New colour
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
