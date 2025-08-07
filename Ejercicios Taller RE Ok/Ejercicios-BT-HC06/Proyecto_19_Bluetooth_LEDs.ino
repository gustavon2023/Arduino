//Variables asociadas a los dos LEDs que se van a controlar
int led_1 = 22;
int led_2 = 23;

char valor;  //Variable para indicar que llega una orden

void setup() {

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available())  //Si el puerto serie (Bluetooth) está disponible
  {
    valor = Serial.read();  //Lee el dato entrante via Bluetooth

    if (valor == 'A')   //Si el dato que llega es una A
    {
      digitalWrite(led_1, HIGH);  //Enciende el LED 1
    }
    if (valor == 'B')   //Si el dato que llega es una B
    {
      digitalWrite(led_1, LOW);   //Apaga el LED 1
    }
    if (valor == 'C')   //Si el dato que llega es una C
    {
      digitalWrite(led_2, HIGH);  //Enciende el LED 2
    }
    if (valor == 'D')   //Si el dato que llega es una D
    {
      digitalWrite(led_2, LOW);   //Apaga el LED 2
    }
  }
}
