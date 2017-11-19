#include <Wire.h>
#include <SPI.h>
#include <TimedAction.h>

#include <Djam/Internet/Wifi.h>
#include <Djam/Digital/DoorSensor.h>
#include <Djam/Internet/Telegram.h>
#include <Djam/Bot/Bot.h>
#include <Djam/Utils/TimeUtil.h>

Djam::Internet::Wifi wifi;
Djam::Digital::DoorSensor doorSensor;
Djam::Internet::Telegram telegram;
Djam::Bot::Bot bot;
Djam::Utils::TimeUtil timeUtil;

TimedAction *thread100ms;
TimedAction *thread1s;
TimedAction *thread1m;

void scanSensors(){
  String doorNewState = doorSensor.getValue();

  if(doorNewState != doorSensor.previousState){
    int passedTime = (millis() - doorSensor.previousStateMillis);
    bot.alert("Door was " + doorNewState + ", previous state time: " + timeUtil.millisToHuman(passedTime));
    doorSensor.previousState = doorNewState;
    doorSensor.previousStateMillis = millis();
  } else if(doorNewState == "Opened"){
    bot.alert("Door is still Open", true);
  }
}

void processMessage(String command){
  bot.process(command);
}

void listenMessages(){
  telegram.listenMessages(processMessage);
}

void setup() {
    Serial.begin(9600);
    wifi.setup();
    wifi.printWifiStatus();
    telegram.setup();

    bot.setup(telegram, doorSensor);

    bot.alert("System initialized");
    bot.process("/status");

    thread100ms = new TimedAction(1000, scanSensors);
    thread1s = new TimedAction(1000, listenMessages);
}

void loop() {
  thread100ms->check();
  thread1s->check();
}
