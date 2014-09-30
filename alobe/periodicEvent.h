#ifndef __alobe__periodicEvent__
#define __alobe__periodicEvent__

#include "event.h"

/**
 * <<Abstract>> PeriodicEvent
 * Inherits Event
 *
 * Starting at triggerStep, PeriodicEvent objects call their action method every triggerPeriod
 */
class PeriodicEvent: public Event
{
    public:
        PeriodicEvent(unsigned int step = 0, unsigned int period = 1); // Constructor
        void notify(unsigned int step);                                // Notification called by the Stepper
        unsigned int getTriggerPeriod();                               // Getter for triggerPeriod

    private:
        unsigned int triggerPeriod;                                    // Store the trigger step value
};

#endif /* defined(__alobe__periodicEvent__) */
