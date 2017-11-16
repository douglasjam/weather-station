#ifndef DJAM_INTERNET_WIFI
#define DJAM_INTERNET_WIFI

#include <Djam/MyConfigs.h>
#include <ESP8266WiFi.h>

namespace Djam { namespace Internet {

  class Wifi {

    public:
      void setup();
      int getSinalStrength();
      void printWifiStatus();

  };

}}

#endif
