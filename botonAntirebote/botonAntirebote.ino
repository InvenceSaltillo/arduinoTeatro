
const int pulsador = 2; // Entrada digital para el pulsador
const int tiempoAntirrebote = 10; // tiempo en ms para evitar el rebote

int cuenta = 0;
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


void setup() {
  Serial.begin(9600);  // Configura la velocidad de la comunicación serie

  pinMode(pulsador, INPUT_PULLUP); // PIN digital del pulsador como entrada

}

void loop() {
  
  estadoBoton = digitalRead(pulsador);

  if (estadoBoton != estadoBotonAnterior) {
    if (antirrebote(pulsador)) {
      cuenta++;
      Serial.println(cuenta);
    }
  }
  estadoBotonAnterior = estadoBoton;
}
