#include <MyConfigs.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN  //4

#if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

class MyOled {

  // garbaje here?
  Adafruit_SSD1306 display{OLED_RESET};

  public: void setup(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.setTextSize(2);
    display.setTextColor(WHITE);

    display.clearDisplay();
    display.display();
  }



  public: void printMessage(String message){
    display.clearDisplay();
    display.setCursor(0,0);
    display.println(message);
    display.display();
  }

  public: void printKeyValue(String key, String value){
    display.clearDisplay();

    display.setCursor(0, 0);
    display.print(key);

    display.setCursor(0, 32);
    display.print(value);

    display.display();
  }

};
