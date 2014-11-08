#include "population.h"

/**
 * Constructor
 */
Population::Population(Land & land, BeingFactory & beingFactory):
    Actor(),
    my_land(&land),
    my_beingFactory(&beingFactory),
    my_beings(vector<unique_ptr<Being> >()),
    mod_beings(vector<unique_ptr<Being> >())
{
}

/**
* Getter for the land
*/
Land * Population::getLand() const
{
	return my_land;
}

/**
* Getter for the being factory
*/
BeingFactory * Population::getBeingFactory() const
{
	return my_beingFactory;
}

/**
* Get beings number
*/
unsigned long Population::getBeingsNumber() const
{
	return my_beings.size();
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
        make_unique<Being>(to_string(rand()), vector<shared_ptr<Chromosome> >()),
        rand() % my_land->getWidth(),
        rand() % my_land->getHeight()
    );
}

/**
 * Apply changes after a step
 */
void Population::applyChanges(Stepper & stepper)
{
    unsigned int modBeingsLength = static_cast<unsigned int>(mod_beings.size());
    for (
        unsigned int index = 0;
        index < modBeingsLength;
        ++index
    ) {
        stepper.attach(*(mod_beings[index].get()));
        my_beings.push_back(move(mod_beings[index]));
    }

    mod_beings = vector<unique_ptr<Being> >();

    for (
        vector<unique_ptr<Being> >::iterator beingIterator = my_beings.begin();
        beingIterator != my_beings.end();
        ++beingIterator
    ) {
        (*beingIterator)->applyChanges(stepper);
    }
}
