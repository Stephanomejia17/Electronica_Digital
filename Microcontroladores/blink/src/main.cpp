#include <Arduino.h>

// Hello World

void setup() {
  // put your setup code here, to run once:
  pinMode(36, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(36, HIGH); // Encender Led
  delay(1000);            // Esperar 1 segundo
  digitalWrite(36, LOW); // Apagar Led
  delay(1000);           // Esperar 1 segundo
}

