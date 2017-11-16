#include <Djam/I2C/BMP280.h>

void Djam::I2C::BMP280::setup(){

  if (!bmp.begin()) {
    Serial.println("Failed to initialize BMP");
    return;
  }
}

double Djam::I2C::BMP280::getTemperature() {
  return bmp.readTemperature() - 2.5;
}

String Djam::I2C::BMP280::getTemperatureLabel() {
  return "Temperature";
}

double Djam::I2C::BMP280::getPressure() {
  return bmp.readPressure();
}

String Djam::I2C::BMP280::getPressureLabel() {
  return "Pressure";
}
