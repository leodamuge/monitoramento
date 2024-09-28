//Declaracao de funcoes
#ifndef CONN_H
#define CONN_H


void iniciarWiFi(const char* ssid, const char* password);
void enviarDadosThingSpeak(int movimento, int calor, int fumaca, int luz, const char* apiKey, const char* server);
void setupSIM800L();  // Configuração do SIM800L
void sendSMS(const char* message);

#endif
