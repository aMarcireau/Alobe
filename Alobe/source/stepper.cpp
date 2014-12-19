#include "stepper.h"

/**
 * Constructor
 */
Stepper::Stepper():
    my_step(0),
    my_actors(vector<Actor *>())
{
}

/**
 * Increment the stepper value and notify the attached events
 */
void Stepper::increment()
{
    my_step += 1;

    vector<Actor*> aliveActors;
    for (
        vector<Actor *>::iterator actorIterator = my_actors.begin();
        actorIterator != my_actors.end();
        ++actorIterator
    ) {
        if (!(*actorIterator)->isDead()) {
            (*actorIterator)->notify(my_step);
            aliveActors.push_back(*actorIterator);
        }
    }

    my_actors = aliveActors;
}

/**
 * Reset the stepper value
 */
void Stepper::reset()
{
    my_step = 0;
}

/**
 * Get the current step
 */
unsigned long Stepper::getStep()
{
    return my_step;
}

/**
 * Attach an event
 */
void Stepper::attach(Actor & actor)
{
    my_actors.push_back(&actor);
}

/**
 * Detach an event
 */
void Stepper::detach(Actor & actor)
{
    my_actors.erase(remove(my_actors.begin(), my_actors.end(), &actor), my_actors.end());
}
