const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

int switchPin = 7;

int motorSpeed = 0;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  Serial.begin(9600);

  Serial.println("Enter motor speed (0-255)... ");
}

void loop() {
  if (Serial.available() > 0) {
    motorSpeed = Serial.parseInt();

    Serial.print("Motor Speed: ");
    Serial.println(motorSpeed);
  }

  if (digitalRead(7) == LOW) {
    spinMotor(motorSpeed);
  } else {
    spinMotor(-1*motorSpeed);
  }
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
