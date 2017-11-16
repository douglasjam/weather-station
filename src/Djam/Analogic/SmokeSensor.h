#ifndef DJAM_ANALOGIC_SMOKESENSOR
#define DJAM_ANALOGIC_SMOKESENSOR

#include <Arduino.h>

namespace Djam { namespace Analogic {

    class SmokeSensor {

      public:
        void setup();
        String getName();
        double getValue();
    };
}}

#endif
