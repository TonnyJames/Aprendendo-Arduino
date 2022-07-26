int buttonPin = 7;
int ledPin = 10;
int estadoButton = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoButton = digitalRead(buttonPin);
  if (estadoButton == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(100);
  }else {
    digitalWrite(ledPin, LOW);
  }
}
