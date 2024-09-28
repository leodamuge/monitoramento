#include "conn.h"
#include <WiFi.h>
#include <HardwareSerial.h>
#include <HTTPClient.h>  // Biblioteca para HTTP requests. Similar para ESP32.

HardwareSerial sim800(1);  // Use UART1 do ESP32




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
void setupSIM800L() {
  sim800.begin(9600, SERIAL_8N1, 7, 8);  // Inicializa a comunicação UART com o SIM800L (TX:7, RX:8)
  delay(1000);

  // Verifica se o módulo está funcionando enviando o comando AT
  sim800.println("AT");
  delay(1000);
//sms enviado
  if (sim800.available()) {
    String response = sim800.readString();
    Serial.println("Resposta do SIM800L: " + response);
  }
}
void sendSMS(const char* message) {
  // Envia os comandos AT para configurar e enviar o SMS
  sim800.println("AT+CMGF=1");  // Configura o modo texto para SMS
  delay(1000);
  sim800.println("AT+CMGS=\"+258840126705\"");
  
  //sim800.println("AT+CMGS=\"" + recipientNumber + "\"");  // Comando para enviar SMS para o número
  delay(1000);

  sim800.print(message);  // Envia a mensagem
  delay(1000);

  sim800.write(26);  // Código ASCII para CTRL+Z, finaliza o SMS
  delay(1000);

  Serial.println("SMS Enviado!"); Serial.println(message);
}