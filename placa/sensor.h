//Declaracao de funcoes
#ifndef SENSOR_H
#define SENSOR_H

void iniciarSensores();  // Função para inicializar os sensores

int lerSensorMovimento();  // Funções para ler os 4 sensores
int lerSensorCalor();
int lerSensorFumaca();
int lerSensorLuz();

#endif
