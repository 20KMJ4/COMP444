
void setup() {

  pinMode(13, OUTPUT);
}


void loop() {

  digitalWrite(13, HIGH);
  delay(2000); //1A
  //delay(14); //for red LED 
  //delay(12); //for blue, green, and yellow LEDs

  digitalWrite(13, LOW);
  delay(2000); //1A
  //delay(14); //for red LED
  //delay(12); //for blue, green, and yellow LEDs
}