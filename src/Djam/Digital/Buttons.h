#ifndef DJAM_DIGITAL_BUTTONS
#define DJAM_DIGITAL_BUTTONS

#include <Arduino.h>
#include <SPI.h>

namespace Djam { namespace Digital {

  class Buttons {

    public:
      void setup();

      /** @todo refactor to have dynamic buttons */
      unsigned int getGreenStatus();
      unsigned int getWhiteStatus();

    private:
      static const int NO_CHANGE = 0;
      static const int TURN_OFF = 1;
      static const int TURN_ON = 2;

      bool lastStateGreen;
      bool greenValue;

      bool lastStateWhite;
      bool whiteValue;

      unsigned int handleStateChange(String id, bool &currentValue, bool &lastState, bool currentState);

   };

}}

#endif
