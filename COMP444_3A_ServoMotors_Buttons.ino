#include <Servo.h>

int greenButton = 10;
int redButton = 8;
int servoPosition;

Servo myservo;

void setup() {
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  myservo.attach(9);
}

void loop() {
  servoPosition = constrain(servoPosition,20,160);
  if(digitalRead(greenButton) == LOW){
    servoPosition += 5; 
    delay(25);
  }
  else if (digitalRead(redButton)== LOW){
    servoPosition--;
    delay(25);
  }
  myservo.write(servoPosition);
}