#ifndef DJAM_I2C_BMP
#define DJAM_I2C_BMP

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

#define BMP280_ADDRESS (0x76)

namespace Djam { namespace I2C {

  class BMP280 {

    Adafruit_BMP280 bmp;

    public:
       void setup();
       double getTemperature();
       String getTemperatureLabel();
       double getPressure();
       String getPressureLabel();
  };

}}

#endif
