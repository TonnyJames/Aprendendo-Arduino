int ledPin = 9;
int potPin = A5;
int valorPot = 0;
int pwm = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
   valorPot = analogRead(potPin);
   pwm = map(valorPot, 0, 1023, 0, 255);
   Serial.println(pwm);
   analogWrite(ledPin, pwm);
   delay(100);
}
