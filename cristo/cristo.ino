

/*=====================================================
   CONEXIONES

   ------ Push Button --------------
   Normalmente Abierto ----- Pin 4
   Comun ------------------- GND
   ------------------------------

   --------- RELE ---------------
   VCC ------------- VCC
   GND ------------- GND
   IN -------------- Pin 7
   
   Se alimenta el Arduino con el Cargador de 9V

   Vease diagrama de conexion en el folder
===================================================== */ 

int rele = 7;
int estadoBoton;
const int pulsador = 4;

void setup() {

  pinMode(pulsador, INPUT_PULLUP);
  pinMode(rele, OUTPUT);

  digitalWrite(rele, HIGH);

  Serial.begin(9600);
}

void loop() {

  estadoBoton = digitalRead(pulsador);

  if (estadoBoton) {
    digitalWrite(rele, LOW);
  } else {
    digitalWrite(rele, HIGH);
  }
  Serial.println(estadoBoton);

}
