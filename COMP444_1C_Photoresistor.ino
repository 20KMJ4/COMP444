int photoresistor = 0;
int threshold = 370;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  photoresistor = analogRead(A0);
  Serial.println(photoresistor);

  if (photoresistor < threshold){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  delay(100);
}
