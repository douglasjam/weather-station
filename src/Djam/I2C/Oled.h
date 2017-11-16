#ifndef DJAM_I2C_OLED
#define DJAM_I2C_OLED

#include <Djam/MyConfigs.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <vector>

#define OLED_RESET LED_BUILTIN  //4

#if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

namespace Djam { namespace I2C {

  class Oled {

    struct Page {
      String name;
      String value;
    };

    // garbaje here?
    Adafruit_SSD1306 display{OLED_RESET};

    std::vector<Page> pages;
    unsigned int currentPageIndex = 0;

    public:
      void setup();
      void addPage(String name);
      void setPageValue(String page, String value);
      void printNextPage();

      void printMessage(String message);
      void printKeyValue(String key, String value);
  };

}}

#endif
