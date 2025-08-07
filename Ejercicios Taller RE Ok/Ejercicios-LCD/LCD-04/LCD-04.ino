/*
  Capitulo 10 de Arduino desde cero en Español
  Programa que muestra texto y utiliza funcion para ir desplazando el mismo.

  Autor: bitwiseAr  

*/

#include <LiquidCrystal.h>    // importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 de modulo 1602A

void setup() {
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
}

void loop() {
  lcd.setCursor(2, 0);      // ubica cursor en columna 2 y linea 0
  lcd.print("Prueba scroll");   // escribe texto
  lcd.scrollDisplayLeft();    // funcion que desplaza de a un caracter por vez hacia
          // la izquierda
  delay(1000);        // demora de un segundo
}
