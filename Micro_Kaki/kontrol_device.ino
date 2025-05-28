#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

const char* ssid = "Bismillah_nasional_24";
const char* password = "";

String com_command;
WebServer server(80);

void init_kontrol() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();
}

void HTTP_handleRoot(void) {
  if (server.hasArg("State")) {
    Serial.println(server.arg("State"));
  }
  server.send(200, "text/html", "");
  delay(1);
}

bool d_langkah_ganti = false;
bool langkah_tangga = false;
bool langkah_geser = false;

void main_kontrol() {
  server.handleClient();
  com_command = server.arg("State");
  if (com_command == "S") command(1, 1, 1, 1, 1);

  if (d_langkah_ganti == false && langkah_tangga == false && langkah_geser == false) {
    if (com_command == "U") maju();
    if (com_command == "B") mundur();
    if (com_command == "L") putar_kiri();
    if (com_command == "R") putar_kanan();
  }

  if (d_langkah_ganti == true) {
    if (com_command == "U") maju_tinggi();
    if (com_command == "B") mundur_tinggi();
    if (com_command == "L") putar_tinggi_kiri();
    if (com_command == "R") putar_tinggi_kanan();
  }

  if (langkah_tangga == true) {
    if (com_command == "U") command(1, 1, 1, 1, 1);
    if (com_command == "B") command(1, 1, 1, 1, 1);
    if (com_command == "L") langkah_tangga_geser_kiri();
    if (com_command == "R") langkah_tangga_geser_kanan();
  }
   if (langkah_geser == true) {
    if (com_command == "U") maju_tinggi();
    if (com_command == "B") mundur_tinggi();
    if (com_command == "L") kiri_tinggi_lambat();
    if (com_command == "R") kanan_tinggi_lambat ();
  }

  if (com_command == "Q") command(1, 1, 1, 0, 0); //Capit_turun
  if (com_command == "W") command(0, 0, 0, 0, 0); //Capit_Tutup
  if (com_command == "I") command(1, 1, 1, 1, 0); //Capit_Buka
  if (com_command == "J") command(1, 1, 1, 0, 1); //Capit_Naik
  if (com_command == "Z") capit_turun_sebagian();


  if (com_command == "G") d_langkah_ganti = false;
  if (com_command == "H") d_langkah_ganti = true;
  if (com_command == "N") langkah_tangga = false;
  if (com_command == "T") langkah_tangga = true;
  if (com_command == "A") langkah_geser = false;
  if (com_command == "X") langkah_geser = true;
  

  Serial.println("code: " + com_command);
}
