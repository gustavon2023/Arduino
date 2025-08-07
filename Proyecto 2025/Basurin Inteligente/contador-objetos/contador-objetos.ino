#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
  int led=8;
  int Buzzer=7;
  int trigger=3;
  int echo=2;
  int tiempo=0;
  int distancia=0;
  int contador=0;
void setup() {
  Wire.begin();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trigger,LOW);
  delay(2);
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  tiempo=pulseIn(echo,HIGH);
  distancia=(tiempo/2)/29;
//  Serial.println(distancia);
  if(distancia<9){
    digitalWrite(led,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
  }else{
    digitalWrite(led,LOW);
    contador=contador;
    digitalWrite(Buzzer,LOW);
  }
  if(digitalRead(led)==HIGH)
  {
    contador++;
    delay(300);
    
  }
  if(contador>10){
    contador=0;
    lcd.clear();
  }
  Serial.println(contador);
  Serial.print(" ");
  Serial.print(distancia);
  Serial.print(" cm ");
  lcd.setCursor(0,0);
  lcd.print("Contar Monedas");
  lcd.setCursor(0,1);
  lcd.print("monedas: ");
  lcd.print(contador);

}
