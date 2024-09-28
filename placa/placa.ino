
#include "sensor.h"
#include "conn.h"



const char* ssid = "lacuna_21";            // Rede Wi-Fi
const char* password = "unavailable";        // Senha da rede Wi-Fi
const char* apiKey = "94FOYFL013UV9VC7";        // Chave API do ThingSpeak
const char* server = "api.thingspeak.com"; // URL do ThingSpeak

void setup() {
  Serial.begin(115200);
  
  iniciarWiFi(ssid, password);  // Conecta ao Wi-Fi
  
  iniciarSensores();  // Inicializa os 4 sensores
}

void loop() {
  // Leitura dos sensores
  int movimento = lerSensorMovimento();
  int calor = lerSensorCalor();
  int fumaca = lerSensorFumaca();
  int luz = lerSensorLuz();
  
  // Exibe os valores no serial monitor
  Serial.print("Movimento: "); Serial.println(movimento);
  Serial.print("Calor: "); Serial.println(calor);
  Serial.print("Fumaca: "); Serial.println(fumaca);
  Serial.print("Luz: "); Serial.println(luz);

  // Envia os dados para o ThingSpeak
  enviarDadosThingSpeak(movimento, calor, fumaca, luz, apiKey, server);
  
  delay(20000);  // Envia os dados a cada 20 segundos (tempo mínimo recomendado pelo ThingSpeak)
}
