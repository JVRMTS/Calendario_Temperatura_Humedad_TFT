/*
 * @JMTS
 * Probado con ESP32 DEVKIT y WEMOS D1 R32 (En la placa WEMOS D1 R32 con forma de arduino 1 para que funcione hay que realizar las modificaciones descritas en la libreria TFT_eSPI)
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
unsigned long intervalo1 = 15000; // INTERVALO PARA MOSTRAR FECHA Y HORA. Cuanto más grande sea tendras menos parpadeo en la pantalla aunque la actualización de la hora sera mas lenta, aquí esta puesto en 15 segundos.

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn onboard LED OFF
  
  dht.begin();

  // Llamamos a la función para configurar la pantalla
  configuracionPantalla();

  // Conexion a la wifi y sincronización del reloj NTP
  conectarWiFi();

  // Configuramos la actualización via OTA
  actualizacionOTA();
}
void loop()
{
  //Si se ha perdido la conexión wifi llamamos a la función para conectar de nuevo y configuramos fecha y hora
  if (WiFi.isConnected() == false){
    conectarWiFi();
    }


  unsigned long currentMillis = millis();   
  // Llamamos, cada minuto, a la función para insertar los datos en la base de datos
  if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
      enviarBD(); // Comentalo si no quieres utilizar la base de datos
      previosMillis = millis();
    }
  // Llamamos, cada 15 segundos a la función de mostrar pantalla
  if ((unsigned long) (currentMillis - previosMillis1) >= intervalo1){
      mostrarPantalla();
      previosMillis1 = millis();
    }
    ArduinoOTA.handle(); //Llamamos a la actualización via OTA
}
