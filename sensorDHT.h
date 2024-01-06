/*
 / Configuración y función para la toma de datos de un sensor DHT, esta probado con DHT11 y DHT22 en Esp32 Dev Module
 / creado por JMTS
 / EL 27/12/2024
*/

#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 22     // Se define el puerto al que conectamos el Sensor DHT: pin digital 22

DHT dht(DHTPIN, DHTTYPE); // Creamos el objeto DHT

double h;
String Hum;
double t;
String Temp;
double hic;
String TeR;
String t1;
String t2;
String t3;

void temperatura(){
   h = dht.readHumidity();                  //Leemos la humedad del sensor
   Hum = String(h, 1);                      // La convertimos a un String
   t = dht.readTemperature();               // Leemos la temperatura del sensor
   Temp = String(t, 2);                     // La convertimos a un String
   hic = dht.computeHeatIndex(t, h, false); // Calculamos la sensación térmica
   TeR = String(hic, 2);                    // La convertimos a un String
   t1=("Tem: " + Temp);                     // Se crea la cadena de la temperatura
   t2=("Hum: " + Hum);                      // Se crea la cadena de la humedad
   t3=("Sen.Ter.: " + TeR);                 // Se crea la cadena de la sensacion termica
}  