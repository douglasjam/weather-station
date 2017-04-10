#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

#define BMP280_ADDRESS (0x76)

class MyBMP {

  Adafruit_BMP280 bmp;

  public: void setup(){

    if (!bmp.begin()) {
      Serial.println("Failed to initialize BMP");
      return;
    }
  }

  public: double getTemperature() {
    return bmp.readTemperature() - 2.5;
  }

  public: double getPressure() {
    return bmp.readPressure();
  }

};
