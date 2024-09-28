#include "conn.h"
#include <WiFi.h>

#include <HTTPClient.h>  // Biblioteca para HTTP requests. Similar para ESP32.

void iniciarWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.print("Conectando-se ao Wi-Fi");
  
  // Espera até a conexão ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conectado ao Wi-Fi");
}

void enviarDadosThingSpeak(int sensor1, int sensor2, int sensor3, int sensor4, const char* apiKey, const char* server) {
  if (WiFi.status() == WL_CONNECTED) {  // Verifica se o Wi-Fi está conectado
    HTTPClient http;
    
    // Monta a URL para enviar dados ao ThingSpeak
    String url = String("/update?api_key=") + apiKey
               + "&field1=" + String(sensor1)
               + "&field2=" + String(sensor2)
               + "&field3=" + String(sensor3)
               + "&field4=" + String(sensor4);
    
    http.begin("http://" + String(server) + url);  // Inicia a requisição
    int httpCode = http.GET();  // Envia a requisição GET
    
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Dados enviados com sucesso: " + response);
    } else {
      Serial.println("Falha ao enviar os dados");
    }
    
    http.end();  // Fecha a conexão
  } else {
    Serial.println("Falha na conexão Wi-Fi");
  }
}
