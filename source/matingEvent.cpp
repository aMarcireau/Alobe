#include "matingEvent.h"

/**
* Constructor
*/
MatingEvent::MatingEvent():
	PeriodicEvent()
{
}

/**
* Get all the beings on the land to maybe mate
*/
void MatingEvent::filteredAction(Actor & actor)
{
	Population & population(dynamic_cast<Population &>(actor));

	for (unsigned long x = 0; x < population.getLand()->getWidth(); ++x) {
		for (unsigned long y = 0; y < population.getLand()->getHeight(); ++y) {

			vector<Being *> beings = population.getLand()->getTile(x, y)->getBeings();
            unsigned long beingsNumber = beings.size();
			for (
                unsigned long beingIndex = 0;
                beingIndex < beingsNumber;
                ++beingIndex
            ) {
                for (
                    unsigned long otherBeingIndex = beingIndex + 1;
                    otherBeingIndex < beingsNumber;
                    ++otherBeingIndex
                ) {
					if (beings[beingIndex]->isWillingToMateWith(*beings[otherBeingIndex]) and beings[otherBeingIndex]->isWillingToMateWith(*beings[beingIndex])) {
                        population.addBeing(
                            population.getBeingFactory()->generateBeing(*beings[beingIndex], *beings[otherBeingIndex]),
                            x, y
                        );
                    }
                }
            }
        }
    }
}
