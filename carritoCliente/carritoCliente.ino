
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "carritoServer";
const char* password = "";
const char* host = "http://192.168.4.1";
String val = "1";

HTTPClient http;


const int pulsador = 4; // D2
const int tiempoAntirrebote = 10; // tiempo en ms para evitar el rebote

int estadoBoton;
int estadoBotonAnterior;

// Función que evita el rebote del pulsador
boolean antirrebote(int pin) {
  int contador = 0;
  boolean estado;
  boolean estadoAnterior;

  do {
    estado = digitalRead(pin);
    if (estado != estadoAnterior) {
      contador = 0;
      estadoAnterior = estado;
    } else {
      contador = contador + 1;
    }
    delay(1);
  } while (contador < tiempoAntirrebote);

  return estado;
}

int pausa = 100;

void setup() {

  pinMode(pulsador, INPUT_PULLUP);

  Serial.begin(115200);
  delay(10);
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi conectada");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {

  estadoBoton = digitalRead(pulsador);

  if (estadoBoton != estadoBotonAnterior) {
    if (antirrebote(pulsador)) {

      if ( val == "1") {
        val = "0";
      } else {
        val = "1";
      }

      enviarPeticion();
      Serial.println(val);

    }
  }
  estadoBotonAnterior = estadoBoton;




}

void enviarPeticion() {

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    delay(500);
  } else {
    //HTTPClient http;
    Serial.print("[HTTP] begin...\n");
    // configure server y url
    http.begin("192.168.4.1", 80, "/led/" + val); //HTTp
    int httpCode1 = http.GET();

    Serial.println(httpCode1);
    delay(100);

  }
}
