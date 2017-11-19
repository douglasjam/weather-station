#include <Djam/Bot/Bot.h>

void Djam::Bot::Bot::setup(
  Djam::Internet::Telegram telegram,
  Djam::Digital::DoorSensor doorSensor
){
  this->telegram = telegram;
  this->doorSensor = doorSensor;
}

void Djam::Bot::Bot::hi(){
  telegram.sendMessage("Hello");
}

void Djam::Bot::Bot::door(){
  telegram.sendMessage("The door is " + doorSensor.getValue());
}

void Djam::Bot::Bot::activate(){
  alertsEnabled = true;
  previousMillis = 0;
  telegram.sendMessage("Alerts activated");
}

void Djam::Bot::Bot::deactivate(){
  alertsEnabled = false;
  telegram.sendMessage("Alerts deactivated");
}

void Djam::Bot::Bot::status(){

  String alertsStatus = alertsEnabled ? "enabled" : "disabled";

  String passedTime = timeUtil.millisToHuman(millis() - doorSensor.previousStateMillis);

  String message = "*Status*\n";
  message += "\t\talerts : *" + alertsStatus + "*\n";
  message += "\t\tdoor : *" + doorSensor.getValue() + "*, last change: " + passedTime + "\n";

  telegram.sendMessage(message, "Markdown");
}

void Djam::Bot::Bot::help(){
  String message = "Welcome to TemujinBot, here you can control house ;)\n\n";
  message += "\t\t/hi : receive a feedback to check if the bot is working\n";
  message += "\t\t/door : check if the door is open or closed\n";
  message += "\t\t/activate : activate alerts for sensor events\n";
  message += "\t\t/deactivate : deactivate alerts for sensor events\n";
  message += "\t\t/status : check bot configs and sensors\n";
  message += "\t\t/help : show this help text\n";

  telegram.sendMessage(message, "Markdown");
}

void Djam::Bot::Bot::notFound(String command){
  alertsEnabled = false;
  telegram.sendMessage("What do you mean with \""+ command +"\"");
}

void Djam::Bot::Bot::alert(String message, bool avoidSpam){
  unsigned long currentMillis = millis();

  if(!alertsEnabled){
    return;
  }

  if(avoidSpam == true && (currentMillis - previousMillis) < TELEGRAM_ALERT_SPANS){
    return;
  }

  telegram.sendMessage(message);
  previousMillis = currentMillis;
}

void Djam::Bot::Bot::process(String command){
  Serial.println("Processing: " + command);

  if(command == "/hi"){
    hi();
  } else if(command == "/door") {
    door();
  } else if(command == "/activate") {
    activate();
  } else if(command == "/deactivate") {
    deactivate();
  } else if(command == "/status") {
    status();
  } else if(command == "/help") {
    help();
  } else {
    notFound(command);
  }
}
