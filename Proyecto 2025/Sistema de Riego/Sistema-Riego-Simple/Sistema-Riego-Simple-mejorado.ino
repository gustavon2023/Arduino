//Sistema de Riego con Bomba Mejorado

//Pines
int bombapin = 8; 
int humedadpin= A0;
//Variables de Calibracion del Sensor de Humedad
int humedadmin = 1023; // Valor minimo de humedad (Suelo seco)
int humedadmax = 300;   // Valor maximo de humedad (suelo saturado)
int humedadvalor = 0;  // Variable para almacenar el valor leido del sensor

void setup() {
//
Serial.begin(9600);

// Configuracion del Pin de la Bomba como salida
pinMode(bombapin,OUTPUT);
digitalWrite(bombapin,LOW); //Apagamos la bomba al inicio
delay(2000); //Esperamos 2 segundos antes de leer el sensor
}

void loop() {
//Leemos el valor del sensor de humedad
humedadvalor = analogRead(humedadpin);

//Calculamos el Porcentaje de Humedad en el Suelo
int humedadporcentaje = map(humedadvalor,humedadmin,humedadmax,0,100);

// Control de la bomba de acuerdo con el porcentaje de humedad
// Si el Porcentaje esta por debajo del 60% activamos la bomba
if(humedadporcentaje < 60){
   digitalWrite(bombapin,HIGH); // Encendemos la bomba
} else if (humedadporcentaje > 80) {
digitalWrite(bombapin,LOW); // Apagamos la bomba
}
else {
  // Si la bomba esta en un rango aceptable (60%-80%)
  digitalWrite(bombapin,LOW); // Apagamos la bomba
}
delay(1000);
}
