void setup() {
  pinMode(3, OUTPUT);
  pinMode(6, INPUT);
  digitalWrite(3, LOW);
}

void loop() {
  int leitor = digitalRead(6);

  if (leitor == HIGH) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(3, HIGH);
      delay(200);
      digitalWrite(3, LOW);
      delay(200);
    }
    delay(2000);
  }
  else {
    digitalWrite(3, LOW);
  }
}