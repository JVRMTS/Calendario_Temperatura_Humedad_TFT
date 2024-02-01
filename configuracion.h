
/* Fichero de configuración para el reloj con envío de datos por POST y actualización via OTA
 * Creado el 27/12/2023
 * por @JMTS
*/

// Configuración de la Ubicación
// tambien da nombre al puerto de actualizacion via OTA

byte ub = 6;// Ubicación (1-despacho) (2-salon) (3-dormitorio) (4-resumen) (5-patio)

char* ubicacion(){
  char *ubic;
    if (ub == 1)
  {
    ubic = "DESPACHO";
  }
  else if (ub == 2)
  {
    ubic = "SALON";
  }
  else if (ub == 3)
  {
    ubic = "DORMITORIO";
  }
  else if (ub == 4)
  {
    ubic = "RESUMEN";
  }
  else if (ub == 5)
  {
    ubic = "PATIO";
  }
  else if (ub == 6)
  {
    ubic = "PRUEBAS";
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
String url = "http://" + dominio + "/config/insertar_post.php"; // Dirección web del servidor con el dominio insertado
