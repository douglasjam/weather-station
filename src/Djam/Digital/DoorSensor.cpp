#include <Djam/Digital/DoorSensor.h>

void Djam::Digital::DoorSensor::setup(){
  pinMode(D0, INPUT);
}

String Djam::Digital::DoorSensor::getName(){
    return "Door";
}

String Djam::Digital::DoorSensor::getValue(){
  return digitalRead(D0) ? "Closed" : "Opened";
}
