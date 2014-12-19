
#include "periodicEvent.h"

/**
 * Constructor
 */
PeriodicEvent::PeriodicEvent(unsigned long step, unsigned long period):
    Event(step),
    my_period(period)
{
}

/**
 * Change event filter rules (add periodicity)
 */
void PeriodicEvent::action(Actor & actor, unsigned long step)
{
    if ((step >= my_step) & ((step - my_step) % my_period == 0)) {
        filteredAction(actor);
    }
}
