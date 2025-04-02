#include <Arduino.h>
#include <ctime>


std::time_t tiempo_actual = std::time(nullptr);
std::time_t tiempo_aux = 0;

void setup() {
  pinMode(16, INPUT);
  pinMode(18, INPUT);

  pinMode(17, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(14, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  Serial.println("hola");
  if (digitalRead(18) == HIGH && digitalRead(16) == HIGH) {
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
    tiempo_aux = tiempo_actual;

    Serial.println("Rojo");

    }

  else if (digitalRead(16) == HIGH && tiempo_actual-tiempo_aux < 10) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(14, LOW);
    
    tiempo_actual = std::time(nullptr);
    Serial.println(tiempo_actual);
    Serial.println("Switch 1");
    
  } 
  
  else if (digitalRead(17) == HIGH) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    Serial.println("Switch 4");
    tiempo_aux = tiempo_actual;
    tiempo_actual = std::time(nullptr);
    Serial.println(tiempo_actual);


  } else if (digitalRead(16) == HIGH && (tiempo_actual-tiempo_aux) >= 10) {
    digitalWrite(14, HIGH);
    delay(1000);
    digitalWrite(14, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    Serial.println("Amarillo");
    } 
  
  
}
