#include <String.h>
#include <WifiClient.h>
#include <MyConfigs.h>

class MyInfluxDb {

  WiFiClient client;

  public: void setup(){
    //db = "db=weatherstation";
  }

  private: void sendPost(String message){

    if (client.connect(INFLUX_HOST, 8086)) {
      Serial.println("InfluxDb sent");

      // EDIT: The POST 'URL' to the location of your insert_mysql.php on your web-host
      client.println("POST " + INFLUX_URL + " HTTP/1.1");

      // EDIT: 'Host' to match your domain
      client.println("Host: " + INFLUX_HOST);
      client.println("User-Agent: ESP8266");
      client.println("Connection: close");
      client.println("Content-Type: application/x-www-form-urlencoded;");
      client.print("Content-Length: ");
      client.println(message.length());
      client.println();
      client.println(message);

    } else {
      // If you couldn't make a connection
      Serial.println("Connection failed");
      Serial.println("Disconnecting.");
      client.stop();
    }
  }

  public: void sendData(float temperature, float pressure, int wifiStrength, float co2){

    String message = String("temperature value=") + String(temperature) + '\n';
    message += String("pressure value=") + String(pressure) + '\n';
    message += String("co2 value=") + String(co2) + '\n';
    message += String("wifi_strenght value=") + String(wifiStrength);

    sendPost(message);
  }

};
