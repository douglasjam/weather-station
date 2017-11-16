#include <Djam/Analogic/SmokeSensor.h>

void Djam::Analogic::SmokeSensor::setup(){
  pinMode(A0, INPUT);
}

String Djam::Analogic::SmokeSensor::getName(){
    return "Smoke";
}

double Djam::Analogic::SmokeSensor::getValue(){
  return analogRead(A0);
}
