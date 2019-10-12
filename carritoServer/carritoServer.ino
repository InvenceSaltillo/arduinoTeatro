#include <ESP8266WiFi.h>

const char WiFiClave[] = "";  //Sin clave
const char AP_Nombre[] = "carritoServer";

const int LED_PIN = 15; // LED rojo
int val;
WiFiServer server(80);

void setup() {

  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_Nombre, WiFiClave);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // ¿Hay un cliente conectado?
  if (!client) {
    return;
  }
  String req = client.readStringUntil('\r');  // Lee la primera linea de la petición del cliente
  if (req.indexOf("/led/0") != -1) val = 0;
  if (req.indexOf("/led/1") != -1) val = 1;
  digitalWrite(LED_PIN, val);
  client.flush();
}
