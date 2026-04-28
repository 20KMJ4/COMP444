#include <Servo.h>

int potPosition;
int servoPosition;

Servo myservo;

void setup() {

  myservo.attach(9);
  //Serial.begin(9600);  // For troubleshooting
}

void loop() {

  potPosition = analogRead(A0);

  servoPosition = map(potPosition, 0, 1023, 20, 160);  //3A

  //servoPosition = map(potPosition, 0, 1023, 160, 20); // CC Reverse Servo Direction

  //servoPosition = map(potPosition, 0, 1023, 50, 100); // CC Change the Range - Large Pot/Small Servo
  //servoPosition = map(potPosition, 0, 500, 20, 160); // CC Change the Range - Medium Pot/Large Servo

  //potPosition = constrain(potPosition, 0, 250); // Only required for pot 0-250
  //servoPosition = map(potPosition, 0, 250, 20, 160);  // CC Change the Range - Small Pot/Large Servo

  //servoPosition = map(potPosition, 850, 1023, 20, 160); // CC Change the Range - Small Pot high values/Large Servo
  myservo.write(servoPosition);


  // For troubleshooting
  //Serial.println(potPosition);
  //delay(100);
}