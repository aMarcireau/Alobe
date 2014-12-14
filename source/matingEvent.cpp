#include "matingEvent.h"

/**
* Constructor
*/
MatingEvent::MatingEvent(unique_ptr<TabulatedDistribution> willingToMateDistribution):
	PeriodicEvent(),
    my_willingToMateDistribution(move(willingToMateDistribution))
{
}

/**
* Get all the beings on the land to maybe mate
* Actor must be a Population
*/
void MatingEvent::filteredAction(Actor & actor)
{
	Population & population(dynamic_cast<Population &>(actor));

	for (unsigned long x = 0; x < population.getLand()->getWidth(); ++x) {
		for (unsigned long y = 0; y < population.getLand()->getHeight(); ++y) {

			vector<Being *> beings = population.getLand()->getTile(x, y)->getBeings();
            vector<Being *> females;
            vector<Being *> males;
            for (
                vector<Being *>::iterator beingIterator = beings.begin();
                beingIterator != beings.end();
                ++beingIterator
            ) {
                if (
                    (*(beingIterator))->getState("age")->getValue() <= BEING_MAXIMUM_AGE - BEING_MINIMUM_MATE_AGE &&
                    (*(beingIterator))->getState("age")->getValue() >= BEING_MAXIMUM_AGE - BEING_MAXIMUM_MATE_AGE
                ) {
                    if ((dynamic_cast<Gender *>((*(beingIterator))->getBehavior("gender")))->get() == "female") {
                        females.push_back(*(beingIterator));
                    } else if ((dynamic_cast<Gender *>((*(beingIterator))->getBehavior("gender")))->get() == "male"){
                        males.push_back(*(beingIterator));
                    } else {
                        throw logic_error("Gender unknown");
                    }
                }
            }

            random_shuffle(females.begin(), females.end());
            random_shuffle(males.begin(), males.end());

            for (
                vector<Being *>::iterator femaleIterator = females.begin();
                femaleIterator != females.end();
                ++femaleIterator
            ) {
                for (
                    vector<Being *>::iterator maleIterator = males.begin();
                    maleIterator != males.end();
                    ++maleIterator
                ) {
                    if (my_willingToMateDistribution->getDecision()) {
                        population.addBeing(
                            population.getBeingFactory()->generateBeing(*(*maleIterator), *(*femaleIterator)),
                            x, y
                        );
                        males.erase(maleIterator);
                        break;
                    }
                }
            }
        }
    }
}
