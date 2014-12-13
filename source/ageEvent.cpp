#include "ageEvent.h"

/**
 * Constructor
 */
AgeEvent::AgeEvent(unique_ptr<TabulatedDistribution> deathDistribution):
    PeriodicEvent(),
    my_deathDistribution(move(deathDistribution))
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

        if (my_deathDistribution->getDecision((*beingIterator)->getState("age")->getValue())) {
            (*beingIterator)->kill();
        }
    }
}
