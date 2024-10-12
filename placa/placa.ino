#include "sensor.h"
#include "conn.h"
#define GasD 35


const char* ssid = "lacuna_21";            // Rede Wi-Fi
const char* password = "unavailable";        // Senha da rede Wi-Fi
const char* apiKey = "94FOYFL013UV9VC7";        // Chave API do ThingSpeak
const char* server = "api.thingspeak.com"; // URL do ThingSpeak

void setup() {
  //LEITURA DIGITAL DO SENSOR DE Fumaca
  pinMode(GasD, INPUT);
  Serial.begin(115200);
  setupSIM800L();
  iniciarWiFi(ssid, password);  // Conecta ao Wi-Fi
  
  iniciarSensores();  // Inicializa os 4 sensores
}

void loop() {
  // Leitura dos sensores
  int movimento = lerSensorMovimento();
  int calor = lerSensorCalor();
  int fumaca = lerSensorFumaca();
  int luz = lerSensorLuz();
  int fumacaD = digitalRead(GasD);
  
  //Envio de alertas de acordo com cada valor anormal verificado
  if(movimento>0){
      sendSMS("Alerta! MOVIMENTO DETECTADO");
  }
  if(calor>55){
      sendSMS("Alerta! CALOR ESCESSIVO");
  }
  if(fumaca>1000 && fumacaD==0){
      sendSMS("Alerta! PRESENCA DE GÁS");
  }
  if(luz>19){
      sendSMS("Alerta! LUZ ACESA");
  }
  
  
  // Exibe os valores no serial monitor
  Serial.print("Movimento: "); Serial.println(movimento);
  Serial.print("Calor: "); Serial.println(calor);
  Serial.print("Fumaca: "); Serial.println(fumaca);
  Serial.print("FumacaD: "); Serial.println(fumacaD);
  Serial.print("Luz: "); Serial.println(luz);

  // Envia os dados para o ThingSpeak
  enviarDadosThingSpeak(movimento, calor, fumaca, luz, apiKey, server);
  
  delay(20000);  // Envia os dados a cada 20 segundos (tempo mínimo recomendado pelo ThingSpeak)
}
