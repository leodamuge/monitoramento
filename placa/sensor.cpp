//implementacao de funcoes
#include "sensor.h"
#include <Arduino.h>

void iniciarSensores() {
  
 pinMode(39, INPUT); //Movimento
  pinMode(32, INPUT); //Calor
 // pinMode(34, INPUT); //FumacaAnalogico
  pinMode(35, OUTPUT); //FumacaDigital 1 e 0
 // pinMode(26, INPUT); //Luz
}

//LEITURA DOS DADOS DOS SENSORES
int lerSensorMovimento() {
  return digitalRead(39);
  
}

int lerSensorCalor() {
  
  int leitura = analogRead(32);
  int leituraconvertida = (leitura*(3.3/1023))/0.01;
  return leituraconvertida; 
}

int lerSensorFumaca() {
 
  return analogRead(34);
}

int lerSensorLuz() {
   
  int intensidade= analogRead(33);
  float nivelar = (intensidade / 4095.0) * 100;
  return nivelar; 
}
