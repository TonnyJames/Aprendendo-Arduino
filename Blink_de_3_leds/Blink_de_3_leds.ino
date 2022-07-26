int yellow = 13;
int green = 12;
int red = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
}
