#include <SPI.h>

class MyAnalogic {

public: void setup(){
  pinMode(A0, INPUT);
}

public: double getCO2(){
  return analogRead(A0);
}

};
