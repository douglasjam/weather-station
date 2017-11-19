#include <Djam/Internet/Telegram.h>

void Djam::Internet::Telegram::setup(){
  bot = new UniversalTelegramBot(TELEGRAM_TOKEN, client);
}

void Djam::Internet::Telegram::sendMessage(String message, String parseMode){
  bot->sendMessage(TELEGRAM_CHAT_ID, message, parseMode);
}

void Djam::Internet::Telegram::listenMessages(void (*callback)(String command)){
  int messagesAmount = bot->getUpdates(bot->last_message_received + 1);

  while(messagesAmount) {
      for (int i=0; i < messagesAmount; i++) {
        Serial.println("Received: " + bot->messages[i].text);
        callback(bot->messages[i].text);
      }
      messagesAmount = bot->getUpdates(bot->last_message_received + 1);
    }
}
