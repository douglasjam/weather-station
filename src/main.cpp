#include <Wire.h>
#include <SPI.h>

#include <MyAnalogic.cpp>
#include <MyDigital.cpp>
#include <MyWifi.cpp>
#include <MyOled.cpp>
#include <MyBMP.cpp>
#include <MyInfluxDb.cpp>
#include <MyTimer.cpp>

MyDigital myDigital;
MyAnalogic myAnalogic;
MyWifi myWifi;
MyOled myOled;
MyBMP myBMP;
MyInfluxDb myInfluxDb;
MyTimer myTimer;

//-- flow control
unsigned int oledPage = 0;
unsigned long oledActiveUntil;
bool oledPermanent;

//-- sensors values
double co2;
double temperature;
double pressure;
int sinalStrength;

void submitData(){
  myInfluxDb.sendData(temperature, pressure, sinalStrength, co2);
}

void readSensors(){
    temperature = myBMP.getTemperature();
    pressure = myBMP.getPressure();
    sinalStrength = myWifi.getSinalStrength();
    co2 = myAnalogic.getCO2();
}

void rotateDisplay(){

    readSensors();
    String message = "";

    if(oledPermanent && oledActiveUntil < millis()){
      myOled.printMessage("");
      return;
    }

    if(oledPage < 5){
      message = String("Temperature: ")  + String(temperature, 2);
      myOled.printMessage(message);
      oledPage++;
      return;
    } else if(oledPage < 10) {
     message = String("Pressure: ") + String(pressure, 2);
     myOled.printMessage(message);
     oledPage++;
     return;
   } else if(oledPage < 15) {
    message = String("CO2: ") + String(co2);
    myOled.printMessage(message);
    oledPage++;
    return;
  } else if(oledPage < 20) {
    message = String("SinalStrength: ") + String(sinalStrength);
    myOled.printMessage(message);
   oledPage++;
   return;
 } else {
    oledPage = 0;
 }
}

void readInputs(){

  unsigned int whiteStatus = myDigital.getWhiteStatus();
  unsigned int greenStatus = myDigital.getGreenStatus();

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
    oledPage+=5;
    oledActiveUntil = millis() + MyTimer::_10s;
    rotateDisplay();
  }
}

void setup() {
    Serial.begin(9600);

    myWifi.setup();
    myOled.setup();
    myBMP.setup();
    myDigital.setup();
    myAnalogic.setup();

    myTimer.set100ms(&readInputs);
    myTimer.set1s(&rotateDisplay);
    myTimer.set1m(&submitData);
}

void loop() {
  myTimer.run();
}
