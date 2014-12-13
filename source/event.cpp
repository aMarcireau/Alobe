#include "event.h"

/**
 * Constructor
 */
Event::Event(unsigned long step):
    my_step(step)
{
}

/**
 * Trigger event action on an actor with a given step
 */
void Event::action(Actor & actor, unsigned long step)
{
    if (step == my_step) {
        filteredAction(actor);
    }
}
