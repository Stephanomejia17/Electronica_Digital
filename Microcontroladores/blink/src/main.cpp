#include <Arduino.h>

// Hello World

void setup() {
  // put your setup code here, to run once:
  pinMode(18, OUTPUT);
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(18, HIGH); // Encender Led
  Serial.println("test");
  delay(1000);            // Esperar 1 segundo
  digitalWrite(18, LOW); // Apagar Led
  delay(1000);           // Esperar 1 segundo
}

