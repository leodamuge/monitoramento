//INTERFACE
#ifndef SENSOR_H
#define SENSOR_H

void iniciarSensores();  // Função para inicializar os sensores

// Declaração de Funções para ler os 4 sensores
int lerSensorMovimento();
int lerSensorCalor();
int lerSensorFumaca();
int lerSensorLuz();

#endif
