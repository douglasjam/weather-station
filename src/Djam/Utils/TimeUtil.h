#ifndef DJAM_UTILS_TIMEUTIL
#define DJAM_UTILS_TIMEUTIL

#include <Arduino.h>
#include <Time.h>

namespace Djam { namespace Utils {

    class TimeUtil {

      public:
        String millisToHuman(unsigned long millis);
    };
}}

#endif
