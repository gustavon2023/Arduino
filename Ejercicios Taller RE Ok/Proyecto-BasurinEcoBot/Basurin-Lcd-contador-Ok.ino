//Proyecto Basurin
//Elementos: Sensor Ultrasonido, Servo Motor, LCD i2c
//Escuela 4068

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo
Servo tapaServo;
const int pinServo = 6;

// Sensor ultrasónico
const int trigPin = 8;
const int echoPin = 9;

// Variables
int contador = 0;
bool detectado = false;
unsigned long tiempoUltimaDeteccion = 0;

void setup() {
  // Inicializaciones
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  tapaServo.attach(pinServo);
  tapaServo.write(0); // Tapa cerrada

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Objetos: 0");

  Serial.begin(9600);
}

void loop() {
  long duracion;
  float distancia;

  // Activar el sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer distancia
  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);

  // Si alguien se acerca (menos de 15 cm)
  if (distancia < 15 && !detectado) {
    contador++;
    detectado = true;
    tiempoUltimaDeteccion = millis();

    // Mostrar en LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Objetos:");
    lcd.setCursor(9, 0);
    lcd.print(contador);

    // Abrir tapa
    tapaServo.write(90); // Tapa abierta
  }

  // Cerrar la tapa después de 3 segundos
  if (detectado && (millis() - tiempoUltimaDeteccion > 3000)) {
    tapaServo.write(0); // Tapa cerrada
    detectado = false;
  }

  delay(100);
}
