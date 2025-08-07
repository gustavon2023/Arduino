
//motor izquierda
int mi1=8;
int mi2=9;
int LED = 11;
//motor derecha
int md1=12;
int md2=13;
//variables del ultrasonido
int distancia;
int tiempo;
int trig=7;
int echo=6;

void setup() {
pinMode(mi1,OUTPUT);
pinMode(mi2,OUTPUT);
pinMode(md1,OUTPUT);
pinMode(md2,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(LED,OUTPUT);
}

void loop() 
{
  
  adelante();
  
  }


 
  
void adelante ()
{
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
digitalWrite(11,LOW);  
}
