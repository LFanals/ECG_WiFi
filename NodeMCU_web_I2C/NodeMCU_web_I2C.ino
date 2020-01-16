/*********
  Llorenç Fanals Batllori
  Pol Fernández Rejón
  Graduat en Enginyeria Electrònica Industrial i Automàtica
  20/11/2019
*********/
#include <Wire.h>
String recibido;

int i_fila = 0;
int i_columna = 0;

#include <ESP8266WiFi.h> // Es carrega la llibreria Wi-Fi

// Credencials de la xarxa Wi-Fi a què ens volem connectar
// const char* ssid     = "DESKTOP-E5M4HBA 4049";
// const char* password = "E^1w1736";

const char* ssid     = "DESKTOP-MQE758J 3309";
const char* password = "04)R936v";

// Port que volem utilitzar. El 80 és el port per defecte, així que teclejant la IP a un navegador en farem prou. Si fos un altre port la IP acabaria en ":número_port".
WiFiServer server(80);


unsigned long TempsActual = millis(); // Current time
unsigned long TempsAnterior = 0; // Previous time
const long TempsConnectat = 100; // Define timeout time in milliseconds (example: 2000ms = 2s)


#define files 24
#define columnes 5

float vector[files][columnes]; // vector de dades
float vector2[files][columnes]; // vector de dades
int i = 0; // iterador per files
int j = 0; // iterador per columnes

#define D0 16
#define D1 5
#define D2 4
#define D3 0

#define ENTRADA_ANALOGICA A0

unsigned int hores_posada_marxa = 10; // l'hora en què es fa la posada en marxa
unsigned int minuts_posada_marxa = 23; // a les 10:23 es fa la posada en marxa

unsigned int hora_actual;
float minuts_actual;
unsigned int millis_anteriors;

void inicialitza_vectors() { // Emplena els vectors de dades fictícies. A còpia d'hores s'aniran reemplaçant per dades reals
  //temps, bpm, pendent bpm
  vector[0][0] = 0; vector[0][1] = 0; vector[0][2] = 0;
  vector[1][0] = 0; vector[1][1] = 0; vector[1][2] = 0;
  vector[2][0] = 0; vector[2][1] = 0; vector[2][2] = 0;
  vector[3][0] = 0; vector[3][1] = 0; vector[3][2] = 0;
  vector[4][0] = 0; vector[4][1] = 0; vector[4][2] = 0;
  vector[5][0] = 0; vector[5][1] = 0; vector[5][2] = 0;
  vector[6][0] = 0; vector[6][1] = 0; vector[6][2] = 0;
  vector[7][0] = 0; vector[7][1] = 0; vector[7][2] = 0;
  vector[8][0] = 0; vector[8][1] = 0; vector[8][2] = 0;
  vector[9][0] = 0; vector[9][1] = 0; vector[9][2] = 0;
  vector[10][0] = 0; vector[10][1] = 0; vector[10][2] = 0;
  vector[11][0] = 0; vector[11][1] = 0; vector[11][2] = 0;
  vector[12][0] = 0; vector[12][1] = 0; vector[12][2] = 0;
  vector[13][0] = 0; vector[13][1] = 0; vector[13][2] = 0;
  vector[14][0] = 0; vector[14][1] = 0; vector[14][2] = 0;
  vector[15][0] = 0; vector[15][1] = 0; vector[15][2] = 0;
  vector[16][0] = 0; vector[16][1] = 0; vector[16][2] = 0;
  vector[17][0] = 0; vector[17][1] = 0; vector[17][2] = 0;
  vector[18][0] = 0; vector[18][1] = 0; vector[18][2] = 0;
  vector[19][0] = 0; vector[19][1] = 0; vector[19][2] = 0;
  vector[20][0] = 0; vector[20][1] = 0; vector[20][2] = 0;
  vector[21][0] = 0; vector[21][1] = 0; vector[21][2] = 0;
  vector[22][0] = 0; vector[22][1] = 0; vector[22][2] = 0;
  vector[23][0] = 0; vector[23][1] = 0; vector[23][2] = 0;

  vector2[0][0] = 0; vector2[0][1] = 0; vector2[0][2] = 0;
  vector2[1][0] = 1; vector2[1][1] = 0; vector2[1][2] = 0;
  vector2[2][0] = 2; vector2[2][1] = 0; vector2[2][2] = 0;
  vector2[3][0] = 3; vector2[3][1] = 0; vector2[3][2] = 0;
  vector2[4][0] = 4; vector2[4][1] = 0; vector2[4][2] = 0;
  vector2[5][0] = 5; vector2[5][1] = 0; vector2[5][2] = 0;
  vector2[6][0] = 6; vector2[6][1] = 0; vector2[6][2] = 0;
  vector2[7][0] = 7; vector2[7][1] = 0; vector2[7][2] = 0;
  vector2[8][0] = 8; vector2[8][1] = 0; vector2[8][2] = 0;
  vector2[9][0] = 9; vector2[9][1] = 0; vector2[9][2] = 0;
  vector2[10][0] = 10; vector2[10][1] = 0; vector2[10][2] = 0;
  vector2[11][0] = 11; vector2[11][1] = 0; vector2[11][2] = 0;
  vector2[12][0] = 12; vector2[12][1] = 0; vector2[12][2] = 0;
  vector2[13][0] = 13; vector2[13][1] = 0; vector2[13][2] = 0;
  vector2[14][0] = 14; vector2[14][1] = 0; vector2[14][2] = 0;
  vector2[15][0] = 15; vector2[15][1] = 0; vector2[15][2] = 0;
  vector2[16][0] = 16; vector2[16][1] = 0; vector2[16][2] = 0;
  vector2[17][0] = 17; vector2[17][1] = 0; vector2[17][2] = 0;
  vector2[18][0] = 18; vector2[18][1] = 0; vector2[18][2] = 0;
  vector2[19][0] = 19; vector2[19][1] = 0; vector2[19][2] = 0;
  vector2[20][0] = 20; vector2[20][1] = 0; vector2[20][2] = 0;
  vector2[21][0] = 21; vector2[21][1] = 0; vector2[21][2] = 0;
  vector2[22][0] = 22; vector2[22][1] = 0; vector2[22][2] = 0;
  vector2[23][0] = 23; vector2[23][1] = 0; vector2[23][2] = 0;
}

