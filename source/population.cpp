#include "population.h"

/**
 * Constructor
 */
Population::Population(Land & land):
    Actor(),
    my_land(&land),
    my_beings(vector<unique_ptr<Being> >()),
    mod_beings(vector<unique_ptr<Being> >())
{
}

Land * Population::getLand()
{
	return my_land;
}

/**
 * Add a being
 */
void Population::addBeing(unique_ptr<Being> being, unsigned long x, unsigned long y)
{
    mod_beings.push_back(move(being));
    my_land->getTile(x, y)->attachBeing(*(mod_beings.back().get()));
}

/**
 * Generate a random being
 */
void Population::randomBeing()
{
    addBeing(
        make_unique<Being>(to_string(rand()), map<string, shared_ptr<Chromosome> >()),
        rand() % my_land->getWidth(),
        rand() % my_land->getHeight()
    );
}

/**
 * Apply changes after a step
 */
void Population::applyChanges(Stepper & stepper)
{
    for (
        vector<unique_ptr<Being> >::iterator beingIterator = mod_beings.begin();
        beingIterator != mod_beings.end();
    ) {
        stepper.attach(*((*beingIterator).get()));

        my_beings.push_back(move(*beingIterator));
        mod_beings.erase(beingIterator);
    }

    for (
        vector<unique_ptr<Being> >::iterator beingIterator = my_beings.begin();
        beingIterator != my_beings.end();
        ++beingIterator
    ) {
        (*beingIterator)->applyChanges(stepper);
    }
}
