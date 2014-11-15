#include "population.h"

/**
 * Constructor
 */
Population::Population(Land & land, BeingFactory & beingFactory):
    Actor(),
    my_land(&land),
    my_beingFactory(&beingFactory),
    my_beings(vector<unique_ptr<Being> >()),
    mod_beings(vector<unique_ptr<Being> >()),
    dead_beings(vector<unique_ptr<Being> >())
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
 * Getter for the beings
 */
vector<Being *> Population::getBeings()
{
    vector<Being *> beings;
    for (
        vector<unique_ptr<Being> >::iterator beingIterator = my_beings.begin();
        beingIterator != my_beings.end();
        ++beingIterator
    ) {
        beings.push_back((*beingIterator).get());
    }

    return beings;
}

/**
 * Get beings number
 */
unsigned long Population::getBeingsNumber() const
{
	return my_beings.size();
}

/**
 * Get the number of dead beings
 */
unsigned long Population::getDeadBeingsNumber() const
{
    return dead_beings.size();
}

/**
 * Generate a random being
 */
void Population::addBeing()
{
    addBeing(
        move(my_beingFactory->generateBeing()),
        rand() % my_land->getWidth(),
        rand() % my_land->getHeight()
    );
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
 * Apply changes after a step
 */
void Population::applyChanges(Stepper & stepper)
{
    unsigned long modBeingsLength = mod_beings.size();
    for (
        unsigned long index = 0;
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
    ) {
        if ((*beingIterator)->isDead()) {
            for (unsigned long x = 0; x < my_land->getWidth(); ++x) {
                for (unsigned long y = 0; y < my_land->getHeight(); ++y) {
                    my_land->getTile(x, y)->detachBeing(*(*beingIterator));
                }
            }
            dead_beings.push_back(move(*beingIterator));
            beingIterator = my_beings.erase(beingIterator);
        } else {
            (*beingIterator)->applyChanges(stepper);
            ++beingIterator;
        }
    }
}
