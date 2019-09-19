#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"


int RELAY_PIN_1 = 4;


char WIFI_SSID[] = " ";//Nombre de la red Wi-Fi 
char WIFI_PASS[] = " ";//Contraseña de la red WiFi

char DEVICE_1[] = "FAN";


fauxmoESP SMART;

void wifiSetup() {    // Configuracion de conexion Wi-Fi
  WiFi.mode(WIFI_STA); //Modulo Wi-Fi en modo Station
  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  // Espera..
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  // Conectado!
  Serial.printf("[WIFI] Modo STATION, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

void setup() {
  
  Serial.begin(115200); //Incializacion del purto serial.
  Serial.println();

  wifiSetup();

  pinMode(RELAY_PIN_1, OUTPUT); //Declaracion de pines de salida
  digitalWrite(RELAY_PIN_1, LOW);

  //Por defecto, la libreria fauxmoESP crea su propio servidor web para el definido
  //El puerto TCP debe ser 80 para dispositivos de tercera generacion
  //Esto debe de ser realizado antes del enable()  
  SMART.createServer(true); 
  SMART.setPort(80); 

  SMART.enable(true);
  
  SMART.addDevice(DEVICE_1); //Se agregan los dispositivos virtuales
  
  SMART.enable(true);
  SMART.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {        
    Serial.printf("[MAIN] Dispositivo #%d (%s) Estado: %s Valor: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    if ( (strcmp(device_name, DEVICE_1) == 0) ) {
      Serial.println("RELAY 1 switched by Alexa");
      if (state) {
        digitalWrite(RELAY_PIN_1, HIGH);
      } else {
        digitalWrite(RELAY_PIN_1, LOW);
      }
    }
  });

}

void loop() {
  
  SMART.handle();

  static unsigned long last = millis();
  if (millis() - last > 5000) {
    last = millis();
    Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
    SMART.enable(true);
  }
    
}
