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
        PeriodicEvent(unsigned long step = 0, unsigned long period = 1);
        virtual ~PeriodicEvent() = default;
        void action(Actor & actor, unsigned long step);                  // Change event filter rules (add periodicity)

    private:
        unsigned long my_period;
};

#endif // __ALOBE__PERIODIC_EVENT__
