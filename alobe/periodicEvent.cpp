#include "periodicEvent.h"

/**
 * Constructor
 */
PeriodicEvent::PeriodicEvent(unsigned int step, unsigned int period):
    Event(step),
    triggerPeriod(period)
{
}

/**
 * Change event filter rules (add periodicity)
 */
void PeriodicEvent::action(Actor & actor, unsigned int step)
{
    if (step >= triggerStep & (step - triggerStep) % triggerPeriod == 0) {
        this->filteredAction(actor);
    }
}
