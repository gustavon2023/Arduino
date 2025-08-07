#include <SoftwareSerial.h>
#include <Servo.h>

// CONEXIONES PARA EL BLUETOOTH.

int bluetoothTx = 2;
int bluetoothRx = 3;
//int ledpin = 13;
//int buzzerpin = 8;
//int ledpinrojo = 4;
//int ledpinverde = 9;
//int buzzerdelay=100;
char dato;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int mi1=6;
int mi2=7;

int md1=10;
int md2=11;


void setup ()
{
bluetooth.begin(9600);
pinMode(mi1,OUTPUT);
pinMode(mi2,OUTPUT);
pinMode(md1,OUTPUT);
pinMode(md2,OUTPUT);
//pinMode(ledpin,OUTPUT);
//pinMode(ledpinrojo,OUTPUT);
//pinMode(ledpinverde,OUTPUT);
//pinMode(buzzerpin,OUTPUT);
digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW );
digitalWrite( md1, LOW );
digitalWrite( md2, LOW);
//digitalWrite(ledpin,LOW);
//digitalWrite(ledpinrojo,LOW);
//digitalWrite(buzzerpin,LOW);
}

void loop()
{

dato = bluetooth.read();
delay(100);

//PARO ELEVADOR

if(dato == 'S')
{ 
//digitalWrite(ledpinverde,LOW);
//digitalWrite(ledpinrojo,LOW);
digitalWrite( mi1, LOW);
digitalWrite( mi2, LOW);

}

//SUBE ELEVADOR

if( dato == 'F')
{
// ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.

//digitalWrite(ledpinrojo,LOW);
//digitalWrite(ledpinverde,HIGH);
//digitalWrite(buzzerpin,LOW);

digitalWrite(mi1,HIGH);
digitalWrite(mi2,LOW);
}


if(dato == 'B')
{
digitalWrite(mi1,LOW);
digitalWrite(mi2,HIGH);

}


}
