/*
 * La función de este archivo es mostrar en la pantalla TFT los datos que queremos ver.
 * Probado con las pantallas 3.5" TFT SHIELD ARDUINO MEGA (ILI9486/9488) EN UN WEMOS D1 R32 Y TFT 3.5" ILI9486/9488 SPI EN UN ESP32 DEV MODULE
 * JMTS
 * 27/12/24
*/

#include <TFT_eSPI.h>     // incluye la libreria para el manejo de la TFT
#include <SPI.h>		      // incluye libreria bus SPI
#include "Free_Fonts.h"   // Incluye el archivo de encabezado adjunto a este sketch.
#include "ico_t.h"
#include "ico_h.h"
#include "ico_st.h"
 
TFT_eSPI tft = TFT_eSPI();	// crea objeto tft
int xpos = tft.width() / 2; // Centro del ancho de pantalla

// con esta función dibujamos lo que no queremos que no se refresque en la pantalla y la orientación de esta, la ejecutamos desde la funcion configuracionPantalla().
void zonaFijaPantalla(){
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);                 // Establece el fondo de pantalla.
  tft.drawLine(0, 0, 480, 0, TFT_WHITE);     // linea horizontal de color blanca
  tft.drawLine(0, 135, 480, 135, TFT_WHITE); // linea horizontal de color blanca
  tft.drawLine(0, 253, 480, 253, TFT_WHITE); // linea horizontal de color blanca
  tft.drawLine(0, 319, 480, 319, TFT_WHITE); // linea horizontal de color blanca
  tft.pushImage(4,155,CW,CH,th);
  tft.pushImage(444,155,HW,HH,ht);
  tft.pushImage(65,200,SW,SH,sh);
  tft.setTextDatum(TC_DATUM);
  tft.pushImage(xpos, 265, xw, xh, xxx);
}

// Esta funcion se ejecuta en el Setup para configurar la pantalla y mostrar los datos o dibujos que mo se refrescan mediante la función zonaFijaPantalla().
void configuracionPantalla(){
  tft.begin();					               // Inicializa pantalla.
  tft.setRotation(1);				           // establece posicion 0 - vertical pines pantalla abajo, 1-horizontal pines pantalla derecha, 2-vertical pines pantalla arriba, 3-horizontal pines pantalla izquierda.
  zonaFijaPantalla();                  // Llamamos a la función para mostrar los datos e imágenes que no se refrescan y permanecen fijos en pantalla.
}

void mostrarPantalla(){
  fecha();                                                                  // Recojemos los datos de fecha y hora
  temperatura();                                                            // Recojemos los datos de temperatura, humedad y sensación térmica.
  int xpos = tft.width() / 2;                                               // Centro del ancho de pantalla
  tft.setTextColor(TFT_WHITE,TFT_BLACK);                                    // Establece el color de texto y del fondo para el texto  
  tft.setFreeFont(FSSB24);                                                  // Seleccionamos la fuente FreeSansBold24pt7b
  tft.setTextPadding(120);                                                  // Se utiliza para borrar los pixeles antiguos al refrescar la pantalla
  tft.drawString(horMin,xpos,22,GFXFF);                                     // Imprimimos por pantalla la hora y los minutos.
  tft.drawString(" " +diaS + " " + dia + " " + mes + " " + ano + " ",xpos,70, GFXFF);  // Imprimimos por pantalla la fecha
  tft.setFreeFont(FSSB18);                                                  // Seleccionamos la fuente FreeSansBold18pt7b
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);                                  // texto en color amarillo y fondo negro.
  tft.drawString(t1 + " | " + t2,xpos,155);		                              // Imprimimos por pantalla la temperatura y la humedad
  tft.drawString(t3,xpos,200, GFXFF);                                       // Imprimimos por pantalla la Sensación Térmica
}