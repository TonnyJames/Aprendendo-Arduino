#include <Thermistor.h>

Thermistor temp(4);


void setup() {
Serial.begin(9600);
}

void loop() {
int temperature = temp.getTemp();
Serial.print("temperatura: ");
Serial.print(abs(temperature));
Serial.println("Cº");
delay(1000);
}
