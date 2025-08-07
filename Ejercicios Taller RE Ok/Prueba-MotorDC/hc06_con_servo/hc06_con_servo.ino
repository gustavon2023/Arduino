#include <Servo.h>
Servo servomotor;
String estado;

void setup() {
  
  servomotor.attach(6); //Pin PWM 6 del Arduino para el Servomotor
  servomotor.write(0); // Inicia el servo en una posicion de 90
  Serial.begin(9600);
  
  }

void loop() {
  delay(25);
  while (Serial.available())
{
  char c = Serial.read(); //lee el dato entrante y lo almacena en una variable tipo char
  estado += c; //Crea una cadena de tipo String con los datos entrantes
}
if (estado.length() > 0) //Se verifica que la cadena de tipo string tenfa un largo mayor a cero
{
servomotor.write(estado.toInt());//Manda el dato en forma de entero
estado = ""; //limpia la variable para poder lerr posteriormente nuevos datos
  
}
}
