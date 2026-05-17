const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

int buttonPin = 7;

int motorSpeed = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

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
    spinMotorForward(motorSpeed);
  } 
  else if (digitalRead(7) == HIGH){
    spinMotorBackward(motorSpeed);
  }
  if (motorSpeed == 0){
      stopMotor(motorSpeed);
  }
}

// -----------------------------------------------------
void spinMotorForward(int motorSpeed) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  analogWrite(PWMA, abs(motorSpeed));
}

void spinMotorBackward(int motorSpeed) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, abs(motorSpeed));
}
void stopMotor(int motorSpeed) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  analogWrite(PWMA, abs(motorSpeed));
}
