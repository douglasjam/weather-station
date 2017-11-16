#include <Djam/Digital/Buttons.h>

void Djam::Digital::Buttons::setup(){
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
}

/**
* 0 MEANS NO CHANGE, 1 TURN OFF: 2 TURN ON
**/
unsigned int Djam::Digital::Buttons::getGreenStatus(){
  return handleStateChange("D4", greenValue, lastStateGreen, digitalRead(D4));
}


/* 0 MEANS NO CHANGE, 1 TURN OFF: 2 TURN ON **/
unsigned int Djam::Digital::Buttons::getWhiteStatus(){
  return handleStateChange("D3", whiteValue, lastStateGreen, digitalRead(D3));
}

unsigned int Djam::Digital::Buttons::handleStateChange(String id, bool &currentValue, bool &lastState, bool currentState){

  if(currentState == false){
    lastState = false;
    return Djam::Digital::Buttons::NO_CHANGE;
  }

  if(lastState == true){
    return Djam::Digital::Buttons::NO_CHANGE;
  }

  lastState = true;
  currentValue = !currentValue;

  Serial.println(id + " value: " + String(currentValue));

  if(currentValue){
    return Djam::Digital::Buttons::TURN_ON;
  } else {
    return Djam::Digital::Buttons::TURN_OFF;
  }

}