int n_rebut = 0;
float mitjana = 0;
float desvest = 0;
int n_dades_hora = 0;
float sumatori_2 = 0;

void setup() {
  Wire.begin(4, 5);

  hora_actual = 0; // hores_posada_marxa
  minuts_actual = 0; // minuts_posada_marxa

  // Dades temporals dels vectors. Serveixen per mostrar com queden representades les gràfiques. S'aniran borrant les dades més antigues.
  inicialitza_vectors();

  Serial.begin(115200); // Habilitem el port sèrie a 115200 de baud rate

  // Ens connectem al Wi-Fi amb l'adreça i la contrasenya definits
  Serial.print("Connectant a: ");
  Serial.println(ssid); // Mostrem l'adreça del Wi-Fi
  WiFi.begin(ssid, password); // Iniciem la comunicació

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); // Cada 0,5 s que passin sense connectar-se mostra un punt
  }

  // S'ha connectat
  Serial.println("");
  Serial.println("WiFi connectat");
  Serial.println("Adreça IP: ");
  Serial.println(WiFi.localIP());
  server.begin();

}

void demana_dada (){
  Wire.requestFrom(8, 3); //0x08 = 8;

  while (0 < Wire.available()) {
    char c = Wire.read(); 
    int nombre = c-48; 
    //  Serial.println(nombre);
    n_rebut = n_rebut*10 + (c-48);
  }

  if (n_rebut != -2523){
  
      vector[i_fila][0] = millis();
      vector[i_fila][1] = n_rebut;
      
          for (i=0; i<files; i++){
            mitjana = vector[i][1]*(1.0/(i+1.0)) + mitjana*i/(i+1.0);  
          }
          int sumatori = 0;
          for (i=0; i<files; i++){
            sumatori += (mitjana - vector[i][1]) * (mitjana - vector[i][1]);  
          }
          desvest = sumatori / (files-1);
  
      vector[i_fila][2] = 1.0*pow(desvest, 0.5);
    // 2 ms per fer els càlculs de mitjana i desvest, acceptable  
          
      i_fila++;
      if (i_fila > files) {
        i_fila = 0;
      }
   
      Serial.println(n_rebut);  
  
  //----- dades hora, 2a gràfica -----
  
      n_dades_hora++;
      vector2[hora_actual][0] = hora_actual;
      vector2[hora_actual][1] = n_rebut*1.0/(n_dades_hora) + vector[hora_actual][1]*(n_dades_hora-1)/(n_dades_hora);
      vector2[hora_actual][2] = vector[i_fila-1][2]*1.0/(n_dades_hora) + vector2[hora_actual][2]*(n_dades_hora-1)/(n_dades_hora);
  }
    
  else {
      Serial.println("és -2523"); // l'Arduino Nano no té cap dada nova, captem aquest número
  }

    n_rebut = 0;

}

