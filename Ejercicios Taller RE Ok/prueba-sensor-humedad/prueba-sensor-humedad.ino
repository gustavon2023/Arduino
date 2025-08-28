// Prueba de funcionamiento del sensor de humedad HW-080 con Arduino UNO

// Pines
const int pinAnalog = A0;   // AO del sensor al pin A0 del Arduino
const int pinDigital = 7;   // DO del sensor al pin digital 7 del Arduino
const int pinLed = 13;      // LED integrado en la placa Arduino UNO

void setup() {
  Serial.begin(9600);
  pinMode(pinDigital, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.println("Prueba de Sensor de Humedad HW-080 iniciada...");
}

void loop() {
  // Leer valores
  int valorAnalogico = analogRead(pinAnalog);
  int valorDigital = digitalRead(pinDigital);

  // Mostrar valores en el monitor serie
  Serial.print("Valor Analógico: ");
  Serial.print(valorAnalogico);
  Serial.print(" | Valor Digital: ");
  Serial.println(valorDigital);

  // Encender LED cuando detecta sequedad (DO = 1)
  if (valorDigital == HIGH) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }

  delay(500);
}
