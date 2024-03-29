<h1>CALENDARIO CON TEMPERATURA, HUMEDAD Y SENSACIÓN TÉRMICA CON ESP32 Y ENVIO A BASE DE DATOS EN UNA TFT 480 x 320</h1>

<h2>ACTUALIZACIÓN DEL 10/02/2024</h2>

Se han actualizado el fichero tft.h. Ahora se utilizan Sprites para dibujar la pantalla y evitar el parpadeo.
Tambien se ha actulizado el fichero configuracion.h para asignar una ip fija en vez de dinamica.
Se han juntado todos los iconos en el fichero imagenes.h.

Es una variación del otro reloj que tengo publicado la diferencia está en la TFT

Se visualiza la Fecha, la Hora, el día de la semana, el día, el mes y el año.
Se actualiza solo el horario de verano.
Tambien se visualiza la temperatura, la humedad y la sensación termica.

La estructura de la base de datos y la publicación en la web la puedes ver en el otro Reloj."# Calendario_Temperatura_Humedad_TFT" 

<img src="Calendario_Temperatura_Humedad_TFT.jpg" alt="Calendario_Temperatura_Humedad_TFT" />

Nota: "En la placa WEMOS D1 R32 no se muestran datos porque no hay conectado un sensor DHT"
<p>
Probado con ESP32 DEVKIT y WEMOS D1 R32 (En la placa WEMOS D1 R32 con forma de arduino 1 para que funcione hay que realizar las modificaciones descritas en la libreria TFT_eSPI y en <a href="https://github.com/s60sc/Adafruit_TouchScreen" target="_blank">github.com/s60sc/Adafruit_TouchScreen</a> si quieres utilizar el touch panel)
<p>
He adjuntado los dos setup para los dos tipos de placas en la libreria TFT_eSPI en el archivo User_Setup_Select.h se ha de seleccionar el que se desea, adjunto foto donde se ve.
<p>
<img src="User_Select_Setup.png" alt="User_Select_Setup para la libreria TFT_eSPI" />

CONFIGURACIÓN DE PINES PARA ESP32 DEV MODULE

DHT         PIN 22 

TFT CS      PIN 15

TFT RST     PIN 4

TFT O/C     PIN 2

TFT SCK     PIN 18

TFT SDI     PIN 23

TFT BL      5V o 3.3V   RETROILUMINACIÓN

TFT SD0     LIBRE

TFT TCK     PIN 18  TOUCH

TFT TCS     PIN 21  TOUCH

TFT TD1     PIN 23  TOUCH

TFT TD0     PIN 19  TOUCH