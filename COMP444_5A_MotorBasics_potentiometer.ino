const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

int buttonPin = 7;
int potPosition;

int motorSpeed = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  potPosition = analogRead(A0);  // 1023

  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);
  Serial.print("Pot position: ");
  Serial.println(potPosition);

  if (potPosition < 10) {
    motorSpeed = 0;
  } else if (potPosition >= 10 && potPosition < 190) {
    motorSpeed = -255;
  } else if (potPosition >= 190 && potPosition < 380) {
    motorSpeed = -150;
  } else if (potPosition >= 380 && potPosition < 570) {
    motorSpeed = -50;
  } else if (potPosition >= 570 && potPosition < 760) {
    motorSpeed = 50;
  } else if (potPosition >= 760 && potPosition < 950) {
    motorSpeed = 150;
  } else if (potPosition >= 950) {
    motorSpeed = 255;
  }
  spinMotor(motorSpeed);
}

// -----------------------------------------------------
void spinMotor(int motorSpeed) {
  if (motorSpeed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else if (motorSpeed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
  analogWrite(PWMA, abs(motorSpeed));
}