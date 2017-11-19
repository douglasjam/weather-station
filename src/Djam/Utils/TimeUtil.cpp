#include <Djam/Utils/TimeUtil.h>

String Djam::Utils::TimeUtil::millisToHuman(unsigned long millis){

  int second = 1000;
  int minute = second * 60;
  int hour = minute * 60;
  int day = hour * 24;

  int seconds = millis / second;

  int days = seconds / day;
  seconds %= day;
  int hours = seconds / hour;
  seconds %= hour;
  int minutes = seconds / minute;
  seconds %= minute;

  String formattedDate = "";

  if(days > 0){
    formattedDate = formattedDate + days + "d";
  }

  if(hours > 0){
    formattedDate = formattedDate + hours + "h";
  }

  if(minutes > 0){
    formattedDate = formattedDate + minutes + "m";
  }

  if(seconds > 0){
    formattedDate = formattedDate + seconds + "s";
  }

  return formattedDate;
}
