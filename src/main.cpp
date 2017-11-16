#include <Wire.h>
#include <SPI.h>
#include <TimedAction.h>

#include <Djam/Analogic/SmokeSensor.h>
#include <Djam/Digital/Buttons.h>
#include <Djam/Internet/Wifi.h>
#include <Djam/I2C/Oled.h>
#include <Djam/I2C/BMP280.h>
#include <Djam/Internet/InfluxDB.h>

Djam::Digital::Buttons buttons;
Djam::Analogic::SmokeSensor smokeSensor;
Djam::Internet::Wifi wifi;
Djam::Internet::InfluxDB influxDB;
Djam::I2C::Oled oled;
Djam::I2C::BMP280 bmp280;

TimedAction *thread100ms;
TimedAction *thread1s;
TimedAction *thread1m;

//-- flow control
unsigned long oledActiveUntil;
bool oledPermanent;

//-- input states
bool lastStateGreen;
bool lastStateWhite;

//-- sensors values
double smoke;
double temperature;
double pressure;
int sinalStrength;

void submitData(){
  influxDB.sendData(temperature, pressure, sinalStrength, smoke);
}

void readSensors(){
    temperature = bmp280.getTemperature();
    oled.setPageValue(smokeSensor.getName(), String(temperature));

    pressure = bmp280.getPressure();
    oled.setPageValue(smokeSensor.getName(), String(pressure));

    smoke = smokeSensor.getValue();
    oled.setPageValue(smokeSensor.getName(), String(smoke));

    sinalStrength = wifi.getSinalStrength();
}

void rotateDisplay(){
    readSensors();

    if(oledPermanent && oledActiveUntil < millis()){
      oled.printMessage("");
      return;
    }

    oled.printNextPage();
}

void readInputs(){

  unsigned int whiteStatus = buttons.getWhiteStatus();
  unsigned int greenStatus = buttons.getGreenStatus();

  if(greenStatus == 2){
    oledPermanent = true;
    rotateDisplay();
    return;
  }

  if(greenStatus == 1){
    oledPermanent = false;
    oledActiveUntil = 0;
    rotateDisplay();
  }

  if(whiteStatus == 2){
    oled.printNextPage();
    oledActiveUntil = millis() + 10000;
    rotateDisplay();
  }
}

void setup() {
    Serial.begin(9600);
    influxDB.setup();
    wifi.setup();

    oled.addPage(smokeSensor.getName());
    oled.addPage(bmp280.getPressureLabel());
    oled.addPage(bmp280.getTemperatureLabel());

    bmp280.setup();
    buttons.setup();

    smokeSensor.setup();

    thread100ms = new TimedAction(300, readInputs);
    thread1s = new TimedAction(5000, rotateDisplay);
    thread1m = new TimedAction(60000, submitData);
}

void loop() {
  thread100ms->check();
  thread1s->check();
  thread1m->check();
}
