#include <SPI.h>

class MyDigital {

  bool lastStateGreen = false;
  bool greenValue = false;

  bool lastStateWhite = false;
  bool whiteValue = false;

  public: void setup(){
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
  }

  /**
  * 0 MEANS NO CHANGE, 1 TURN OFF: 2 TURN ON
  **/
  public: unsigned int getGreenStatus(){
    return handleStateChange("D4", greenValue, lastStateGreen, digitalRead(D4));
  }

  /**
  * 0 MEANS NO CHANGE, 1 TURN OFF: 2 TURN ON
  **/
  public: unsigned int getWhiteStatus(){
    return handleStateChange("D3", whiteValue, lastStateGreen, digitalRead(D3));
  }

  private: unsigned int handleStateChange(String id, bool &currentValue, bool &lastState, bool currentState){

    if(currentState == false){
      lastState = false;
      return 0;
    }

    if(lastState == true){
      return 0;
    }

    lastState = true;
    currentValue = !currentValue;

    //Serial.println(id + " value: " + String(currentValue));

    if(currentValue){
      return 2;
    } else {
      return 1;
    }

  }


};
