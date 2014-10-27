#include "periodicEvent.h"

/**
 * Constructor
 */
PeriodicEvent::PeriodicEvent(unsigned long step, unsigned long period):
    Event(step),
    my_triggerPeriod(period)
{
}

/**
 * Change event filter rules (add periodicity)
 */
void PeriodicEvent::action(Actor & actor, unsigned long step)
{
    if (step >= my_triggerStep & (step - my_triggerStep) % my_triggerPeriod == 0) {
        this->filteredAction(actor);
    }
}
