#ifndef DJAM_INTERNET_TELEGRAM
#define DJAM_INTERNET_TELEGRAM

#include <String.h>
#include <Djam/MyConfigs.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

namespace Djam { namespace Internet {

  class Telegram {

    public:
      void setup();
      void sendMessage(String message, String parseMode = "");
      void listenMessages(void (*callback)(String command));

    private:
      WiFiClientSecure client;
      UniversalTelegramBot* bot;
  };

}}

#endif
