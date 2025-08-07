#include <SoftwareSerial.h>
#include <Servo.h>

// CONEXIONES PARA EL BLUETOOTH.

int bluetoothTx = 2;
int bluetoothRx = 3;
char dato;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int mi1=6;
int mi2=7;

int md1=10;
int md2=11;


void setup ()
{
bluetooth.begin(9660);
pinMode(mi1,OUTPUT);
pinMode(mi2,OUTPUT);
pinMode(md1,OUTPUT);
pinMode(md2,OUTPUT);

digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW );
digitalWrite( md1, LOW );
digitalWrite( md2, LOW);
}

void loop()
{
dato = bluetooth.read();
delay(100);
if(dato == 'S')
{
digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW);
digitalWrite( md1, LOW),
digitalWrite( md2, LOW);

}
if( dato == 'F')
{
// ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.


digitalWrite(mi1,HIGH);
digitalWrite(mi2,LOW);
digitalWrite(md1,HIGH);
digitalWrite(md2,LOW);

//digitalWrite(mi1,HIGH);
//digitalWrite(mi2,LOW);
//digitalWrite(md1,HIGH);
//digitalWrite(md2,LOW);  

}
if(dato == 'B')
{

// ESTOS HARA RETROCEDER EL CARRITO.

digitalWrite(mi1,LOW);
digitalWrite(mi2,HIGH);
digitalWrite(md1,LOW);
digitalWrite(md2,HIGH);


//digitalWrite(mi1,LOW);
//digitalWrite(mi2,HIGH);
//digitalWrite(md1,LOW);
//digitalWrite(md2,HIGH);
}

if( dato == 'L')
{
// ESTOS HARAN QUE VAYA PARA DERECHA.

digitalWrite(mi1,HIGH);
digitalWrite(mi2,LOW);
digitalWrite(md1,LOW);
digitalWrite(md2,LOW);

}

if( dato == 'R')
{
// ESTOS HARAN QUE VAYA PARA IQUIERDA.

digitalWrite(mi1,LOW);
digitalWrite(mi2,LOW);
digitalWrite(md1,HIGH);
digitalWrite(md2,LOW);

}
}
