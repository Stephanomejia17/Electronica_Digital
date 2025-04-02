#include <Arduino.h>

// Hello World

void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(12)) {
    digitalWrite(14, HIGH);
  } else {
    digitalWrite(14, LOW);
  }
}

