#include "event.h"

/**
 * Constructor
 */
Event::Event(unsigned int step)
{
}

/**
 * Trigger event action on an actor with a given step
 */
void Event::action(Actor & actor, unsigned int step)
{
    if (step == triggerStep) {
        this->filteredAction(actor);
    }
}
