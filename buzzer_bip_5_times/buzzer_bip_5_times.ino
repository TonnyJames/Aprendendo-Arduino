int buzzer = 8;
int i = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for(i; i < 5; i++){
    tone(buzzer, 1500);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
}
