 //motor izquierda
int buzzerpin = 9;
int buzzerdelay=50;
int mi1=2;
int mi2=3;
//motor derecha
int md1=4;
int md2=5;
//variables del ultrasonido
int distancia;
int tiempo;
int trig=7;
int echo=6;
int led = 13;
void setup() {
pinMode(buzzerpin,OUTPUT);  
pinMode(mi1,OUTPUT);
pinMode(mi2,OUTPUT);
pinMode(md1,OUTPUT);
pinMode(md2,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(led,OUTPUT);
}

void loop() 
{
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);
tiempo=pulseIn(echo, HIGH);
//distancia=VxT
distancia=tiempo/58.8; // distancia en centímetros

if(distancia > 50)
{
  
  adelante();
  }
  else // para cuando encuentre distancias menores a 50
{
  parar();
  delay(1000);
  atras();
  delay(1000);
  derecha();
  delay(1000);
  izquierda();
  delay(1000);
  adelante();
  
  }

}


void adelante ()
{
  digitalWrite(buzzerpin,LOW);
digitalWrite(led,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);  
}
void atras()
{
digitalWrite(buzzerpin,HIGH);
delay(buzzerdelay);
digitalWrite(buzzerpin,LOW);
delay(buzzerdelay);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);  
}

void derecha ()// debe funcionar el motor izquierdo
{
digitalWrite(buzzerpin,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);  
}


void izquierda () // debe funcionar el motor derecho
{

digitalWrite(buzzerpin,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);  
}

void parar () // debe funcionar el motor derecho
{
digitalWrite(buzzerpin,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);  
}
