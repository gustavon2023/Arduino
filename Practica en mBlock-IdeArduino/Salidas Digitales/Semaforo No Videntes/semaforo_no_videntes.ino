/**
 * Sem�foro para invidentes
 *
 * En esta pr�ctica vamos a simular el sem�foro para peatones invidentes 
 * a trav�s de 1 zumbador que avisa al peat�n.
 *
 * @author Miguel �ngel Abell�n
 * @company El Cable Amarillo
 * @license Creative Commons. Reconocimiento CompartirIgual 4.0 (Se
 * permite el uso comercial de la obra y de las posibles obras derivadas,
 * la distribuci�n de las cuales se debe hacer con una licencia igual a
 * la que regula la obra original.)
 */

// Definimos las variables de tipo entero
int ledPinRojo = 13;
int ledPinVerde = 12;
int ledPinZumbador = 11;

//Este c�digo se ejecuta la primera vez
void setup() {
  // Configuramos los pines en modo salida
  pinMode(ledPinRojo, OUTPUT);
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinZumbador, OUTPUT);
  // Inicializamos los pines a un valor BAJO
  digitalWrite(ledPinRojo, LOW);
  digitalWrite(ledPinVerde, LOW);
  digitalWrite(ledPinZumbador, LOW);
}

//Este c�digo se ejecuta en bucle repetidamente
void loop() {
  // Mostramos el led de color rojo
  digitalWrite(ledPinRojo, HIGH);
  delay(5000);
  digitalWrite(ledPinRojo, LOW);
  
  // Mientras el sem�foro est� en verde suena el zumbador
  digitalWrite(ledPinVerde, HIGH);
  for(int i=0; i<10; i++){
    digitalWrite(ledPinZumbador, HIGH);
    delay(200);
    digitalWrite(ledPinZumbador, LOW);
    delay(500);
  }
  digitalWrite(ledPinVerde, LOW);
}