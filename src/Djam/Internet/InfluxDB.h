#ifndef DJAM_INTERNET_INFLUXDB
#define DJAM_INTERNET_INFLUXDB

#include <String.h>
#include <WifiClient.h>

namespace Djam { namespace Internet {

  class InfluxDB {

    public:
      void setup();
      void sendData(float temperature, float pressure, int wifiStrength, float co2);

    private:
      WiFiClient client;
      void sendPost(String message);

  };

}}

#endif
