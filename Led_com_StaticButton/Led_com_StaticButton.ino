int buttonPin = 7;
int ledPin = 10;
int estadoButton = 0;
bool estadoLed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoButton = digitalRead(buttonPin);
  if (estadoButton == HIGH) {
    estadoLed = !estadoLed;
    delay(200);
    if (estadoLed == true) {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
}
