// Prueba de mini bomba de agua 5V con módulo relé

const int pinRele = 7; // Pin de control del relé

void setup() {
  pinMode(pinRele, OUTPUT);
  digitalWrite(pinRele, HIGH); // Relé inactivo (dependiendo del módulo puede ser LOW)
  Serial.begin(9600);
  Serial.println("Prueba de bomba de agua iniciada...");
}

void loop() {
  // Encender la bomba por 5 segundos
  Serial.println("Bomba ENCENDIDA");
  digitalWrite(pinRele, LOW); // Activa el relé (puede variar según el módulo)
  delay(5000);

  // Apagar la bomba por 5 segundos
  Serial.println("Bomba APAGADA");
  digitalWrite(pinRele, HIGH); // Desactiva el relé
  delay(5000);
}
