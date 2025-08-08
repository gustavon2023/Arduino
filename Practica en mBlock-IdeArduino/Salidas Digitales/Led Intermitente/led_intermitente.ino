**
 * Luz intermitente
 * 
 * En esta pr�ctica se va a construir y programar un diodo Led que parpadea
 * continuamente con una frecuencia de 1 segundo.
 * 
 * @author Miguel �ngel Abell�n
 * @company El Cable Amarillo
 * @license Creative Commons. Reconocimiento CompartirIgual 4.0 (Se 
 * permite el uso comercial de la obra y de las posibles obras derivadas, 
 * la distribuci�n de las cuales se debe hacer con una licencia igual a 
 * la que regula la obra original.)
 */

// Se definen las variables de tipo entero
int ledPin = 13;
int delayTime = 1000;

//Este c�digo se ejecuta la primera vez
void setup() {
  // Configuramos el pin en modo salida
  pinMode(ledPin, OUTPUT);
}

//Este c�digo se ejecuta en bucle repetidamente
void loop() {
  // Se enciende el led
  digitalWrite(ledPin, HIGH);
  // Esperamos
  delay(delayTime);
  // Se apaga el led
  digitalWrite(ledPin, LOW);
  // Esperamos
  delay(delayTime);