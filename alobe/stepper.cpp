#include "stepper.h"

/**
 * Constructor
 */
Stepper::Stepper():
    _step(0),
    _actors(vector<Actor *>())
{
}

/**
 * Increment the stepper value and notify the attached events
 */
void Stepper::increment()
{
    _step += 1;

    for (
        vector<Actor *>::iterator actorIterator = _actors.begin();
        actorIterator != _actors.end();
        ++actorIterator
    ) {
        (*actorIterator)->notify(_step);
    }
}

/**
 * Reset the stepper value
 */
void Stepper::reset()
{
    _step = 0;
}

/**
 * Get the current step
 */
unsigned int Stepper::getStep()
{
    return _step;
}

/**
 * Attach an event
 */
void Stepper::attach(Actor & actor)
{
    _actors.push_back(&actor);
}

/**
 * Detach an event
 */
void Stepper::detach(Actor & actor)
{
    _actors.erase(std::remove(_actors.begin(), _actors.end(), &actor), _actors.end());
}
