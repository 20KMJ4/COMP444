int speakerPin = 10;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  //eighth note = 1
  //quarter note = 2
  //half note = 4
  play('C', 2); //baa
  play('C', 2); //baa
  play('G', 2);
  play('G', 2);
  play('A', 1);
  play('B', 1);
  play('c', 1);
  play('A', 1);
  play('G', 4); //wool

  play('F', 2); //yes
  play('F', 2);
  play('E', 2);
  play('E', 2);
  play('D', 2);
  play('D', 2);
  play('C', 4); //full

  play('G', 2); //one
  play('G', 1);
  play('G', 1);
  play('F', 2); //mas-
  play('F', 2); //ter
  play('E', 2); //one
  play('E', 1);
  play('E', 1);
  play('D', 4); //dame

  play('G', 2); //one
  play('G', 1);
  play('G', 1);
  play('F', 1); 
  play('F', 1); 
  play('F', 1); 
  play('F', 1); 
  play('E', 2); 
  play('E', 1);
  play('E', 1);
  play('D', 4); //lane

  play('C', 2); //baa
  play('C', 2); //baa
  play('G', 2);
  play('G', 2);
  play('A', 1);
  play('B', 1);
  play('c', 1);
  play('A', 1);
  play('G', 4); //wool

  play('F', 2); //yes
  play('F', 2);
  play('E', 2);
  play('E', 2);
  play('D', 2);
  play('D', 2);
  play('C', 4); //full

  while (true) {}
}

void play(char note, int beats) {
  int numNotes = 8;

  char notes[] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c'};

  int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523};

  int currentFrequency = 0;
  int beatLength = 200;

  for (int i = 0; i < numNotes; i++) {
    if (notes[i] == note) {
      currentFrequency = frequencies[i];
    }
  }

  tone(speakerPin, currentFrequency, beats * beatLength);
  delay(beats * beatLength);
  delay(50);
}