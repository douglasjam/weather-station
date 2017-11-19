#ifndef DJAM_ANALOGIC_DOORSENSOR
#define DJAM_ANALOGIC_DOORSENSOR

#include <Arduino.h>

namespace Djam { namespace Digital {

    class DoorSensor {

      public:
        void setup();
        String getName();
        String getValue();
        
        String previousState = "Closed";
        unsigned long previousStateMillis = 0;
    };
}}

#endif
