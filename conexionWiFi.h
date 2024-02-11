
/*
 * Conexión WiFi
 * 24/02/2024
 */
#include <WiFi.h>

// Conexión a la WiFi
void conectarWiFi()
{
  //Serial.println("Arrancando");
  WiFi.mode(WIFI_STA);
  if (!WiFi.config(ip, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Fallo en la configuración.");
  }
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    //Serial.println("Conexion fallida! Reseteando...");
    delay(1000);
    ESP.restart();
  }
}
