#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <MyConfigs.h>

class MyThingSpeak {

  WiFiClient client;

  public: void setup(){
    ThingSpeak.begin(client);
  }

  public: void sendData(float temperature, float pressure, float sinalStrength){
    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, pressure);
    ThingSpeak.setField(3, sinalStrength);
    ThingSpeak.writeFields(THINGSPEAK_CHANNEL, THINGSPEAK_KEY);
    Serial.println("Thing speak sent");
  }

};
