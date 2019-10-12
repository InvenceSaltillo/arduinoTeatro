int pinLedR = 3;  // pin Rojo del led RGB
int pinLedV = 5;  // pin Verde del led RGB

int pinLedR2 = 6;  // pin Rojo del led RGB
int pinLedV2 = 9;  // pin Verde del led RGB

int pinLedR3 = 10;  // pin Rojo del led RGB
int pinLedV3 = 11;  // pin Verde del led RGB

const int pulsadorON = 4; // Entrada digital para el pulsador

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
  pinMode(pinLedV, OUTPUT);    // pone el pinLedA como output

  color1(255, 255, 255);
  color2(255, 255, 255);
  color3(255, 255, 255);
  delay(2000);
}

void loop() {

//  estadoBoton = digitalRead(pulsadorON);
//
//  if (estadoBoton != estadoBotonAnterior) {
//    if (antirrebote(pulsadorON)) {

      color1(0, 220, 0);
      color2(0, 220, 0);
      color3(0, 255, 0);

//      Serial.println("Boton");
//    }
//  }
//  estadoBotonAnterior = estadoBoton;


}

// funcion para generar colores
void color1 (int rojo, int verde, int azul) {
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
}

// funcion para generar colores
void color2 (int rojo, int verde, int azul) {
  analogWrite(pinLedR2, rojo);
  analogWrite(pinLedV2, verde);
}

// funcion para generar colores
void color3 (int rojo, int verde, int azul) {
  analogWrite(pinLedR3, rojo);
  analogWrite(pinLedV3, verde);
}
