int reedPin = 8;
int ledPin = 9;
int valorLido = 0;

void setup() {
  Serial.begin(9600);
  pinMode(reedPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  valorLido = digitalRead(reedPin);
  if (valorLido == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println();
  } else  {
    Serial.println("ALERTA: Campo magnético detectado");
    digitalWrite(ledPin, HIGH);
  }
  delay(100);
}
