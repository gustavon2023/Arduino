/*
  Web impresa:
  <!DOCTYPE html>
  <html>
  <body>
  <p>LED APAGADO</p>
  <form action="" method="post">
  <input type="submit" value="Enciende Led" />
  </form>
  </body>
  </html>
*/

#include <SPI.h>
#include <Ethernet.h>

const int pin_led = 8;

//Configuración Ethernet
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xYY  //Sustituir YY por el numero de MAC correcto
};

EthernetServer server = EthernetServer(80);

boolean led_state = LOW;

void setup()
{
  Serial.begin(9600);
  //Inicializar Ethernet
  Serial.println("inicializando red...");
  //Ethernet.begin(mac, ip, DNS, gateway, subnet);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for (;;)
      ;
  }
  else {
    Serial.print("IP asignada por DHCP: ");
    Serial.println(Ethernet.localIP());
  }

  pinMode(pin_led, OUTPUT);
  digitalWrite(pin_led, LOW);
  led_state = LOW;

  //Comienzo a escuchar cliente ethernet
  server.begin();
}

void loop()
{
  String recibido = ""; //Buffer

  //Si hay in cliente entrante, hay caracteres por leer
  EthernetClient client = server.available();
  if (client) {
    while (client.available()) {
      recibido += char(client.read());
      //Serial.println(client.read());  //Para hacer debug
    }
    Serial.println("He recibido por ethernet: ");
    Serial.println(recibido);

    if (recibido.startsWith("GET / HTTP/1.1")) {
      Serial.println("------> Muestro web");
      muestraWeb(client);
    }
    else if (recibido.startsWith("POST / HTTP/1.1")) {
      Serial.println("------> Cambio estado LED");
      led_state = !led_state;
      digitalWrite(pin_led, led_state);  //cambio el estado del led
      muestraWeb(client);
    }
    else {
      client.println("HTTP/1.0 200K");
      client.println();
      client.println();
      client.stop();
      client.flush();
    }
  }
}

void muestraWeb(EthernetClient client) {
  client.println("HTTP/1.0 200K");
  client.println();
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<body>");
  if (led_state == HIGH) client.println("<p>LED ENCENDIDO</p>");
  else client.println("<p>LED APAGADO</p>");
  client.println("<form action=\"\" method=\"post\">");
  if (led_state == HIGH) client.println("<input type=\"submit\" value=\"Apaga Led\" />");
  else client.println("<input type=\"submit\" value=\"Enciende Led\" />");
  client.println("</form>");
  client.println("</body>");
  client.println("</html>");
  client.println();
  client.stop();
  client.flush();
}
