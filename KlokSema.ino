const int dirPin = 12;
const int stepPin = 11;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(dirPin, true); // richting
}

void runStepper(int steps){
  for(int i=0;i<steps;i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000); // pulsbreedte, regelt snelheid (
    digitalWrite(stepPin, LOW);
    delayMicroseconds(5000);
  }
}

void loop() {
  /*
   * Driver is geconfigureerd op 800 stappen. 800/60 is 13,333 stappen voor 1 seconde; dus na 3 keer
   * 13 stappen moet er een stap extra komen.
   * Dit zijn dan 4 seconden; 60 / 4 is 15, ie er moet 15 keer deze loop gedaan worden.
   * Dit geeft geen 800 stappen, er komen er 5 tekort, daarom wordt er bij de derde 1 stap extra gedaan.
   */
  // Eerste
  for(int i=0;i<3;i++){
  runStepper(13);
  delay(870); // 1000 - 13 x 10 us voor de tijd van de stappen
  }
  runStepper(14);
  delay(860);

  // Tweede
  for(int i=0;i<3;i++){
  runStepper(13);
  delay(870);
  }
  runStepper(14);
  delay(860);

  //Derde met 1 extra stap
  runStepper(13);
  delay(870);
  runStepper(14);
  delay(860);
  runStepper(13);
  delay(870);
  runStepper(14);
  delay(860);
}
