#ifndef __alobe__stepper__
#define __alobe__stepper__

#include <map>

#include "event.h"

using namespace std;

/**
 * Stepper
 *
 * A stepper will trigger its observers (Event objects) after each step.
 * When attaching an Event, a weight can be specified (default: 1).
 * Events with a bigger weight are triggered before.
 */
class Stepper
{
    public:
        Stepper();                                  // Constructor
        void increment();                           // Increment the stepper value and notify the attached events
        void reset();                               // Reset the stepper value
        unsigned int getStep();                     // Get the current step
        void attach(Event & event, int weight = 1); // Attach an event, and give it a weight

    private:
        unsigned int step;                          // Store the stepper value
        multimap<int, Event *> eventsByWeight;      // Store attached events and their associated weight
};

#endif /* defined(__alobe__stepper__) */
