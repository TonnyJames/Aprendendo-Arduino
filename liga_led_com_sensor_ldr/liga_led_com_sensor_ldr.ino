int led = 10;
int ldr = A0;
int valorldr = 0;

void setup() {
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorldr = analogRead(ldr);
  Serial.println(valorldr);
  if (valorldr < 500) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
