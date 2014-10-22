#include "event.h"

/**
 * Constructor
 */
Event::Event(unsigned long step)
{
}

/**
 * Trigger event action on an actor with a given step
 */
void Event::action(Actor & actor, unsigned long step)
{
    if (step == my_triggerStep) {
        this->filteredAction(actor);
    }
}
