const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

const int PWMB = 10;
const int BIN2 = 9;
const int BIN1 = 8;

const int trigPin = 6;
const int echoPin = 5;

int switchPin = 7;

float distance = 0;

int backupTime = 300;
int turnTime = 200; // 5C
//int turnTime = 700; // 5C CC Change the Behaviour of the Robot When it Senses an Obstacle
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(switchPin, INPUT_PULLUP);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);
  Serial.print("To infinity and beyond!");
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" in");

  if (digitalRead(switchPin) == LOW) {
    //Either distance can be used with CC Change the Behaviour of the Robot When it Senses an Obstacle
    // I used distance < 20 in video
    if (distance < 10) { // 5C
    //if (distance < 20) { // 5C CC Change the Distance at Which Your Robot Reacts
      Serial.print(" ");
      Serial.print("BACK!");

      rightMotor(0);
      leftMotor(0);
      delay(200);

      rightMotor(-255);
      leftMotor(-255);
      delay(backupTime);

      rightMotor(255);
      leftMotor(-255);
      delay(turnTime);
    } else {
      Serial.print(" ");
      Serial.print("Moving...");

      rightMotor(255);
      leftMotor(255);
    }
  } else {
    rightMotor(0);
    leftMotor(0);
  }

  delay(50);
}

//---------------------------------------------------------------
void rightMotor(int motorSpeed) {
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

//----------------------------------------------------------------
void leftMotor(int motorSpeed) {
  if (motorSpeed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else if (motorSpeed < 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
  analogWrite(PWMB, abs(motorSpeed));
}

//------------------------------------------------------------------
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