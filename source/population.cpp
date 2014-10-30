#include "population.h"

/**
 * Constructor
 */
Population::Population(Land & land):
    Actor(),
    my_land(&land),
    my_beings(vector<unique_ptr<Being> >())
{
}

/**
 * Add a being
 */
void Population::addBeing(unique_ptr<Being> being, unsigned long x, unsigned long y, Stepper & stepper)
{
    my_beings.push_back(move(being));
    stepper.attach(*(my_beings.back().get()));
}

/**
 * Generate a random being
 */
void Population::randomBeing(Stepper & stepper)
{
    this->addBeing(
        make_unique<Being>(to_string(rand()), map<string, shared_ptr<Chromosome> >()),
        rand() % my_land->getWidth(),
        rand() % my_land->getHeight(),
        stepper
    );
}

/**
 * Apply changes after a step
 */
void Population::applyChanges()
{
    for (
        vector<unique_ptr<Being> >::iterator beingIterator = my_beings.begin();
        beingIterator != my_beings.end();
        ++beingIterator
    ) {
        (*beingIterator)->applyChanges();
    }
}
