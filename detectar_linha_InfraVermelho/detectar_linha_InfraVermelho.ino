int pinoIR = 8;
int ledPin = 9;
int valorLido = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoIR, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  valorLido = digitalRead(pinoIR);
  if (valorLido == LOW) {
    Serial.println("Linha detectada");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("Linha não detectada");
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
