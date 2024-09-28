//implementacao de funcoes
#include "sensor.h"
#include <Arduino.h>

void iniciarSensores() {
  // Inicializa 4 pinos de sensores (A0 a A3)
  pinMode(25, INPUT); //Movimento
  pinMode(32, INPUT); //Calor
  pinMode(34, INPUT); //Fumaca
  pinMode(36, INPUT); //Luz
}

//LEITURA DOS DADOS DOS SENSORES
int lerSensorMovimento() {
  return analogRead(25);
}

int lerSensorCalor() {
   //int leituraADC = analogRead(lm35Pin);

  // Converter a leitura ADC para tensão (em Volts)
  /*float tensao = (leituraADC / 4095.0) * 3.3;

  // Converter a tensão para temperatura em Celsius
  float temperaturaC = leituraconvertida * 100;*/
  int leitura = analogRead(32);
  int leituraconvertida = (leitura*(5.0/1023))/0.01;
  return leituraconvertida; 
}

int lerSensorFumaca() {
  return analogRead(34);  
}

int lerSensorLuz() {
  /*O valor maximo a ser medido é de 4095. Mas para que sejam visualizados valores de 0 a 100*/
  int intensidade= analogRead(33);
  float nivelar = (intensidade / 4095.0) * 100;
  return nivelar; 
}
