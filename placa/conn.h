//INTERFACE
#ifndef CONN_H
#define CONN_H


void setupSIM800L();  // Configuração do SIM800L
void iniciarWiFi(const char* ssid, const char* password);
void enviarDadosThingSpeak(int movimento, int calor, int fumaca, int luz, const char* apiKey, const char* server);
void sendSMS(const char* message);

#endif
