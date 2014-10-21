#include "periodicEvent.h"

/**
 * Constructor
 */
PeriodicEvent::PeriodicEvent(unsigned int step, unsigned int period):
    Event(step),
    my_triggerPeriod(period)
{
}

/**
 * Change event filter rules (add periodicity)
 */
void PeriodicEvent::action(Actor & actor, unsigned int step)
{
    if (step >= my_triggerStep & (step - my_triggerStep) % my_triggerPeriod == 0) {
        this->filteredAction(actor);
    }
}
