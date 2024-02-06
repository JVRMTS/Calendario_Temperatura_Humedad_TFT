/*
 * @JMTS
 * Probado con ESP32 DEVKIT y WEMOS D1 R32 (palaca con forma de arduino 1 para que funcione hay que realizar las modificaciones descritas en la libreria TFT_eSPI)
 * Reloj con fecha y hora más sensor de temperatura y humedad en pantalla TFT con la libreria TFT_eSPI
 * Sensor de Temperatura-Humedad DHT22 o DHT11 solo has de configurarlo en su script
 * Hora a traves de servidor NTP basado en el ejemplo SimpleTime de la libreria del ESP32
 * Conexión a base de datos Mysql mediante php con el método POST para realizar un registro
 * Actualización del frimware via OTA con contraseña basado en el ejemplo ArduinoOTA
 * 27/12/2024
 *                          NOTA IMPORTANTES
 * El orden en el que se ponen los includes es muy importante, siempre han de ir primero los primeros que se llaman
 */
#include "configuracion.h"
#include "sensorDHT.h"
#include "reloj.h"
#include "tft.h"
#include "conexionWiFi.h"
#include "baseDatos.h"
#include "ota.h"

#define LED_PIN 2 // Led integrado en el PIN2

// Iniciamos los contadores para insertar en la base de datos y actualizar el reloj
unsigned long previosMillis;
unsigned long previosMillis1;
unsigned long intervalo = 60000;
unsigned long intervalo1 = 15000;

void setup()
{
  Serial.begin(115200);

  // Ponemos el LED de la placa en OFF
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); 
  
  // Iniciamos el sensor DHT
  dht.begin(); 

  // Llamamos a la función para configurar la pantalla
  configuracionPantalla();

  // Conexion a la wifi
  conectarWiFi();

  // Configuramos la actualización via OTA
  actualizacionOTA();
}
void loop()
{
  //Si se ha perdido la conexión wifi llamamos a la función para conectar de nuevo
  if (WiFi.isConnected() == false){
    conectarWiFi();
    }

  unsigned long currentMillis = millis();   
  // Llamamos, cada minuto, a la función para insertar los datos en la base de datos
  if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
      enviarBD(); // Comentalo si no quieres utilizarlo
      previosMillis = millis();
    }
  // Llamamos a la función para que se muestre la pantalla cada 15 segundos y asi evitamos que parpadee mucho.
  if ((unsigned long) (currentMillis - previosMillis1) >= intervalo1){
      mostrarPantalla();
      previosMillis1 = millis();
    }
  //Llamamos a la actualización via OTA
  ArduinoOTA.handle(); 
}
