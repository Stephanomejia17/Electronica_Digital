#include <Arduino.h>

#define TRIG_PIN 27  // Pin de activación (Trigger)
#define ECHO_PIN 26  // Pin de eco (Echo)
int cont_alto=0, cont_bajo = 0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT);   
  
  Serial.begin(9600);
  Serial.println("HC-SR04 listo...");
}

void loop() {
  unsigned long tiempo_eco, tiempo_inicial, tiempo_final;
  float distancia;

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

  if(digitalRead(ECHO_PIN) == HIGH && cont_alto==0){
    Serial.println("entro");
    tiempo_inicial = micros();
    cont_alto=1;

  } else if (digitalRead(ECHO_PIN) == LOW && cont_bajo == 0) {
    tiempo_final = micros();
    cont_bajo = 1;
  } else if (cont_alto == 1 && cont_bajo == 1) {
    cont_bajo = 0;
  }


  tiempo_eco = tiempo_final - tiempo_inicial;
  Serial.println(tiempo_inicial);
  Serial.println(tiempo_final);
  Serial.println(tiempo_eco);

  distancia = (tiempo_eco * 0.0343) / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500);
}
