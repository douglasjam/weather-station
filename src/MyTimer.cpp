#include <SPI.h>

class MyTimer {

  public: static const unsigned long _100ms = 100;
  public: static const unsigned long _500ms = 500;
  public: static const unsigned long _1s = 1000;
  public: static const unsigned long _10s = 10000;
  public: static const unsigned long _1m = 60000;

  void (*callback100ms)(void);
  void (*callback500ms)(void);
  void (*callback1s)(void);
  void (*callback10s)(void);
  void (*callback1m)(void);

  unsigned long timer100ms = 0;
  unsigned long timer500ms = 0;
  unsigned long timer1s = 0;
  unsigned long timer10s = 0;
  unsigned long timer1m = 0;

  public: void set100ms(void (*callback)(void)){
      callback100ms = callback;
  }

  public: void set500ms(void (*callback)(void)){
      callback500ms = callback;
  }

  public: void set1s(void (*callback)(void)){
      callback1s = callback;
  }

  public: void set10s(void (*callback)(void)){
      callback10s = callback;
  }

  public: void set1m(void (*callback)(void)){
      callback1m = callback;
  }

public: void run(){

  if(callback100ms != NULL && millis() > timer100ms){
    on100ms();
    timer100ms = millis() + _100ms;
  }

  if(callback500ms != NULL && millis() > timer500ms){
    on500ms();
    timer500ms = millis() + _500ms;
  }

  if(callback1s != NULL && millis() > timer1s){
    on1s();
    timer1s = millis() + _1s;
  }

  if(callback10s != NULL && millis() > timer10s){
    on10s();
    timer10s = millis() + _10s;
  }

  if(callback1m != NULL && millis() > timer1m){
    on1m();
    timer1m = millis() + _1m;
  }
}

  private: void on100ms(){
    callback100ms();
  }

  private: void on500ms(){
    callback500ms();
  }

  private: void on1s(){
    callback1s();
  }

  private: void on10s(){
    callback10s();
  }

  private: void on1m(){
    callback1m();
  }

};