void loop() {
  //  Wire.beginTransmission(8);//0x08 = 8;
  //  Wire.write("esp to uno \n");
  //  Wire.endTransmission();
  // int temps_xyz = millis();
  
  demana_dada();
  delay(50);

// ---------------------------------------------------------------------------------------------

  WiFiClient client = server.available();   // Escolta si hi ha clients

  if (client) {                             // Si es connecta un nou client,
    Serial.println("Nou client.");
    String LiniaActual = "";                // una cadena memoritza la informació enviada pel client
    TempsActual = millis();
    TempsAnterior = TempsActual;
    while (client.connected() && TempsActual - TempsAnterior <= TempsConnectat) { // Si estem connectats i no han passat els milisegons que indica TempsConnectat,

      TempsActual = millis();
      if (client.available()) {             // Si el client ens passa informació,
        char c = client.read();             // llegim un caràcters ascii (un byte)
        Serial.write(c);                    // i el mostrem per pantalla
        if (c == '\n') {                    // Si rebem un canvi de línia com a caràcter,
          // és el final de la petició HTTP
          if (LiniaActual.length() == 0) {
            // Ara responem donant un OK i indicant el content type, volem una pàgina html. Finalment una línia en blanc, és el protocol
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Tancant connexió");
            client.println();
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("    <meta charset=\"UTF-8\">\n<meta http-equiv=\"Content-type\" content=\"text/html; charset=UTF-8\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("    <link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.7.2/css/all.css\" integrity=\"sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr\" crossorigin=\"anonymous\">\n""");
            client.println("    <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n    <script type=\"text/javascript\">\n      google.charts.load('current', {'packages':['line']});\n      google.charts.setOnLoadCallback(drawChart);\n\n");
            
            // Definim la gràfica de la primera branca
            client.println("    function drawChart() {\n\n      var data = new google.visualization.DataTable();\n      data.addColumn('number', 'Segons');\n      data.addColumn('number', 'Freqüència cardíaca (bpm)');\n      data.addColumn('number', 'Variabilitat (bpm/s)');");

            client.println("\n data.addRows([\n");
            for (i = i_fila; i < files; i++) {
              client.println("[");
              client.println(String(vector[i][0]));
              for (j = 1; j < 3; j++) {
                client.println(","); client.println(String(vector[i][j]));
              }
              client.println("]"); client.println(","); client.println("\n");
            }

            for (i = 0; i < i_fila; i++) {
              client.println("[");
              client.println(String(vector[i][0]));
              for (j = 1; j < 3; j++) {
                client.println(","); client.println(String(vector[i][j]));
              }
              client.println("]"); client.println(","); client.println("\n");
            }
            
          client.println("]);\n\n\n  var options = {\n            'width': 1000,\n            'height': 400,\n        chart: {\n          title: 'Frequència cardíaca (30 s)',\n          bold: true, \n          // subtitle: 'in millions of dollars (USD)'\n          width: 100,\n        },\n        titleTextStyle: {\n          bold: true,\n          fontSize: 18,\n        }\n     //   width: 900,\n     //   height: 500\n      };\n\n      var chart = new google.charts.Line(document.getElementById('linechart_material'));\n\n      chart.draw(data, google.charts.Line.convertOptions(options));\n    }\n    </script>");
          // Definim la gràfica de la segona branca
          client.println(" \n\n   <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n    <script type=\"text/javascript\">\n    google.charts.load('current', {'packages':['line']});\n    google.charts.setOnLoadCallback(drawChart);\n    \n\n    function drawChart() {\n\n    var data = new google.visualization.DataTable();\n    data.addColumn('number', 'Hora');\n      data.addColumn('number', 'Freqüència cardíaca (bpm)');\n      data.addColumn('number', 'Variabilitat (bpm/s)');");
/*           
            client.println("data.addRows([\n"); 
            for (i = hora_actual+1; i < files; i++) { // i = hora_actual ...
              client.println("[");
              client.println(String(vector2[i][0]));
              for (j = 1; j < 3; j++) {
                client.println(","); client.println(String(vector2[i][j]));
              }
              client.println("]"); client.println(","); client.println("\n");
            }
*/
            client.println("data.addRows([\n"); 
            for (i = 0; i < files; i++) { // i = hora_actual ...
              client.println("[");
              client.println(String(vector2[i][0]));
              for (j = 1; j < 3; j++) {
                client.println(","); client.println(String(vector2[i][j]));
              }
              client.println("]"); client.println(","); client.println("\n");
            }
/*
            for (i = 0; i < hora_actual+1; i++) {
              client.println("[");
              client.println(String(vector2[i][0]));
              for (j = 1; j < 3; j++) {
                client.println(","); client.println(String(vector2[i][j]));
              }
              client.println("]"); client.println(","); client.println("\n");
            }
*/
    client.println(" ]); \n\n\n\n   var options = {\n      'width': 1000,\n      'height': 400,\n        chart: {\n        title: 'Freqüència cardíaca (1 dia)',\n       // is3D: true\n        // subtitle: 'in millions of dollars (USD)'\n        },\n      titleTextStyle: {\n        bold: true,\n        fontSize: 18,\n      }\n     //   width: 700,\n     //   height: 400\n    };\n\n    var chart = new google.charts.Line(document.getElementById('linechart_material2'));\n\n    chart.draw(data, google.charts.Line.convertOptions(options));\n    }\n    </script>\n\n  </head>\n\n  <style>\n        .content {\n          max-width: 100%;\n          margin: left;\n        }\n   </style>\n\n<!--  ####################################################################################   -->\n\n    <style>\nul {\n  list-style-type: none;\n  margin: 0;\n  padding: 0;\n  overflow: hidden;\n  background-color: #333;\n}\n\nli {\n  float: left;\n}\n\nli a {\n  display: block;\n  color: white;\n  text-align: center;\n  padding: 14px 16px;\n  text-decoration: none;\n}\n\n/* Change the link color to #111 (black) on hover */\nli a:hover {\n  background-color: #f3f3f3;\n}\n\n.active {\n    background-color: #4CAF50;\n  }\n\n  li {\n    border-right: 1px solid #bbb;\n  }\n  \n  li:last-child {\n    border-right: none;\n  }\n\n  ul {\n    position: fixed;\n    top: 0;\n    width: 100%;\n  }\n/*\n  div{\n    display: none;\n}*/\n    \n.button {\n    align-items: right;\n    font-size: 16px;\n    display:inline-block;\n    padding:0.55em 1.0em;\n    border:0.25em solid #000000;\n    margin:0.3em 0.3em 0.3em 0.3em;\n    border-radius:0.05em;\n    box-sizing: border-box;\n    text-decoration:none;\n    font-family:'Roboto',sans-serif;\n    font-weight:800;\n    color:#000000;\n    text-align:center;\n    transition: all 0.2s;\n\n    background-color: #ffffff;\n    }\n    .button:hover{\n    color:#ffffff;\n    background-color:#000000;\n    }\n    @media all and (max-width:30em){\n    .button{\n    display:block;\n    margin:0.4em auto;\n    }\n    }\n\n    p.solid {\n             font-size: 25px;\n             font-weight: bold;\n             margin:0.3em 0.25em 0.3em 0.3em;\n             font-family:'Roboto',sans-serif;\n             border:0.25em solid #000000;\n             padding:0.25em 0.5em;\n             margin-left: 3pt;\n    }\n\n\n\n  p.text_limitat {\n    max-width: 600px;\n    margin-left: 30pt;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n    font-size: 15px;\n  }\n\n  h2.text_limitat {\n    max-width: 600px;\n    margin-left: 30pt;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n    font-size: 25px;\n  }\n\n  img.text_limitat {\n    max-width: 600px;\n    margin-left: 30pt;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n    font-size: 25px;\n    padding-top: 10px;\n  }\n\n h3.text_limitat {\n    max-width: 600px;\n    margin-left: 30pt;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n    font-size: 18px;\n    margin-bottom: -5pt;\n  }  h2.titol {\n    max-width: 600px;\n    margin-left: 15pt;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n    font-size: 25px;\n    margin-bottom: -5pt;\n  }\n    \n    </style>\n\n<style>\n  .footer {\n    position: fixed;\n    left: 0;\n    bottom: 0;\n    width: 100%;\n    background-color: black;\n    color: white;\n    text-align: center;\n    height: 35px;\n    padding: 10px;\n    padding-top: 6px;\n    font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\n  }\n\n\n\n\n  .s-m{\n  margin: 0px auto;\n  justify-content: space-around;\n  display: flex;\n  max-width: 80px;\n   display: block;\nmargin: 0 auto;\n}\n.s-m a{\n  text-decoration: none;\n  font-size: 40px;\n  color: #f1f1f1;\n  width: 40px;\n  height: 40px;\n  text-align: center;\n  transition: 0.4s all;\n  line-height: 40px;\n  cursor: pointer;\n  background: #314652;\n  border-radius: 50%;\n}\n.s-m a:hover{\n  transform: scale(1.25);\n}\n\n\n  </style>\n\n\n<!--  ####################################################################################   -->\n\n\n  <body class=\"content\">\n\n    <p class=\"solid\">\n      Monitorització de freqüència cardíaca - Lloren&ccedil Fanals Batllori i Pol Fernández Rejón\n    </p>\n    \n      \n      <button class=\"button\" onclick=\"MostraGrafiques()\">Gràfiques</button>\n      <button class=\"button\" onclick=\"MostraImatge()\">Hardware</button>\n      <button class=\"button\" onclick=\"Explicacio()\">Explicació ECG</button>\n\n    <script>\n      function MostraGrafiques() {\n        var x = document.getElementById(\"hardware\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"teoria\");\n        x.style.display = \"none\";\n\n        x = document.getElementById(\"titol_grafs\");\n        x.style.display = \"block\";\n        x = document.getElementById(\"linechart_material2\");\n        x.style.display = \"block\";\n        x = document.getElementById(\"linechart_material\");\n        x.style.display = \"block\";\n      }\n      </script>\n\n    <script>\n      function MostraImatge() {\n        var x = document.getElementById(\"hardware\");\n        x.style.display = \"block\";\n        x = document.getElementById(\"teoria\");\n        x.style.display = \"none\";\n\n        x = document.getElementById(\"titol_grafs\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"linechart_material2\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"linechart_material\");\n        x.style.display = \"none\";\n      }\n      </script>\n\n    <script>\n      function Explicacio() {\n        var x = document.getElementById(\"hardware\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"teoria\");\n        x.style.display = \"block\";\n\n        x = document.getElementById(\"titol_grafs\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"linechart_material2\");\n        x.style.display = \"none\";\n        x = document.getElementById(\"linechart_material\");\n        x.style.display = \"none\";\n      }\n      </script>\n\n       <!-- <img src=\"https://drive.google.com/uc?export=view&id=1XgS6bALyKzA9_3eu245chrkyhIlQpjpq\" style=\"width: 50%;\" alt=\"Flowers in Chania\"> --> \n      <!--  <h2 align=\"margin-left\">Pol Fernández Rejón</h2> --> \n        <div id=\"titol_grafs\"><h2 class=\"text_limitat\">Gràfiques temporals</h2>  </div>\n\n        <div id=\"linechart_material\" style=\"width: 800px; height: 400px; padding: 25px\"></div>  \n        <div id=\"linechart_material2\" style=\"width: 800px; height: 400px; padding: 25px\"></div> \n\n      <div id=\"hardware\">    \n  <h2 class=\"text_limitat\">Esquema de blocs</h2>\n        <p class=\"text_limitat\">Mitjançant un parell de convertidors s'aconsegueixen tensions\n           de 5 V i 3,3 V respectivament, les quals permeten alimentar tota l'electrònica.\n          Hi ha comunicació I2C entre l'Arduino Nano i l'ESP-01. L'Arduino actua com el cervell\n          i l'ESP-01 mostra la web amb les dades més recents.  </p>\n          <img class=\"text_limitat\"\n          src=\"https://drive.google.com/uc?export=view&id=1OwWSyZsfkwHrD8OPpXs3E0eJzi3jnsBT\"\n         alt=\"Flowers in Chania\">\n\n      <p class=\"text_limitat\"> </br></p>     <!-- <img src=\"https://drive.google.com/uc?export=view&id=15-EkLWMhYaRsv-dtbyrlKOrbD7dY71B2\"\n      style=\"width: 500px; height: 500px; margin-left: 100px; padding: 25px\" alt=\"Flowers in Chania\"> --> \n       <h3 class=\"text_limitat\">Circuit imprès</h3>\n      <p class=\"text_limitat\">S'ha dissenyat un circuit imprès per integrar tot el hardware en una placa\n        de dimensions reduïdes. S'ha intentat disposar les plaques d'avaluació de manera que \n        s'optimitzi l'espai el màxim possible. La placa és a dues cares. \n      </p>\n      <img class=\"text_limitat\"\n      src=\"https://drive.google.com/uc?export=view&id=1zm5T1PXHEUKQYz4tofg1PaqOihKiulTZ\"\n      alt=\"Flowers in Chania\">\n\n      <!-- BATERIA-->\n\n         <h3 class=\"text_limitat\">Bateria 1,2 V</h3>\n      <p class=\"text_limitat\">La bateria de 1,2 V és pila de 2800 mAh de capacitat. Ofereix\n        una molt bona densitat d'energia, ja que té les dimensions estàndard d'una pila AA.\n        És recarregable i permet alimentar el nostre equip durant més d'un dia de forma continuada,\n        fins i tot si es tenen els LEDs encesos durant 24 hores. \n      </p>\n      <img class=\"text_limitat\"\n      src=\"https://drive.google.com/uc?export=view&id=1su7yWmxdUWt62ViUL51esPzXSx__obBr\"\n      alt=\"Flowers in Chania\">\n      <p class=\"text_limitat\">Passades 24 hores es recomana que es recarregui la pila per evitar \n        que deixi de funcionar l'electrònica. No és desitjable perdre dades emmagatzemades a la memòria\n        RAM de l'ESP-01.\n      </p>\n\n      <!-- CONVERTIDOR 5 V-->\n      <h3 class=\"text_limitat\">Convertidor Boost</h3>\n      <p class=\"text_limitat\">L'etapa de potència del nostre equip s'encarrega de transformar\n        la tensió d'aproximadament 1,2 V de la pila a 5 V mitjançant un convertidor Boost que\n         admet una tensió d'entrada mínima de 1 V i pot donar fins a 500 mA a la seva \n       sortida de 5 V. Té una eficiència elevada i la seva sortida és constant. Les dimensions\n        són acceptables.\n      </p>\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1fSzKGQfWndyXMUUC9zmsDMvqrOHgsf7d\">\n\n      <!-- CONVERTIDOR 3,3 V-->\n      <h3 class=\"text_limitat\">Convertidor lineal</h3>\n      <p class=\"text_limitat\">No n'hi ha prou de tenir 5 V a la sortida d'aquest convertidor. Els 5 V\n         són necessaris per alimentar l'Arduino Nano, ja que el seu microcontrolador ATMEGA328 funciona\n          a 5 V. La petita placa que conté l'ESP8266 i la placa de l'ADS8232\n         van alimentades a 3,3 V. Per tant, és necessari disposar d'una tensió d'alimentació de 3,3 V.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1AuJwkozRa4aLbtxMsWHGX_w2L3Sn2Uql\">\n\n      <p class=\"text_limitat\">\n        S'opta per un regulador lineal de bona eficiència anomenat AMS1117-3.3. Està especialment pensat\n         per passar de tensions de 5 V a 3,3 V, que és exactament el que necessitem. A la seva entrada \n         hi connectarem un condensador de 10 uF, així com a la seva sortida. \n        Aquests condensadors evitaran la caiguda de tensió a la sortida en pics d'intensitat a la sortida.\n      </p>\n\n\n      <!-- AD8232-->\n      <h3 class=\"text_limitat\">AD8232</h3>\n      <p class=\"text_limitat\">La part d'instrumentació de la placa dona una senyal analògica a partir\n         de la senyal captada als tres elèctrodes. \n        Per això es fa servir una placa de desenvolupament que conté un integrat anomenat AD8232.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1EaA605i9rI-t80x6dUTh64XHpr6J7Ve-\">\n\n      <p class=\"text_limitat\">En essència, el que es fa és alimentar la placa i llegir les \n        tensions als tres elèctrodes. Dues d'aquestes tensions es resten i el \n        resultat s'amplifica amb un amplificador diferencial, la referència del qual és el tercer elèctrode.\n     </p>\n\n      <!-- ESP-01-->\n      <h3 class=\"text_limitat\">ESP-01</h3>\n      <p class=\"text_limitat\">L'integrat ESP8266 muntat en una placa amb antena, cristall oscil·lador, \n        resistències de pullup i condensadors de desacoblament es coneix com a ESP-01 i el seu pinout.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1nRSj8TfxQX8b6YnCC7QlvUsoBs0WtlVC\">\n\n      <p class=\"text_limitat\">El fet de què aquesta placa només tingui 8 pins no vol dir que el \n        component només tingui 8 pins, de fet en té al voltant de 30. La placa que utilitzem té \n        dos pins d'alimentació, un pin de TX i un de \n        RX, dos pins de caràcter general, un pin per fer reset i un pin per habilitar l'integrat.\n      </p>\n\n      <!--Arduino NANO-->\n      <h3 class=\"text_limitat\">Arduino Nano</h3>\n      <p class=\"text_limitat\">L'integrat ESP8266 muntat en una placa amb antena, cristall oscil·lador, \n        resistències de pullup i condensadors de desacoblament es coneix com a ESP-01 i el seu pinout.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1gQma7MnP8vwtP7156rMhl5s3wbR8Psqq\">\n\n      <p class=\"text_limitat\">El fet de què aquesta placa només tingui 8 pins no vol dir que el \n        component només tingui 8 pins, de fet en té al voltant de 30. La placa que utilitzem té \n        dos pins d'alimentació, un pin de TX i un de \n        RX, dos pins de caràcter general, un pin per fer reset i un pin per habilitar l'integrat.\n     </p>\n\n      <!-- Anell de LEDs -->\n      <h3 class=\"text_limitat\">Anell de LEDs</h3>\n      <p class=\"text_limitat\">S'ha previst disposar d'un anell de LEDs per visualitzar de forma \n        ràpida i intuïtiva la freqüència cardíaca de la persona que porti el dispositiu. Per bé que no podrà\n         conèixer amb excessiva precisió la freqüència cardíaca de la persona, se'n pot fer una bona idea.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1dXnm-I8f1N_SSJA29Ub9T15MHDirklRu\">\n\n      <p class=\"text_limitat\">L'anell que s'ha escollit és de la casa SparkFun. Té 16 LEDs 5050 disposats\n         de forma circular. S'ha d'alimentar a 5 V i mitjançant un pin de DATA\\_IN es pot fer el\n         control dels colors de tots els LEDs així com de la seva intensitat llumínica i la seva saturació.\n     </p>\n\n\n\n      <p class=\"text_limitat\"> </br></p>   </div>    \n        \n      <div id=\"teoria\" class=\"teoria\">\n           <h2 class=\"text_limitat\">Electrocardiograma</h2>\n      <p class=\"text_limitat\">De forma teòrica, un electrocardiograma és una mesura indirecta de \n        l'activitat elèctrica cardíaca. De fet, és la única mesura no invasiva de què es disposa per aquest fi. \n        Permet identificar alteracions anatòmiques, el ritme, alteracions iòniques...\n      </p>\n      <p class=\"text_limitat\">Durant la despolarització del miòcit cardíac es genera una diferència \n        de potencial de 90 mV. El camp elèctric que es genera és captat pels elèctrodes. Aquesta senyal \n        elèctrica s'amplifica per tal d'aprofitar el rang \n        dels convertidors analògics digitals de què disposen els electrocardiògrafs digitals.\n      </p>\n\n      <img class=\"text_limitat\" style=\"height:200px;\"\n      src=\"https://drive.google.com/uc?export=view&id=1EOcIxBEm0G_6diMqYsgq4QYmasYX7arc\">\n\n      <p class=\"text_limitat\">Hi ha molta literatura que permet identificar malalties analitzant \n        els diferents segments, la seva durada i l'amplitud de la senyal. Tot i que considerem que \n        es podria programar un algorisme per fer un anàlisi de la senyal, \n        ens hem centrat en calcular la freqüència cardíaca en batecs per minut.\n      </p>\n        <img class=\"text_limitat\" style=\"height:200px;\"\n        src=\"https://drive.google.com/uc?export=view&id=14taRHhw0VruvAXfy3oI7wcPZ6cPwhSoV\">\n\n        <p class=\"text_limitat\">Per calcular la freqüència cardíaca es defineixen dos nivells d'amplitud\n          de la senyal analògica captada. Quan se supera el llindar superior vol dir que hi ha hagut un nou\n          batec i s'indica canviant l'estat d'un booleà. A més, es calcula el temps respecte el batec anterior.\n          Quan es baixa d'el llindar inferior es canvia el valor del booleà, indicant que ja s'ha donat el \n          pic del batec; ens preparem pel següent batec.\n        </p>\n        <p class=\"text_limitat\"> </br></p>      </div>\n\n      <div class=\"footer\">\n        <span style=\"float:left; margin-top: 10 px; margin-left: 10px;\">Electrocardiograma</span>\n        <span style=\"float:right; margin-right: 25px;\">Llorenç Fanals Batllori - Pol Fernández Rejón</span>\n        <div class=\"s-m\">\n          <a class=\"fab fa-github\"  href=\"https://github.com/LFanals/ECG_WiFi\"></a>\n\n        </div>\n\n      </div>\n\n\n  </body>\n</html>\n\n");
    //Serial.println(millis());
    
            break; // Sortim del if (LiniaActual.length() == 0) 
          }
          else { // si tens una nova línia, neteja LiniaActual
            LiniaActual = "";
          }
        }

        else if (c != '\r') {  // Si tens algun caràcter afegiex-lo al final de LiniaActual
          LiniaActual += c;
        }
      }
    }

    // Tanquem la connexió, esperant un nou client o que el client existent refresqui la pàgina
    client.stop();
    Serial.println("Client desconnectat.");
    Serial.println("");
  }
  // Mirem si cal actualitzar els minuts i les hores i si cal fer una lectura de tensions
  comprova_temps();
 
}

void comprova_temps() {
  if ((millis() - millis_anteriors) >= 60000) { // ha passat un minut
  //  minuts_actual = (millis() - millis_anteriors) / 60000; // minuts_actual que sigui float i que guardi segons
    minuts_actual++; 
    // Serial.print("        MINUTS"); Serial.println(minuts_actual);
    millis_anteriors = millis(); // memoritzem el moment en què això ha passat
    if (minuts_actual >= 60) { // si portem 60 minuts, diem que en portem 0 i incrementem l'hora
      minuts_actual = 0;
      hora_actual++;
      sumatori_2 = 0; n_dades_hora = 0;
      //      lectura_tensions(); // cridem la funció que llegeix les tensions
    }
    if (hora_actual >= 24) { // si l'hora és 24, la passem a 0
      hora_actual = 0;
    }
  }
}
