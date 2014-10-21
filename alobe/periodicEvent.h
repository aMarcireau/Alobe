#ifndef __ALOBE__PERIODIC_EVENT__
#define __ALOBE__PERIODIC_EVENT__

#include "event.h"

/**
 * <<Abstract>> PeriodicEvent
 * Inherits Event
 *
 * Starting at triggerStep, PeriodicEvent objects call their filteredAction method every triggerPeriod
 */
class PeriodicEvent: public Event
{
    public:
        PeriodicEvent(unsigned int step = 0, unsigned int period = 1); 
        void action(Actor & actor, unsigned int step);                 // Change event filter rules (add periodicity)

    private:
        unsigned int my_triggerPeriod;
};

#endif // __ALOBE__PERIODIC_EVENT__
