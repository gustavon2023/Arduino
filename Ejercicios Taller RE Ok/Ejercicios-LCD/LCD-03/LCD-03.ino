/*
  Capitulo 10 de Arduino desde cero en Español
  Programa que muestra texto y parpadeo de cursor.

  Autor: bitwiseAr  

*/

#include <LiquidCrystal.h>    // importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 de modulo 1602A

void setup() {
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
}

void loop() {
  lcd.setCursor(0, 0);      // ubica cursor en columna 0 y fila 0   
  lcd.print("Ingrese clave:");    // escribe texto
  lcd.setCursor(0, 1);      // ubica cursor en columna 0 y fila 1
  lcd.cursor();       // muestra cursor
  delay(500);       // demora de medio segundo
  lcd.noCursor();     // oculta cursor
  delay(500);       // demora de medio segundo
}
