#include <Djam/Internet/Wifi.h>

void Djam::Internet::Wifi::setup(){
  WiFi.begin(WIFI_SSID, WIFI_PWD);

  Serial.print("Conectando ao wifi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  printWifiStatus();
  Serial.println("");
}

int Djam::Internet::Wifi::getSinalStrength(){
  return WiFi.RSSI();
}

void Djam::Internet::Wifi::printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(String(ip));

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(String(rssi));
  Serial.println(" dBm");
}
