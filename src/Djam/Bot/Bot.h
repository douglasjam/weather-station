#ifndef DJAM_BOT_BOT
#define DJAM_BOT_BOT

#include <Arduino.h>
#include <SPI.h>
#include <Djam/MyConfigs.h>
#include <Djam/Digital/DoorSensor.h>
#include <Djam/Internet/Telegram.h>
#include <Djam/Utils/TimeUtil.h>
#include <UniversalTelegramBot.h>

namespace Djam { namespace Bot {

  class Bot {

    public:
      void setup(
          Djam::Internet::Telegram telegram,
          Djam::Digital::DoorSensor doorSensor
       );
       void process(String command);
       void alert(String message, bool avoidSpam = false);

    private:
      bool alertsEnabled = true;
      unsigned long previousMillis;
      Djam::Internet::Telegram telegram;
      Djam::Digital::DoorSensor doorSensor;
      Djam::Utils::TimeUtil timeUtil;

      void hi();
      void door();
      void activate();
      void deactivate();
      void status();
      void help();
      void notFound(String command);
   };

}}

#endif
