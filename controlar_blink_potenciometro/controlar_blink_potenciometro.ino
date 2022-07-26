int ledPin = 9;
int potPin = A5;
int tempo = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  tempo = analogRead(potPin);
  Serial.println(tempo);

  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(tempo);
}
