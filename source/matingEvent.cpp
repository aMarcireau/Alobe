#include "matingEvent.h"

/**
* Constructor
*/
MatingEvent::MatingEvent() :
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

			for (
				vector<Being *>::iterator beingIterator = beings.begin();
				beingIterator != beings.end();
				++beingIterator
            ) {
				//Iteration on all beings that haven't met the previous being yet
				for (
					vector<Being *>::iterator otherBeingsIterator = beingIterator + 1;
					otherBeingsIterator != beings.end();
					++otherBeingsIterator
                ){
					//Test if the being want to mate with an other being
					if ((*beingIterator)->isReadyToMate(**otherBeingsIterator))
                    {
                        // Creation of the child chromosomes
                        vector<shared_ptr<Chromosome>> childChromosomes = (*beingIterator)->setChildChromosomes(**otherBeingsIterator);
                        //Creation of the new being on the current tile
                        population.addBeing(make_unique<Being>(to_string(rand()), childChromosomes), x, y);
                    }
                }
            }
        }
    }
}
