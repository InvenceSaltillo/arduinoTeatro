int pinLedR = 9;  // pin Rojo del led RGB
int pinLedV = 10;  // pin Verde del led RGB
int pinLedA = 11;   // pin Azul del led RGB


const int pulsadorON = 4; // Entrada digital para el pulsador
const int pulsadorOFF = 5; // Entrada digital para el pulsador
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

  Serial.begin(9600);  // Configura la velocidad de la comunicación serie

  pinMode(pulsadorON, INPUT_PULLUP); // PIN digital del pulsador como entrada
  pinMode(pinLedR, OUTPUT);    // pone el pinLedR como output
  pinMode(pinLedV, OUTPUT);    // pone el pinLedV como output
  pinMode(pinLedA, OUTPUT);    // pone el pinLedA como output

  //  color(255, 255, 255);
}

void loop() {

  color(200, 5, 0);

  estadoBoton = digitalRead(pulsadorON);

//  if (estadoBoton != estadoBotonAnterior) {
//    if (antirrebote(pulsadorON)) {
//
//      color(0, 255, 255);   // vela encendida
//    }
//  }
//  estadoBotonAnterior = estadoBoton;


}

// funcion para generar colores
void color (int rojo, int verde, int azul) {
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
  analogWrite(pinLedA, azul);
}
