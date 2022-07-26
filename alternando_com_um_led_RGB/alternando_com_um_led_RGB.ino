int vermelho = 12;
int verde = 10;
int azul = 9;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}
void loop() {
  digitalWrite(vermelho, HIGH);
  delay(1000);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH);
  delay(1000);
  digitalWrite(azul, LOW);
}
