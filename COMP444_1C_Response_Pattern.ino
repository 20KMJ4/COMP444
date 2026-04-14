int photoresistor = 0;
int threshold = 550;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  photoresistor = analogRead(A0);
  Serial.println(photoresistor);

  if (photoresistor < threshold){
    //H
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(150);

  //E
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(150);

  //L
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(150);

  //L
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(150);

  //O
  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(1500);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(350);

  //W
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);
  
  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(150);

  //O
  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(350);

  //R
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);
  
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(150);

  //L
  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(150);

  //D
  digitalWrite(13, HIGH);
  delay(150);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(50);

  digitalWrite(13, HIGH);
  delay(50);

  digitalWrite(13, LOW);
  delay(350);
  }
  else{
    digitalWrite(13,LOW);
  }
  delay(100);
}
