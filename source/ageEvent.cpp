#include "ageEvent.h"

/**
 * Constructor
 */
AgeEvent::AgeEvent():
    PeriodicEvent()
{
}

/**
 * Age all the beings of the population
 * Actor must be a Population
 */
void AgeEvent::filteredAction(Actor & actor)
{
    Population & population(dynamic_cast<Population &>(actor));

    vector<Being *> beings = population.getBeings();
    for (
        vector<Being *>::iterator beingIterator = beings.begin();
        beingIterator != beings.end();
        ++beingIterator
    ) {
        (*beingIterator)->getState("age")->decrement();

        if ((*beingIterator)->getState("age")->getValue() == 0) {
            (*beingIterator)->kill();
        }
    }
}
