#include <SoftwareSerial.h>
int hor = 12;
int anti = 13;
char opcion;
SoftwareSerial blue(2,3); //se conecta al pin 2 TX del HC-06 y pin 3 al RX

void setup() {

blue.begin(9600);
pinMode(hor,OUTPUT);
pinMode(anti,OUTPUT);
}

void loop() {
  if (blue.available() > 0)
  opcion = blue.read();
  switch (opcion)
{
  case '0':
    digitalWrite(hor,LOW);
    digitalWrite(anti,LOW);
    break;
    case '1':
        digitalWrite(hor,HIGH);
        break;
    case '2':
        digitalWrite(anti,HIGH);
        break;
}
}
