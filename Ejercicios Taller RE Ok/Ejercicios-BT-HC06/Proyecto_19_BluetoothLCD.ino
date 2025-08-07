#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Variables de control y/o lectura
char valor;
String estado;

void setup() {

  lcd.begin(16, 2);  //Inicializamos la pantalla LCD
  Serial.begin(9600);
}

void loop() {

  if (Serial.available())  //Si el puerto serie (Bluetooth) está disponible
  {
    valor = Serial.read(); //Lee el dato entrante via Bluetooth

    if (valor == 'A')  //Si el dato entrante es una A
    {
      pantalla_LCD();  //Llama la función que muestra el mensaje en la pantalla LCD
    }
  }
}

void pantalla_LCD()
{
  delay(30);
  while (Serial.available())
  {
    char c = Serial.read();  //Lee el dato entrante y lo almacena en una variable tipo char
    estado += c;             //Crea una cadena tipo String con los datos entrates
  }
  if (estado.length() > 0)   //Se verifica que la cadena tipo String tenga un largo mayor a cero
  {
    lcd.clear();             //Borra cualquier mensaje que esté mostrando la pantalla LCD
    lcd.setCursor(0, 0);     //Posiciona el cursor en la Fila 0 y Columna 0 en la pantalla LCD
    lcd.print(estado);      //Muestra el mensaje en la pantalla LCD
    estado = "";            //Limpia la variable para posteriormente leer nuevos datos
  }
}
