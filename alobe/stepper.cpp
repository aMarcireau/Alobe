#include "stepper.h"

/**
 * Constructor
 */
Stepper::Stepper():
    step(0),
    eventsByWeight(multimap<int, Event *>())
{
}

/**
 * Increment the stepper value and notify the attached events
 */
void Stepper::increment()
{
    step += 1;

    for (
        multimap<int, Event *>::iterator weightAndEventIterator = eventsByWeight.begin();
        weightAndEventIterator != eventsByWeight.end();
        ++weightAndEventIterator
    )
    {
        weightAndEventIterator->second->notify(this->getStep());
    }
}

/**
 * Reset the stepper value
 */
void Stepper::reset()
{
    step = 0;
}

/**
 * Get the current step
 */
unsigned int Stepper::getStep()
{
    return step;
}

/**
 * Attach an event
 */
void Stepper::attach(Event & event, int weight)
{
    eventsByWeight.insert(pair<int, Event *>(weight, &event));
}
