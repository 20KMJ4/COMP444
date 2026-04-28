#include <Servo.h>

int servoPosition;

Servo myservo;

void setup() {

  myservo.attach(9);
  myservo.write(160);
  //Serial.begin(9600); All serial montior usage was for troubleshooting and verification
}

void loop() {

for (servoPosition = 160; servoPosition >= 30; servoPosition -= 5){
    myservo.write(servoPosition);
    delay(50);
    //Serial.println(servoPosition);
  }

  for (servoPosition = 29; servoPosition >= 11; servoPosition -= 1){
    myservo.write(servoPosition);
    delay(100);
    //Serial.println(servoPosition);
  }

    for (servoPosition = 10; servoPosition <= 29; servoPosition += 1){
    myservo.write(servoPosition);
    delay(100);
    //Serial.println(servoPosition);
  }

  for (servoPosition = 30; servoPosition <= 160; servoPosition += 5){
    myservo.write(servoPosition);
    delay(50);
    //Serial.println(servoPosition);
  }

  delay(2000);

}