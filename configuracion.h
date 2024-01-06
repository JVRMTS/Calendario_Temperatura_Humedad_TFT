
/* Fichero de configuración para el reloj con envío de datos por POST y actualización via OTA
 * Creado el 27/12/2023
 * por @JMTS
*/

// Configuración de la Ubicación
// tambien da nombre al puerto de actualizacion via OTA

byte ub = 3;// Ubicación (1-despacho) (2-salon) (3-pruebas) estas las puedes cambiar a lo que desees asi como añadir o quitar.

char* ubicacion(){
  char *ubic;
  if (ub == 1)
  {
    ubic = "Despacho";
  }
  else if (ub == 2)
  {
    ubic = "Salon";
  }
  else if (ub == 3)
  {
    ubic = "Pruebas";
  }
  return ubic;
}

//Configuración de la WiFi
const char *ssid = "****";     // Pon el nombre de tu WiFi
const char *password = "****"; // Pon la contraseña de tu WiFi

//Password para la actualización via OTA
char *passwordOTA = "****";    // Pon una contraseña para la actualización via OTA

//Configuración del Servidor Web
String dominio = "tu_dominio.com";                          // Pon el dominio que vayas a utilizar
String url = "http://" + dominio + "/config/inse_post.php"; // Dirección web del servidor con el dominio insertado
