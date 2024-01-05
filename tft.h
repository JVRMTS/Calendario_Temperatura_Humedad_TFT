/*
 * La función de este archivo es mostrar en la pantalla TFT los datos que queremos ver.
 * Probado con las pantallas 3.5" TFT SHIELD ARDUINO MEGA (ILI9486/9488) EN UN WEMOS D1 R32 Y TFT 3.5" ILI9486/9488 SPI EN UN ESP32 DEV MODULE
 * JMTS
 * 27/12/24
*/

#include <TFT_eSPI.h>     // incluye la libreria para el manejo de la TFT
#include <SPI.h>		      // incluye libreria bus SPI
#include "Free_Fonts.h"   // Include the header file attached to this sketch
//#include "LOGO_JMTS.h"

// Objeto TFT 
TFT_eSPI tft = TFT_eSPI();	// crea objeto;

// con esta función dibujamos lo que no queremos que no se refresque en la pantalla y la orientación de esta, la ejecutamos desde la funcion configuracionPantalla().
void zonaFijaPantalla(){
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);                 // Establece el fondo de pantalla.
  tft.drawLine(0, 0, 480, 0, TFT_WHITE);     // linea horizontal de color AZUL
  tft.drawLine(0, 135, 480, 135, TFT_WHITE); // linea horizontal de color AZUL
  tft.drawLine(0, 253, 480, 253, TFT_WHITE); // linea horizontal de color AZUL
  tft.drawLine(0, 319, 480, 319, TFT_WHITE); // linea horizontal de color AZUL
  tft.pushImage(310, 265, xw, xh, xxx);
}

// Esta funcion se ejecuta en el Setup para configurar la pantalla y mostrar los datos o dibujos que mo se refrescan mediante la función zonaFijaPantalla().
void configuracionPantalla(){
  tft.begin();					               // Inicializa pantalla.
  tft.setRotation(1);				           // establece posicion 1 - vertical pines pantalla abajo, 2-horizontal pines pantalla derecha, 3-vertical pines pantalla arriba, 4-horizontal pines pantalla izquierda.
  zonaFijaPantalla();                  // Llamamos a la función para mostrar los datos e imágenes que no se refrescan y permanecen fijos en pantalla.
}

void mostrarPantalla(){
  fecha();                                              // Recojemos los datos de fecha y hora
  temperatura();                                        // Recojemos los datos de temperatura, humedad y sensación térmica.
  int xpos = tft.width() / 2;                           // Centro del ancho de pantalla
  tft.setTextColor(TFT_WHITE,TFT_BLACK);                // Establece el color de texto y del fondo para el texto  
  tft.setFreeFont(FSSB24);                              // Select Free Serif 24 point font
  tft.setTextPadding(120);
  tft.setTextDatum(TC_DATUM);
  tft.drawString(horMin,xpos,22,GFXFF);
  tft.drawString(diaS + " " + dia + " " + mes + " " + ano,xpos,70, GFXFF);  // Imprimimos la fecha
  tft.setFreeFont(FSSB18);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);              // texto en color amarillo y fondo negro.
  tft.drawString(t1 + " | " + t2,xpos,155);		              // Imprimimos la temperatura y la humedad
  tft.drawString(t3,xpos,200, GFXFF);                     // Imprimimos la Sensación Térmica
}




